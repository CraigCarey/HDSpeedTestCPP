/*
 * utils.cpp
 *
 *  Created on: 25 Jun 2014
 *      Author: craig
 */

#include "utils.h"

#include <cstring>
#include <iostream>
#include <iomanip>

/*
 *  Writes arbitrary data to file
 *  Inputs: 	Pointer to file to be written
 *		 		Number of blocks to write to file
 * 				Size of blocks to write
 *  Outputs:	None
 */
void file_write (FILE *wfp, int n_blocks, int block_size_kb)
{
	char *data_block = create_block(block_size_kb);

	// print progress every 1024 blocks
	int print_interval = n_blocks / 128;

	// print string n times
	for(int i = 0; i < n_blocks; i++)
	{
		// write formatted data to stream
//		fprintf(wfp, "%s", data_block);
		fwrite(data_block,sizeof(char),block_size_kb*1024,wfp);
		//fflush(wfp);

//		// when n_blocks is a multiple of 1024
//		if ((n_blocks % print_interval) == 0)
//		{
//			std::cout << std::fixed << std::setw(3) << std::setprecision(1) << 100 * ((float) i / n_blocks) << "%\n";
//		}
	}
}


/*
 * 	Produces an n kb block of arbitrary data
 * 	Inputs: 	Required block size in kb multiples
 * 	Outputs:	A char array
 */
char *create_block(int block_size_kb)
{
	char* data_block = new char[KIB * block_size_kb];

	for (int i = 0; i < block_size_kb; i++)
	{
		strcat(data_block, test_data_1kb);
	}

	return data_block;

}

/*
 * Checks to see if an an input is a power of 2
 * Inputs:	One integer
 * Outputs:	One if true, 0 if false
 */
int is_power_of_two(int x)
{
	int pow_two = 1;

	while (pow_two < x && pow_two < KIB)
	{
		pow_two *= 2;
	}

	return (x == pow_two);
}


/*
 * Formats the amount of data into human readable form
 * Input:	long long unsigned amount of data
 * Outputs:	Human readable string
 */
std::string format_data_quantity(unsigned long long data_quantity)
{
	// TODO
	return "todo";
}



