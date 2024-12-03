#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void getMinNumber(char n[], int k) {
    int len = strlen(n);
    int remain = len - k;  
    char stack[1000];     
    int top = -1;         
    for (int i = 0; i < len; i++) {
        while (top >= 0 && stack[top] > n[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = n[i];
    }
    top -= k;
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }
    if (start > top) {
        printf("0\n");
    }
    else {
        for (int i = start; i <= top; i++) {
            putchar(stack[i]);
        }
        printf("\n");
    }
}
int main() {
    char n[1000];
    int k;
    while (scanf("%s %d", n, &k) != EOF) {
        getMinNumber(n, k);
    }
    return 0;
}
