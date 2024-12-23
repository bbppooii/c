#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����������
void CountingSort(int* a, int n) {
    if (n <= 1) return; // ���鳤�Ȳ���ʱֱ�ӷ���

    // �ҵ������е����ֵ����Сֵ
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    // �����������鲢��ʼ��
    int range = max - min + 1; // Ԫ�ط�Χ
    int* count = (int*)calloc(range, sizeof(int));
    if (count == NULL) {
        perror("Memory allocation failed");
        return;
    }

    // ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int i = 0; i < n; i++) {
        count[a[i] - min]++;
    }

    // �ۻ����������ڼ���ÿ��Ԫ�ص�����λ��
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // ����Ŀ������
    int* output = (int*)malloc(n * sizeof(int));
    if (output == NULL) {
        perror("Memory allocation failed");
        free(count);
        return;
    }

    // �������ԭ���飬��Ԫ�ط��õ���ȷλ��
    for (int i = n - 1; i >= 0; i--) {
        int index = count[a[i] - min] - 1;
        output[index] = a[i];
        count[a[i] - min]--;
    }

    // ��������д�ص�ԭ����
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    // �ͷ��ڴ�
    free(count);
    free(output);
}

int main() {
    int a[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    CountingSort(a, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
