#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int q(int e) {
	int sum=0,q=e;
	for (int i = 0; i < 5; i++)
	{
		sum = sum + e;
		e = e * 10 + q;
	}
	return sum;
}
int main() {
	int a;
	scanf("%d",&a);
	printf("%d", q(a));
}