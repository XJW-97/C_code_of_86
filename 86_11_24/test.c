#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值
int main() {
	float sum = 0;
	
	for (int i = 1; i <= 100; i++) {
		if (i % 2 == 0) {
			sum+=(1/(float)i);
		}
		else {
			sum-= (float)(1/ (float)i);
		}
		
	}
	printf("%f  ",sum);
}




//1-100中9出现的个数
//int main() {
//	int index = 0;
//	for (int i = 1; i <= 100; i++) {
//		if (i % 10 == 9||(i/10)%10==9) {
//			index++;
//		}
//	
//	}
//	printf("%d  ",index);
//}




//int main() {
//	printf("1	不是素数也不是合数\n");
//	printf("2	是素数\n");
//	for (int i = 3; i <= 100; i++) {
//		int index = 1;
//		for (int j = 2; j <=((i / 2)+1); j++) {
//			if ((i % j )== 0) {
//				index = 0;
//				break;
//			}
//		}
//		if (index) {
//			printf("%d	是素数\n",i);
//		}
//	}
//	system("pause");
//	return 0;
//}

//求闰年和世纪闰年
//int main() {
//	for (int i = 1000;i <= 2000; i++){
//		if ((i % 4 == 0) && (i % 100 != 0)) {
//			printf("%d是普通闰年\n", i);
//		}
//		if (i%400==0) {
//			printf("%d	是世纪闰年\n",i);
//		}
//	}
//	system("pause");
//	return 0;
//}

//求两个数的最大公因数
/*int x = 0;
int commonDivisor(int a, int b) 
{
	
	while (a) {
		if (a > b) {
			a = a-b;
		}
		else if(b>a){
			b= b-a;
		}
		else {
			return a;
		}

	}

}

int commonDivisor2(int a, int b)
{
	int temp = 2;
	x++;
		if (a > b) {
			int temp = a-b;
			if (temp == 0) {
				return a;
			}
			else if (temp == 1) {
				return 1;
			}
			else {
				commonDivisor2(temp, b);
			}
		}
		else{
			int temp = b-a;
			if(temp==0) {
			return a;
			}
			else if (temp == 1) {
			return 1;
			}
			else {
				commonDivisor2(temp, a);
			}
		}
		
	

}

int commonDivisor3(int a, int b) {
	x++;
	if (a > b) {
		if (b == 1) {
			return b;
		}
		commonDivisor3(a - b, b);
	}
	else if(b>a){
		if (a == 1) {
			return a;
		}
		commonDivisor3(b-a, a);
	}
	else {
		
		return a;

	}
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数字：");
	scanf("%d ,%d", &a ,&b);
	printf("%d ,%d\n", a,b);
	if (a == 0 || b == 0) {
		printf("输入的数字有零，请您重新输入");
	}
	else {
		int c = commonDivisor3(a, b);
		printf("x=%d\n", x);
		printf("最大公因数：%d ", c);
	}
	system("pause");
	return 0;*/


	//打印从1-100中所有3的倍数
	//for (int i = 1; i <= 100; i++) {
	//	if (i % 3 == 0) {
	//		printf("%d ",i);
	//	}
	//}
	//system("pause");
	//return 0;
	

	//三个数，按从大到小排列
	//int a = 0, b = 0, c = 0;
	//printf("请输入三个数字\n");
	//scanf("%d，%d, %d", &a,&b,&c);
	//if (a > b && a > c) {
	//	printf("%d	,", a);
	//		if (b > c) {
	//			printf("%d	,%d", b, c);
	//		}
	//		else {
	//			printf("%d	,%d", c, b);
	//		}
	//}
	//else if (b > a && b > c) {
	//	printf("%d	,", b);
	//		if (a > c) {
	//			printf("%d	,%d", a, c);
	//	}
	//		else {
	//			printf("%d	,%d", c, a);
	//	}
	//}
	//else if (c > a && c > b) {
	//	printf("%d	,",c);
	//	if (a > b) {
	//		printf("%d	,%d", a, b);
	//	}
	//	else {
	//		printf("%d	,%d", b, a);
	//	}
	//}
	//system("pause");
	//return 0;


	//求两个数中的最大值
	//int a = 0;
	//int b = 0;
	//printf("请输入两个数字\n");	
	//scanf("%d", &a);
	//scanf("%d", &b);
	//int c=(a > b )? a : b;
	//printf("两个数中的最大值为：%d", c);

//}