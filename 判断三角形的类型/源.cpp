#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && c + b > a) {
        if (a == b && a == c && b == c)
            printf("Equilateral triangle!\n");
        else if (a == b || b == c || c == a)
            printf("Isosceles triangle!\n");
        else
            printf("Ordinary triangle!\n");
    }
    else
        printf("Not a triangle!\n");

    return 0;
}