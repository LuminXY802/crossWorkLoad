#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for block
struct Block {
	char data[256];
	unsigned char digest[5];
	struct Block* previous_block;
};

// Define struct for blockchain
struct Blockchain {
	struct Block* head;
};

// Define the SHA_40 function
unsigned char* SHA_40()