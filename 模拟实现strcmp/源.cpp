#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_strcmp(const char *str1,const char *str2) {
	while (*str1 == *str2) {
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main() {
	const char* st1 = "qwe";
	const char* st2 = "qwa";
	if (my_strcmp(st1,st2) > 0)
		printf("1´ó");
	else if (my_strcmp(st1,st2) < 0)
		printf("2´ó");
	else
		printf("=");
		
}