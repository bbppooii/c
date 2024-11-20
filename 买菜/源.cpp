#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int maxPrice = -1;
        int price;
        for (int i = 0; i < m; i++) {
            scanf("%d", &price);
            if (price <= n && price > maxPrice) {
                maxPrice = price;
            }
        }
        if (maxPrice == -1) {
            printf("xiaohongGG\n");
        }
        else {
            printf("%d\n", maxPrice);
        }
    }
    return 0;
}
