#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_atoi(const char*str)
{
	int ret=0;
	int sign = 1;
	if (*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str!='\0')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return ret * sign;
}
int main()
{
	const char* a = "12345";
	int num = my_atoi(a);
	printf("%d", num);
}