#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//дһ���꣬���Խ�һ�������ֵ�����λ��ż��λ������
#if 0
#define change_even_odd(num) ((num&0xaaaaaaaa)>>1)|((num&0x55555555)<<1)

int main()
{
	int num = 0xaaaaaaaa;
	int ret=change_even_odd(num);
	printf("�����: %x", ret);
}
#endif

//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��

#if 1
#include<stdlib.h>

#define offset_of_first(StructType,MemberName) (size_t)&( ((StructType *)0)->MemberName)

typedef struct 
	{
		char sex;
		int age;
		char name[20];
		char number[20];
	}S;

int main()
{
	printf("ƫ����Ϊ%d\n", offset_of_first(S, sex));
	printf("ƫ����Ϊ%d\n",offset_of_first(S, age));
	printf("ƫ����Ϊ%d\n", offset_of_first(S, name));
	printf("ƫ����Ϊ%d\n", offset_of_first(S, number));
	return 0;
}
#endif