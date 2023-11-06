#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int DigitSum(int n)
{
	int sum = 0;
	if (n != 0)
		sum = n % 10 + DigitSum(n/10);
	return sum;
}
int main() {
	int k;
	scanf("%d", &k);
	printf("%d", DigitSum(k));
}