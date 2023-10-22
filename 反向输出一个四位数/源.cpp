#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
   printf("%d%d%d%d\n", n % 10, (n / 10) % 10, (n / 100) % 10, n / 1000);
}