#include "roster.h"

Student  create_student(const char *first, const char *last,
                        int id, double gpa){
    Student s = {first, last, id, gpa};
    return s;
}
int      roster_add(Roster *r, Student s){

}
int      roster_remove(Roster *r, int student_id){

}
Student *roster_find_by_id(Roster *r, int student_id){

}
Student *roster_find_by_name(Roster *r, const char *last_name){

}
void     roster_sort_by_name(Roster *r){

}
void     roster_sort_by_gpa(Roster *r){

}
void     print_student(const Student *s){

}
void     print_roster(const Roster *r){

}
const char *grade_to_string(Grade g){

}
double   roster_average_gpa(const Roster *r){

}