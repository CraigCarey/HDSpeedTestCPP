/*
 * user_io.h
 *
 *  Created on: 25 Jun 2014
 *      Author: craig
 */

#pragma once	// prevents multiple includes

// fx prototypes
int get_block_size();
unsigned long long get_byte_multiplier();
unsigned long long get_data_quantity();
unsigned long test_data_mult(char mult);

#define KIB 1024
#define MIB 1024 * KIB
#define GIB 1024 * MIB
