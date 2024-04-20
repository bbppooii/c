#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
int qwe(char q[], char w[],int z,int x) {
	char asd;
	if (z == x) {
		for (int i = 0; i < z; i++) {
			asd = q[0];
			for (int j = 0; j < z - 1; j++) {
				q[j] = q[j + 1];
			}
			q[z-1] = asd;
			if (strcmp(q, w) == 0) {
				return 1;
				break;
			}
		}
	}
	else
		return 0;
}
int main() {
	char a[] = "asdf";
	char b[] = "sdfa";
	int z, x;
	z = strlen(a);
	x = strlen(b);
	z = qwe(a, b, z, x);
	if (z == 1)
		printf("ÊÇ");
	else
		printf("²»ÊÇ");
	return 0;
}