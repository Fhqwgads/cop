#include "mathlib.h"
#include <math.h>

int clamp(int value, int lo, int hi) {
    if( value < hi && value > lo){
        return value;
    }
    else if( value >= hi ){
        return hi;
    }else if ( value <= lo){
        return lo;
    }
    return 0;
}

double power(double base, int exp) {
    for(int i = 1; i < exp; i++){
        base = base * base;
    }
    return base;
}

int is_prime(int n) {
    if(n < 2){
        return 0;
    }
    double root = sqrt(n);
    for(int i = 2; i <= root; i++){
        if((int)root%i != 0){
            continue;
        }else{
            return 1;
        }
    }
    return 0;
}

int gcd(int a, int b) {
    if(a > b){
        if(a%b == 0){
            return b;
        }
        int remainder = a%b;
        int quotient = (a - remainder)/b;
        while(remainder != 0){
            if(remainder == 0){
            return quotient;
            }
        }
        

    }
    return 0;
}

double average(int arr[], int len) {
    /* TODO */
    return 0.0;
}

int count_digits(long long n) {
    /* TODO */
    return 0;
}