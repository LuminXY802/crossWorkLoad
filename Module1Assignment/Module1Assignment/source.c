#include <stdio.h>
#include <string.h>

// Function to create the Decryption Key
void createDecryptionKey(char keymap[256][2], const char* keyFileName) {
    // Open the decryption key file for writing
    FILE* keyFile = fopen(keyFileName, "w");

    // Check if the file opened successfully
    if (keyFile == NULL) {
        printf("Error: Unable to create the decryption key file.\n");
        exit(1);
    }

    // Generate a key that includes all possible characters
    // This assumes ASCII characters from 0 to 255
    for (int i = 0; i < 256; i++) {
        keymap[i][0] = (char)i; // Plaintext letter
        keymap[i][1] = i;       // Corresponding key value

        // Write the mapping to the decryption key file
        fprintf(keyFile, "%c,%d\n", keymap[i][0], keymap[i][1]);
    }

    // Close the decryption key file
    fclose(keyFile);
}

void performXOREncryption(char keymap[256][2], const char* input, char* output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char character = input[i];
        if (character >= 0 && character < 256) {
            output[i] = character ^ keymap[(int)character][1]; // Apply XOR operation
        }
        else {
            // Handle invalid characters if necessary
            output[i] = character;
        }
    }
}

int main() {
    char keymap[256][2];
    char keyFileName[] = "decryption_key.txt";
    char input[100];
    char encryptedOutput[100];
    char decryptedOutput[100];

    // Create the decryption key file
    printf("Creating the decryption key file...\n");
    createDecryptionKey(keymap, keyFileName);
    printf("Decryption key file created.\n");

    // Prompt the user for input
    printf("Enter the message to encrypt: ");
    scanf(" %[^\n]s", input);

    // Encrypt the input
    performXOREncryption(keymap, input, encryptedOutput);
    printf("Encryption complete.\n");

    // Decrypt the encrypted input (which should be the same as the encrypted output)
    performXOREncryption(keymap, encryptedOutput, decryptedOutput);
    printf("Decryption complete.\n");

    printf("Original message: %s\n", input);
    printf("Encrypted message: %s\n", encryptedOutput);
    printf("Decrypted message: %s\n", decryptedOutput);

    return 0;
}
