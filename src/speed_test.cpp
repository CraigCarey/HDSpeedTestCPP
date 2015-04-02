//============================================================================
// Name        : speed_test.cpp
// Author      : Craig Carey
// Date		   : 24/06/14
// Version     : 1
// Description : Calculates disk write speed by writing data to a file.
// Issues	   : TODO - write format_data_quantity() fx
//				 TODO - change printfs to couts - safer
//				 TODO - verify written data
//				 TODO - automate testing & logging
//============================================================================

#include <sys/time.h>
#include <cstdio>		// C library to perform Input/Output operations - fopen, fclose
#include <iostream>

#include "user_io.h"	// Custom header for user IO stuff
#include "utils.h"		// Custom header containing file stuff

int main() {

	struct timeval start_time, end_time;
	long seconds, useconds;
	float elapsed_time;
	int block_size_kib = 1;								// number of kb to write at once
	unsigned long long byte_multiplier = MIB;			// default is 1 meg
	unsigned long long data_quantity = 1 * GIB;			// amount of data to write

	// user input
	block_size_kib = get_block_size();
	byte_multiplier = get_byte_multiplier();
	data_quantity = get_data_quantity() * byte_multiplier;

	// break data amount in number of blocks of appropriate size
	unsigned long num_blocks = data_quantity / (block_size_kib * KIB);

	// Output info to console
	std::cout << "\nBlock size:\t\t" << block_size_kib << "kb\n";
	std::cout << "Data quantity:\t\t" << data_quantity << " bytes\n";
	std::cout << "Number of blocks:\t" << num_blocks << "\n\n";
	std::cout << "File opening...\n";


	// opens (creates if doesn't exist) file and associates it with a stream. "w" - write
	FILE *ofp = fopen ("/mnt/crucial/write_test", "w");

	// if file pointer isn't valid...
	if (ofp == NULL)
	{
		std::cout << "Error opening file, quitting\n";

	    // exit abnormally - errors
	    return 1;
	}

	std::cout << "Writing to file...\n\n";

	// start time
	gettimeofday(&start_time, NULL);

	// call file_write function, passing in file pointer and argument
	file_write(ofp, num_blocks, block_size_kib);

	// end time
	gettimeofday(&end_time, NULL);

	// get time difference using timeval structures
    seconds  = end_time.tv_sec  - start_time.tv_sec;
    useconds = end_time.tv_usec - start_time.tv_usec;
    elapsed_time = (float) seconds + ((float) useconds/1000000.0);

    std::cout << "Start time:\t" << start_time.tv_sec << "." << start_time.tv_usec << "\n";
    std::cout << "End time:\t" << end_time.tv_sec << "." << end_time.tv_usec << "\n";
    std::cout << "Wrote:\t\t" << block_size_kib * num_blocks << " KiB\n";
    std::cout << "In:\t\t" << elapsed_time << " seconds\n";
    std::cout << "Block size:\t" << block_size_kib << " KiB\n";
    std::cout << "Write speed:\t" << ((float)(block_size_kib * num_blocks) / KIB) / elapsed_time << " MiB/s\n\n";

    std::cout << "File close\n";

	// closes the file associated with the stream and dissociates it
	fclose(ofp);

	// exit program normally - no errors
	return 0;

}

