#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char* my_strstr(const char* str1,const char* str2) {
	char* cp = (char*)str1;
	char* s1, * s2;
	if (!*str2)
		return((char*)str1);
	while (*cp) {
		s1 = cp;
		s2 = (char*)str2;
		while (*s2&&*s1==*s2) {
			s1++;
			s2++;
		}
		if (!*s2)
			return cp;
		cp++;
	}
	return NULL;
}
int main() {
	char a[] = "hello world qweqwe !";
	strncpy(my_strstr(a, "qwe"), "asdasd",6);
	printf("%s",a);
	return 0;
}