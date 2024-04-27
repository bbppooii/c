#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void* my_memmove(void* destination, const void* source, size_t num)
{
	void* ret = destination;
	if (destination <= source)
	{
		while(num--)
		{
			*(char*)destination = *(char*)source;
			destination = (char*)destination + 1;
			source = (char*)source + 1;
		}
	}
	else
	{
		destination = (char*)destination + num - 1;
		source = (char*)source + num - 1;
		while (num--)
		{
			*(char*)destination = *(char*)source;
			destination = (char*)destination - 1;
			source = (char*)source - 1;
		}
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,4,6 };
	int arr2[20] = {};
	my_memmove(arr2, arr1, 20);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", arr2[i]);
	}
	return 0;
}