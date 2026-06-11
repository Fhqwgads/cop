#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printReport(char *name, int *scores, float average, char grade);
int validateName(char *name);
float calculateAvg(int *scores);
char calculateGrade(float average);
int main(){
    char name[64];
    int scores[5];
    float average;
    char grade;
     
    do{
        printf("Enter student name: ");
        fscanf(stdin, "%63s", name);
        if(!validateName(name)){
            printf("Try again.\n");
        }
    }while(!validateName(name));
    
    for(int i = 0; i < 5; i++){
        printf("Enter score %d: ", i + 1);
        fscanf(stdin, " %d", &scores[i]);
    }

    average = calculateAvg(scores);
    grade = calculateGrade(average);
    printReport(name, scores, average, grade);
    
}
int validateName(char *name){
    int length = strlen(name);
    for(int i = 0; i < length; i++)
    {

        if(isalpha(name[i])){
            if( i-1 == length){
                return 1;
            }
            continue;    
        }else{
            return 0;
        }
    }
    return 0;
}
float calculateAvg(int *scores){
    return ((float)(scores[0] + scores[1] + scores[2] + scores[3] + scores[4])/5);
}
char calculateGrade(float average){

    switch(((int)average/10)){
        case 10:
        case 9:
            return 'A';
            break;
        case 8:
            return 'B';
            break;
        case 7:
            return 'C';
            break;
        case 6:
            return 'D';
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            return 'F';
            break;
    }
    return 'A';
}
void printReport(char *name, int *scores, float average, char grade){
    printf("= Grade Report =\n");
    printf("Student: %s\n", name);
    printf("Scores: %d %d %d %d %d\n", scores[0], scores[1], scores[2], scores[3], scores[4]);
    printf("Average: %.2f\n", average);
    printf("Grade: %c\n", grade);
    if (average <= 69){
        printf("Status: Failing\n");
    }else{
        printf("Status: Passing\n");
    }
}