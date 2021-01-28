#include "tree.h"

void main()
{
	BinTree bt = NULL;
	BinTreeCreate(&bt);
	printf("VLR : ");
	PreOrder(bt);
	printf("\n");
	printf("LVR : ");
	InOrder(bt);
	printf("\n");
	printf("LRV : ");
	PostOrder(bt);
	printf("\n");
}