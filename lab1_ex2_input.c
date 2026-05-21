#include <stdio.h>

int main(void){
    int age;
    double id = 0.0;
    do{
        printf("Enter your age (1-120): ");
        fscanf(stdin, "%d ", &age);

    }while (age > 0 && age < 121);

}