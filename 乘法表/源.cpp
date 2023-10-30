#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int m( int q) {
    for (int a = 1; a <= q; a++) {
        for (int b = 1; b <= a; b++) {
            printf(" %d * %d = %d ", a, b, a * b);
        }
        printf("\n");
    }
    return 0;
}
int main(){
    int q = 0;
    scanf("%d",&q);
    m(q);
    return 0;
}
