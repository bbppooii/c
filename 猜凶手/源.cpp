#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main() {
	int a[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		a[i] = 1;
		if ((a[0] != 1) + (a[2] == 1) + (a[3] == 1) + (a[3] != 0) == 3) 
			printf("ÊÇ%d",i);
	}
	return 0;
}