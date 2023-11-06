#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int a, b;
    a = getchar();
    if(a>=65 && a<=90)
        putchar(a + 32);
    else if(a>=97 && a<=122)
        putchar(a - 32);
    getchar();
    
    return 0;
}