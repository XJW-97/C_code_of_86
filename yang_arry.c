#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
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
				printf("%d ���ڣ�λ��Ϊ (%d , %d) ", num, i, j);
			return 0;
		}
	}
	printf("%d������", num);
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