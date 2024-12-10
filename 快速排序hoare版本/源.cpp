#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void _printf(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
void QuickSort(int* a, int left, int right) {
	if (left >= right) { 
		return;
	}
	int begin = left;
	int end = right;
	int keyi = left;
	while (left < right) {
		while (a[right] >= a[keyi] && left < right) {
			right--;
		}
		while (a[left] <= a[keyi] && left < right) {
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	keyi = left;
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
int main() {
	int a[] = { 7,5,6,4,8,9,2,1,3,0 };
	_printf(a, sizeof(a) / sizeof(a[0]));
	printf("\n");
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	_printf(a, sizeof(a) / sizeof(a[0]));
}
