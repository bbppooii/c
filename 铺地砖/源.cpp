#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n < 1 || m < 1 || n > 100 || m > 100) {
            printf("Invalid input. n and m must be between 1 and 100.\n");
            continue;
        }
        int maxDominoes = (n * m) / 2;
        printf("%d\n", maxDominoes);
    }
    return 0;
}
