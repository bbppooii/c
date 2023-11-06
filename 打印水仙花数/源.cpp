#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	for (int i = 0; i <= 100000; i++) {
		if (i<10&&i!=0) {
			printf("%d ", i);
		}
		if (i >= 10&&i<100) {
			if (i == pow(i % 10, 2) + pow(i / 10, 2))
				printf("%d ", i);
		}
		if (i >= 100 && i < 1000) {
			if (i == pow(i % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 100, 3))
				printf("%d ", i);
		}
		if (i >= 1000 && i < 10000) {
			if (i == pow(i % 10, 4) + pow(i / 10 % 10, 4) + pow(i / 100 % 10, 4) + pow(i / 1000, 4))
				printf("%d ", i);
		}
		if (i >= 10000 && i < 100000) {
			if (i == pow(i % 10, 5) + pow(i / 10 % 10, 5) + pow(i / 100 % 10, 5) + pow(i / 1000 % 10, 5) + pow(i / 10000, 5))
				printf("%d ", i);
		}
	}
}