#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// ��������Ԫ�ص�λ��
void Swap(int* p1, int* p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
// ��ӡ����
void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// ����������
void QuickSort(int* a, int left, int right) {
    // ���������Ч��ֻʣһ��Ԫ�أ�ֱ�ӷ���
    if (left >= right) {
        return;
    }
    // ���ó�ʼ��׼ֵ��λ�ã�ѡȡ��ߵ�Ԫ����Ϊ��׼ֵ��
    int prev = left;  // prev ���ڱ��С�ڻ�׼ֵ�������ĩβλ��
    int cur = prev + 1;  // cur ���ڱ�������
    int pivotIndex = left;  // ��׼ֵ��λ�ã���ʼ��Ϊ��߽磩
    // �����������䣬���з���
    while (cur <= right) {
        // �����ǰԪ��С�ڻ�׼ֵ���� prev λ�û�û���� cur ����
        if (a[cur] < a[pivotIndex] && ++prev != cur) {
            // ��������������򽻻� a[prev] �� a[cur]
            Swap(&a[prev], &a[cur]);
        }
        ++cur;  // ���������ƶ� cur ָ��
    }
    // ��󽫻�׼ֵ�� prev λ�õ�Ԫ�ؽ���������׼ֵ�ŵ���ȷ��λ��
    Swap(&a[prev], &a[pivotIndex]);
    pivotIndex = prev;  // ���»�׼ֵλ��
    // �ݹ鴦����������������
    QuickSort(a, left, pivotIndex - 1);  // ����������
    QuickSort(a, pivotIndex + 1, right);  // ����������
}
int main() {
    // ��ʼ��һ������
    int a[] = { 7, 5, 6, 4, 8, 9, 2, 1, 3, 0 };
    int n = sizeof(a) / sizeof(a[0]);  // �����Ԫ�ظ���
    // �������ǰ������
    printf("Before sorting:\n");
    PrintArray(a, n);
    // ���ÿ�������
    QuickSort(a, 0, n - 1);
    // �������������
    printf("After sorting:\n");
    PrintArray(a, n);
    return 0;
}
