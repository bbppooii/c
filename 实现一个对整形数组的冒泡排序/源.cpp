#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
	int qwe[5] = {2,8,5,4,7};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j <4-i; j++) {
			if (qwe[j] > qwe[j + 1]) {
				int tmp = qwe[j];
				qwe[j] = qwe[j + 1];
				qwe[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ",qwe[i]);
	}
	return 0;
}