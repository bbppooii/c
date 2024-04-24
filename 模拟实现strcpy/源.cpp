#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
char* my_strcpy(char*qwq,const char* aa ) {
	char* ret = qwq;
	while ((*qwq++ = *aa++)) {
		
	}
	return ret;
}
int main() {
	char q[20] = "";
	const char* a = "aaaa";
	printf("%s", my_strcpy(q, a));

	return 0;
}