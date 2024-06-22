// Write a program to find the gcd of two input integers using Euclid's algorithm
#include <stdio.h>

int euclidean(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    printf("%d = %dx%d + %d\n", a, a / b, b, a % b);
    return euclidean(b, a % b);
}
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    if (num1 < num2)
    {
        swap(&num1, &num2);
    }
    int gcd = euclidean(num1, num2);
    // printf("\ngcd(%d, %d): \n", num1, num2);
    printf("\nGCD of %d and %d is %d\n", num1, num2, gcd);
    if (gcd == 1)
    {
        printf("The numbers are co-prime.\n");
    }

    return 0;
}
