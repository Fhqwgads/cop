#include <stdio.h>

int main(){
    int age = 1;
    char initial = "n";
    double id = 0.0;
    do{
        fscanf(stdin, "Enter your age (1-120): %d ", &age);
    }while (age > 0 && age < 121);
    
}