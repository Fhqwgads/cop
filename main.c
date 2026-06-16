#include <stdio.h>
#include "roster.h"

int main(void){
    int selection = 0;
    do{
        printf("= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");
        printf("Enter choice (1-8): \n");
        fscanf(stdin, "%d", &selection);
        if(selection > 8 || selection < 1){
            printf("Invalid choice. Try again.\n");
        }
            switch (selection){
        case 1:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            printf("Length: %d \n", str_length(str));
            break;
        case 2:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            str_copy(dst, str, 64);
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
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            printf("Enter char: \n");
            fscanf(stdin, " %c", &target5);
            printf("%s has %c in it %d time(s).\n", str, target5, str_count_char(str, target5));
            break;
        case 6:
            printf("Enter string: \n");
            fscanf(stdin, "%s", str);
            str_to_upper(str);
            printf("%s \n", str);
            break;
        case 7:
            printf("Enter count then values: \n");
            fscanf(stdin, "%d", &count);
            for(int i = 0; i<count; i++){
                fscanf(stdin, "%d", &intstr[i]);
            }
            array_stats(intstr, count, &min, &max, &average);
            printf("min=%d  max=%d  avg=%.2lf \n", min, max, average);
            break;
        case 8:
            return 0;
            break;

    }

    }while (selection > 9 || selection < 1 || selection != 9);
    
}