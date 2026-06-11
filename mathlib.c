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
    if(n < 2){
        return 0;
    }
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    if(a%b == 0){
       return b;
    }
    int remainder;        
    do{
        remainder = a%b;
        a = b; 
        if(remainder == 0){
            return b;
        }else{
            b = remainder;
        }
    }while(remainder != 0);
return 0;
}
double average(int arr[], int len) {
    if (len <= 0) return 0.0;
    double sum = 0.0;
    for(int i = 0; i < len; i++){
        sum = sum+arr[i];
    }
    return sum/len;

    return 0.0;
}

int count_digits(long long n) {

    if(n < 0){
        n = n*-1;
    }
    if(n == 0){
        return 1;
    }
    int count = 0;
    for(long long i = 1; i <= n + i; i = i*10){
        if(n - i <= 0)
        {
            return count;
        }
        count = count + 1;
    }

    return 0;
}