#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
void find_num(int arr[][3], int row, int col, int num)
{
	int i = 0;//row
	int j = col-1;//col
	while (i < row && j >= 0)
	{
		if (arr[i][j] < num)
		{
			i++;
		}
		else if (arr[i][j] > num)
		{
			j--;
		}
		else
		{
				printf("%d 存在，位置为 (%d , %d) ", num, i, j);
			return 0;
		}
	}
	printf("%d不存在", num);
}
int main()
{
	int arr[][3] = { {1,3,5},
					 {2,4,6},
					 {7,9,11},
					 };
	int num=0;
	scanf("%d", &num);
	find_num(arr, 3, 3, num);
	
	
}