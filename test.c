#include <stdio.h>

int main(void) {
    int age;
    char initial;
    
    printf("Age? ");
    fscanf(stdin, "%d", &age);
    
    printf("Initial? ");       // trailing space eats whitespace/newline
    
    fscanf(stdin, " %c",  &initial);   // now reads the real character
    printf("Age: %d, Initial: %c\n", age, initial);
    return 0;
}