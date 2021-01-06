#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//写一个宏，可以将一个整数字的奇数位和偶数位交换。
#if 0
#define change_even_odd(num) ((num&0xaaaaaaaa)>>1)|((num&0x55555555)<<1)

int main()
{
	int num = 0xaaaaaaaa;
	int ret=change_even_odd(num);
	printf("输出是: %x", ret);
}
#endif

//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明

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
	printf("偏移量为%d\n", offset_of_first(S, sex));
	printf("偏移量为%d\n",offset_of_first(S, age));
	printf("偏移量为%d\n", offset_of_first(S, name));
	printf("偏移量为%d\n", offset_of_first(S, number));
	return 0;
}
#endif