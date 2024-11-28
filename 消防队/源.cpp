#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int fireCount = 0; 
        int cell;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &cell);
                if (cell == 1) {
                    fireCount++;
                }
            }
        }
        if (fireCount == 1) {
            printf("need 1 Firefighter\n");
        }
        else {
            printf("need %d Firefighters\n", fireCount);
        }
    }
    return 0;
}
