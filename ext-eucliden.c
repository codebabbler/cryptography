// Write a program to find the inverse of input integer in mod n

#include <stdio.h>

int modInverse(int a, int n)
{
    int t = 0, newt = 1;
    int r = n, newr = a;

    while (newr != 0)
    {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }

    if (r > 1)
    {
        return -1; 
    }

    if (t < 0)
    {
        t = t + n;
    }

    return t;
}

int main()
{
    int a, n;
    printf("Enter an integer a: ");
    scanf("%d", &a);
    printf("Enter modulus n: ");
    scanf("%d", &n);

    int inverse = modInverse(a, n);

    if (inverse == -1)
    {
        printf("Inverse of %d mod %d does not exist.\n", a, n);
    }
    else
    {
        printf("Inverse of %d mod %d is %d.\n", a, n, inverse);
    }

    return 0;
}

