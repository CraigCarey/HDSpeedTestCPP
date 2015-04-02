/*
 * utils.h
 *
 *  Created on: 24 Jun 2014
 *      Author: craig
 */

#pragma once	// prevents multiple includes

#include <cstdio>
#include <string>

#define KIB 1024
#define MIB 1024 * KIB
#define GIB 1024 * MIB


// function prototypes
void file_write (FILE *wfp, int n_blocks, int block_size_kb);
char *create_block(int block_size_kb);
int is_power_of_two(int x);
std::string format_data_quantity(unsigned long long data_quantity);


// 1kb of test data for constructing block sizes from
const char test_data_1kb[1025] =  	"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work and no play makes Jack a dull boy.\n"
								"All work an\n";
