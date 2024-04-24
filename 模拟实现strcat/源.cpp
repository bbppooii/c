#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char *my_strcat(char *str1,const char *str2) {
	char* ret = str1;
	while (*str1) {
		str1++;
	}
	while ((*str1++=*str2++)) {
	}
	return ret;
}
int main() {
	char q[20] = "asd";
	const char* a = "asda";
	printf("%s", my_strcat(q, a));
}