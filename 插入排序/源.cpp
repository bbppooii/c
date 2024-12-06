#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// ��������ʵ��
void InsertSort(int* a, int n) {
    if (a == NULL || n <= 1) {
        return; // �������Ϊ�ջ�Ԫ�ظ�������1����ֱ�ӷ���
    }
    // ����ÿ��Ԫ�أ�������뵽�Ѿ��ź���Ĳ���
    for (int i = 0; i < n - 1; i++) {
        int end = i;               // �����򲿷ֵ����һ��λ��
        int tmp = a[end + 1];      // �������Ԫ��
        // �Ӻ���ǰ�������ҵ�����λ��
        while (end >= 0 && a[end] > tmp) {
            a[end + 1] = a[end];   // ���ݺ��ƣ�Ϊ�����ڳ�λ��
            end--;
        }
        a[end + 1] = tmp;          // ���뵽��ȷλ��
    }
}
// ��ӡ����
void PrintArray(int* a, int n) {
    if (a == NULL || n <= 0) {
        return; // �������Ϊ�ջ���Ԫ�أ���ֱ�ӷ���
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n"); // ������з������ָ�ʽ����
}