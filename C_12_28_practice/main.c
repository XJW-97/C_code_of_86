#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//找单身狗

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
void find_single(int arr[],int sz)
{
	for (int i = 0; i < sz; i++)
	{
		int index = 1;
		for (int j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j] && i!=j)
			{
				index = 0;
				break;
			}
		}
		if (index)
		{
			printf("单身狗数为:	%d\n",arr[i]);
		}
	}
}
void test()
{
	int arr[] = { 1,2,3,4,5,6,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	find_single(arr,sz);
}
int main()
{
	test();
	return 0;
}