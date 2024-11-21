#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void printSword(int n) {
    // ��һ��
    printf("     |\n");
    // �ڶ��У������ͽ���
    printf("@");
    for (int i = 0; i < 4; i++) {
        printf("*");
    }
    printf("|");
    for (int i = 0; i < n; i++) {
        printf("=");
    }
    printf(">\n");
    // ������
    printf("     |\n");
}

int main() {
    int n;
    // �������봦��
    while (scanf("%d", &n) != EOF) {
        if (n < 1 || n > 10) {
            printf("Invalid input: n must be between 1 and 10.\n");
            continue;
        }
        printSword(n);
    }
    return 0;
}
