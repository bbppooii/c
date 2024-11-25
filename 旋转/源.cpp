#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void rotate90(int n, int m, int matrix[50][50], int result[50][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = matrix[i][j];
        }
    }
}
int main() {
    int n, m, d;
    while (scanf("%d %d", &n, &m) == 2) {
        int matrix[50][50], result[50][50];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        scanf("%d", &d);
        d = d % 4;
        while (d > 0) {
            rotate90(n, m, matrix, result);
            int temp = n;
            n = m;
            m = temp;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = result[i][j];
                }
            }
            d--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", matrix[i][j]);
                if (j < m - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
