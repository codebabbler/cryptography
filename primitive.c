// Write a program to test if the number is privitive root or not
/**
 * Take a prime number p and a potential primitive root g as input.
 * Calculate the powers of g modulo p from 1 to p-1.
 * Check if all the calculated values are unique and cover all the numbers from 1 to p-1.
 * If all the values are unique and cover the range, then g is a primitive root modulo p.
 * If there are duplicates or missing values, then g is not a primitive root modulo p.
 */


// bool isPrimitiveRoot(int p, int g) {
//     int g_powers[p - 1];
//     bool used[p - 1];

//     for (int i = 0; i < p - 1; i++) {
//         used[i] = false;
//     }

//     for (int i = 0; i < p - 1; i++) {
//         g_powers[i] = (int)power(g, i + 1) % p;
//         printf("g^%d mod %d = %d \n", i + 1, p, g_powers[i]);
//         if (used[g_powers[i] - 1]) {
//             return false;
//         }
//         used[g_powers[i] - 1] = true;
//     }
//     return true;
// }


#include <stdio.h>
#include <stdbool.h>


double power(int base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


bool isPrimitiveRoot(int p, int g) {
    int g_powers[p - 1];
    bool used[p - 1];

    for (int i = 0; i < p - 1; i++) {
        used[i] = false;
    }

    for (int i = 0; i < p - 1; i++) {
        g_powers[i] = (int)power(g, i + 1) % p;
        printf("g^%d mod %d = %d \n", i + 1, p, g_powers[i]);
        if (used[g_powers[i] - 1]) {
            return false;
        }
        used[g_powers[i] - 1] = true;
    }
    return true;
}

int main() {
    int p, g;
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");

    printf("Enter a prime number (p): ");
    scanf("%d", &p);

    printf("Enter a potential primitive root (g): ");
    scanf("%d", &g);

    if (isPrimitiveRoot(p, g)) {
        printf("Since all roots are distincts, %d is a primitive root modulo %d\n", g, p);
    } else {
        printf("Since there is duplication, %d is not a primitive root modulo %d\n", g, p);
    }

    return 0;
}
