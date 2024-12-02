#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ����Ͱ�Ľṹ
typedef struct Bucket {
    int* data;   // ��̬����
    int count;   // ��ǰ�洢��Ԫ�ظ���
    int capacity; // Ͱ������
} Bucket;

// ��ʼ��Ͱ
void InitBucket(Bucket* bucket) {
    bucket->capacity = 10; // ��ʼ����
    bucket->data = (int*)malloc(bucket->capacity * sizeof(int));
    bucket->count = 0;
}

// ��Ͱ�����Ԫ��
void AddToBucket(Bucket* bucket, int value) {
    if (bucket->count == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->data = (int*)realloc(bucket->data, bucket->capacity * sizeof(int));
    }
    bucket->data[bucket->count++] = value;
}

// Ͱ��ʹ�ò�������
void InsertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Ͱ������
void BucketSort(int* arr, int n) {
    if (n <= 1) return;

    // �ҵ������е����ֵ����Сֵ
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int bucketCount = 10; // Ĭ�Ϸֳ�10��Ͱ
    int range = max - min + 1;
    int bucketRange = range / bucketCount + 1;

    // ��ʼ��Ͱ����
    Bucket* buckets = (Bucket*)malloc(bucketCount * sizeof(Bucket));
    for (int i = 0; i < bucketCount; i++) {
        InitBucket(&buckets[i]);
    }

    // �����ݷ��䵽Ͱ��
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketRange;
        AddToBucket(&buckets[bucketIndex], arr[i]);
    }

    // ��ÿ��Ͱ�е��������򲢺ϲ����
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].count > 0) {
            InsertionSort(buckets[i].data, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].data[j];
            }
        }
        free(buckets[i].data);
    }

    // �ͷ�Ͱ����
    free(buckets);
}

// ���Ժ���
int main() {
    int arr[] = { 42, 32, 33, 52, 37, 47, 51, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    BucketSort(arr, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
