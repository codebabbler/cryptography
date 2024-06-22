// /**
//  * Write a program to simulate diffie-hellman key exchange algorithm
//  * 
//  * 
//  * 
//  */

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// // Function to compute (base^exp) % mod
// long long int power(long long int base, long long int exp, long long int mod) {
//     long long int result = 1;
//     base = base % mod;
//     while (exp > 0) {
//         if (exp % 2 == 1)
//             result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp = exp / 2;
//     }
//     return result;
// }

// int main() {
//     long long int P, G, x, a, y, b, ka, kb;

//     // Both the persons will be agreed upon the public keys P and G
//     printf("Enter the value of P (a prime number): ");
//     scanf("%lld", &P);
//     // printf("The value of P : %lld\n", P);

//     printf("Enter the value of G (a primitive root for P): ");
//     scanf("%lld", &G);
//     // printf("The value of G : %lld\n\n", G);

//     // Alice will choose the private key a
//     a = 4; // a is the chosen private key
//     printf("The private key a for Alice : %lld\n", a);
//     x = power(G, a, P); // gets the generated key
//     printf("The public key x for Alice : %lld\n", x);

//     // Bob will choose the private key b
//     b = 3; // b is the chosen private key
//     printf("The private key b for Bob : %lld\n", b);
//     y = power(G, b, P); // gets the generated key
//     printf("The public key y for Bob : %lld\n", y);

//     ka = power(y, a, P); // Secret key for Alice
//     kb = power(x, b, P); // Secret key for Bob

//     printf("Secret key for the Alice is : %lld\n", ka);
//     printf("Secret Key for the Bob is : %lld\n", kb);

//     return 0;
// }


// #include <stdio.h>
// #include <math.h>


// int power_mod(int base, int exp, int mod) 
// {
//     int result = 1;
//     base = base % mod;
//     while (exp > 0) {
//         if (exp % 2 == 1)
//             result = (result * base) % mod;
//         exp = exp >> 1;
//         base = (base * base) % mod;
//     }
//     return result;
// }


// int alice_public_key_generation(int g, int p, int Xa) {
//     return power_mod(g, Xa, p);
// }


// int bob_public_key_generation(int g, int p, int Xb) {
//     return power_mod(g, Xb, p);
// }


// int alice_key_generation(int Xa, int p, int Yb) {
//     return power_mod(Yb, Xa, p);
// }


// int bob_key_generation(int Xb, int p, int Ya) {
//     return power_mod(Ya, Xb, p);
// }

// int main() {
// 	int g,p,Xa,Xb;
// 	printf("Enter a primitve rooot and its corrosponding prime number g and p:\n");
// 	scanf("%d%d", &g , &p);
// 	printf("Enter the value of Xa:\n");
// 	scanf("%d",&Xa);
// 	printf("enter the value of Xb:\n");
// 	scanf("%d",&Xb);
//     int Ya = alice_public_key_generation(g, p, Xa);
//     int Yb = bob_public_key_generation(g, p, Xb);
//     int Ka = alice_key_generation(Xa, p, Yb);
//     int Kb = bob_key_generation(Xb, p, Ya);
//     printf("Public parameters (p, g): (%d, %d)\n", p, g);
//     printf("Alice's private key (Xa): %d\n", Xa);
//     printf("Bob's private key (Xb): %d\n", Xb);
//     printf("Alice's public key (Ya): %d\n", Ya);
//     printf("Bob's public key (Yb): %d\n", Yb);
//     printf("Alice's shared key (Ka): %d\n", Ka);
//     printf("Bob's shared  key (Kb): %d\n", Kb);
//     printf("Hence the shared key of Both alice and bob are same \n");
//     return 0;
// }

//simpler version

#include <stdio.h>
#include <math.h>

int main() {
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
    int p, g, Xa, Xb, Ya, Yb, Key_Alice, Key_Bob;
    
    printf("Enter the prime number:");
    scanf("%d", &p);
    
    printf("Enter the primitive root of p:");
    scanf("%d", &g);
    
    printf("Enter the value of Xa and Xb less than p:");
    scanf("%d%d", &Xa, &Xb);
    
    Ya = (int)pow(g, Xa) % p;
    printf("Ya:%d\n", Ya);
    
    Yb = (int)pow(g, Xb) % p;
    printf("Yb:%d\n", Yb);
    
    Key_Alice = (int)pow(Yb, Xa) % p;
    Key_Bob = (int)pow(Ya, Xb) % p;
    
    printf("Key of Alice:%d\n", Key_Alice);
    printf("Key of Bob:%d\n", Key_Bob);
    
    if (Key_Alice == Key_Bob) {
        printf("Since keys are the same. So, keys are exchanged.\n");
    } else {
        printf("Keys are not the same. So, keys are not exchanged.\n");
    }
    
    return 0;
}
