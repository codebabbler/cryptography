// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function to encrypt plaintext using Rail Fence Cipher
// void encryptRailFence(char *plaintext, int rails, char *ciphertext) {
//     int length = strlen(plaintext);
//     char railsArray[rails][length];
//     int j = 0; // Variable to iterate over plaintext

//     // Initialize railsArray with spaces
//     for (int i = 0; i < rails; i++) {
//         for (int k = 0; k < length; k++) {
//             railsArray[i][k] = ' ';
//         }
//     }

//     // Fill railsArray with characters from plaintext
//     int row = 0, dir = 0;
//     while (j < length) {
//         if (plaintext[j] == ' ') {
//             j++; // Skip spaces
//             continue;
//         }

//         railsArray[row][j] = plaintext[j];
//         j++;

//         if (row == 0) {
//             dir = 0; // Down
//         } else if (row == rails - 1) {
//             dir = 1; // Up
//         }

//         if (dir == 0) {
//             row++;
//         } else {
//             row--;
//         }
//     }




//     // Fill ciphertext from railsArray
//     int k = 0;
//     for (int i = 0; i < rails; i++) {
//         for (int j = 0; j < length; j++) {
//             if (railsArray[i][j] != ' ') {
//                 ciphertext[k++] = railsArray[i][j];
//             }
//         }
//     }
//     ciphertext[k] = '\0'; // Null-terminate the ciphertext
// }

// int main() {
//     char plaintext[100], ciphertext[100];
//     int rails;

//     // Input plaintext and number of rails
//     printf("Enter the plaintext: ");
//     fgets(plaintext, sizeof(plaintext), stdin);
//     plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

//     printf("Enter the number of rails: ");
//     scanf("%d", &rails);

//     // Encrypt the plaintext
//     encryptRailFence(plaintext, rails, ciphertext);

//     // Print the encrypted ciphertext
//     printf("Ciphertext: %s\n", ciphertext);

//     return 0;
// }


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void encryptRailFence(char *text, int key, char *result) {
    int len = strlen(text);
    char rail[key][len];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == key - 1)     
            dir_down = !dir_down;
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
        // find the next row using direction flag
        dir_down ? row++ : row--;
    }
    int k = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                result[k++] = rail[i][j];
    result[k] = '\0';
}
void decryptRailFence(char *cipher, int key, char *result) {
    int len = strlen(cipher);
    char rail[key][len];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
    // to find the direction
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < len; i++) {    // mark the places with '*'
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;
        rail[row][col++] = '*';
        dir_down ? row++ : row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];
    // now read the matrix in zig-zag manner to construct the resultant text
    row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        if (rail[row][col] != '*')
            result[i] = rail[row][col++];

        dir_down ? row++ : row--;
    }
    result[len] = '\0';
}

int main() {
    char text[100], result[100];
    int key;
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");

    printf("\nEnter the plaintext : ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Enter the number of rails: ");
    scanf("%d", &key);

    encryptRailFence(text, key, result);
    printf("Encrypted Message : %s\n", result);

    char encrypted_text[100];
    strcpy(encrypted_text, result); // Save the encrypted text for decryption

    decryptRailFence(encrypted_text, key, result);
    printf("Decrypted Message : %s\n", result);

    return 0;
}