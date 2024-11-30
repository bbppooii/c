#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MAX_SIZE 20

void rotate90Left(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rotate90Right(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int j = 0; j < n; j++) {
        for (int i = m - 1; i >= 0; i--) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rotate180(int matrix[MAX_SIZE][MAX_SIZE], int m, int n) {
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, r;

    // 输入行列数
    if (scanf("%d %d", &m, &n) != 2) {
        printf("data type error\n");
        return 1;
    }
    if (m <= 0 || m > MAX_SIZE || n <= 0 || n > MAX_SIZE) {
        printf("matrix data error\n");
        return 1;
    }

    // 输入旋转角度
    if (scanf("%d", &r) != 1) {
        printf("data type error\n");
        return 1;
    }
    if (r != 90 && r != 180 && r != -90) {
        printf("angle data error\n");
        return 1;
    }

    // 输入矩阵数据
    int matrix[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("data type error\n");
                return 1;
            }
            if (matrix[i][j] < 0 || matrix[i][j] > 255) {
                printf("matrix data error\n");
                return 1;
            }
        }
    }

    // 根据角度选择旋转方法
    if (r == 90) {
        rotate90Left(matrix, m, n);
    }
    else if (r == -90) {
        rotate90Right(matrix, m, n);
    }
    else if (r == 180) {
        rotate180(matrix, m, n);
    }

    return 0;
}
