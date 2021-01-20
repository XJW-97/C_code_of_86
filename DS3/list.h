#ifndef _LIST_H_
#define _LIST_H_

#include "sysutil.h"
//�궨��
#define ElemType int 

//���ȶ���һ���Լ��Ľ��
typedef struct SListNode
{
	ElemType data;//������
	struct SListNode* next;//ָ����
}SListNode;

//����һ���Լ�������
typedef struct SList
{
	SListNode* head;//��һ���ڵ�ָ�������������
}SList;
/////////////////////////////////////////////////////////////////////
//��������
void SLIstInit(SList * plist);//�����ʼ��
void SListPushBack(SList* plist, ElemType x);//β�巨����1
void SListPushFront(SList* plist, ElemType x);//ͷ�巨����2
void SListShow(SList* plist);//��ӡ���е�����3
void SListPopBack(SList* plist);//����β��ɾ��4
void SListPopFront(SList* plist);//����ͷ��ɾ��5
int  SListLength(SList* plist);//���㵱ǰ����ĳ���6
void SListInsertByVal(SList* plist, ElemType x);//��ֵ���������8
SListNode* SListFind(SList* plist, ElemType x);//��ֵ����12
void SListDeleteByVal(SList* plist, ElemType x);//��ֵɾ��10
void SListClear(SList* plist);//�������16
void SListReverse(SList* plist);//ת��14






////////////////////////////////////////////////////////////////////


//���岿��
void SLIstInit(SList* plist)//��ʼ���Ķ���
{
	plist->head = NULL;
}

SListNode* _BuyNode()//����һ���ڵ�
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->data = 0;
	s->next = NULL;
}

void SListPushBack(SList* plist, ElemType x)//β�巨�Ķ���
{
	assert(plist);
	SListNode* s = _BuyNode();
	s->data = x;
	//_BuyNode()�����Ѿ���s��next����ΪNULL����˲���Ҫ�ٽ���һ���ÿ�

	SListNode* p = plist->head;
	if (p==NULL)
	{
		plist->head = s;
	}
	else//β�巨��Ҫ�ҵ���ǰ�����ĩβ
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
}

void SListPushFront(SList* plist, ElemType x)//ͷ�巨����
{
	assert(plist);
	//���ȶ������һ���ڵ㣬��������Ҫ���������
	SListNode* s = _BuyNode();
	s->data = x;
	//�������һ���ڵ㣬������ʾ��һ���ڵ�
	/*if (plist->head == NULL)
	{
		plist->head = s;
	}
	else
	{
			s->next = plist->head;
			plist->head = s;
	}*/
	//�ȼ���
	s->next = plist->head;
	plist->head = s;
}


void SListShow(SList* plist)
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("����Ϊ�գ�û�пɴ�ӡ������\n");
		return;
	}
	while (p != NULL)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("over\n");
}

void SListPopBack(SList* plist)//β��ɾ��
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("û�п���ɾ��������\n");
		return ;
	}
	else
	{
		if ((plist->head)->next == NULL)//��ζ��ֻ��һ���ڵ�
		{
			plist->head =NULL;
			//free(plist->head);
		}
		else
		{
			SListNode* pre = NULL;//��������β���ڵ��ǰһ���ڵ�
			while (p->next!=NULL)//��p->next==NULL ʱ��p�������һ����Ч�ڵ㣬pre���ǵ����ڶ������
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

void SListPopFront(SList* plist)//����ͷ��ɾ��
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL)
	{
		printf("��ǰû�п���ɾ��������\n");
		return;
	}
	else
	{
		/*if (p->next == NULL)//����ֻ��һ���ڵ�
		{
			plist->head = NULL;
			free(p);
		}*/
		plist->head = p->next;//����ڵ��һ���ڵ�
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

void SListInsertByVal(SList* plist, ElemType x)//��ֵ����
{
	assert(plist);
	SListNode* s = _BuyNode();
	s->data = x;

	SListNode* p = plist->head;
	if (p == NULL)//��ǰ����Ϊ��
	{
		plist->head = s;
	}
	else//��һ�������ڵ�
	{
		SListNode* pre = NULL;
		while (p != NULL && p->data < x)
		{
			pre = p;
			p = p->next;
		}
		if (pre == NULL)//��Ҫ����ͷ��
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
		printf("Ҫɾ����ֵ������\n");
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
		if (pre == NULL)//֤����һ�����ݾ���Ҫɾ��������
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


void SListClear(SList* plist)//����ɾ��
{
	assert(plist);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
	printf("ɾ������\n");
}

void SListReverse(SList* plist)//ת��
{
	assert(plist);
	SListNode* p = plist->head;
	if (p == NULL || p->next == NULL)
	{
		return;
	}
	else
	{
		//�ó���һ��������ͷ����������ȡ����һ��������ͷ��
		p = p->next;
		plist->head->next = NULL;//��ͷȡ������
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
