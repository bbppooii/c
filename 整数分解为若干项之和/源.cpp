#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int outputCount = 0;  
void printSolution(int n, int parts[], int length, int isLast) {
    printf("%d=", n);
    for (int i = 0; i < length; i++) {
        printf("%d", parts[i]);
        if (i < length - 1) {
            printf("+");
        }
    }
    outputCount++;  
    if (!isLast) {
        if (outputCount % 4 == 0) {
            printf("\n");
        }
        else {
            printf("; ");
        }
    }
    else {
        printf("\n"); 
    }
}
void decompose(int n, int remain, int parts[], int length, int start, int isLast) {
    if (remain == 0) {
        printSolution(n, parts, length, isLast);
        return;
    }
    for (int i = start; i <= remain; i++) {
        parts[length] = i;
        decompose(n, remain - i, parts, length + 1, i, (remain == i) && isLast);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int* parts = (int*)malloc(n * sizeof(int));
    if (parts == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    decompose(n, n, parts, 0, 1, 1);
    free(parts);
    return 0;
}
