#include <stdio.h>
#include <ctype.h>
//ģ��ʵ��atoi
#if 1
int my_atoi(char* pr)
{
	if (pr == NULL)
	{
		printf("��������");
		return 0;
	}
	//�����ո�
	while (isspace(*pr))
	{
		pr++;
	}
	//�ж�����
	int sign = 1;
	if (*pr == '-')
	{
		sign = -1;
	}
	if (*pr == '+' || *pr == '-')
	{
		pr++;
	}

	//��ԭÿһλ����
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