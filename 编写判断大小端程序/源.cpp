#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int check_sys()
{
	int i = 1;
	return (*(char*)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("⼤端\n");
	}
	return 0;
}