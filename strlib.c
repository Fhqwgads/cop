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
    for(int i = 0; src[i] != '\0' || i == dst_size - 1 ; i++){
        dst[i] = src[i];
    }
    
    /* TODO: copy characters one at a time, stop at dst_size-1 or '\0' */
    /* Always null-terminate dst */
}

int str_compare(const char *a, const char *b) {
    int garbageN;
     for(int i = 0; a[i] != '\0' && b[i] != '\0' ; i++){
        if(a[i] == b[i]){
            garbageN = 0;
            continue;
        }else if(a[i] > b[i]){
            garbageN = 1;
        }else if(a[i] < b[i]){
            garbageN = -1;
        }
    }
    return garbageN;
    /* TODO: walk both strings simultaneously, return first difference */
    return 0;
}

void str_reverse(char *s) {
    int count;
    for(int i = 0; s[i] != '\0'; i++){
        count += 1;
    }
    char temp[16];
    for(int i = 0; s[i] != '\0' || i == count - 1 ; i++){
        temp[i] = s[i];
    }
    for(int i = 0; s[i] != '\0'; i++){
        
        s[i] = temp[count - i];
    }

    /* TODO: swap characters from both ends toward the middle */
}

int str_count_char(const char *s, char c) {
    int count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == c){
            count += 1;
        }
        
    }
    /* TODO */
    return count;
}

void str_to_upper(char *s) {

    for(int i = 0; s[i] != '\0'; i++){
        if('a' <= s[i] <= 'z'){
            s[i] -= 32;
        }
        
    }
    /* TODO: for each char, if 'a' <= c <= 'z', subtract 32 */
}

void array_stats(const int arr[], int len,
                 int *out_min, int *out_max, double *out_avg) {
                     
    *out_min = arr[0];
    *out_max = arr[0];
    *out_avg = 0.0;
    double count = 0.0;             
                    
    if(len <= 0){
        *out_min = 0;
        *out_max = 0; 
        *out_avg = 0.0;
        return;
    }

    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] <= *out_min){
            *out_min = arr[i];
        }
        if(arr[i] >= *out_max){
            *out_max = arr[i];
        }
        
        count += arr[i];
        *out_avg = count/len;
    }                          
    /* TODO: handle len <= 0 case; otherwise scan for min/max/sum */
}

int array_find(const int arr[], int len, int target) {
    
    
    for(int i = 0; i < len; i++){
        if(arr[i] == target){
            return i;
        }
        
    }
    
    
    /* TODO: linear scan; return index or -1 */
    return -1;
}