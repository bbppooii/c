#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* my_strncpy(char* destination,const char*source,size_t num)
{
	char* start = destination;
	while (num>0 && *source != '\0')
	{
		*destination++ = *source++;
		num--;
	}
	*destination = '\0';
	return start;
}

int main() 
{
	const char* src = "hello world";
	char dest[20];
	my_strncpy(dest, src, 5);
	printf("%s", dest);
}