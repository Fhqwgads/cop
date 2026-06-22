#include <stdio.h>
#include "roster.h"

int main(void){
    int selection = 0;
    char firstName[64];
    char lastName[64];
    int id;
    double gpa;

    Roster r = {
        .count = 0
    };

    do{
        printf("= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");
        printf("Enter choice (1-8): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 8 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
            switch (selection){
        case 1:
            printf("First name: ");
            fscanf(stdin, "%s", firstName);
            printf("Last name:  ");
            fscanf(stdin, "%s", lastName);
            printf("Student ID: ");
            fscanf(stdin, "%d", &id);
            printf("GPA:        ");
            fscanf(stdin, "%lf", &gpa);
            int added = roster_add(&r,create_student(firstName, lastName, id, gpa));
            if(added == 0){
                printf("\nRoster Full, Student Not Added.\n");
            }else if(added == -1){
                printf("\nID Already Exists, Student Not Added.\n");
            }
            break;
        case 2:
            printf("Enter student ID: ");
            fscanf(stdin, "%d", &id);
            if(roster_remove(&r, id)){
                printf("\nStudent removed.\n");
            }else{
                printf("\nStudent not found.\n");
            }
            break;
        case 3:
            printf("Enter student ID: ");
            fscanf(stdin, "%d", &id);
            Student *tempID = roster_find_by_id(&r, id);
            print_student(tempID);
            break;
        case 4:
            printf("Enter student last name: ");
            fscanf(stdin, "%s", lastName);
            Student *tempName = roster_find_by_name(&r, lastName);
            print_student(tempName);
            break;
        case 5:
            roster_sort_by_name(&r);
            break;
        case 6:
            roster_sort_by_gpa(&r);
            break;
        case 7:
            print_roster(&r);
            break;
        case 8:
            return 0;
            break;

    }

    }while (selection > 9 || selection < 1 || selection != 8);
    
}