#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



#if 0
void cout_multiplication_table(int x) {
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%02d*%02d=%3d	", j, i, j * i);
		}
		printf("\n");
	}
}

int main() {
	int i; 
	printf("请输入9或12：");
	scanf("%d", &i);
	cout_multiplication_table(i);
	system("pause");
	return 0;
}
#endif
#if 0
void swap(int* x, int* y) {
	int c = 0;
	c = *x;
	*x = *y;
	*y = c;
}

int main() {
	int a = 10;
	int b = 20;
	printf("打印前：%d	%d\n",a,b);
	swap(&a, &b);
	printf("打印后：%d	%d",a,b);
	system("pause");
	return 0;
}
#endif
#if 0
int is_leapyear(int x) {
	if (((x % 4 == 0) && (x % 100 != 0))|| (x % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	for (int i = 1000; i <= 2000; i++) {
		if (1 == is_leapyear(i)) {
			printf("%d 是闰年\n",i);
		}
	}
	system("pause");
	return 0;
}

#endif

#if 0
int is_prime(int x) {
	for (int j = 2; j <= (x / 2) + 1; j++) {
		if (x % j == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int count = 0;
	for (int i = 100; i <= 200;i++) {
		if (1 == is_prime(i)) {
			count++;
			printf("%d  ",i);
		}
	}
	printf("\n%d  ", count);
}
#endif



#if 0
int main() {
	int arr[100] = {0};
	for (int i = 0; i < 100; i++) {
		arr[i] = i*2;
	}
	int a = 0; //初始化输入元素
	int i = 1; //(运行条件标识符)
	int left = 0;//左下标
	int right= sizeof(arr) /  sizeof(arr[0]);//右下标
	int index = (right+left)/2;//中间下标（对比数值）
	printf("请输入一个数字：");
	scanf("%d",&a);
	while (i) {
		if (a > arr[index]) {//该数字是否比中间的数大
			left=index;		//将左下标移至中间
			index= (right + left) / 2;//重新计算中间下标
			if ((left + 1 == right) && (a > arr[left] && a < arr[right])) {//判断该数字是否存在
				printf("查无此人");
				i = 0;
			}
		}
		else if(a < arr[index]) {
			right = index;
			index = (right + left) / 2;
			if ((left + 1 == right) && (a > arr[left] && a < arr[right])) {
				printf("查无此人");
				i = 0;
			}
		}
		else {//a=arr[index],找到当前数字，下标为index
			printf("这个数的下标是 %d:", index);
			i = 0;
		}
	}
	
}

#endif
#if 0
//乘法口诀表
int main() {
	for (int i = 1; i < 10; i++) {//输出行
		for (int j = 1; j <= i; j++) {//输出列
			printf("%d*%d=%d\t", j, i, j * i);//打印乘法口诀
		}
		printf("\n");//每行结束需要换行
	}
}
#endif

#if 0
//输入十个数求最大值
//可用scanf完成数组的初始化
int main(){
	printf("请输入10个数字");

	int max = 0;//初始化最大的数字
	int arr[10] = { 0 };//初始化当前的数组
	for (int i = 0; i < 10; i++){//为当前的数组赋值
		scanf("%d", &arr[i]);

	}
	for (int i = 0; i < 10; i++) {//按顺序查找我们所需要的最大数
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("\nthe max number:%d  ", max);
}
#endif