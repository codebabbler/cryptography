#include <stdio.h>
#include <math.h>

// Function to compute gcd using Euclidean algorithm
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Function to compute modular inverse using Extended Euclidean algorithm
int mod_inverse(int a, int m)
{
	int m0 = m, t, q;
	int x0 = 0, x1 = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient
		q = a / m;

		t = m;

		// m is remainder now, process same as Euclid's algo
		m = a % m, a = t;

		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}

	// Make x1 positive
	if (x1 < 0)
		x1 += m0;

	return x1;
}

// Function to compute the power of a number modulo n
int power_mod(int base, int exponent, int modulus)
{
	int result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		{
			result = (result * base) % modulus;
		}
		base = (base * base) % modulus;
		exponent /= 2;
	}
	return result;
}

// Code to demonstrate RSA algorithm
int main()
{
  printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
	// Two random prime numbers
	int p, q, n, euler_totient_function;
	int e, d;
	printf("Enter two random prime number:");
	scanf("%d%d", &p, &q);

	n = p * q;
	euler_totient_function = (p - 1) * (q - 1);

	// Prompt user to enter a value for e until it is valid
	do
	{
		printf("Enter a value for e (1 < e < %d) such that gcd(e, %d) = 1: ", euler_totient_function, euler_totient_function);
		scanf("%d", &e);

		if (e <= 1 || e >= euler_totient_function || gcd(e, euler_totient_function) != 1)
		{
			printf("Invalid input. Please try again.\n");
		}
	} while (e <= 1 || e >= euler_totient_function || gcd(e, euler_totient_function) != 1);

	d = mod_inverse(e, euler_totient_function);

	printf("The public key is (%d,%d) and the private key is (%d,%d)\n", e, n, d, n);

	// for encryption
	char message[100]; // Assuming the message will not exceed 100 characters

	printf("Enter a message to encrypt: ");
	scanf("%s", message); // Read the string input from the user

	// printf("Encrypted message: ");

	// for (int i = 0; message[i] != '\0'; ++i)
	// {
	// 	// Convert the character to a number in the range 0-25
	// 	int char_num = message[i] - 'a';
	// 	// Encrypt the number
	// 	int encrypted_char = power_mod(char_num, e, n);
	// 	printf("%d ", encrypted_char);
	// }
	// printf("\n");

	printf("Encrypted message: ");

	for (int i = 0; message[i] != '\0'; ++i)
	{
		// Encrypt each character using the public key
		int encrypted_char = power_mod(message[i] - 'a', e, n);
		// Convert to alphabet
		char encrypted_alphabet = (encrypted_char % 26) + 'a';
		printf("%c", encrypted_alphabet);
	}

	printf("\n");

	// printf("Decrypted message: ");
	// // for decrypt
	// for (int i = 0; message[i] != '\0'; ++i)
	// {
	// 	// Convert the character to a number in the range 0-25
	// 	int char_num = message[i] - 'a';
	// 	// Encrypt the number
	// 	int encrypted_char = power_mod(char_num, e, n);
	// 	int decrypted_char = power_mod(encrypted_char, d, n);
	// 	printf("%d ", decrypted_char);
	// }
	// printf("\n");

	printf("Decrypted message: ");
	for (int i = 0; message[i] != '\0'; ++i)
	{
		// Encrypt each character using the public key
		int encrypted_char = power_mod(message[i] - 'a', e, n);
		int decrypted_char = power_mod(encrypted_char, d, n);

		char decrypted_alphabet = (decrypted_char % 26) + 'a';
		printf("%c", decrypted_alphabet);
	}
	printf("\n");

	return 0;
}