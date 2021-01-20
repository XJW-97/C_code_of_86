#ifndef _LIST_H_
#define _LIST_H_

#include "sysutil.h"
//宏定义
#define ElemType int 

//首先定义一个自己的结点
typedef struct SListNode
{
	ElemType data;//数据域
	struct SListNode* next;//指针域
}SListNode;

//定义一个自己的链表
typedef struct SList
{
	SListNode* head;//用一个节点指针代表整个链表
}SList;
/////////////////////////////////////////////////////////////////////
//声明部分
void SLIstInit(SList * plist);//链表初始化
void SListPushBack(SList* plist, ElemType x);//尾插法声明1
void SListPushFront(SList* plist, ElemType x);//头插法声明2
void SListShow(SList* plist);//打印所有的数据3
void SListPopBack(SList* plist);//进行尾部删除4
void SListPopFront(SList* plist);//进行头部删除5
int  SListLength(SList* plist);//计算当前链表的长度6
void SListInsertByVal(SList* plist, ElemType x);//按值插入的声明8
SListNode* SListFind(SList* plist, ElemType x);//按值查找12
void SListDeleteByVal(SList* plist, ElemType x);//按值删除10
void SListClear(SList* plist);//进行清除16
void SListReverse(SList* plist);//转置14






////////////////////////////////////////////////////////////////////


//定义部分
void SLIstInit(SList* plist)//初始化的定义
{
	plist->head = NULL;
}

SListNode* _BuyNode()//创建一个节点
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->data = 0;
	s->next = NULL;
}

void SListPushBack(SList* plist, ElemType x)//尾插法的定义
{
	assert(plist);
	SListNode* s = _BuyNode();
	s->data = x;
	//_BuyNode()函数已经将s的next设置为NULL，因此不需要再进行一次置空

	SListNode* p = plist->head;
	if (p==NULL)
	{
		plist->head = s;
	}
	else//尾插法需要找到当前链表的末尾
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void SListPushFront(SList* plist, ElemType x)//头插法定义
{
	assert(plist);
	//首先定义出来一个节点，用来接收要插入的数据
	SListNode* s = _BuyNode();
	s->data = x;
	//定义出来一个节点，用来表示第一个节点
	/*if (plist->head == NULL)
	{
		plist->head = s;
	}
	else
	{
			s->next = plist->head;
			plist->head = s;
	}*/
	//等价于
	s->next = plist->head;
	plist->head = s;
}


void SListShow(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("链表为空，没有可打印的数据\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("over\n");
}

void SListPopBack(SList* plist)//尾部删除
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("没有可以删除的数据\n");
		return ;
	}
	else
	{
		if ((plist->head)->next == NULL)//意味着只有一个节点
		{
			plist->head =NULL;
			//free(plist->head);
		}
		else
		{
			SListNode* pre = NULL;//用来接收尾部节点的前一个节点
			while (p->next!=NULL)//当p->next==NULL 时，p就是最后一个有效节点，pre就是倒数第二个结点
			{
				pre = p;
				p = p->next;
			}
			pre->next = NULL;
			//free(p);
		}
		free(p);
	}
}

void SListPopFront(SList* plist)//进行头部删除
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("当前没有可以删除的数据\n");
		return;
	}
	else
	{
		/*if (p->next == NULL)//代表只有一个节点
		{
			plist->head = NULL;
			free(p);
		}*/
		plist->head = p->next;//多个节点或一个节点
		free(p);
	}
}

int SListLength(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		return 0;
	}
	else
	{
		int num = 1;
		while (p->next!=NULL)
		{
			p = p->next;
			num++;
		}
		return num;
	}
 }

void SListInsertByVal(SList* plist, ElemType x)//按值插入
{
	assert(plist);
	SListNode* s = _BuyNode();
	s->data = x;

	SListNode* p = plist->head;
	if (p == NULL)//当前链表为空
	{
		plist->head = s;
	}
	else//有一个或多个节点
	{
		SListNode* pre = NULL;
		while (p != NULL && p->data < x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//需要进行头插
		{
			s->next = p;
			plist->head = s;
		}
		else
		{
			s->next = p;
			pre->next = s;

		}
	}
}

SListNode* SListFind(SList * plist, ElemType x)
{	
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL && p->data != x)
		p = p->next;
	return p;
	/*while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
	*/
}

void SListDeleteByVal(SList* plist, ElemType x)
{
	assert(plist);
	if (NULL == SListFind(plist, x))
	{
		printf("要删除的值不存在\n");
		return;
	}
	else
	{
		SListNode* pre = NULL;
		SListNode* p = plist->head;
		while (p->data != x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//证明第一个数据就是要删除的数据
		{
			plist->head = p->next;
		}
		else
		{
			pre->next = p->next;
		}
		free(p);
	}
}


void SListClear(SList* plist)//进行删除
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
	printf("删除结束\n");
}

void SListReverse(SList* plist)//转置
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL || p->next == NULL)
	{
		return;
	}
	else
	{
		//拿出第一个数据作头，其他数据取下来一个，进行头插
		p = p->next;
		plist->head->next = NULL;//把头取下来了
		SListNode* q = p;

		while (p != NULL)
		{
			p = p->next;
			q->next = plist->head;
			plist->head = q;
			q = p;
		}
	}
}











#endif 
