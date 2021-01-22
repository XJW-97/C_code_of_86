#ifndef _DCLIST_H_
#define  _DCLIST_H_

#include "sysutil.h"
//定义自己存储元素的类型
#define ElemType int
//定义自己的双循环结点
typedef struct DCListNode
{
	struct DCListNode* prev;
	struct DCListNode* next;
	ElemType data;

}DCListNode;

//定义自己的有头双循环链表
typedef struct DCList
{
	DCListNode* first;
	DCListNode* last ;
	size_t size;

}DCList;
/////////////////////////////////////////////////////////////
//声明
void DCListInit(DCList* plist);//进行初始化
void DCListPushBack(DCList* plist,ElemType x);//进行尾部插入
void DCListPushFront(DCList* plist,ElemType x);//进行头部插入
void DCListShow(DCList* plist);//进行数据打印
void DCListPushBack(DCList* plist);//进行尾部删除
void DCListPopFront(DCList* plist);//进行头部删除
size_t DCListLength(DCList* plist);//进行数据长度计算
void DCListInvByValu(DCList* plist,ElemType x);//实现按值插入
DCListNode* DCListFind(DCList* plist, ElemType x);//查找输入的数字
void DCListClean(DCList* plist );//实现链表的清除
void DCListDestroy(DCList* plist);//实现链表的摧毁
void DCListDelyValu(DCList* plist, ElemType x);//实现按值删除
void DCListRevers(DCList* plist);//实现链表的转置
void DCListSort(DCList* plist );//实现链表的排序
void DCListRemoveAll(DCList* plist,ElemType x);//删除与给定值相同的所有数据
/////////////////////////////////////////////////////////////
DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s);
	s->data = x;
	s->next = s->next = NULL;
}


void DCListInit(DCList* plist)//进行初始化
{
//首先需要创建一个头节点
	DCListNode* s = _BuyDCListNode(0);
	plist->first = plist->last = s;

	plist->first->prev = plist->last;
	plist->last->next = plist->first;
	plist->size = 0;

}

void DCListPushBack(DCList* plist, ElemType x)//进行尾部插入
{
	assert(plist);
	//生成一个结点，接收当前数据
	DCListNode* s = _BuyDCListNode(x);
	//将当前数据拼接在链表末尾
	s->prev = plist->last;
	plist->last->next = s;
	plist->last = s;
	//将头和尾重新连接起来的过程
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	//添加了一个数据后将size加一
	plist->size++;
}

void DCListPushFront(DCList* plist, ElemType x)//进行头部插入
{
	assert(plist);
	//创建一个结点进行数据接收
	DCListNode* s = _BuyDCListNode(x);
	//将数据添加到头部
	if (plist->first == plist->last)//证明当前只有头节点，没有数据结点
	{
		plist->last = s;
	}
	s->next = plist->first->next;
	plist->first->next->prev = s;

	plist->first->next = s;
	s->prev = plist->first;
	plist->size++;
	
}

void DCListShow(DCList* plist)//打印数据
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if(p==plist->first)
	{
		printf("当前数据为空	");
	}
	while (p!=plist->first)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("over.\n");
}

void DCListPopBack(DCList* plist)//进行尾部删除
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p == plist->first)//证明当前只有头节点，没有数据结点
	{
		printf("当前链表没有可以删除的数据\n");
		return;
	}
	else
	{
		DCListNode* s = plist->last;
		//更改最后一个节点的指向
		plist->last = s->prev;
		//将头和尾连接起来
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		//将数据个数减一
		plist->size--;
	}

}


void DCListPopFront(DCList* plist)//进行头部删除
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p==plist->first)
	{
		printf("当前链表内没有可以删除的数据\n");
		return;
	}
	else 
	{
		if (p->next == plist->first)//证明当前数据只有一个元素,考虑当前的最后节点
		{
			plist->last = plist->first;
			plist->last->next = plist->first;
			plist->first->prev = plist->last;
			free(p);
		}
		else
		{
			plist->first->next = p->next;
			p->next->prev = plist->first;
			free(p);
		}
	}

}


size_t DCListLength(DCList* plist)//计算当前数据的长度
{
	return plist->size;
}

