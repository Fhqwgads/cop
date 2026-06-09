#include "mathlib.h"

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
    
    return 0;
}

int gcd(int a, int b) {
    /* TODO */
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