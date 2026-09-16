/*
Assignment:
hillcolumnar- Hill cipher and columnar transposition
Author: Nicholas Anthony Hernandez
Language: C, C++, or Rust (only)
To Compile:
gcc-Wall-Wextra-std=c11-O2 hillcolumnar.c-o hillcolumnar
g++-Wall-Wextra-std=c++17-O2 hillcolumnar.cpp-o hillcolumnar
rustc-O hillcolumnar.rs-o hillcolumnar
To Execute (on Eustis):
./hillcolumnar <mode> <direction> <hill_key_file> <column_key_file> <text_file>
where:
<mode>
<direction>
hill, columnar, or combine
encrypt or decrypt (hill and combine: encrypt only)
<hill_key_file> n, then the n x n Hill key matrix (hill and combine)
<column_key_file> the column key, a permutation of 1..k (columnar and combine)
<text_file>
the text to encrypt, or the ciphertext to decrypt
Notes:- Letters A-Z only (case-insensitive); every other character is discarded.- Letter values: A = 0, B = 1, ..., Z = 25.- The pad letter is X at both stages. Decryption keeps trailing X’s.- Every error goes to stderr with a non-zero exit status and nothing on stdout.- Tested on Eustis.
Class: CIS3360- Security in Computing
Instructor: Jie Lin, Ph.D.
Due Date: See Webcourses
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void hillEncrypt(char* keyFile, char* plainTextFile);
void columnarEncrypt(char* keyFile, char* plainTextFile);
void columnarDecrypt(char* keyFile, char* cypherTextFile);
void combineEncrypt(char* keyFile, char* plainTextFile);
void freeMemory(int** key);

static void fail(char* error);

int main(int argc, char *argv[])
{
    if(argc != 6)
    {
        fail("Wrong number of arguments.");
    }

    if(!strcmp(argv[1], "hill" ))
    {
        hillEncrypt(argv[3], argv[5]);
    }


}

static void fail(char * error)
{
    fprintf(stderr, "Error: %s\n", error);
    exit(1);
}

void hillEncrypt(char* keyFile, char* plainTextFile)
{    
    FILE* fptr = fopen(keyFile, "r");
    if (fptr == NULL)
    {
        fail("Key file unable to be opened.");        
    }
    if(fgetc(fptr) == EOF)
    {
        fail("Empty key file.");
    }
    int temp = 0;
    int n = 0;
    fscanf(fptr, "%d", &n);
    if(n < 1 || n > 9)
    {
        fail("n is outside bounds (1-9)");
    }
    int **key = malloc(n * sizeof(int *));
    if(key == NULL)
    {
        fail("Malloc failed.");
    }
    for (int i = 0; i < n; i++)
    {
        key[i] = malloc(n*sizeof(int));
        if(key[i] == NULL)
        {
            fail("Malloc failed.");
        }
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(fscanf(fptr, "%d", &temp) == 1)
            {
                key[i][j] = temp % 26;
            }
            else
            {
                fail("Early EOF or non integer value found.");
            }
        }
    }
    fclose(fptr);
    
    
    fptr = fopen(plainTextFile, "r");
    if (fptr == NULL)
    {
        fail("Plaintext file could not be opened.");
    }
    if(fgetc(fptr) == EOF)
    {
        fail("Empty plaintext file.");
    }
    int *plainText;
    char ch;
    int i = 0;
    while((ch = fgetc(fptr)) != EOF)
    {
        if(isalpha(ch))
        {
            toupper(ch);
            plainText[i] = ch;
            i++;
        }
    }
    
}