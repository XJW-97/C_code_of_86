#ifndef _DCLIST_H_
#define  _DCLIST_H_

#include "sysutil.h"
//�����Լ��洢Ԫ�ص�����
#define ElemType int
//�����Լ���˫ѭ�����
typedef struct DCListNode
{
	struct DCListNode* prev;
	struct DCListNode* next;
	ElemType data;

}DCListNode;

//�����Լ�����ͷ˫ѭ������
typedef struct DCList
{
	DCListNode* first;
	DCListNode* last ;
	size_t size;

}DCList;
/////////////////////////////////////////////////////////////
//����
void DCListInit(DCList* plist);//���г�ʼ��
void DCListPushBack(DCList* plist,ElemType x);//����β������
void DCListPushFront(DCList* plist,ElemType x);//����ͷ������
void DCListShow(DCList* plist);//�������ݴ�ӡ
void DCListPushBack(DCList* plist);//����β��ɾ��
void DCListPopFront(DCList* plist);//����ͷ��ɾ��
size_t DCListLength(DCList* plist);//�������ݳ��ȼ���
void DCListInvByValu(DCList* plist,ElemType x);//ʵ�ְ�ֵ����
DCListNode* DCListFind(DCList* plist, ElemType x);//�������������
void DCListClean(DCList* plist );//ʵ����������
void DCListDestroy(DCList* plist);//ʵ������Ĵݻ�
void DCListDelyValu(DCList* plist, ElemType x);//ʵ�ְ�ֵɾ��
void DCListRevers(DCList* plist);//ʵ�������ת��
void DCListSort(DCList* plist );//ʵ�����������
void DCListRemoveAll(DCList* plist,ElemType x);//ɾ�������ֵ��ͬ����������
/////////////////////////////////////////////////////////////
DCListNode* _BuyDCListNode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s);
	s->data = x;
	s->next = s->next = NULL;
}


void DCListInit(DCList* plist)//���г�ʼ��
{
//������Ҫ����һ��ͷ�ڵ�
	DCListNode* s = _BuyDCListNode(0);
	plist->first = plist->last = s;

	plist->first->prev = plist->last;
	plist->last->next = plist->first;
	plist->size = 0;

}

void DCListPushBack(DCList* plist, ElemType x)//����β������
{
	assert(plist);
	//����һ����㣬���յ�ǰ����
	DCListNode* s = _BuyDCListNode(x);
	//����ǰ����ƴ��������ĩβ
	s->prev = plist->last;
	plist->last->next = s;
	plist->last = s;
	//��ͷ��β�������������Ĺ���
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	//�����һ�����ݺ�size��һ
	plist->size++;
}

void DCListPushFront(DCList* plist, ElemType x)//����ͷ������
{
	assert(plist);
	//����һ�����������ݽ���
	DCListNode* s = _BuyDCListNode(x);
	//��������ӵ�ͷ��
	if (plist->first == plist->last)//֤����ǰֻ��ͷ�ڵ㣬û�����ݽ��
	{
		plist->last = s;
	}
	s->next = plist->first->next;
	plist->first->next->prev = s;

	plist->first->next = s;
	s->prev = plist->first;
	plist->size++;
	
}

void DCListShow(DCList* plist)//��ӡ����
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if(p==plist->first)
	{
		printf("��ǰ����Ϊ��	");
	}
	while (p!=plist->first)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("over.\n");
}

void DCListPopBack(DCList* plist)//����β��ɾ��
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p == plist->first)//֤����ǰֻ��ͷ�ڵ㣬û�����ݽ��
	{
		printf("��ǰ����û�п���ɾ��������\n");
		return;
	}
	else
	{
		DCListNode* s = plist->last;
		//�������һ���ڵ��ָ��
		plist->last = s->prev;
		//��ͷ��β��������
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		//�����ݸ�����һ
		plist->size--;
	}

}


