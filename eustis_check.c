/*
Assignment:
eustis_check - HW1 Eustis environment check
Author: Nicholas Anthony Hernandez
Language: C, C++, or Rust (only)
To Compile:
gcc -Wall -Wextra -std=c11 -O2 eustis_check.c -o eustis_check
g++ -Wall -Wextra -std=c++17 -O2 eustis_check.cpp -o eustis_check
rustc -O eustis_check.rs -o eustis_check
To Execute (on Eustis):
./eustis_check <input_file> <key>
where:
<input_file> is the path to the input text file
<key> is a key string
Notes:
- Checks argc before reading argv[1] or argv[2].
- Echoes argc/argv, prints the key, prints the file with line numbers,
and reports line and letter counts.
- Tested on Eustis.
Class: CIS3360 - Security in Computing
Instructor: Jie Lin, Ph.D.
Due Date: See Webcourses
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    if(argc != 3) //argument validation
    {    
        printf("Usage: ./eustis_check <input_file> <key>\n");
        printf("Error: expected exactly 2 arguments, received %d.\n", argc - 1);
        return 1; 
    }
    printf("argc = %d\n", argc); //prints the arguments
    printf("argv[0] = %s\n", argv[0]);
    printf("argv[1] = %s\n", argv[1]);
    printf("argv[2] = %s\n\n", argv[2]);
    printf("Key: %s\n\n", argv[2]);

    FILE *fptr; //creates a FILE pointer
    char line[256]; //temperary place to store the read lines from the file
    int strLength = strlen(line); //stores how long each line is to strip the newline character
    int totalChar = 0;//running tally to store number of letters
    int totalLines = 0;//running tally to store number of lines

    fptr = fopen(argv[1], "r");//opens the txt file to read
    if(fptr == NULL)//checks if fopen was successful
    {
        printf("Error: cannot open file '%s'\n", argv[1]);
        return 1;
    }
    printf("File contents: \n");
    while (fgets(line, sizeof(line), fptr) != NULL)//runs through each line until it hits EOF
    {
        if(strLength > 0 && line[strLength - 1] == '\n')//strips newlines
        {
            line[strLength - 1] = '\0';
        }
        printf("%d: %s",totalLines + 1, line);
        totalLines++;
        for(int i = 0; line[i] != '\0'; i++)//running tally of alpha characters
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