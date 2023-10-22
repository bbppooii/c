#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    printf("%#o ", a);
    printf("%#X", a);
    return 0;
}