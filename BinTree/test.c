#include"tree.h"

int main()
 {
	//首先创建自己的树节点
	BinTree bt1;
	//进行树的创建1
	//BinTreeCreate_1(&bt1);
	//进行树的创建2
	BinTree bt2=BinTreeCreate_2();
	//进行树的创建3
	int i = 0;
	char* s = "ABC##DE##F##G#H##";
	BinTree bt3 = BinTreeCreate_3(s,&i);
	//进行前序中序后序三种方式进行输出
	//printf("=====================一=====================\n");
	//printf("VLR:");
	//PreOrder(&bt1);
	//printf("\n");
	//printf("LVR:");
	//InOrder(&bt1);
	//printf("\n");
	//printf("LRV:");
	//PostOrder(&bt1);
	//printf("\n");
	printf("=====================二=====================\n");
	printf("VLR:");
	PreOrder(&bt2);
	printf("\n");
	printf("LVR:");
	InOrder(&bt2);
	printf("\n");
	printf("LRV:");
	PostOrder(&bt2);
	printf("\n");
	printf("=====================三=====================\n");
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
