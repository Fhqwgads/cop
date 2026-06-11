#include <stdio.h>
int main(void) {
int a = 10;
int b = 20;
int *p = &a;
printf("a = %d\n", a); /* predict: 10 */
printf("b = %d\n", b); /* predict: 20 */
printf("*p = %d\n", *p); /* predict: 10 */
printf("p == &a? = %d\n", p == &a); /* predict: true */
*p = 99;
printf("\nAfter *p = 99:\n");
printf("a = %d\n", a); /* predict: 99 */
printf("*p = %d\n", *p); /* predict: 99 */
p = &b;
printf("\nAfter p = &b:\n");
printf("*p = %d\n", *p); /* predict: 20 */
printf("a = %d\n", a); /* predict: 99 */
*p = *p + 5;
printf("\nAfter *p = *p + 5:\n");
printf("b = %d\n", b); /* predict: 25 */
return 0;
}