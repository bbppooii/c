#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n = 7; 
    int mid = n / 2; 
    for (int i = 0; i < n; i++) {
        int numStars = i <= mid ? 2 * i + 1 : 2 * (n - i - 1) + 1;
        int numSpaces = (n + 4 - numStars) / 2;
        for (int j = 0; j < numSpaces; j++) {
            printf(" ");
        }
        for (int j = 0; j < numStars; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
