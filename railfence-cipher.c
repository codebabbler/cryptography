#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt plaintext using Rail Fence Cipher
void encryptRailFence(char *plaintext, int rails, char *ciphertext) {
    int length = strlen(plaintext);
    char railsArray[rails][length];
    int j = 0; // Variable to iterate over plaintext

    // Initialize railsArray with spaces
    for (int i = 0; i < rails; i++) {
        for (int k = 0; k < length; k++) {
            railsArray[i][k] = ' ';
        }
    }

    // Fill railsArray with characters from plaintext
    int row = 0, dir = 0;
    while (j < length) {
        if (plaintext[j] == ' ') {
            j++; // Skip spaces
            continue;
        }

        railsArray[row][j] = plaintext[j];
        j++;

        if (row == 0) {
            dir = 0; // Down
        } else if (row == rails - 1) {
            dir = 1; // Up
        }

        if (dir == 0) {
            row++;
        } else {
            row--;
        }
    }




    // Fill ciphertext from railsArray
    int k = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < length; j++) {
            if (railsArray[i][j] != ' ') {
                ciphertext[k++] = railsArray[i][j];
            }
        }
    }
    ciphertext[k] = '\0'; // Null-terminate the ciphertext
}

int main() {
    char plaintext[100], ciphertext[100];
    int rails;

    // Input plaintext and number of rails
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    // Encrypt the plaintext
    encryptRailFence(plaintext, rails, ciphertext);

    // Print the encrypted ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
