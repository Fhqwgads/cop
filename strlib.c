#include "strlib.h"

int str_length(const char *s) {
    int count = 0;

    for(int i = 0; s[i] != '\0'; i++){
        count += 1;
    }
        return count;
    
    return 0;
}

void str_copy(char *dst, const char *src, int dst_size) {
    /* TODO: copy characters one at a time, stop at dst_size-1 or '\0' */
    /* Always null-terminate dst */
}

int str_compare(const char *a, const char *b) {
    /* TODO: walk both strings simultaneously, return first difference */
    return 0;
}

void str_reverse(char *s) {
    /* TODO: swap characters from both ends toward the middle */
}

int str_count_char(const char *s, char c) {
    /* TODO */
    return 0;
}

void str_to_upper(char *s) {
    /* TODO: for each char, if 'a' <= c <= 'z', subtract 32 */
}

void array_stats(const int arr[], int len,
                 int *out_min, int *out_max, double *out_avg) {
    /* TODO: handle len <= 0 case; otherwise scan for min/max/sum */
}

int array_find(const int arr[], int len, int target) {
    /* TODO: linear scan; return index or -1 */
    return -1;
}