void DCListPopFront(DCList* plist)//����ͷ��ɾ��
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p==plist->first)
	{
		printf("��ǰ������û�п���ɾ��������\n");
		return;
	}
	else 
	{
		if (p->next == plist->first)//֤����ǰ����ֻ��һ��Ԫ��,���ǵ�ǰ�����ڵ�
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


size_t DCListLength(DCList* plist)//���㵱ǰ���ݵĳ���
{
	return plist->size;
}

void DCListInvByValu(DCList* plist, ElemType x)//������ֵ�Ĵ�С���в���
{
	assert(plist);
	//������һ���ڵ�������ݽ���
	DCListNode* s = _BuyDCListNode(x);
	//��һ��������һ��ͷ�ڵ����һ�����
	DCListNode* p;
	p = plist->first->next;
/*	while (p != plist->first && x > p->data)
	{
		p = p->next;
	}
	if (p == plist->first)//�������  1. �����ǵ�ǰ����û�����ݽ��  2. ������������ݱȵ�ǰ�������ݶ���
	{
		plist->last = s;//��ĩβָ��ָ��ǰ����Ľ��
	}
	//��ʼ���в���
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;

	//plist->first->prev = plist->last;
	//plist->last->next = plist->first;
	plist->size++;
*/

	if (p == plist->first)//��ǰ����û�����ݽ�㣬������Ҫ����β�ڵ�
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
		if (p == plist->first)//�������ݱȵ�ǰ�������ݶ���
		{
			plist->last = s;
			s->prev = p->prev;
			p->prev->next = s;
			plist->first->prev = plist->last;
			plist->last->next = plist->first;
		}
		else//��ζ���������ݿɲ���������
		{
			s->next = p;
			s->prev = p->prev;

			p->prev = s;
			p->prev->prev->next = s;
		}
	
	}
	plist->size++;

}

DCListNode* DCListFind(DCList* plist, ElemType x)//�������������
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

void DCListClean(DCList* plist)//ʵ����������
{
	assert(plist);
	DCListNode* p;
	p = plist->first->next;
	if (p == plist->first)
	{
		printf("��ǰ�����ѿ�\n");
	}
	else//��ǰ�����������ݿ���ɾ��
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
void DCListDestroy(DCList* plist)//ʵ������Ĵݻ�
{
	assert(plist);
	//���Ƚ�����������
	DCListClean(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	printf("�����ϣ����й��ܶ����޷�ʹ��\n");
	return 0;
}

void DCListDelyValu(DCList* plist, ElemType x)//ʵ�ְ�ֵɾ��
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
		printf("��ǰ����û�п�ɾ��������\n");
		return;
	}
	else
	{
		p->prev->next = p->next;
		p->prev->prev = p->prev;
		free(p);
	}
}

void DCListRevers(DCList* plist)//ʵ�������ת��
{
	assert(plist);
	DCListNode* p ,*q;
	p= plist->first->next;
	if (p == plist->first || p->next == plist->first)
	{
		printf("��ǰ����Ϊ�ջ����ݸ���Ϊ1������Ҫ����ת��\n");
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

void DCListSort(DCList* plist)//ʵ�����������
{
	assert(plist);
	DCListNode* p = plist->first->next;
	if (plist->size <= 1)
	{
		printf("��ǰ������Ҫ��������\n");
		return;
	}
	else
	{
		//�Ȱ�ͷ�ڵ�͵�һ�����ݽ��������
		DCListNode* q = p->next;
		plist->last = p;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
		//���������������������ͷ��
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
			if (h == plist->first)//����β������Ҫ�������Ľڵ�
				plist->last = s;
			//�������ݲ���
			s->next = h;
			s->prev = h->prev;
			h->prev->next = s;
			h->prev = s;
		}
	}
}

void DCListRemoveAll(DCList* plist, ElemType x)//ɾ�������ֵ��ͬ����������
{
	assert(plist);
	DCListNode* p=plist->
}



/////////////////////////////////////////////////////////////

#endif