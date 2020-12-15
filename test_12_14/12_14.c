#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//实现一个函数，可以左旋字符串中的k个字符。
#if 0
void circle(char* arr, int times)//字符串旋转函数
{
	//计算当前字符串的长度
	int len = strlen(arr);
	//计算旋转断开的位置
	int pose = times % len;
	//确定不动的后半部分
	char* remain = arr + pose;
	//将不动的后半部分先存放到一个临时的空字符串中
	char temp[100] = { 0 };
	strcpy(temp, remain);
	//将需要旋转的那几个字符拼接到后面
	strncat(temp, arr, pose);
	//将临时存放旋转后的字符串重新拷回去
	strcpy(arr, temp);
}
int compare(char* compared, char* compare)
{
	//计算两个字符串的长度
	int len1=strlen(compare);
	int len2 = strlen(compared);
	if (len1 != len2) 
	{
		return 0;
	}
	for (int i = 0; i < len1; i++)
	{	char* temp = compare;
		circle(temp, i);
		if (0 == strcmp(temp, compared)) {
			return 1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "ASDFG";
	char arr2[] = "asdfg";
	char arr3[] = "DFGAS";
	char arr4[] = "GASDF";
	int result1 = compare(arr1, arr2);
	int result2 = compare(arr1, arr3);
	int result3 = compare(arr2, arr3);
	int result4 = compare(arr1, arr4);
	printf("%d\n%d\n%d\n%d\n", result1, result2, result3,result4);
}

#endif 


//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
#if 1
void circle(char* arr,int times)
{
	//计算当前字符串的长度
	int len = strlen(arr);
	//计算旋转断开的位置
	int pose = times % len;
	//确定不动的后半部分
	char* remain = arr + pose;
	//将不动的后半部分先存放到一个临时的空字符串中
	char temp[100] = { 0 };
	strcpy(temp, remain);
	//将需要旋转的那几个字符拼接到后面
	strncat(temp, arr, pose);
	//将临时存放旋转后的字符串重新拷回去
	strcpy(arr,temp);
}
int main()
{
	char arr[] = "abcdefg";
	printf("请输入您需要旋转的字符长度");
	int n = 0;
	scanf("%d",&n);
	circle(arr, n);
	printf("旋转后的字符串为：%s", arr);
}
#endif
