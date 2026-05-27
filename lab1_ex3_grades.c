#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printReport();
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
        printf("Enter grade %d", i + 1);
        scores[i] = fscanf(stdin, " %d", scores[i]);
    }
    float average = calculateAvg(scores);
    char grade = calculateGrade(average);
   
    
}
int validateName(char *name){
    int length = strlen(name);
    for(int i = 0; i < length; i++)
    {
        if(isalpha(name[i])){
            continue;
        }else{
            return 0;
        }
    }

}
float calculateAvg(int *scores){
    return ((scores[0] + scores[1] + scores[2] + scores[3] + scores[4])/5);
}
char calculateGrade(float average){
    switch:
    case
}