#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <assert.h>
int qwe(const char* str){
	int count = 0;
	assert(str != NULL);
	while (*str++){
		count++;
	}
	return count;
}
int main(){
	int len = 0;
	char p[] = "qweasd";
	len = qwe(p);
	printf("len=%d\n", len);
	return 0;
}