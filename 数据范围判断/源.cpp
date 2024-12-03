#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n > 100) {
            printf("GO To PARIS !\n");
        }
        else if (n >= 90) {
            printf("A\n");
        }
        else if (n >= 80) {
            printf("B\n");
        }
        else if (n >= 70) {
            printf("C\n");
        }
        else if (n >= 60) {
            printf("d\n");
        }
        else {
            printf("GO TO SHAOXING !\n");
        }
    }
    return 0;
}
