#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ҵ���

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
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
			printf("������Ϊ:	%d\n",arr[i]);
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