#include"tree.h"

int main()
 {
	//���ȴ����Լ������ڵ�
	BinTree bt1;
	//�������Ĵ���1
	//BinTreeCreate_1(&bt1);
	//�������Ĵ���2
	BinTree bt2=BinTreeCreate_2();
	//�������Ĵ���3
	int i = 0;
	char* s = "ABC##DE##F##G#H##";
	BinTree bt3 = BinTreeCreate_3(s,&i);
	//����ǰ������������ַ�ʽ�������
	//printf("=====================һ=====================\n");
	//printf("VLR:");
	//PreOrder(&bt1);
	//printf("\n");
	//printf("LVR:");
	//InOrder(&bt1);
	//printf("\n");
	//printf("LRV:");
	//PostOrder(&bt1);
	//printf("\n");
	printf("=====================��=====================\n");
	printf("VLR:");
	PreOrder(&bt2);
	printf("\n");
	printf("LVR:");
	InOrder(&bt2);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt2);
	printf("\n");
	printf("=====================��=====================\n");
	printf("VLR:");
	PreOrder(&bt3);
	printf("\n");
	printf("LVR:");
	InOrder(&bt3);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt3);
	printf("\n");

	return 0;
}
