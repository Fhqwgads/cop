#include <stdio.h>
#include <stdlib.h>

int mainMenu();
int subMenu(int choice1);
void unitConverter(int, int);

int main(void){
    int choice1;
    int choice2 = 0;
    double convertedUnit;
    do{
        choice1 = mainMenu();
        if(choice1 == 5){
            printf("Goodbye!");
            return 0;
        }
        choice2 = subMenu(choice1);
    }while (choice1 != 5);
return 0;
}

int mainMenu(){
    int selection;
    do{
        printf("= Unit Conversion Station =\n");
        printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
        printf("2. Distance     (Miles <-> Kilometers)\n");
        printf("3. Weight       (Pounds <-> Kilograms)\n");
        printf("4. Speed        (MPH <-> KPH)\n");
        printf("5. Quit\n");
        printf("Enter choice (1-5): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 5 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
    }while (selection > 5 || selection < 1);
    return selection;
}
int subMenu(int choice1){
    int selection2;
    switch (choice1){
        case 1:
            do{
                printf("--- Temperature ---\n");
                printf("1. Celsius to Fahrenheit\n");
                printf("2. Fahrenheit to Celsius\n");
                printf("Enter direction (1-2):\n");
                fscanf(stdin, "%d", &selection2);
                if(selection2 != 1 && selection2 != 2){
                    printf("Invalid direction. Try again.\n");
                }
            }while(selection2 != 1 && selection2 != 2);
            
            return selection2;
        case 2:
            do{
                printf("--- Distance ---\n");
                printf("1. Miles to Kilometers\n");
                printf("2. Kilometers to Miles\n");
                printf("Enter direction (1-2):\n");
                fscanf(stdin, "%d", &selection2);
                if(selection2 != 1 && selection2 != 2){
                    printf("Invalid direction. Try again.\n");
                }
            }while(selection2 != 1 && selection2 != 2);
            
            return selection2;
        case 3:
            do{
                printf("--- Weight ---\n");
                printf("1. Pounds to Kilograms\n");
                printf("2. Kilograms to Pounds\n");
                printf("Enter direction (1-2):\n");
                fscanf(stdin, "%d", &selection2);
                if(selection2 != 1 && selection2 != 2){
                    printf("Invalid direction. Try again.\n");
                }
            }while(selection2 != 1 && selection2 != 2);
            
            return selection2;
        case 4:
            do{
                printf("--- Speed ---\n");
                printf("1. MPH to KPH\n");
                printf("2. KPH to MPH\n");
                printf("Enter direction (1-2):\n");
                fscanf(stdin, "%d", &selection2);
                if(selection2 != 1 && selection2 != 2){
                    printf("Invalid direction. Try again.\n");
                }
            }while(selection2 != 1 && selection2 != 2);
            
            return selection2;
            
    }
}
void unitConverter(int choice1, int choice2){
    double units;
    double convertedUnits;
    switch (choice1){
        case 1:
            if (choice2 == 1){
                printf("Enter degrees in Celsius: \n");
                fscanf(stdin, "%d", &units);
                convertedUnits = (units * (9.0/5.0) + 32);
                printf("")
            }else{
                printf("Enter degrees in Fahrenheit: \n");
                fscanf(stdin, "%d", &units);
                return ((units - 32) * (5.0/9.0));
            }
        case 2:
            if (choice2 == 1){
                printf("Enter amount of Miles: \n");
                fscanf(stdin, "%d", &units);
                return (units * 1.60934);
            }else{
                printf("Enter amount of Kilometers: \n");
                fscanf(stdin, "%d", &units);
                return (units / 1.60934);
            }
        case 3:
            if (choice2 == 1){
                printf("Enter amount of Pounds: \n");
                fscanf(stdin, "%d", &units);
                return (units * 0.453592);
            }else{
                printf("Enter amount of Kilograms: \n");
                fscanf(stdin, "%d", &units);
                return (units / 0.453592);
            }
        case 4:        
            if (choice2 == 1){
                printf("Enter MPH: \n");
                fscanf(stdin, "%d", &units);
                return (units * 1.60934);
            }else{
                printf("Enter KPH: \n");
                fscanf(stdin, "%d", &units);
                return (units / 1.60934);
            }
    }   
    
}

