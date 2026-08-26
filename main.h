#ifndef MAIN_C
#define MAIN_C

#define MAXSTRLEN 20 

typedef struct { 
    char name[MAXSTRLEN+1]; 
    char type[MAXSTRLEN+1]; 
    int level; 
    int hp; 
    int attack; 
    int defense; 
} Monster; 

#endif