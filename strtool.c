#include <stdio.h>
#include "strlib.h"

int main(void){
    int selection;
    do{
        printf("= String & Array Toolkit =\n");
        printf("1. String length\n");
        printf("2. String copy (with truncation demo)\n");
        printf("3. String compare\n");
        printf("4. Reverse a string\n");
        printf("5. Count a character\n");
        printf("6. Convert to uppercase\n");
        printf("7. Array stats (min/max/avg)\n");
        printf("8. Find value in array\n");
        printf("9. Quit\n");
        printf("Enter choice (1-9): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 9 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
    }while (selection > 9 || selection < 1);
    char str[65];
    switch (selection){
        case 1:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            printf("Length: %d \n", str_length(*str));
            break;
        case 2:
            char dst[64];
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            str_copy(*dst, *str, 64);
            printf("String 1: %s \nString 2: %s \n", str, dst);
            break;
        case 3:
            char str2[64];
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            printf("Enter string 2: \n");
            fscanf(stdin, "%s", str2);
            printf("(%s, %s) -> %d \n", str, str2, str_compare(str, str2));
            break;
        case 4:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            str_reverse(str);
            printf("Reversed: %s \n", str);
            break;
        case 5:
        char target = 'a';
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            printf("Enter char: \n");
            fscanf(stdin, "%c", target);
            printf("%s has %c in it %d time(s).\n", str, target, str_count_char(str, target));
            break;
        case 6:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            str_to_upper(str);
            printf("%s \n", str);
            break;
        case 7:
            int count;
            int min;
            int max;
            int average;
            printf("Enter count then values: \n");
            fscanf(stdin, "%d", &count);
            for(int i = 0; i<count; i++){
                fscanf(stdin, "%d", &str[i]);
            }
            array_stats(str, count, min, max, average);
            printf("min=%d  max=%d  avg=%.2lf \n", min, max, average);

        case 8:
            int count;
            int target;
            printf("Enter count then values: \n");
            fscanf(stdin, "%d", &count);
            for(int i = 0; i<count; i++){
                fscanf(stdin, "%d", &str[i]);
            }
            printf("Enter target: \n");
            fscanf(stdin, "%d", &target);

            printf("Found at index %d", array_find(str, count, target));
        case 9:
            return 0;


    }


}