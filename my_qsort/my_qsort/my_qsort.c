#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//创建自己的qsort函数
//首先写出最为简单的冒泡排序算法
//根据qsort的结构和作用自行更改
//用两个测试代码调试


//常规的冒泡排序
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
	int sz = sizeof(arr) / sizeof(arr[0]);//得到元素个数
	print(arr, sz);
	sort(arr, sz);
	print(arr, sz);
}
#endif

//创建自身的qsort
//qsort 模板
//void qsort(
//			void* base, 
//			size_t num, //元素个数
//			size_t width, //元素宽度
//			int(__cdecl* compare)(const void* elem1, const void* elem2)
//			);
void print(int* arr, size_t sz)//创建一个打印函数
{
	for (size_t i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int cmp_int(const void* e1, const void* e2)//此时的比较函数需要自行编写
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
			if (cmp((char*)base + (j - 1) * width, (char*)base + j * width) > 0)//这里是进行两个元素的大小判断，此时采用的是cmp函数返回两个数的差值
			{
				swap((char*)base + (j - 1) * width, (char*)base + j * width, width);
			}

		}
}

void test1()//整数测试数据
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
void test2()//结构体测试
{
	struct Book book[3] = { {"renjianshige",30},{"laorenyuhai",33},{"zuihoudewancan",29} };
	//my_qsort(book, 3, sizeof(struct Book), cmp_by_name);
	my_qsort(book, 3, sizeof(struct Book), cmp_by_price);
}
int main()
{
	test1();//采用整数作为测试数据
	//test2();//采用结构体作为测试数据
	return 0;

}