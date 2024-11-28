#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
void ShellSort(int* a, int n) {
    // ��ʼ��������gap��Ϊ���鳤��
    int gap = n;
    // ʹ�����������ķ�ʽ������
    while (gap > 1) {
        // ��С������ʹ�ø�С�ķ���
        gap = gap / 3 + 1; // ϣ���������е�һ��ѡ��ʽ
        // ��ÿ�����ݽ��в�������
        for (int i = 0; i < n - gap; i++) {
            // ��ǰ��������һ��������Ԫ��
            int end = i;
            // �������Ԫ��
            int tmp = a[end + gap];
            // �� tmp ���뵽��ǰ�������ȷλ��
            while (end >= 0 && a[end] > tmp) {
                // �����ǰԪ�ش��ڴ�����Ԫ�أ�������ƶ�
                a[end + gap] = a[end];
                end -= gap; // �ƶ�����һ������λ��
            }
            // ����Ԫ�ص���ȷλ��
            a[end + gap] = tmp;
        }
    }
}
void Print(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}