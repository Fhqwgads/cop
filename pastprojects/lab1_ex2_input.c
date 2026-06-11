#include <stdio.h>
#include <ctype.h>

int main(void){
    int age = 0;
    char initial = ' ';
    float id = 0.0;
    do{
        printf("Enter your age (1-120): ");
        fscanf(stdin, "%d", &age);
        if(age < 1 || age > 120){
            printf("Invalid input. Try again.\n");
        }
    }while (age < 1 || age > 120);
    do{
        printf("\nEnter your initial (A-Z): ");
        fscanf(stdin, " %c", &initial);
        if(!isalpha(initial)){
            printf("Invalid input. Try again.\n");
        }
    }while (!isalpha(initial));
    do{
        printf("\nEnter a positive decimal: ");
        fscanf(stdin, " %f", &id);
        if(id <= 0.0){
            printf("Invalid input. Try again.\n");
        }
    }while (id <= 0.0);
    printf("Hello, %c. You are %d years old. Your number: %.2f", initial, age, id);

}