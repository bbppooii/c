#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int b;
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		if (i == 0)
			printf("1 ");
		else if(i==1)
			printf("1 1 ");
		else {
			printf("1 ");
			for (int j = 0; j < i-1; j++) {
					printf("%d ",i);
			}
			printf("1 ");
		}
		printf("\n");
	}
}