#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if(argc != 3)
    {    
        printf("Usage: ./eustis_check <input_file> <key>\n");
        printf("Error: expected exactly 2 arguments, received %d.\n", argc - 1);
        return 1; 
    }
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]);
    printf("argv[1] = %s\n", argv[1]);
    printf("argv[2] = %s\n\n", argv[2]);
    printf("Key: %s\n\n", argv[2]);

    FILE *fptr;
    char line[256];
    int strLength = strlen(line);
    int totalChar = 0;
    int totalLines = 0;

    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }
    printf("File contents: \n");
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        if(strLength > 0 && line[strLength - 1] == '\n')
        {
            line[strLength - 1] = '\0';
        }
        printf("%d: %s",totalLines + 1, line);
        totalLines++;
        for(int i = 0; line[i] != '\0'; i++)
        {
            if(isalpha(line[i]))
            {
                totalChar++;
            }
        }
        
    }   
    printf("\n\nLines: %d", totalLines);
    printf("\nLetters: %d\n", totalChar);
    return 0;
}