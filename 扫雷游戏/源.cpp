#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu(){
	printf("----------------------\n");
	printf("------  1.��ʼ  ------\n");
	printf("------  0.����  ------\n");
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
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (i);
	return 0;
}
