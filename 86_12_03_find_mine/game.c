#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void initial_board(char arr[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows ; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = set;
		}
	}
}
void display_board(char arr[ROWS][COLS], int row, int col) {
	for (int i = 0; i <=row; i++) {
		printf("%d ", i);
	} 
	printf("\n");
	for (int i = 1; i <=row; i++) {
		printf("%d ", i);
		for (int j = 1; j <=col; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char arr[ROWS][COLS], int row, int col,int count) {
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (arr[x][y] == '0') {
			arr[x][y] = '1';
			count--;
		}
	}
	printf("布雷结束,请开始游戏\n");
}
count_mine(char	mine[ROWS][COLS], int x, int y) {
	return (mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1]
		+ mine[x - 1][y] + mine[x + 1][y] + mine[x - 1][y - 1]
		+ mine[x][y - 1] + mine[x + 1][y - 1] - 8 * '0');

}
find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = ROW * COL - easy_count;
	while (win) {
		printf("请输入您的输入坐标\n");
		scanf("%d%d", &x, &y);
		//计算当前坐标四周雷的数量
		if (mine[x][y] == '1') {
			printf("游戏结束，您被炸死了\n");
			display_board(mine, ROW, COL);
			break;
		}
		else if ((x > 9) || (x < 1) || (y > 9) || (y < 1)) {
			printf("非法坐标，请重新输入坐标\n");
		}
		else if (show[x][y] != '*') {
			printf("该坐标已被排除，请重新输入坐标\n");
		}
		else if(show[x][y] == '*'){
		int num = count_mine(mine, x, y);
		show[x][y] = num + '0';
		display_board(show, ROW, COL);
		win--;
		}
	}
}