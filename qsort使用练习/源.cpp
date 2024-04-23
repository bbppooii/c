#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct qwe{
	char name[20];
	int age;
};
int int_cmp(const void* p1, const void* p2){
	return (*(int*)p1 - *(int*)p2);
}
int cmp_name(const void* p1, const void* p2) {
	return strcmp(((struct qwe*)p1)->name, ((struct qwe*)p2)->name);
}
int cmp_age(const void* p1, const void* p2) {
	return ((struct qwe*)p1)->age - ((struct qwe*)p2)->age;
}
int main(){
	int arr[] = {0,8,7,5,6,9,4,1,3,2};
	int i = 0;
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	struct qwe a[] = { {"ccxc",13},{"cc",11},{"asdf",18}};
	int sz = sizeof(a) / sizeof(a[0]);
	qsort(a, sz, sizeof(a[0]), cmp_age);
	for (i = 0; i < sz; i++) {
		printf("%d ", a[i].age);
	}
	qsort(a, sz, sizeof(a[0]), cmp_name);
	for (i = 0; i < sz; i++) {
		printf("%s ", a[i].name);
	}
	return 0;
}
