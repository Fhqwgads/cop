#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "roster.h"

Student  create_student(const char *first, const char *last,
                        int id, double gpa){
    Grade standing;
    if(gpa > 4.0 || gpa < 0.0){
        standing = GRADE_INVALID;
    }if(gpa <= 4.0 && gpa >= 3.5){
        standing = GRADE_A;
    }else if(gpa <= 3.49 && gpa >= 3.0){
        standing = GRADE_B;
    }else if(gpa <= 2.99 && gpa >= 2.0){
        standing = GRADE_C;
    }else if(gpa <= 1.99 && gpa >= 1.0){ 
        standing = GRADE_D;
    }else if(gpa < 1.0){
        standing = GRADE_F;
    }
    
    Student s;
    strcpy(s.first_name, first);
    strcpy(s.last_name, last);
    s.student_id = id;
    s.gpa = gpa;
    s.standing = standing;
    return s;
}
int      roster_add(Roster *r, Student s){
    if(r->count >= MAX_STUDENTS){
        return 0;
    }
    for(int i = 0; i < r->count; i++){
        if(r->students[i].student_id == s.student_id){
            return -1;
        }
    }
    r->students[r->count] = s;
    r->count++;
    return 1;
}
int      roster_remove(Roster *r, int student_id){
    int flag = 0;
    for(int i = 0; i < r->count; i++){
        if(r->students[i].student_id == student_id){
            flag = 1;
            for(i = i; i < r->count - 1; i++){
                r->students[i] = r->students[i+1];
            }
        }
    }
    r->count--;
    return flag;
}
Student *roster_find_by_id(Roster *r, int student_id){
for(int i = 0; i < r->count; i++){
    if(r->students[i].student_id != student_id){
        continue;
    }else{
        return &r->students[i];
    }
}
return NULL;
}

Student *roster_find_by_name(Roster *r, const char *last_name){
for(int i = 0; i < r->count; i++){
     if(strcmp(r->students[i].last_name, last_name)){
        continue;
    }else{
        return &r->students[i];
    }
}
return NULL;
}
void     roster_sort_by_name(Roster *r){
    Student temp;
    for(int i = 0; i < r->count - 1; i++){
        for(int j = 0; j < r->count - 1 - i; j++){
            if (strcmp(r->students[j].last_name, r->students[j+1].last_name) > 0){
                temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            }else if(strcmp(r->students[j].first_name, r->students[j+1].first_name) > 0){
                  temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            }
        }
    }
    

}
void     roster_sort_by_gpa(Roster *r){
Student temp;
    for(int i = 0; i < r->count - 1; i++){
        for(int j = 0; j < r->count - 1 - i; j++){
            if (r->students[j].gpa < r->students[j+1].gpa){
                temp = r->students[j];
                r->students[j] = r->students[j+1];
                r->students[j+1] = temp;
            }
        }
    }
}
void     print_student(const Student *s){
    if(s == NULL){
        printf("No Student to Print.\n");
    }else{
    printf("[%d] %s, %s          GPA: %.2lf  Standing: %s\n", s->student_id, s->last_name, s->first_name, s->gpa, grade_to_string(s->standing));
    }
}
void     print_roster(const Roster *r){
printf("╔══════════════════════════════════════════════════╗\n");
printf("║  Student Roster (%d students)                    ║\n", r->count);
printf("╠══════════════════════════════════════════════════╣\n");
    for(int i = 0; i < r->count; i++){
        print_student(&r->students[i]);
    }
printf("╠══════════════════════════════════════════════════╣\n");
printf("║  Class average GPA: %.2lf                        ║\n", roster_average_gpa(r));
printf("╚══════════════════════════════════════════════════╝\n");
}

const char *grade_to_string(Grade g){
    switch (g){
        case 0:
            return "A";
            break;
        case 1:
            return "B";
            break;
        case 2:
            return "C";
            break;
        case 3:
            return "D";
            break;
        case 4:
            return "F";
            break;
        case 5:
            return "Incomplete";
            break;
    }
    return "NULL";
}
double   roster_average_gpa(const Roster *r){
    double sum = 0.0;
for(int i = 0; i < r->count; i++){
    sum += r->students[i].gpa;
}
return sum/r->count;
}