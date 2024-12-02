#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[101];
    int count[128] = { 0 }; 
    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 1; 
    }
    for (int i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            count[(int)s[i]]++; 
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (count[i] > 0) { 
            printf("%c:%d\n", i, count[i]);
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (count[i] > 0) { 
            printf("%c:%d\n", i, count[i]);
        }
    }
    return 0;
}
