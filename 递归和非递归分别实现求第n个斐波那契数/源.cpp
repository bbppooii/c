#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fun(int n)
{
    if (n <= 2)
        return 1;
    else
        return Fun(n - 1) + Fun(n - 2);
}
int main() {
    int a = 0, b[100] = {0}, i = 0;
    scanf("%d", &a);
    printf("µÝ¹é%d\n", Fun(a));
    b[1] = 1;
    b[2] = 1;
    for (i = 3; i <= a; i++) {
        b[i] = b[i - 1] + b[i - 2];
    }
    printf("Ñ­»·%d", b[i-1]);
}