#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"

void game() {
	//生成两个二维数组作用分别为布雷和对外展示
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘与打印棋盘
	initial_board(mine, ROWS, COLS, '0');
	//display_board(mine, ROW, COL);初始化成功了将其关闭
	initial_board(show, ROWS, COLS, '*');
	//display_board(show, ROW, COL);初始化成功了将其关闭
	//布雷
	set_mine(mine,ROW,COL,easy_count);
	//display_board(mine, ROW, COL);布雷成功将其关闭
	//打印初始化的展示棋盘
	display_board(show, ROW, COL);
	//排雷
	find_mine(mine, show, ROW, COL);

}

void manu() {
	printf("***********************\n");
	printf("******* 1.play  *******\n");
	printf("******* 0.exist *******\n");
	printf("***********************\n");
}
int main() {
	srand((unsigned)time(NULL));
	int index = 1;
	while (index)
	{
		manu();
		printf("请输入您的选项\n");
		scanf("%d",&index);
		switch (index) {
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束，欢迎下次继续\n");
			break;
		default:
			printf("请重新输入\n");
		}
	}

}