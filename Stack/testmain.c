#include"Stack.h"
//用链表实现栈
int main()
{
	//干活之前要有自己的栈
	LinkStack mystack;
	//有了自己的栈之后需要进行初始化
	LinkStackInt(&mystack);
	//进行数据的插入
	LinkStackEn(&mystack, 1);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 2);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 3);
	LinkStackShow(&mystack);
	LinkStackEn(&mystack, 4);
	LinkStackShow(&mystack);
	printf("当前的栈顶为 %d \n", LinkStackTop(&mystack));
	printf("================================\n");
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackShow(&mystack);
	LinkStackDe(&mystack);
	LinkStackDestroy(&mystack);

	return 0;
}






/*
//用线性表和链表实现栈
//先进后出  或者  后进先出
int main()
{
	//干活之前需要有自己的栈
	SeqStack mystack;
	//有了自己的栈则需要进行初始化
	SeqStackInit(&mystack,0);
	//实现数据存储——先进后出
	SeqStackEn(&mystack, 1);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 2);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 3);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 4);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 5);
	SeqStackShow(&mystack);
	SeqStackEn(&mystack, 6);
	SeqStackShow(&mystack);
	printf("当前的栈顶元素为%d \n", SeqStackTop(&mystack));
	printf("================================\n");
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
	SeqStackDe(&mystack);
	SeqStackShow(&mystack);
}
*/