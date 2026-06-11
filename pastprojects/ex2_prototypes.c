#include <stdio.h>


int clamp(int val, int lo, int hi);
int absolute_value(int x);
double celsius_to_fahrenheit(double c);
int is_even(int n);

int main(void){

}

int clamp(int val, int lo, int hi){
    if( val < hi && val > lo){
        return val;
    }
    else if( val >= hi ){
        return hi;
    }else if ( val <= lo){
        return lo;
    }
    return val;
}

int absolute_value(int x){
    if (x < 0){
        return (x * -1);
    }
    return x;
}

double celsius_to_fahrenheit(double c){
    return c * 9.0/5.0 + 32;
}

int is_even(int n){
    if (n % 2 == 0){
        return 1;
    }
    return 0;
}