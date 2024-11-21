#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void printSword(int n) {
    // 第一行
    printf("     |\n");
    // 第二行，剑柄和剑身
    printf("@");
    for (int i = 0; i < 4; i++) {
        printf("*");
    }
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("=");
    }
    printf(">\n");
    // 第三行
    printf("     |\n");
}

int main() {
    int n;
    // 多组输入处理
    while (scanf("%d", &n) != EOF) {
        if (n < 1 || n > 10) {
            printf("Invalid input: n must be between 1 and 10.\n");
            continue;
        }
        printSword(n);
    }
    return 0;
}
