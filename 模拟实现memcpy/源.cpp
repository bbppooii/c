#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void* my_memcpy(void* destination, const void* source, size_t num)
{
	void *ret = destination;
	while (num--)
	{
		*(int*)destination = *(int*)source;
		destination = (int*)destination+1;
		source = (int*)source + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,4,6 };
	int arr2[20] = {};
	my_memcpy(arr2, arr1, 5);
	for(int i=0;i<5;i++)
	{
		printf("%d", arr2[i]);
	}
	return 0;
}