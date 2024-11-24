#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int countClaps(int n) {
    int count = 0;
    count += n / 7;
    for (int i = 7; i <= n; i += 10) {
        if (i % 7 != 0) {
            count++;
        }
    }
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int claps = countClaps(n);
    printf("%d", claps);
    return 0;
}
