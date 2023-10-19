#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main() {
        int i,j,q,a;
        char z[] = " ";
        scanf("%s %d", &z,&a);
      
        for (i = 1; i <= a / 2; i++) {
            for (q = a / 2 - i; q >= 0; q--) {
                printf(" ");
            }
            for (j = 1; j < i * 2; j++) {
                printf("%s", z);
            }
            printf("\n");
        }
        if (a % 2 != 0) {
            for (i = a; i > 0; i--) {
                printf("%s", z);
            }
            printf("\n");
        }
        for (i = a / 2; i >= 1; i--) {
            for (q = a / 2 - i; q >= 0; q--) {
                printf(" ");
            }
            for (j = 1; j < i * 2; j++) {
                printf("%s", z);
            }
            printf("\n");
        }
        return 0;
    }
 