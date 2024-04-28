#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int test()
{
	union 
	{
		int a = 1;
		char b;
	}c;
	return c.b;
}
int main()
{
	int c=test();
	printf("%d", c);
	return 0;
}