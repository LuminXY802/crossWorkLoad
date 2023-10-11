#include "hash.h"

//SHA_40 Digest
struct Digest {
	BYTE hash0, hash1, hash2, hash3, hash4;
};


//SHA_40 hash function
unsigned char* SHA_40(const unsigned char* x, size_t size)
{
	unsigned char A = 11;
	unsigned char B = 22;
	unsigned char C = 33;
	unsigned char D = 44;
	unsigned char E = 55;

	for (int i = 0; i < size; i++)
	{
		for (int r = 0; r < 12; r++) {
			unsigned char F = (B & C) ^ D;
			unsigned char newA = A;
			/*Use the diagram to determine what these values should be*/
			A = ?????
			E = ?????
			D = ?????
			C = ?????
			B = ?????
		}
	}

	unsigned char* digest = (unsigned char*)malloc(DIGEST_SIZE);

	digest[0] = A;
	digest[1] = B;
	digest[2] = C;
	digest[3] = D;
	digest[4] = E;

	return digest;
}

//return one (true) or return zero (false)
int digestEqual(struct Digest* digest1, struct Digest* digest2) {
	//Should return 1 if the two digests are equal and 0 if the two digests are not equal.
}