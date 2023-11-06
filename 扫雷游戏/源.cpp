#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu(){
	printf("----------------------\n");
	printf("------  1.开始  ------\n");
	printf("------  0.结束  ------\n");
	printf("----------------------\n");
}
void game() {
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}
int main() {
	int i ;
	srand((unsigned int)time(NULL));
	do{
		menu();
		scanf("%d", &i);
		switch (i){
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (i);
	return 0;
}
