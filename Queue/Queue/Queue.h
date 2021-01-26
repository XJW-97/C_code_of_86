#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"Sysutil.h"
#define QueueElemType int

//用链表实现队列
//首先定义自己的队列结点
typedef struct LinkQueueNode
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;
//定义自己的队列

typedef struct LinkQueue
{
	LinkQueueNode* head;
	struct LinkQueueNode* tail;
}LinkQueue;

//声明
void LinkQueueInit(LinkQueue* pq);//进行队列的初始化
void LinkQueueEn(LinkQueue* pq, QueueElemType x);//进行数据的存入
void LinkQueueDe(LinkQueue* pq);//进行数据的删除
void LinkQueueShow(LinkQueue* pq);//进行数据的打印
QueueElemType LinkQueueFront(LinkQueue* pq);//返回队列尾部数据
QueueElemType LinkQueueBack(LinkQueue* pq);//返回队列尾部数据
void LinkQueueDestory(LinkQueue* pq);//进行队列的清除
///////////////////////////////////////////////////////////
//定义
void LinkQueueInit(LinkQueue* pq)//进行队列的初始化
{
	pq->head = pq->tail = NULL;
}
void LinkQueueEn(LinkQueue* pq, QueueElemType  x)//进行数据的存入
{
	assert(pq);
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	s->data = x;
	s->next = NULL;
	if (pq->head == NULL)//空队列
	{
		pq->head = pq->tail = s;
	}
	else
	{
		pq->tail->next = s;
		pq->tail = s;
	}
}
void LinkQueueDe(LinkQueue* pq)//进行数据的删除
{
	assert(pq);
	if (pq->head == NULL)
	{
		printf("当前队列没有可以删除的数据\n");
		return;
	}
	else
	{
		LinkQueueNode* p = pq->head;
		pq->head = pq->head->next;
		if (pq->head == NULL)
			pq->tail = NULL;
		free(p);
		p = NULL;
	}
}

void LinkQueueShow(LinkQueue* pq)//进行数据的打印
{
	assert(pq);
	if (pq->head==NULL)
	{
		printf("当前队列没有可打印的数据\n");
		return;
	}
	else 
	{
		LinkQueueNode* p = pq->head;
		while (p != NULL)
		{
			printf("%d<-", p->data);
			p = p->next;
		}
		printf("over. \n");
	}
}

QueueElemType LinkQueueFront(LinkQueue* pq)//返回队列头部数据
{
	assert(pq && pq->head);
	return(pq->head->data);
}


QueueElemType LinkQueueBack(LinkQueue* pq)//返回队列尾部数据
{
	assert(pq && pq->head);
	return(pq->tail->data);
}
void LinkQueueDestroy(LinkQueue* pq)//进行队列的清除
{
	assert(pq);

	while (pq->head != NULL)
	{
		LinkQueueNode* p = pq->head;
		pq->head = pq->head->next;
		free(p);
		p = NULL;
	}
	pq->tail = NULL;
}



//////////////////////////用循环线性表实现队列////////////////////////////////////
#define DEFAULT_QUEUE_SIZE 8

//定义自己的队列
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int first;
	int tail;

}SeqQueue;

//声明部分
void SeqQueueInit(SeqQueue* ps);//进行初始化
void SeqQueueEn(SeqQueue* ps, QueueElemType x);//进行数据存储
void SeqQueueDe(SeqQueue* ps);//进行数据删除
void SeqQueueShow(SeqQueue* ps);//进行数据打印
QueueElemType SeqQueueBack(SeqQueue* pq);//返回队列尾部
QueueElemType SeqQueueFront(SeqQueue* pq);//返回队列头部
void SeqQueueDestroy(SeqQueue* pq);//队列清除



