#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int int_cmp(const void* p1, const void* p2){
	return (*(int*)p1 - *(int*)p2);
}
void _swap(void* p1, void* p2, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
void bubble(void* base, int count, int size, int(*cmp)(const void*, const void*)){
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++){
		for (j = 0; j < count - i - 1; j++){
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0){
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}
int main(){
	int arr[] = {0,8,6,4,5,1,3,2,7,9};
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}