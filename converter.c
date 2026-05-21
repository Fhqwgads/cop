#include <stdio.h>

int choice1;
int choice2;

void mainMenu();
void subMenu(int choice1);
double unitConverter(double unit, int choice1, int choice2);

int main(void){

    
}

void mainMenu(){
    printf("= Unit Conversion Station =\n");
    printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
    printf("2. Distance     (Miles <-> Kilometers)\n");
    printf("3. Weight       (Pounds <-> Kilograms)\n");
    printf("4. Speed        (MPH <-> KPH)\n");
    printf("5. Quit\n");
    printf("Enter choice (1-5): \n");
}
void subMenu(int choice1){
    switch (choice1){
        case '1':
            printf("blahblah\n");
            break;
        case '2':
            printf("blahblah\n");
            break;
        case '3':
            printf("blahblah\n");
            break;
        case '4':
            printf("blahblah\n");
            break;
        case '5':
            printf("blahblah\n");
            break;
    }

}