///////////////////////////////
//定义部分
void SeqQueueInit(SeqQueue* ps)//进行初始化
{
	assert(ps);
	ps->capacity = DEFAULT_QUEUE_SIZE;
	ps->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (DEFAULT_QUEUE_SIZE + 1));
	ps->first = ps->tail = 0;
}
void SeqQueueEn(SeqQueue* ps, QueueElemType x)//进行数据存储
{
	assert(ps);
	if ((ps->tail+1)%(ps->capacity+1) == ps->first)
	{
		printf("当前队列已满，%d 无法继续插入\n",x);
		return;
	}
	ps->base[ps->tail] = x;
	//更改tail的值
	ps->tail = (ps->tail + 1) % (ps->capacity + 1);
}
void SeqQueueDe(SeqQueue* ps)//进行数据删除
{
	if (ps->first == ps->tail)
	{
		printf("当前队列中没有可以删除的元素\n");
		return;
	}
	ps->first=(ps->first+1)%(ps->capacity+1);
}
void SeqQueueShow(SeqQueue* ps)//进行数据打印
{
	for (int i = ps->first;i!=ps->tail;)
	{
		printf("%d<-", ps->base[i]);
		i = (i + 1) % (ps->capacity + 1);
	}
	printf("over.\n");
}
void SeqQueueDestroy(SeqQueue* pq)//队列清除
{
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->first = pq->tail = 0;
}
QueueElemType SeqQueueBack(SeqQueue* pq)//返回队列尾部
{
	assert(pq && pq->first != pq->tail);
	//考虑到尾部下标需要-1的操作，防止出现负值
	return ( pq->base[(pq->tail - 1 + pq->capacity + 1) % (pq->capacity + 1)]);
}


QueueElemType SeqQueueFront(SeqQueue* pq)//返回队列头部
{
	assert(pq && pq->first != pq->tail);
	return (pq->base[pq->first]);
}













/*
//用线性表实现队列
#define DEFAULT_QUEUE_SIZE 8

//定义自己的队列
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int first;
	int tail;

}SeqQueue;

//声明部分
void SeqQueueInit(SeqQueue* ps);//进行初始化
void SeqQueueEn(SeqQueue* ps,QueueElemType x);//进行数据存储
void SeqQueueDe(SeqQueue* ps);//进行数据删除
void SeqQueueShow(SeqQueue* ps);//进行数据打印
QueueElemType SeqQueueBack(SeqQueue* pq);//返回队列尾部
QueueElemType SeqQueueFront(SeqQueue* pq);//返回队列头部
void SeqQueueDestroy(SeqQueue* pq);//队列清除



///////////////////////////////
//定义部分
void SeqQueueInit(SeqQueue* ps)//进行初始化
{
	assert(ps);
	ps->capacity = DEFAULT_QUEUE_SIZE;
	ps->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (DEFAULT_QUEUE_SIZE ));
	ps->first = ps->tail = 0;
}
void SeqQueueEn(SeqQueue* ps, QueueElemType x)//进行数据存储
{
	assert(ps);
	if (ps->tail >= ps->capacity)
	{
		printf("当前队列已满，无法继续插入\n");
		return;
	}
	ps->base[ps->tail++] = x;
}
void SeqQueueDe(SeqQueue* ps)//进行数据删除
{
	if (ps->first==ps->tail)
	{
		printf("当前队列中没有可以删除的元素\n");
		return;
	}
	ps->first++;
}
void SeqQueueShow(SeqQueue* ps)//进行数据打印
{
	for (int i=ps->first;i<ps->tail;i++)
	{
		printf("%d<-",ps->base[i]);
	}
	printf("over.\n");
}
void SeqQueueDestroy(SeqQueue* pq)//队列清除
{
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->first = pq->tail = 0;
}
QueueElemType SeqQueueBack(SeqQueue* pq)//返回队列尾部
{
	assert(pq && pq->first!=pq->tail);
	return (pq->base[pq->tail-1]);
}


QueueElemType SeqQueueFront(SeqQueue* pq)//返回队列头部
{
	assert(pq && pq->first != pq->tail);
	return (pq->base[pq->first]);
}

*/





#endif // /*_QUEUE_H_*/

