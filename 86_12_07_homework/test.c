#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//���ͼ��
#if 1
int main()
{
	printf("�������ӡͼƬ������\n");
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
//ˮ�ɻ���
//1.ȷ��λ��
//2.ȷ��ÿ������
//3.�ж�
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
		//�ж�λ��
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
			printf("��ǰˮ�ɻ���Ϊ��%d \n", i);
		}
	}
	
	return 0;
}
#endif

//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������ ���磺2 + 22 + 222 + 2222 + 22222
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
	printf("������������Ҫ�����ֺͼ���λ��\n");
	int input = 0;
	int time = 0;
	scanf("%d,%d", &input,&time);
	int result = sum(input, time);
	int result1=sum1(input,time);
	printf("������Ϊ��%d\n",result);
	printf("������Ϊ��%d", result1);
	return 0;
}


#endif


//дһ����������������һ���ַ��������ݡ�
#if 0
void revert(char* arr, int size)
{
	char* left = arr;
	char* right = arr + size - 2;//-2Ϊ��ȥһ����\0��,�����㿪ʼ�������
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
	int size = sizeof(arr) / sizeof(arr[0]);//����������ַ�����С
	//int size=strlen(arr)//����������ַ������ȣ��ַ�����С���ַ������ȴ�һ����\0��
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
	printf("��ӡż��λ ");
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
	printf("\n��ӡ����λ ");
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
	printf("������һ�������\n");
	int num = 0;
	scanf("%d",&num);
	printf_even_number(num);
	printf_odd_number(num);
	return 0;
}

#endif
//2��n�η�����
#if 0
int main()
{	printf("����Ҫ2�Ķ��ٴη����㣿\n");
	int n = 0;
	int result = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		result *= 2;
	}
	printf("%d", result);

}


#endif

//����������������������ʱ������

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
//���������������в�ͬλ�ĸ���
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
	printf("��������������\n");
	scanf("%d%d",&a,&b);
	//���Ϊ����������ͬ��Ϊ1
	int result = a ^ b;
	//��һ������1�ĸ���
	int num=number_of_one(result);
	printf("%d", num);
	//printf("%d", number_of_one(32));

}

#endif