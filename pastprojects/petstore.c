#include <stdio.h>
typedef enum{
    PET_BIRD,
    PET_REPTILE,
    PET_RODENT,
    PET_INSECTS
}Animals;

typedef struct{
    char name[64];
    Animals product;
    int age;
    char breed[64];
    int adoptable;
} animal;


int main(void){
    animal fox;
}