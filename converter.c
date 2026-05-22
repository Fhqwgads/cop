#include <stdio.h>
#include <stdlib.h>

int mainMenu();
int subMenu(int choice1);
void unitConverter(int, int);

int main(void){
    int choice1;
    int choice2 = 0;
    do{
        choice1 = mainMenu();
        if(choice1 == 5){
            printf("Goodbye!");
            return 0;
        }
        choice2 = subMenu(choice1);
        unitConverter(choice1, choice2);
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
    int selection2 = 0;
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
            
            break;
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
            
            break;
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
            
            break;
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
            break;
    }
    return selection2;
}
void unitConverter(int choice1, int choice2){
    float units;
    float convertedUnits;
    switch (choice1){
        case 1:
            if (choice2 == 1){
                printf("Enter degrees in Celsius: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units * (9.0/5.0) + 32);
                printf("%.2f \xb0 Celsius is %.2f \xb0 Fahrenheit. \n", units, convertedUnits);
            }else{
                printf("Enter degrees in Fahrenheit: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = ((units - 32) * (5.0/9.0));
                printf("%.2f \xb0 Fahrenheit is %.2f \xb0 Celsius.\n", units, convertedUnits);
            }
            break;
        case 2:
            if (choice2 == 1){
                printf("Enter amount of Miles: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units * 1.60934);
                printf("%.2f Miles is %.2f Kilometers.\n", units, convertedUnits);
            }else{
                printf("Enter amount of Kilometers: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units / 1.60934);
                printf("%.2f Kilometers is %.2f Miles.\n", units, convertedUnits);
            }
            break;
        case 3:
            if (choice2 == 1){
                printf("Enter amount of Pounds: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units * 0.453592);
                printf("%.2f Pounds is %.2f Kilograms.\n", units, convertedUnits);
            }else{
                printf("Enter amount of Kilograms: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units / 0.453592);
                printf("%.2f Kilograms is %.2f Pounds.\n", units, convertedUnits);
            }
            break;
        case 4:        
            if (choice2 == 1){
                printf("Enter MPH: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units * 1.60934);
                printf("%.2f MPH is %.2f KPH.\n", units, convertedUnits);
            }else{
                printf("Enter KPH: \n");
                fscanf(stdin, "%f", &units);
                convertedUnits = (units / 1.60934);
                printf("%.2f KPH is %.2f MPH.\n", units, convertedUnits);
            }
            break;
    }   
    
}

