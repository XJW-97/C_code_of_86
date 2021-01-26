#include "Queue.h"

//用循环线性表实现队列
int main()
{
	//干活之前，需要有自己的队列
	SeqQueue myqueue;
	//有了自己的队列需要进行初始化
	SeqQueueInit(&myqueue);
	//初始化完成之后需要进行赋值
	SeqQueueEn(&myqueue, 1);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 2);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 3);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 4);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 5);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 6);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 7);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 8);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 9);
	SeqQueueEn(&myqueue, 10);
	printf("返回头部数据为%d \n", SeqQueueFront(&myqueue));
	printf("返回尾部数据为%d \n", SeqQueueBack(&myqueue));
	printf("==========================================\n");
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 9);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 10);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueDestroy(&myqueue);
	return 0;
}




/*
//用线性表实现队列
int main()
{
	//干活之前，需要有自己的队列
	SeqQueue myqueue;
	//有了自己的队列需要进行初始化
	SeqQueueInit(&myqueue);
	//初始化完成之后需要进行赋值
	SeqQueueEn(&myqueue, 1);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 2);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 3);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 4);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 5);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 6);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 7);
	SeqQueueShow(&myqueue);
	SeqQueueEn(&myqueue, 8);
	SeqQueueShow(&myqueue);
	printf("返回头部数据为%d \n", SeqQueueFront(&myqueue));
	printf("返回尾部数据为%d \n", SeqQueueBack(&myqueue));
	printf("==========================================\n");
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueShow(&myqueue);
	SeqQueueDe(&myqueue);
	SeqQueueDestroy(&myqueue);
	return 0;
}

*/

/*
//用链表实现
int main()
{
	//首先要有自己的队列
	LinkQueue myqueue;
	//有了自己的队列后进行初始化
	LinkQueueInit(&myqueue);
	//添加数据
	LinkQueueEn(&myqueue, 1);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 2);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 3);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 4);
	LinkQueueShow(&myqueue);
	LinkQueueEn(&myqueue, 5);
	LinkQueueShow(&myqueue);
	printf("====================================================\n");
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);//出队(相当于删除一个数据)
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);
	LinkQueueDe(&myqueue);
	LinkQueueShow(&myqueue);

	return 0;
}*/