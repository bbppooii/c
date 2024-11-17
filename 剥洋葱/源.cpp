#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    n = n * 2 - 1;
    int mid = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int layer = i < j ? (i < n - 1 - j ? i : n - 1 - j) : (j < n - 1 - i ? j : n - 1 - i);
            char ch = 'A' + layer;  
            printf("%c", ch);
        }
        printf("\n"); 
    }
    return 0;
}
