#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//�����Լ���qsort����
//����д����Ϊ�򵥵�ð�������㷨
//����qsort�Ľṹ���������и���
//���������Դ������


//�����ð������
#if 0
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 1; j < sz - i; j++)
		{
			if (arr[j - 1] > arr[j])
			{
				int tem = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tem;

			}
		}
	}
}
int main()
{
	int arr[] = { 8,7,5,9,4,6,3,1,2,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//�õ�Ԫ�ظ���
	print(arr, sz);
	sort(arr, sz);
	print(arr, sz);
}
#endif

//���������qsort
//qsort ģ��
//void qsort(
//			void* base, 
//			size_t num, //Ԫ�ظ���
//			size_t width, //Ԫ�ؿ��
//			int(__cdecl* compare)(const void* elem1, const void* elem2)
//			);
void print(int* arr, size_t sz)//����һ����ӡ����
{
	for (size_t i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int cmp_int(const void* e1, const void* e2)//��ʱ�ıȽϺ�����Ҫ���б�д
{
	return *((int*)e1) - *((int*)e2);
}
void swap(char* e1, char* e2, size_t width)
{
	for (size_t i = 0; i < width; i++)
	{
		char tem = *e1;
		*e1 = *e2;
		*e2 = tem;
		e1++;
		e2++;

	}

}
void my_qsort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2))
{
	for (size_t i = 0; i < num - 1; i++)
		for (size_t j = 1; j < num - i; j++)
		{
			if (cmp((char*)base + (j - 1) * width, (char*)base + j * width) > 0)//�����ǽ�������Ԫ�صĴ�С�жϣ���ʱ���õ���cmp���������������Ĳ�ֵ
			{
				swap((char*)base + (j - 1) * width, (char*)base + j * width, width);
			}

		}
}

void test1()//������������
{
	int arr[] = { 8,7,5,9,4,6,3,1,2,0 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	my_qsort(arr, sz, sizeof(int), cmp_int);
	print(arr, sz);
}
struct Book
{
	char name[20];
	int price;
};
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Book*)e1)->name, ((struct Book*)e2)->name);
}
int cmp_by_price(const void* e1, const void* e2)
{
	return (((struct Book*)e1)->price) - (((struct Book*)e2)->price);
}
void test2()//�ṹ�����
{
	struct Book book[3] = { {"renjianshige",30},{"laorenyuhai",33},{"zuihoudewancan",29} };
	//my_qsort(book, 3, sizeof(struct Book), cmp_by_name);
	my_qsort(book, 3, sizeof(struct Book), cmp_by_price);
}
int main()
{
	test1();//����������Ϊ��������
	//test2();//���ýṹ����Ϊ��������
	return 0;

}