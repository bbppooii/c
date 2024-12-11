#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// �ϲ���������������
void Merge(int* a, int left, int mid, int right, int* tmp) {
    int i = left;      // �����������
    int j = mid + 1;   // �����������
    int k = 0;         // ��ʱ��������

    // �ϲ�������������
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        }
        else {
            tmp[k++] = a[j++];
        }
    }

    // �������������ʣ�ֱ࣬�ӿ���
    while (i <= mid) {
        tmp[k++] = a[i++];
    }

    // �������������ʣ�ֱ࣬�ӿ���
    while (j <= right) {
        tmp[k++] = a[j++];
    }

    // ����ʱ�����е�Ԫ�ؿ�����ԭ����
    for (i = 0; i < k; ++i) {
        a[left + i] = tmp[i];
    }
}

// �鲢����������
void MergeSort(int* a, int left, int right, int* tmp) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // ����벿������
        MergeSort(a, left, mid, tmp);

        // ���Ұ벿������
        MergeSort(a, mid + 1, right, tmp);

        // �ϲ�������
        Merge(a, left, mid, right, tmp);
    }
}

// ��������
void MergeSortWrapper(int* a, int n) {
    int* tmp = (int*)malloc(n * sizeof(int));  // ���丨���ռ�
    if (tmp == NULL) {
        perror("Memory allocation failed");
        return;
    }

    MergeSort(a, 0, n - 1, tmp);
    free(tmp);  // �ͷŸ����ռ�
}

void PrintArray(int* a, int n) {
    if (a == NULL || n <= 0) {
        return; // �������Ϊ�ջ���Ԫ�أ���ֱ�ӷ���
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); // ������з������ָ�ʽ����
}
 int main() {
        int a[] = { 1,5,9,8,7,4,6,2,3,44,55,11,23,58 };
        PrintArray(a, sizeof(a) / sizeof(int));
        MergeSortWrapper(a, sizeof(a) / sizeof(int));
        PrintArray(a, sizeof(a) / sizeof(int));
        return 0;
    }