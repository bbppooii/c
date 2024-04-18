#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int sum = 0,q=0;
	for (int i = 1; i <= 500; i++) {
		if (i % 2 != 0 && i % 5 != 0 && i % 7 != 0)
			sum = sum + 1;
		q = q + 1;
	}
	printf("%d %d", sum,q);
}
