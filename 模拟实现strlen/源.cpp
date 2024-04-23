#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int my_strlen(const char *str) {
	const char* s = str;
	while (*s != '\0')
		s++;
	return s - str;
}
int main() {
	const char* q = "abcdef";
	const char *a = q;
	printf("%d", my_strlen(a));
	return 0;
}