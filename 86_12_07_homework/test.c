#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//输出图形
#if 1
int main()
{
	printf("请输入打印图片的行数\n");
	int row = 0;
	int star = 1;
	scanf("%d",&row);
	int count = 0;
	for (int k = row; row > 0; row -= 2)
	{
		for (int i = 0; i < row / 2; i++)
		{
			printf(" ");
		}
		for (int j = 0; j < star; j++)
		{
			printf("*");
		}
		star += 2;
		for (int i = 0; i < row / 2; i++)
		{
			printf(" ");
		}
		printf("\n");
		count++;
	}
	//printf("%d", count);
	star -= 4;
	for (int i = 1; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (int i = 0; i < star; i++)
		{
			printf("*");
		}
		star -= 2;
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}

#endif
//水仙花数
//1.确定位数
//2.确定每个数字
//3.判断
#if 0
int pow(int number, int times) 
{
	int result = 1;
	for (int i = 0; i < times; i++)
	{
		result *= number;
	}
	return result;
}
int main() 
{
	for (int i = 100; i <= 100000; i++)
	{
		//判断位数
		int count = 1;
		int sum = 0;
		int tem = i;
		while (tem / 10)
		{
			count++;
			tem /= 10;
		}
		
		tem = i;
		for (int j = 0; j < count; j++)
		{
			sum += pow(tem % 10, count);
			tem /= 10;
		}
		if (sum == i) {
			printf("当前水仙花数为：%d \n", i);
		}
	}
	
	return 0;
}
#endif

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字 例如：2 + 22 + 222 + 2222 + 22222
#if 0
int sum(int input,int time)
{
	int x = input;
	int result = input;
	time = time - 1;
	while(time)
	{
	    input = input * 10 + x;
		result +=input;
		time--;
	}
	return result;
}
int sum1(int input, int time)
{
	int tem = 0;
	int sum = 0;
	for (int i = 0; i < time; i++)
	{
		tem = tem * 10 + input;
		sum += tem;
	}
	return sum;
}
int main()
{
	printf("请输入您所需要的数字和计算位数\n");
	int input = 0;
	int time = 0;
	scanf("%d,%d", &input,&time);
	int result = sum(input, time);
	int result1=sum1(input,time);
	printf("计算结果为：%d\n",result);
	printf("计算结果为：%d", result1);
	return 0;
}


#endif


//写一个函数，可以逆序一个字符串的内容。
#if 0
void revert(char* arr, int size)
{
	char* left = arr;
	char* right = arr + size - 2;//-2为减去一个‘\0’,并从零开始计算个数
	while(left<=right)
	{	char temp = *left;
	*left = *right;
	*right = temp;
	left++;
	right--;
	}
}
int main()
{
	char arr[] = "abcdef";
	int size = sizeof(arr) / sizeof(arr[0]);//求出来的是字符串大小
	//int size=strlen(arr)//求出来的是字符串长度，字符串大小比字符串长度大一个“\0”
	revert(arr, size);
	printf("%s", arr);
}
#endif
#if 0
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int* p = arr;
	int i = sizeof(arr)/sizeof(arr[0]);
	while (i)
	{
		printf("%d ", *p);
		p++;
		i--;
	}
	return 0;
}
#endif

#if 0
void printf_even_number(int num)
{
	printf("打印偶数位 ");
	for (int i = 31; i >0; i -= 2) 
	{
		
		if ((num >>i)&1 == 1) {
			printf("%d ", 1);
		}
		else 
		{
			printf("%d ", 0);
		}
	}
}
void printf_odd_number(int num)
{
	printf("\n打印奇数位 ");
	for (int i = 30; i >=0; i -= 2)
	{
		if ((num >> i)&1 == 1) {
			printf("%d ", 1);
		}
		else
		{
			printf("%d ", 0);
		}
	}
}
int main()
{
	printf("请输入一个随机数\n");
	int num = 0;
	scanf("%d",&num);
	printf_even_number(num);
	printf_odd_number(num);
	return 0;
}

#endif
//2的n次方计算
#if 0
int main()
{	printf("您需要2的多少次方计算？\n");
	int n = 0;
	int result = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		result *= 2;
	}
	printf("%d", result);

}


#endif

//交换两个变量（不创建临时变量）

#if 0
int main()
{
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d,%d", a, b);
}
#endif
#if 0
//求两个数二进制中不同位的个数
int number_of_one(int result) 
{
	int count = 0;
	for (int i = 0 ; i < 32; i++)
	{
		int temp = result & 1;
		if (temp == 1) 
		{
			count++;
		}
		result >>= 1 ;
	}
	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数字\n");
	scanf("%d%d",&a,&b);
	//异或为两个数不相同则为1
	int result = a ^ b;
	//求一个数中1的个数
	int num=number_of_one(result);
	printf("%d", num);
	//printf("%d", number_of_one(32));

}

#endif