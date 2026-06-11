#include <stdio.h>
#include "strlib.h"

int main(void){
    int selection;
    do{
        printf("= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Find value in array\n");
        printf("9. Quit\n");
        printf("Enter choice (1-9): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 7 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
    }while (selection > 7 || selection < 1);
    
    switch (selection){
        case 1:
            int val;
            int lo;
            int hi;
            printf("Enter value, lo, hi: ");
            fscanf(stdin, "%d", &val);
            fscanf(stdin, "%d", &lo);
            fscanf(stdin, "%d", &hi);
            printf("\nclamp(%d, %d, %d) = %d", val, lo, hi, clamp(val, lo, hi));
            break;
        case 2:
            double base;
            int exponent;
            printf("Enter base and exponent: ");
            fscanf(stdin, "%lf", &base);
            fscanf(stdin, "%d", &exponent);
            printf("power(%lf, %d) = %.2lf", base, exponent, power(base, exponent));
            break;
        case 3:
            int checkPrime;
            printf("Enter n: ");
            fscanf(stdin, "%d", &checkPrime);
            if (is_prime(checkPrime)){
                printf("%d is prime.", checkPrime);
            }else{
                printf("%d is not prime.", checkPrime);
            }
            break;
        case 4:
            int a;
            int b;
            printf("Enter a and b: ");
            fscanf(stdin, "%d", &a);
            fscanf(stdin, "%d", &b);
            printf("gcd(%d, %d) = %d", a, b, gcd(a, b));
            break;
        case 5:
            int count;
            int values[10];
            printf("Enter count then values: ");
            fscanf(stdin, "%d", &count);
            for(int i = 0; i<count; i++){
                fscanf(stdin, "%d", &values[i]);
            }
            printf("average = %.2lf ", average(values, count));
            break;
        case 6:
            long long digitNumber;
            printf("Enter integer: ");
            fscanf(stdin, "%lld", &digitNumber);
            printf("%lld has %d digits.", digitNumber, count_digits(digitNumber));
            break;
        case 7:
            return 0;


    }


}