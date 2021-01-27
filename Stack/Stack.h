#ifndef _STACK_H_
#define _STACK_H_
#include "Sysutil.h"

#define SeqStackElemtype int
#define SEQSTACK_DEFAULT_SIZE 8
/////////////////////////���Ա��ʾջ//////////////////////////
//�����Լ���ջ
typedef struct SeqStack
{
	SeqStackElemtype* base;
	size_t	capacity;
	int top;

}SeqStack;

//��������
void SeqStackInit(SeqStack* pst,int sz);//����ջ�ĳ�ʼ��
void SeqStackEn(SeqStack* pst, SeqStackElemtype x);//�������ݵ�����
void SeqStackDe(SeqStack* pst);//�������ݵ�ɾ��
void SeqStackShow(SeqStack* pst);//�������ݵĴ�ӡ
SeqStackElemtype SeqStackTop(SeqStack* pst);//�鿴ջ����Ԫ��
void SeqStackDestory(SeqStack* pst);//����ջ��ɾ��
///////////////////////////////////////////////

//���岿��
bool _IsFull(SeqStack* pst)//�жϵ�ǰ��ջ�Ƿ�Ϊ��
{
	return pst->top >= pst->capacity;
}
bool _IsEmpty(SeqStack* pst)
{
	return pst->top == 0;
}
void SeqStackInit(SeqStack* pst,int sz)//����ջ�ĳ�ʼ��
{
	assert(pst);
	pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
	pst->base = (SeqStackElemtype*)malloc(sizeof(SeqStackElemtype)*pst->capacity);
	//�鿴�ռ��Ƿ񿪱ٳɹ�
	assert(pst->base);
	pst->top = 0;
}
void SeqStackEn(SeqStack* pst, SeqStackElemtype x)//�������ݵ�����
{
	assert(pst);
	if (_IsFull(pst))
	{
		printf("ջ�������޷��洢\n");
		return;
	}
	//��������������㣬��ʵ���˷��أ���֮���е��µĴ���
		pst->base[pst->top++] = x;
}

void SeqStackDe(SeqStack* pst)//�������ݵ�ɾ��
{
	assert(pst);
	if (_IsEmpty(pst))
	{
		printf("��ǰ�����ݿɹ�ɾ��\n");
		return;
	}
	pst->top--;
}

void SeqStackShow(SeqStack* pst)//�������ݵĴ�ӡ
{
	assert(pst);
	if (pst->top == 0)
		printf("��ǰ�����ݿɹ���ӡ\n");
	else
	{
		for (int i = pst->top-1 ; i >= 0; i--)
		{
			printf("%d<-",pst->base[i]);
		}
		printf("over.\n");
	}
}
SeqStackElemtype SeqStackTop(SeqStack* pst)//�鿴ջ����Ԫ��
{
	assert(pst && !_IsEmpty(pst));
	return pst->base[pst->top - 1];
}
void SeqStackDestory(SeqStack* pst)//����ջ��ɾ��
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}










/////////////////////////�����ʾջ//////////////////////////
#define LinkStackElemtype int
//�����Լ���ջ���
typedef struct LinkStackNode
{
	LinkStackElemtype data;
	struct LinkStackNode* next;
}LinkStackNode;

//�����Լ���ջ
typedef struct LinkStack
{
	LinkStackNode* head;
}LinkStack;

//����
void LinkStackInt(LinkStack* pst);//���г�ʼ��
void LinkStackEn(LinkStack*pst,LinkStackElemtype x);//�������ݵĲ���
void LinkStackDe(LinkStack* pst);//�������ݵ�ɾ��
LinkStackElemtype LinkStackTop(LinkStack* pst);//����ջ������
void LinkStackShow(LinkStack* pst);//�������ݴ�ӡ
void LinkStackDestroy(LinkStack* pst);//����ջ�����



//////////////////////////////////////////////////////////////////////////////


//����
void LinkStackInt(LinkStack* pst)//���г�ʼ��
{
	assert(pst);
	pst->head = NULL;
}
void LinkStackEn(LinkStack* pst, LinkStackElemtype x)//�������ݵĲ���
{
	assert(pst);
	LinkStackNode* s = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(s);
	s->data = x;
	s->next = NULL;
	s->next = pst->head;
	pst->head = s;
}
void LinkStackDe(LinkStack* pst)//�������ݵ�ɾ��
{
	assert(pst);
	//ɾ��֮ǰ�ж��Ƿ�Ϊ��
	LinkStackNode* p = pst->head;
	if (p == NULL)
	{
		printf("��ǰջ��û�п�ɾ��������\n");
		return;
	}
	pst->head = p->next;
	free(p);
	p = NULL;
}
LinkStackElemtype LinkStackTop(LinkStack* pst)//����ջ������
{
	assert(pst && pst->head);
	return (pst->head->data);
}
void LinkStackShow(LinkStack* pst)//�������ݴ�ӡ
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
void LinkStackDestroy(LinkStack* pst)//����ջ�����
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
