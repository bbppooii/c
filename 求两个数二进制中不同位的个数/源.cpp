#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a, b, q, w, s = 0;
	scanf("%d %d", &a, &b);
	for (int i = 32; i > 0; i = i--) {
		q = (a >> i) & 1;
		w = (b >> i) & 1;
		if (q != w)
			s++;
	}
	printf("%d", s);
}