#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


//������A�е����ݺ�����B�е����ݽ��н�����������һ����
#if 0
void print(int arr[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void change(int arr[], int arr1[], int sz) {
	for (int i = 0; i < sz; i++) {
		int temp = arr[i];
		arr[i] = arr1[i];
		arr1[i] = temp;
	}
	printf("\n");
}
int main() {
	int arr[] = { 1,2,3,4,5,6 };
	int arr1[] = { 6,5,4,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	print(arr1, sz);
	change(arr, arr1, sz);
	print(arr, sz);
	print(arr1, sz);
	return 0;
}
#endif
#if 0
void init(int arr[],int sz){
	for (int i = 0; i < sz; i++) {
		arr[i] = 0;
	}
}
void print(int arr[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
reverse(int arr[], int sz) {
	int* left = arr;
	int* right = arr + sz - 1;
	while (left <= right) {
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

}

int main(){
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	init(arr,sz);
	print(arr,sz);
	return 0;
}
#endif
//ð������
#if 0
int main() {
	int arr[7] = { 2,1,5,8,9,7,6 };
	for (int i = 0; i < 7; i++) {
		for (int j = i+1; j < 7; j++) {
			if (arr[i] > arr[j]) {
				int tem = arr[i];
				arr[i] = arr[j];
				arr[j] = tem;
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		printf("%d",arr[i]);
	}
}
#endif 
//��һ������k�η�
#if 0

int fun(int a, int b) {
	if (b > 0) {
		return  a * fun(a, (b - 1));
	}
	return 1;

}
int main() {
	printf("����������n�Լ�Ҫ��Ĵη���k\n");
	int n = 0;
	int k = 0;
	scanf("%d%d",&n,&k);
	int result = fun(n, k);
	printf("%d��%d�η���:	%d", n, k, result);


}
#endif 

//����һ������ÿλ֮��
#if 0
//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
int DigitSum(int x) {
	if (x > 9) {
		return DigitSum(x / 10)+(x%10);
	}
		return x;
}

int main() {

	printf("������һ�����֣��Ҹ�����������ÿλ��\n");
	int num = 0;
	scanf("%d", &num);
	int result= DigitSum(num);
	printf("�������ÿλ��Ϊ��%d\n",result);
	return 0;
}

#endif

//�ַ�������
#if 0
void reverse_string(char* str) {
	int len = strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);

	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
		reverse_string(str + 1);

	*(str + len - 1) = tmp;
	
}
void reverse_string1(char* str) {
	int len = strlen(str);
	char* left = str;
	char* right= (str + len - 1);
	while (left < right) {
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}

}
int main() {//�ַ������򣨵ݹ�ʵ�֣�
	char p[] = "abcdefg";
	//reverse_string(p);
	reverse_string1(p);
	printf("%s ", p);
	return 0;
}

#endif

//�ݹ�����ַ�������
#if 0
the_number_of_p(char* pr) {
	if (*pr != '\0') {
		return 1+the_number_of_p(pr + 1);
	}
	return 0;
}
the_number_of_p1(char* pr) {//�ǵݹ�
	int count = 0;
	while (*pr) {
		count++;
		pr++;
	}
	return count;
}
int main() {
	char* p = "abcdefghi";
	int num=the_number_of_p(p);
	int num2 = the_number_of_p1(p);
	printf("%d	\n",num );
	printf("%d	", num2);
	return 0;

}
#endif

//ʵ��һ�����Ľ׳�
#if 0
int Factorial(int x) {
	if (x >1) {
		return x*Factorial(x - 1);
	}
	return 1;
}
int Factorial2(int x) {//�ǵݹ�
	int result = 1;
	for (int i = 1; i <= x; i++) {
		result *= i;
	}
	return result;
}
int main() {
	int num = 0;
	printf("��������Ҫ��׳˵�����\n");
	scanf("%d",&num);
	int result = Factorial(num);
	int result2=Factorial2(num);
	printf("Factorial	%d\n",result);
	printf("Factorial2	%d ", result2);
	return 0;
}

#endif

//����1234  ��ӡ1 2 3 4
#if 0
void display(int x) {
	if (x > 9) {
		display(x / 10);
	}
		printf("%d ", x % 10);
}
int main() {
	int num = 0;
	printf("������һ������\n");
	scanf("%d",&num);
	display(num);
	return 0;
}
#endif 

//fib����
#if 0
//int fib(int num) {//�ǵݹ�
//	int arr[100] = {0};
//	arr[0] = 1;
//	arr[1] = 1;
//	for (int i = 2; i <= 99 ; i++) {
//		arr[i] = arr[i - 1] + arr[i - 2];
//	}
//	return arr[num - 1];
//}
int fib1(int num) {//�ݹ�
	if (num > 2) {
		return fib1(num - 1) + fib1(num-2);
	}
	return 1;
}
int main() {
	int n=0;
	printf("����Ҫ�ĵ��ڼ���쳲���������\n");
	scanf("%d",&n);
	//int result=fib(n);
	int result1 = fib1(n);
	//printf("%d\n", result);
	printf("��%d��쳲�������Ϊ��%d",n, result1);
	return 0;
}
#endif

//��������Ϸ
#if 0 
void menu(void) {
	printf("*********************\n");
	printf("**** 1.play 0.end****\n");
	printf("*********************\n");
}
void play_game(void) {
	int random = rand()%100+1;
	int input = 0;
	//printf("%d\n", random);
	printf("please guess this number\n");
	while (1) {
		scanf("%d",&input);
		if (input > random) {
			printf("�´���\n");
		}
		else if (input < random) {
			printf("��С��\n");
		}
		else {
			printf("��ϲ���������¶��ˣ�����\n");
			getchar();//get���ˡ�\n��,��˲���ֹͣ����Ҫ������һ��getchar() 
			getchar();
			//Sleep(3000);
			system("cls");
			break;
		}
		printf("please try again\n");
	}
}
int main() {
	srand((unsigned)time(NULL));
	int index = 0;
	do {
		menu();
		scanf("%d", &index);
		switch (index) {
		case 1:
			printf("Let's play\n");
			play_game();
			break;
		case 0:
			printf("game over\n");
			break;
		default:
			printf("please input again\n");
		}	
	} while (index);
	return 0;
}

#endif