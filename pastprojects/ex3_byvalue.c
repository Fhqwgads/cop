#include <stdio.h>

void triple(int x);
int triple_return(int x);
void add_ten(int a, int b);

int main(void){
    int x = 4;
    int a = 3;
    int b = 6;
    triple(x);
    printf("%d \n", x);
    printf("%d \n", triple_return(x));
    add_ten(a, b);
    printf("%d, %d \n", a, b);
}

void triple(int x){
    printf("%d \n", x*3);
}

int triple_return(int x){
    return x*3;
}
void add_ten(int a, int b){
    printf("%d, %d \n", a + 10, b + 10);
}