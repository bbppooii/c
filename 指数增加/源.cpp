#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main() {
    int a, x;
    while (scanf("%d %d", &a, &x) == 2) {
        // 检查输入是否在合理范围内
        if (a < 1 || a > 10 || x < 1 || x > 20) {
            printf("Invalid input\n");
            continue; // 跳过当前错误输入
        }
        long long result = (long long)pow(a, x - 1);
        printf("%lld\n", result);
    }
    return 0;
}
