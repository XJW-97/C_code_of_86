#ifndef _STACK_H_
#define _STACK_H_
#include "Sysutil.h"

#define SeqStackElemtype int
#define SEQSTACK_DEFAULT_SIZE 8
/////////////////////////线性表表示栈//////////////////////////
//定义自己的栈
typedef struct SeqStack
{
	SeqStackElemtype* base;
	size_t	capacity;
	int top;

}SeqStack;

//声明部分
void SeqStackInit(SeqStack* pst,int sz);//进行栈的初始化
void SeqStackEn(SeqStack* pst, SeqStackElemtype x);//进行数据的输入
void SeqStackDe(SeqStack* pst);//进行数据的删除
void SeqStackShow(SeqStack* pst);//进行数据的打印
SeqStackElemtype SeqStackTop(SeqStack* pst);//查看栈顶的元素
void SeqStackDestory(SeqStack* pst);//进行栈的删除
///////////////////////////////////////////////

//定义部分
bool _IsFull(SeqStack* pst)//判断当前的栈是否为满
{
	return pst->top >= pst->capacity;
}
bool _IsEmpty(SeqStack* pst)
{
	return pst->top == 0;
}
void SeqStackInit(SeqStack* pst,int sz)//进行栈的初始化
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
	pst->base = (SeqStackElemtype*)malloc(sizeof(SeqStackElemtype)*pst->capacity);
	//查看空间是否开辟成功
	assert(pst->base);
	pst->top = 0;
}
void SeqStackEn(SeqStack* pst, SeqStackElemtype x)//进行数据的输入
{
	assert(pst);
	if (_IsFull(pst))
	{
		printf("栈已满，无法存储\n");
		return;
	}
	//如果上述条件满足，则实现了返回，反之进行底下的代码
		pst->base[pst->top++] = x;
}

void SeqStackDe(SeqStack* pst)//进行数据的删除
{
	assert(pst);
	if (_IsEmpty(pst))
	{
		printf("当前无数据可供删除\n");
		return;
	}
	pst->top--;
}

void SeqStackShow(SeqStack* pst)//进行数据的打印
{
	assert(pst);
	if (pst->top == 0)
		printf("当前无数据可供打印\n");
	else
	{
		for (int i = pst->top-1 ; i >= 0; i--)
		{
			printf("%d<-",pst->base[i]);
		}
		printf("over.\n");
	}
}
SeqStackElemtype SeqStackTop(SeqStack* pst)//查看栈顶的元素
{
	assert(pst && !_IsEmpty(pst));
	return pst->base[pst->top - 1];
}
void SeqStackDestory(SeqStack* pst)//进行栈的删除
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}










/////////////////////////链表表示栈//////////////////////////
#define LinkStackElemtype int
//定义自己的栈结点
typedef struct LinkStackNode
{
	LinkStackElemtype data;
	struct LinkStackNode* next;
}LinkStackNode;

//定义自己的栈
typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

//声明
void LinkStackInt(LinkStack* pst);//进行初始化
void LinkStackEn(LinkStack*pst,LinkStackElemtype x);//进行数据的插入
void LinkStackDe(LinkStack* pst);//进行数据的删除
LinkStackElemtype LinkStackTop(LinkStack* pst);//返回栈顶数据
void LinkStackShow(LinkStack* pst);//进行数据打印
void LinkStackDestroy(LinkStack* pst);//进行栈的清除



//////////////////////////////////////////////////////////////////////////////


//定义
void LinkStackInt(LinkStack* pst)//进行初始化
{
	assert(pst);
	pst->head = NULL;
}
void LinkStackEn(LinkStack* pst, LinkStackElemtype x)//进行数据的插入
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s);
	s->data = x;
	s->next = NULL;
	s->next = pst->head;
	pst->head = s;
}
void LinkStackDe(LinkStack* pst)//进行数据的删除
{
	assert(pst);
	//删除之前判断是否为空
	LinkStackNode* p = pst->head;
	if (p == NULL)
	{
		printf("当前栈内没有可删除的数据\n");
		return;
	}
	pst->head = p->next;
	free(p);
	p = NULL;
}
LinkStackElemtype LinkStackTop(LinkStack* pst)//返回栈顶数据
{
	assert(pst && pst->head);
	return (pst->head->data);
}
void LinkStackShow(LinkStack* pst)//进行数据打印
{
	assert(pst);
	LinkStackNode* p = pst->head;
	while (p != NULL)
	{
		printf("%d<-",p->data);
		p = p->next;
	}
	printf("over\n");
}
void LinkStackDestroy(LinkStack* pst)//进行栈的清除
{
	assert(pst);
	while (pst->head != NULL)
	{
		LinkStackNode* p = pst->head;
		pst->head = p->next;
		free(p);
		p = NULL;
	}
}












#endif/*_STACK_H_*/
