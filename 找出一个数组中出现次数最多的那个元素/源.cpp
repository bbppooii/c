#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// �ҳ����ִ�������Ԫ��
int FindMostFrequent(int* arr, int n) {
    int maxCount = 0;   // �����ִ���
    int result = arr[0];  // ���ִ�������Ԫ��
    for (int i = 0; i < n; ++i) {
        int count = 0; // ��ǰԪ�صļ���
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // �����ǰԪ�س��ִ������࣬������ȵ�λ�ø���ǰ�����½��
        if (count > maxCount) {
            maxCount = count;
            result = arr[i];
        }
    }
    return result;
}

int main() {
    int n;
    printf("����������n��������20����");
    scanf("%d", &n);

    int arr[20];
    printf("������%d��������", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int mostFrequent = FindMostFrequent(arr, n);
    printf("���ִ�������Ԫ���ǣ�%d\n", mostFrequent);

    return 0;
}
