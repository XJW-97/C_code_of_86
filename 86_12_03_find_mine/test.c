#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"

void game() {
	//����������ά�������÷ֱ�Ϊ���׺Ͷ���չʾ
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ���������ӡ����
	initial_board(mine, ROWS, COLS, '0');
	//display_board(mine, ROW, COL);��ʼ���ɹ��˽���ر�
	initial_board(show, ROWS, COLS, '*');
	//display_board(show, ROW, COL);��ʼ���ɹ��˽���ر�
	//����
	set_mine(mine,ROW,COL,easy_count);
	//display_board(mine, ROW, COL);���׳ɹ�����ر�
	//��ӡ��ʼ����չʾ����
	display_board(show, ROW, COL);
	//����
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
		printf("����������ѡ��\n");
		scanf("%d",&index);
		switch (index) {
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ��������ӭ�´μ���\n");
			break;
		default:
			printf("����������\n");
		}
	}

}