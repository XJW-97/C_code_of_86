#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//杨辉三角
#if 1
void yanghui_triangle(int num)
{
	int arrdate[100] = { 1 };
	printf("1\n");
	for (int i = 1; i < num; i++)
	{
		for (int j = i; j > 0; j--)//赋值过程
		{
			//1 0 0 0 0 0 0
			//1 1 0 0 0 0 0
		  	//1 2 1 0 0 0 0
			//1 3 3 1 0 0 0
			arrdate[j] += arrdate[j - 1];
		}

		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arrdate[j]);
		}
		printf("\n");
	}

}
int main()
{
	printf("请输入您需要的行数\n");
	int num = 0;
	scanf("%d", &num);
	yanghui_triangle(num);
}

#endif 
//调整数组使奇数全部都位于偶数前面。
#if 0
int main() 
{
	int arr[14] = { 1,2,3,4,5,6,7,8,9,10,12,14,11,13 };
	int* left = arr;
	int* right = arr + sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right)
	{
		if ((*left) % 2 == 1 && (*right) % 2 == 1)
		{
			left++;
		}
		else if ((*left) % 2 == 0 && (*right) % 2 == 0)
		{
			right--;
		}
		else if ((*left) % 2 == 1 && (*right) % 2 == 0)
		{
			left++;
			right--;
		}
		else if ((*left) % 2 == 0 && (*right) % 2 == 1)
		{
			int temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;
		}
	}
	for (int i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


#endif
//模拟实现strcpy函数
#if 0
char* my_strcpy(char * destination ,const char *source)
{
	
	
	char* star = destination;
	while (*star++ = *source++)
	{
		;
	}
	return destination;
}
int main()
{
	char* p ="abcdefg";
	assert(p != NULL);
	char destination[100] = {0};
	my_strcpy(destination,p);
	printf("%s", destination);
}

#endif
//模拟实现strlen函数
#if 0
int my_strlen(const char* p)
{
	char* star = p;
	//int count = 0;
	while (*p++ != '\0')
	{
		;
	//	count++;
	}
	return p - star-1;
	//return count;
}

int main()
{
	char* pr = "abcdefgh";
	int length=my_strlen(pr);
	printf("该字符串长度为%d\n", length);
}

#endif 

#if 0
int main()
{
	printf("请输入你手里有多少钱\n");
	int money = 0;
	scanf("%d",&money);
	int soda = money;
	
    while (money>0&&!(money==1))
	{
		soda += money/2;
		money = money / 2 + money % 2;
	}

	if (money == 1)//最后如果剩下瓶子，则问老板借一个瓶子，换一瓶饮料喝完，把空瓶子还给他
	{
		soda += 1;
	}
	if (money == 0)
	{
		;
	}
	printf("一共喝了%d瓶汽水", soda);
	return 0;
}
#endif