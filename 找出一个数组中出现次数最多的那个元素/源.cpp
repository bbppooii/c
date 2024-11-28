#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 找出出现次数最多的元素
int FindMostFrequent(int* arr, int n) {
    int maxCount = 0;   // 最大出现次数
    int result = arr[0];  // 出现次数最多的元素
    for (int i = 0; i < n; ++i) {
        int count = 0; // 当前元素的计数
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // 如果当前元素出现次数更多，或者相等但位置更靠前，更新结果
        if (count > maxCount) {
            maxCount = count;
            result = arr[i];
        }
    }
    return result;
}

int main() {
    int n;
    printf("请输入整数n（不超过20）：");
    scanf("%d", &n);

    int arr[20];
    printf("请输入%d个整数：", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int mostFrequent = FindMostFrequent(arr, n);
    printf("出现次数最多的元素是：%d\n", mostFrequent);

    return 0;
}
