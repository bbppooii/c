#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ��ȡ�����е����ֵ
int GetMax(int* a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// �����鰴��ĳ��λ�����м�������
void CountingSortForRadix(int* a, int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = { 0 }; // ��Ϊ�ǰ�λ����ֻ�� 0-9 �� 10 ������

    // ͳ��ÿ��λ�ϵĳ��ִ���
    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    // �����ۻ�����
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // ����ǰλ���򣬽����ݷ����������
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // �����������ƻ�ԭ����
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    free(output);
}

// ��������������
void RadixSort(int* a, int n) {
    int max = GetMax(a, n); // �ҵ����������ֵ
    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountingSortForRadix(a, n, exp);
    }
}

// ���Ժ���
int main() {
    int a[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    RadixSort(a, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
