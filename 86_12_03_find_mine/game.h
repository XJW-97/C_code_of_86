#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define easy_count 10
#define ROWS  11
#define COLS  11
#define ROW    9
#define COL    9
//初始化棋盘
void initial_board(char arr[ROWS][COLS], int rows, int cols, char set);
//打印棋盘
void display_board(char arr[ROWS][COLS], int row, int col);
//布雷
void set_mine(char arr[ROWS][COLS], int row, int col,int count);
//排雷
find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//计算当前坐标雷的个数
count_mine(char	mine[ROWS][COLS],int x,int y);