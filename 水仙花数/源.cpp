#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <string.h>
#include <stdio.h>
int get(int num, int pos) {
    return(num / (int)pow(10, pos - 1)) % 10;
}
int main() {
    int n = 0, q = 0, d = 0, sum = 0, b[100] = { 0 }, c = 0;
    scanf("%d", &n);
    if (n < 3) {
        printf("N 必须大于等于 3。\n");
        return 1;
    }
    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
        for (q = 0; q < n; q++) {
            d = get(i, q + 1);
            sum +=pow(d, n);
        }
        if (i == sum) {
            b[c++] = i;
        }
        sum = 0;
    }
    q = 0;
    for (q = 0; b[q] != 0 && q < c; q++) {  
        printf("%d", b[q]);
        if (b[q + 1] != 0) {
            printf("\n");
        }
    }
    return 0;
}