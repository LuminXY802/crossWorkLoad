#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [encrypt/decrypt]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        // Include encryption-specific code
        #include "encryption.c"
    }

    else if (strcmp(argv[1], "decrypt") == 0) {
        // Include decryption-specific code
        #include "decryption.c"
    }

    else {
        printf("Invalid option: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
