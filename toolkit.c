#include <stdio.h>

int main(void){
    int selection;
    do{
        printf("= Math Toolkit =\n");
        printf("1. Clamp a value\n");
        printf("2. Compute a power\n");
        printf("3. Prime check\n");
        printf("4. GCD\n");
        printf("5. Array average\n");
        printf("6. Count digits\n");
        printf("7. Quit\n");
        printf("Enter choice (1-7): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 7 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
    }while (selection > 7 || selection < 1);
    return selection;
}