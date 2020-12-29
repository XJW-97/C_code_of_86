#include <stdio.h>
#include <ctype.h>
//模拟实现atoi
#if 1
int my_atoi(char* pr)
{
	if (pr == NULL)
	{
		printf("输入有误");
		return 0;
	}
	//跳过空格
	while (isspace(*pr))
	{
		pr++;
	}
	//判断正负
	int sign = 1;
	if (*pr == '-')
	{
		sign = -1;
	}
	if (*pr == '+' || *pr == '-')
	{
		pr++;
	}

	//还原每一位数字
	int result = 0;
	while (*pr)
	{
		result = result * 10 + *pr - '0';
		pr++;
	}
	int ret = result * sign;
	return ret;
}
int main()
{
	char arr1[] = "123";
	char arr2[] = "-100";
	int ret = my_atoi(arr1) + my_atoi(arr2);
	printf("%d %d %d", my_atoi(arr1), my_atoi(arr2), ret);
	return 0;
}
#endif