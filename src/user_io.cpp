/*
 * user_io.cpp
 *
 *  Created on: 25 Jun 2014
 *      Author: craig
 */

#include <cctype>
#include <iostream>

#include "utils.h"
#include "user_io.h"

char mult_input[4];	// shared by get_byte_multiplier and get_data_quantity


/*
 * Prompts user for block size
 * Inputs:	None
 * Outputs:	Integer block size in n^2 kb multiples
 */
int get_block_size()
{
	int block_size = 1;

	// user prompt and input
	std::cout << "Block size (1, 2, 4, 8, 16, 32... kb):\t";
	std::cin >> block_size;

	// type check input
	if (std::cin.fail() || !is_power_of_two(block_size))
	{
		std::cout << "\nError: block size must be a power of 2\n\n";
		std::cin.clear();
		std::cin.ignore();
		get_block_size();

	} else {

		return block_size;
	}

	std::cout << "\n";

	return 1;
}


/*
 * Prompts user for a byte multiplier
 * Inputs:	None
 * Outputs:	llu byte multiplier :- K, M or G
 */
unsigned long long get_byte_multiplier()
{
	unsigned long long byte_mult = 1;

	std::cout << "Byte multiple (KiB/MiB/GiB):\t\t";
	std::cin >> mult_input;
	//std::cout << "\n";

	if (std::cin.fail())
	{
		std::cout << "Error: invalid entry\n\n";
		std::cin.clear();
		std::cin.ignore();
		get_data_quantity();
	}

	// format input
	mult_input[0] = toupper(mult_input[0]);
	mult_input[1] = 'i';
	mult_input[2] = 'B';
	mult_input[3] = '\0';

	// test input for correctness
	byte_mult = test_data_mult(mult_input[0]);

	return byte_mult;

}


/*
 * Prompts the user for an amount of data (in KB/MB/GB)
 * Inputs:	None
 * Outputs:
 */
unsigned long long get_data_quantity()
{
	unsigned long long data_quant = 1;

	std::cout << "Data Quantity (" << mult_input << "):\t\t\t";
	std::cin >> data_quant;

	// check input
	if (std::cin.fail())
	{
		std::cout << "Error: invalid amount";
		std::cin.clear();
		std::cin.ignore();
		get_data_quantity();	// restart function
	}

	std::cout << "\n";

	return data_quant;
}


/*
 *	Tests user input for valid byte multiple
 *	Input:	First character of multiplier input
 *	Output:	Integer byte multiplier
 */
unsigned long test_data_mult(char mult)
{
	switch(mult)
	{
		case 'K':
			return KIB;	// 1024
			break;
		case 'M':
			return MIB;	// 1024^2
			break;
		case 'G':
			return GIB; // 1024^3
			break;
		default:
			std::cout << "Error: invalid multiplier\n\n";
			get_byte_multiplier();	// restart function
	}

	return 1;
}

