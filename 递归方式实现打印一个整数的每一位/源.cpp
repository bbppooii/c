#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void c(int a) {
	int z = 0;
	if (a > 9) {
		z = a / 10;
		c(z);
	}
	printf("%d ", a % 10);
}
int main() {
	int q;
	scanf("%d", &q);
	c(q);
}