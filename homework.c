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
	printf("������9��12��");
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
	printf("��ӡǰ��%d	%d\n",a,b);
	swap(&a, &b);
	printf("��ӡ��%d	%d",a,b);
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
			printf("%d ������\n",i);
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
	int a = 0; //��ʼ������Ԫ��
	int i = 1; //(����������ʶ��)
	int left = 0;//���±�
	int right= sizeof(arr) /  sizeof(arr[0]);//���±�
	int index = (right+left)/2;//�м��±꣨�Ա���ֵ��
	printf("������һ�����֣�");
	scanf("%d",&a);
	while (i) {
		if (a > arr[index]) {//�������Ƿ���м������
			left=index;		//�����±������м�
			index= (right + left) / 2;//���¼����м��±�
			if ((left + 1 == right) && (a > arr[left] && a < arr[right])) {//�жϸ������Ƿ����
				printf("���޴���");
				i = 0;
			}
		}
		else if(a < arr[index]) {
			right = index;
			index = (right + left) / 2;
			if ((left + 1 == right) && (a > arr[left] && a < arr[right])) {
				printf("���޴���");
				i = 0;
			}
		}
		else {//a=arr[index],�ҵ���ǰ���֣��±�Ϊindex
			printf("��������±��� %d:", index);
			i = 0;
		}
	}
	
}

#endif
#if 0
//�˷��ھ���
int main() {
	for (int i = 1; i < 10; i++) {//�����
		for (int j = 1; j <= i; j++) {//�����
			printf("%d*%d=%d\t", j, i, j * i);//��ӡ�˷��ھ�
		}
		printf("\n");//ÿ�н�����Ҫ����
	}
}
#endif

#if 0
//����ʮ���������ֵ
//����scanf�������ĳ�ʼ��
int main(){
	printf("������10������");

	int max = 0;//��ʼ����������
	int arr[10] = { 0 };//��ʼ����ǰ������
	for (int i = 0; i < 10; i++){//Ϊ��ǰ�����鸳ֵ
		scanf("%d", &arr[i]);

	}
	for (int i = 0; i < 10; i++) {//��˳�������������Ҫ�������
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("\nthe max number:%d  ", max);
}
#endif