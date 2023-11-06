#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int a, b=0, c=0;
	a = 20;
	b = a / 2;
	a = a + b;
	while (1) {
		if (b / 2 != 0) {
			a = a + b / 2;
			b = b / 2;
		}
		else
			break;
	}
	printf("%d", a);
}