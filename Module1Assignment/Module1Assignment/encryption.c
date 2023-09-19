#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYMAP_SIZE 256
#define MAX_FILENAME_LENGTH 100
#define MAX_MESSAGE_LENGTH 100

void encryptMessage(char keymap[MAX_KEYMAP_SIZE][2], const char* message, const char* outputFileName) {
    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error: Unable to open the output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; message[i] != '\0'; i++) {
        char character = message[i];
        int encryptedCharacter = -1;

        if (character >= 0 && character < MAX_KEYMAP_SIZE) {
            encryptedCharacter = character ^ keymap[(int)character][1];
        }

        if (encryptedCharacter != -1) {
            fprintf(outputFile, "%d\n", encryptedCharacter);
        }
        else {
            fprintf(outputFile, "Character not found in keymap: %c\n", character);
        }
    }

    fclose(outputFile);
}

//int main() {
//    char keymap[MAX_KEYMAP_SIZE][2];
//    char message[MAX_MESSAGE_LENGTH];
//    char outputFileName[MAX_FILENAME_LENGTH];
//
//    printf("Enter the message to encrypt (up to %d characters): ", MAX_MESSAGE_LENGTH - 1);
//    if (fgets(message, sizeof(message), stdin) == NULL) {
//        perror("Error reading input");
//        return EXIT_FAILURE;
//    }
//    message[strcspn(message, "\n")] = '\0'; // Remove the newline character
//
//    printf("Enter the name of the output file (up to %d characters): ", MAX_FILENAME_LENGTH - 1);
//    if (scanf("%s", outputFileName) != 1) {
//        perror("Error reading output file name");
//        return EXIT_FAILURE;
//    }
//
//    encryptMessage(keymap, message, outputFileName);
//
//    printf("Encryption complete. Output saved to %s\n", outputFileName);
//
//    return EXIT_SUCCESS;
//}
