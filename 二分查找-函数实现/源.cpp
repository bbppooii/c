#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void bin_search(int arr[], int left, int right, int key) {
	int find=0,mid;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] > key) {
			right = mid - 1;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			find = 1;
			break;
		}
	}
	if (find == 1)
		printf("下标是%d", mid);
	else
		printf("没找到");
}
int main() {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b=0;
	printf("查找");
	scanf("%d", &b);
	bin_search(a,0,9,b);
	return 0;
}