#include <stdio.h>

void main(){

    printf("7/2: my prediction 3 %d \n", 7/2);
    printf("7.0/2: my prediction 3 %.6f \n", 7.0/2);
    printf("7/2.0: my prediction 3 %.6f \n", 7/2.0);
    printf("(double)7/2: my prediction 3 %.6f \n", (double)7/2);
    printf("(double)(7/2): my prediction 3.5 %.6f \n", (double)(7/2));
    printf("7%%2: my prediction 1 %d \n", 7%2);
    printf("-7/2: my prediction -3 %d \n", -7/2);
    printf("-7%%2: my prediction 1 %d \n", -7%2);
}