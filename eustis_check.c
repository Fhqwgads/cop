#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 3)
    {    
        printf("Usage: ./eustis_check <input_file> <key>\n");
        printf("Error: expected exactly 2 arguments, received %d.\n", argc - 1);
        return 1; 
    }
    printf("argc = %d\n", argc);
    printf("argv[0] = %63s\n", argv[0]);
    printf("argv[1] = %63s\n", argv[1]);
    printf("argv[2] = %63s\n\n", argv[2]);
    printf("Key: %63s\n\n", argv[2]);

    FILE *fptr;
    char line[256];

    fptr = fopen(argv[1], "r");
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        printf("%s\")
    }