#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYMAP_SIZE 256
#define MAX_FILENAME_LENGTH 100

void decryptMessage(char keymap[MAX_KEYMAP_SIZE][2], const char* inputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error: Unable to open the input file");
        exit(EXIT_FAILURE);
    }

    int encryptedCharacter;
    while (fscanf(inputFile, "%d\n", &encryptedCharacter) == 1) {
        char character = encryptedCharacter;
        char decryptedCharacter = -1;

        if (character >= 0 && character < MAX_KEYMAP_SIZE) {
            decryptedCharacter = character ^ keymap[(int)character][1];
        }

        if (decryptedCharacter != -1) {
            putchar(decryptedCharacter);
        }
        else {
            printf("Character not found in keymap: %c\n", character);
        }
    }

    fclose(inputFile);
}

//int main() {
//    char keymap[MAX_KEYMAP_SIZE][2];
//    char inputFileName[MAX_FILENAME_LENGTH];
//
//    printf("Enter the name of the input file: ");
//    if (scanf("%s", inputFileName) != 1) {
//        perror("Error reading input file name");
//        return EXIT_FAILURE;
//    }
//
//    decryptMessage(keymap, inputFileName);
//
//    return EXIT_SUCCESS;
//}
