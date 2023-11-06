#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	printf("-------ɨ����Ϸ-------\n");
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
//������
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
//����ΧһȦ
int GetMineCount(char mine[ROWS][COLS], int x, int y) {
	return (mine[x-1][y] + mine[x][y-1] + mine[x+1][y] + mine[x][y+1] + mine[x-1][y+1] + mine[x+1][y-1] + mine[x+1][y+1] + mine[x-1][y-1]) - 8 * '0';
}
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x,y,win= 10;
	while (win<((row * col) - EASY_COUNT)) {
		printf("����Ҫ���ҵ�λ��");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row && y >= 1 && y <= col)) {
			if (mine[x][y] == '1') {
				printf("ʧ��\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				show[x][y]=GetMineCount(mine,x,y)+'0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else printf("�������\n");
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("�ɹ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}