#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//ʵ��һ�����������������ַ����е�k���ַ���
#if 0
void circle(char* arr, int times)//�ַ�����ת����
{
	//���㵱ǰ�ַ����ĳ���
	int len = strlen(arr);
	//������ת�Ͽ���λ��
	int pose = times % len;
	//ȷ�������ĺ�벿��
	char* remain = arr + pose;
	//�������ĺ�벿���ȴ�ŵ�һ����ʱ�Ŀ��ַ�����
	char temp[100] = { 0 };
	strcpy(temp, remain);
	//����Ҫ��ת���Ǽ����ַ�ƴ�ӵ�����
	strncat(temp, arr, pose);
	//����ʱ�����ת����ַ������¿���ȥ
	strcpy(arr, temp);
}
int compare(char* compared, char* compare)
{
	//���������ַ����ĳ���
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


//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#if 1
void circle(char* arr,int times)
{
	//���㵱ǰ�ַ����ĳ���
	int len = strlen(arr);
	//������ת�Ͽ���λ��
	int pose = times % len;
	//ȷ�������ĺ�벿��
	char* remain = arr + pose;
	//�������ĺ�벿���ȴ�ŵ�һ����ʱ�Ŀ��ַ�����
	char temp[100] = { 0 };
	strcpy(temp, remain);
	//����Ҫ��ת���Ǽ����ַ�ƴ�ӵ�����
	strncat(temp, arr, pose);
	//����ʱ�����ת����ַ������¿���ȥ
	strcpy(arr,temp);
}
int main()
{
	char arr[] = "abcdefg";
	printf("����������Ҫ��ת���ַ�����");
	int n = 0;
	scanf("%d",&n);
	circle(arr, n);
	printf("��ת����ַ���Ϊ��%s", arr);
}
#endif
