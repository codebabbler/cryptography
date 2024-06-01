#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int map[26] = {0};
    int i, j, k, len = strlen(key);

    for (i = 0, k = 0; i < len; i++) {
        if (key[i] != 'J' && map[key[i] - 'A'] == 0) {
            keyTable[k / SIZE][k % SIZE] = key[i];
            map[key[i] - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i != 'J' - 'A' && map[i] == 0) {
            keyTable[k / SIZE][k % SIZE] = 'A' + i;
            k++;
        }
    }
}

void formatMessage(char message[], char formatted[]) {
    int i, j = 0;
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            formatted[j++] = toupper(message[i]);
            if (j > 1 && formatted[j-1] == formatted[j-2]) {
                formatted[j-1] = 'X';
                formatted[j++] = toupper(message[i]);
            }
        }
    }
    if (j % 2 != 0) {
        formatted[j++] = 'X';
    }
    formatted[j] = '\0';
}

void findPosition(char keyTable[SIZE][SIZE], char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void replaceJwithI(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'J') {
            str[i] = 'I';
        }
    }
}


void encrypt(char keyTable[SIZE][SIZE], char plaintext[], char ciphertext[]) {
    int i, a, b, c, d;
    for (i = 0; plaintext[i] != '\0'; i += 2) {
        findPosition(keyTable, plaintext[i], &a, &b);
        findPosition(keyTable, plaintext[i + 1], &c, &d);

        if (a == c) {
            ciphertext[i] = keyTable[a][(b + 1) % SIZE];
            ciphertext[i + 1] = keyTable[c][(d + 1) % SIZE];
        } else if (b == d) {
            ciphertext[i] = keyTable[(a + 1) % SIZE][b];
            ciphertext[i + 1] = keyTable[(c + 1) % SIZE][d];
        } else {
            ciphertext[i] = keyTable[a][d];
            ciphertext[i + 1] = keyTable[c][b];
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char keyTable[SIZE][SIZE], char ciphertext[], char plaintext[]) {
    int i, a, b, c, d;
    int len = strlen(ciphertext);
    int index = 0; // Index for plaintext

    for (i = 0; i < len; i += 2) {
        findPosition(keyTable, ciphertext[i], &a, &b);
        findPosition(keyTable, ciphertext[i + 1], &c, &d);

        if (a == c) {
            plaintext[index++] = keyTable[a][(b + SIZE - 1) % SIZE];
            plaintext[index++] = keyTable[c][(d + SIZE - 1) % SIZE];
        } else if (b == d) {
            plaintext[index++] = keyTable[(a + SIZE - 1) % SIZE][b];
            plaintext[index++] = keyTable[(c + SIZE - 1) % SIZE][d];
        } else {
            plaintext[index++] = keyTable[a][d];
            plaintext[index++] = keyTable[c][b];
        }
    }
    plaintext[index] = '\0';

    // Remove 'X' characters from plaintext
    int j = 0;
    for (i = 0; i < index; i++) {
        if (plaintext[i] != 'X') {
            plaintext[j++] = plaintext[i];
        }
    }
    plaintext[j] = '\0';
}

void toUpper(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void removeSpaces(char str[]) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}


void displayKeyTable(char keyTable[SIZE][SIZE]) {
    int i, j;
    printf("Key Table:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }
}
int main() {
    char key[100];
    char message[100];
    char formattedMessage[100];
    char ciphertext[100];
    char decryptedMessage[100];
    char keyTable[SIZE][SIZE];

    printf("***********Playfair Cypher***********\n");
printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character

    toUpper(key);
    removeSpaces(key);
    replaceJwithI(key);
    prepareKeyTable(key, keyTable);

    // Display the key table
    displayKeyTable(keyTable);

    formatMessage(message, formattedMessage);
    toUpper(formattedMessage);
    replaceJwithI(formattedMessage);

    encrypt(keyTable, formattedMessage, ciphertext);
    printf(" Ciphertext: %s\n", ciphertext);

    decrypt(keyTable, ciphertext, decryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}
