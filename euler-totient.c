/**
 * Write a program to calculate the euler totient function of input integer
 */
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int euler_totient(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (gcd(num, i) == 1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    int totient = euler_totient(num);
    printf("The Euler totient of %d is %d\n", num, totient);

    return 0;
}