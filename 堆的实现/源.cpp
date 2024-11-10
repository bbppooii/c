#define _CRT_SECURE_NO_WARNINGS 1
#include "t.h"
// �ѵĳ�ʼ��
void HeapInit(Heap* hp) {
	assert(hp);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0; 
}
void swap(HPDataType* px, HPDataType* py) {
	HPDataType newdata = *px;
	*px = *py;
	*py = newdata;
}
void AdjustUp(HPDataType* a,int child){
	int parent = (child - 1) / 2;
	while (child > 0){
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}else {
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n){
		if (child + 1 < n && a[child] > a[child + 1]) {
			++child;
		}
		if (a[child] < a[parent]) {
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}else {
			break;
		}
	}
	
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	if (hp->size == hp->capacity) {
		int newcapaity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp =(HPDataType*) realloc(hp->a, sizeof(HPDataType) * newcapaity);
		if (tmp == NULL) {
			perror("realloc fail");
			return;
		}
		hp->a = tmp;
		hp->capacity = newcapaity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	assert(hp);
	assert(hp->size > 0);
	swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->a, hp->size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp){
	assert(hp);
	return hp->size;
}
// �ѵ��п�
bool HeapEmpty(Heap* hp) {
	assert(hp);	
	return hp->size == 0;
}