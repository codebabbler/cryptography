#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(char *text, char *key, int length, int encrypt) {
    for (int i = 0; i < length; ++i) {
        int textNum = (text[i] - 'a'); // Convert plaintext character to 0-25
        int keyNum = (key[i] - 'a');   // Convert key character to 0-25
        
        if (encrypt) {
            textNum = (textNum + keyNum) % 26; // Encryption
        } else {
            textNum = (textNum - keyNum + 26) % 26; // Decryption, adding 26 to handle negative values
        }
        
        text[i] = textNum + 'a'; // Convert back to character
    }
}

void printBinary(char *text, int length) {
    for (int i = 0; i < length; ++i) {
        int value = text[i] - 'a';
        for (int j = 4; j >= 0; --j) { // 5 bits needed to represent 0-25
            printf("%d", (value >> j) & 1);
        }
        printf(" ");
    }
}

int main() {
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
    int length;
    
    printf("Enter the length of the text and key: ");
    scanf("%d", &length);

    char text[length + 1];
    char key[length + 1];

    printf("Enter the input to encrypt: ");
    scanf("%s", text);

    printf("Enter the key for encryption: ");
    scanf("%s", key);

    // Ensure the entered text and key lengths match the given length
    if (strlen(text) != length || strlen(key) != length) {
        printf("Error: The length of the input text and key must match the specified length.\n");
        return 1;
    }

    // Printing plaintext in binary
    printf("\nPlaintext:\n");
    printf("Binary: ");
    printBinary(text, length);
    printf("\n");

    // Printing key in binary
    printf("\nKey:\n");
    printf("Binary: ");
    printBinary(key, length);
    printf("\n");

    // Encryption
    encryptDecrypt(text, key, length, 1);

    // Printing encrypted text in binary
    printf("\nText after Encryption:\n");
    printf("Binary: ");
    printBinary(text, length);
    printf("\n");

    // Decryption
    encryptDecrypt(text, key, length, 0);

    // Printing decrypted text in binary
    printf("\nText after decryption:\n");
    printf("Binary: ");
    printBinary(text, length);
    printf("\n");

    return 0;
}