void DCListInvByValu(DCList* plist, ElemType x)//按输入值的大小进行插入
{
	assert(plist);
	//首先用一个节点进行数据接收
	DCListNode* s = _BuyDCListNode(x);
	//用一个结点接收一下头节点的下一个结点
	DCListNode* p;
	p = plist->first->next;
/*	while (p != plist->first && x > p->data)
	{
		p = p->next;
	}
	if (p == plist->first)//两种情况  1. 首先是当前链表没有数据结点  2. 其次是输入数据比当前所有数据都大
	{
		plist->last = s;//将末尾指针指向当前插入的结点
	}
	//开始进行插入
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;

	//plist->first->prev = plist->last;
	//plist->last->next = plist->first;
	plist->size++;
*/

	if (p == plist->first)//当前链表没有数据结点，插入需要考虑尾节点
	{
		plist->last = s;
		s->prev = plist->first;
		plist->first->next = s;

		plist->first->prev = plist->last;
		plist->last->next = plist->first;
	}
	else
	{
		while (p != plist->first && x > p->data)
		{
			p = p->next;
		}
		if (p == plist->first)//输入数据比当前所有数据都大
		{
			plist->last = s;
			s->prev = p->prev;
			p->prev->next = s;
			plist->first->prev = plist->last;
			plist->last->next = plist->first;
		}
		else//意味着输入数据可插入链表内
		{
			s->next = p;
			s->prev = p->prev;

			p->prev = s;
			p->prev->prev->next = s;
		}
	
	}
	plist->size++;

}

DCListNode* DCListFind(DCList* plist, ElemType x)//查找所需的数据
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	while(p != plist->first && p->data != x)
	{
		p = p->next;
	}
	if (p == plist->first)
	{
		return NULL;
	}
	else
	{
		return p;
	}
}

void DCListClean(DCList* plist)//实现链表的清除
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p == plist->first)
	{
		printf("当前链表已空\n");
	}
	else//当前的链表还有数据可以删除
	{
		while (p != plist->first)
		{
			plist->first->next = p->next;
			p->next->prev = plist->first;
			free(p);
			p = plist->first->next;
		}		
		plist->last = p;
		plist->size = 0;
	}
}
void DCListDestroy(DCList* plist)//实现链表的摧毁
{
	assert(plist);
	//首先进行链表的清除
	DCListClean(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	printf("清除完毕，所有功能都将无法使用\n");
	return 0;
}

void DCListDelyValu(DCList* plist, ElemType x)//实现按值删除
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	while (p != plist->first && p->data != x)
	{
		p = p->next;
	}
	if (p == plist->first)
	{
		printf("当前链表没有可删除的数据\n");
		return;
	}
	else
	{
		p->prev->next = p->next;
		p->prev->prev = p->prev;
		free(p);
	}
}

void DCListRevers(DCList* plist)//实现链表的转置
{
	assert(plist);
	DCListNode* p ,*q;
	p= plist->first->next;
	if (p == plist->first || p->next == plist->first)
	{
		printf("当前链表为空或数据个数为1，不需要进行转置\n");
		return;
	}
	else
	{
		q = p->next;
		plist->last = p;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		DCListNode* s = NULL;
		while (q != plist->first)
		{
			s = q;
			q = q->next;
			s->next = plist->first->next;
			s->prev = plist->first;
			plist->first->next = s;
			plist->first->next->prev = s;
		}
	}
}

void DCListSort(DCList* plist)//实现链表的排序
{
	assert(plist);
	DCListNode* p = plist->first->next;
	if (plist->size <= 1)
	{
		printf("当前链表不需要进行排序\n");
		return;
	}
	else
	{
		//先把头节点和第一个数据结点拿下来
		DCListNode* q = p->next;
		plist->last = p;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		//将接下来的数据逐个进行头插
		DCListNode* s = NULL;
		while (q!=plist->first)
		{
			s = q;
			q = q->next;
			DCListNode* h = plist->first->next;
			while (h != plist->first && s->data > h->data)
			{
				h = h->next;
			}
			if (h == plist->first)//进行尾部插入要考虑最后的节点
				plist->last = s;
			//进行数据插入
			s->next = h;
			s->prev = h->prev;
			h->prev->next = s;
			h->prev = s;
		}
	}
}

void DCListRemoveAll(DCList* plist, ElemType x)//删除与给定值相同的所有数据
{
	assert(plist);
	DCListNode* p=plist->
}



/////////////////////////////////////////////////////////////

#endif