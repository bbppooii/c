#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void a(int z[3][3], int s,int q,int w) {
	int x = 0;
	int y = w-1;
	while (x < q && y >= 0) {
		if (z[x][y] < s) {
			x++;
		}	
		else if (z[x][y] > s) {
			y--;
		}
		else {
			printf("�ҵ��ˣ��±��ǣ�%d %d\n", x, y);
			return;
		}			
	}
	printf("������\n");
}
int main() {
	int z[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int s;
	scanf("%d", &s);
	a(z,s,3,3);
}