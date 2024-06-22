// #include <stdio.h>

// int extendedEuclidean(int a, int b, int *x, int *y) {
//     // Base case: if b is 0, then gcd is a
//     if (b == 0) {
//         *x = 1;
//         *y = 0;
//         return a;
//     }

//     int x1, y1; // To store results of recursive call
//     int gcd = extendedEuclidean(b, a % b, &x1, &y1);

//     // Update x and y using results of recursive call
//     *x = y1;
//     *y = x1 - (a / b) * y1;

//     return gcd;
// }
// int swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int a, b;
//     int s, t;

//     // Input the numbers
//     // printf("Enter two integers a and b such that a is greater than b");
//     // scanf("%d %d", &a, &b);
//     printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
//     int num1, num2;

//     printf("Enter two positive integers: ");
//     scanf("%d %d", &num1, &num2);
//     if (num1 < num2)
//     {
//         swap(&num1, &num2);
//     }

//     // Calculate the GCD and the coefficients x and y
//     int gcd = extendedEuclidean(a, b, &s, &t);

//     // Output the results
//     printf("GCD of %d and %d is %d\n", a, b, gcd);
//     printf("Coefficients s and t are %d and %d\n", s, t);

//     return 0;
// }

#include <stdio.h>

int extendedEuclidean(int a, int b, int *x, int *y) {
    // Base case: if b is 0, then gcd is a
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1; // To store results of recursive call
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
  printf("~~~~~~~~~~~~Miraj Aryal~~~~~~~~~~~~\n\n\n");
    int a, b;
    int s, t;

    // Input the numbers
    printf("Enter the number for finding the inverse: ");
    scanf("%d", &a);
    
    printf("Enter the modulo value: ");
    scanf("%d", &b);

    // Calculate the GCD and the coefficients s and t
    int gcd;
    int inverse;
    if(a>b){
        gcd = extendedEuclidean(a, b, &s, &t);
        if(s<0){
        s+=b;
        inverse=s%b;
        }
    }else{
        gcd = extendedEuclidean(b, a, &s, &t);
        if(t<0){
        t+=b;
        inverse=t%b;
        }
     
    }
   

    // Output the results
    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients:\ns = %d\nt = %d\n", s, t);
    
    printf("Inverse of %d is %d with modulo %d\n",a,inverse,b);

    return 0;
}