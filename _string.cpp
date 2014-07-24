#include "_string.h"


/* Str operations */
char* createStr() {
    static char str[N+1] = "0123456789";

    puts(str);

    return str;
}


void strReverse(char* str) {
    int len = strlen(str);
    int halfLen = len / 2;
    int i;
    char tmp;

    for (i = 0; i < halfLen; ++i) {
        tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
 }

