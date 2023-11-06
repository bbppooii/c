#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	printf("-------扫雷游戏-------\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf("%d ",i);
		for (int j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//布置雷
void SetMine(char board[ROWS][COLS], int row, int col) {
	int c = EASY_COUNT;
	while (c){
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			c--;
		}
	} 
}
//查周围一圈
int GetMineCount(char mine[ROWS][COLS], int x, int y) {
	return (mine[x-1][y] + mine[x][y-1] + mine[x+1][y] + mine[x][y+1] + mine[x-1][y+1] + mine[x+1][y-1] + mine[x+1][y+1] + mine[x-1][y-1]) - 8 * '0';
}
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x,y,win= 10;
	while (win<((row * col) - EASY_COUNT)) {
		printf("输入要查找的位置");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row && y >= 1 && y <= col)) {
			if (mine[x][y] == '1') {
				printf("失败\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				show[x][y]=GetMineCount(mine,x,y)+'0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else printf("输入错误！\n");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}