#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define easy_count 10
#define ROWS  11
#define COLS  11
#define ROW    9
#define COL    9
//��ʼ������
void initial_board(char arr[ROWS][COLS], int rows, int cols, char set);
//��ӡ����
void display_board(char arr[ROWS][COLS], int row, int col);
//����
void set_mine(char arr[ROWS][COLS], int row, int col,int count);
//����
find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//���㵱ǰ�����׵ĸ���
count_mine(char	mine[ROWS][COLS],int x,int y);