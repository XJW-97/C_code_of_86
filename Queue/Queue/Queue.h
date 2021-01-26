#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"Sysutil.h"
#define QueueElemType int

//������ʵ�ֶ���
//���ȶ����Լ��Ķ��н��
typedef struct LinkQueueNode
{
	QueueElemType data;
	struct LinkQueueNode* next;
}LinkQueueNode;
//�����Լ��Ķ���

typedef struct LinkQueue
{
	LinkQueueNode* head;
	struct LinkQueueNode* tail;
}LinkQueue;

//����
void LinkQueueInit(LinkQueue* pq);//���ж��еĳ�ʼ��
void LinkQueueEn(LinkQueue* pq, QueueElemType x);//�������ݵĴ���
void LinkQueueDe(LinkQueue* pq);//�������ݵ�ɾ��
void LinkQueueShow(LinkQueue* pq);//�������ݵĴ�ӡ
QueueElemType LinkQueueFront(LinkQueue* pq);//���ض���β������
QueueElemType LinkQueueBack(LinkQueue* pq);//���ض���β������
void LinkQueueDestory(LinkQueue* pq);//���ж��е����
///////////////////////////////////////////////////////////
//����
void LinkQueueInit(LinkQueue* pq)//���ж��еĳ�ʼ��
{
	pq->head = pq->tail = NULL;
}
void LinkQueueEn(LinkQueue* pq, QueueElemType  x)//�������ݵĴ���
{
	assert(pq);
	LinkQueueNode* s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	s->data = x;
	s->next = NULL;
	if (pq->head == NULL)//�ն���
	{
		pq->head = pq->tail = s;
	}
	else
	{
		pq->tail->next = s;
		pq->tail = s;
	}
}
void LinkQueueDe(LinkQueue* pq)//�������ݵ�ɾ��
{
	assert(pq);
	if (pq->head == NULL)
	{
		printf("��ǰ����û�п���ɾ��������\n");
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

void LinkQueueShow(LinkQueue* pq)//�������ݵĴ�ӡ
{
	assert(pq);
	if (pq->head==NULL)
	{
		printf("��ǰ����û�пɴ�ӡ������\n");
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

QueueElemType LinkQueueFront(LinkQueue* pq)//���ض���ͷ������
{
	assert(pq && pq->head);
	return(pq->head->data);
}


QueueElemType LinkQueueBack(LinkQueue* pq)//���ض���β������
{
	assert(pq && pq->head);
	return(pq->tail->data);
}
void LinkQueueDestroy(LinkQueue* pq)//���ж��е����
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



//////////////////////////��ѭ�����Ա�ʵ�ֶ���////////////////////////////////////
#define DEFAULT_QUEUE_SIZE 8

//�����Լ��Ķ���
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int first;
	int tail;

}SeqQueue;

//��������
void SeqQueueInit(SeqQueue* ps);//���г�ʼ��
void SeqQueueEn(SeqQueue* ps, QueueElemType x);//�������ݴ洢
void SeqQueueDe(SeqQueue* ps);//��������ɾ��
void SeqQueueShow(SeqQueue* ps);//�������ݴ�ӡ
QueueElemType SeqQueueBack(SeqQueue* pq);//���ض���β��
QueueElemType SeqQueueFront(SeqQueue* pq);//���ض���ͷ��
void SeqQueueDestroy(SeqQueue* pq);//�������



///////////////////////////////
//���岿��
void SeqQueueInit(SeqQueue* ps)//���г�ʼ��
{
	assert(ps);
	ps->capacity = DEFAULT_QUEUE_SIZE;
	ps->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (DEFAULT_QUEUE_SIZE + 1));
	ps->first = ps->tail = 0;
}
void SeqQueueEn(SeqQueue* ps, QueueElemType x)//�������ݴ洢
{
	assert(ps);
	if ((ps->tail+1)%(ps->capacity+1) == ps->first)
	{
		printf("��ǰ����������%d �޷���������\n",x);
		return;
	}
	ps->base[ps->tail] = x;
	//����tail��ֵ
	ps->tail = (ps->tail + 1) % (ps->capacity + 1);
}
void SeqQueueDe(SeqQueue* ps)//��������ɾ��
{
	if (ps->first == ps->tail)
	{
		printf("��ǰ������û�п���ɾ����Ԫ��\n");
		return;
	}
	ps->first=(ps->first+1)%(ps->capacity+1);
}
void SeqQueueShow(SeqQueue* ps)//�������ݴ�ӡ
{
	for (int i = ps->first;i!=ps->tail;)
	{
		printf("%d<-", ps->base[i]);
		i = (i + 1) % (ps->capacity + 1);
	}
	printf("over.\n");
}
void SeqQueueDestroy(SeqQueue* pq)//�������
{
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->first = pq->tail = 0;
}
QueueElemType SeqQueueBack(SeqQueue* pq)//���ض���β��
{
	assert(pq && pq->first != pq->tail);
	//���ǵ�β���±���Ҫ-1�Ĳ�������ֹ���ָ�ֵ
	return ( pq->base[(pq->tail - 1 + pq->capacity + 1) % (pq->capacity + 1)]);
}


QueueElemType SeqQueueFront(SeqQueue* pq)//���ض���ͷ��
{
	assert(pq && pq->first != pq->tail);
	return (pq->base[pq->first]);
}













/*
//�����Ա�ʵ�ֶ���
#define DEFAULT_QUEUE_SIZE 8

//�����Լ��Ķ���
typedef struct SeqQueue
{
	QueueElemType* base;
	size_t capacity;
	int first;
	int tail;

}SeqQueue;

//��������
void SeqQueueInit(SeqQueue* ps);//���г�ʼ��
void SeqQueueEn(SeqQueue* ps,QueueElemType x);//�������ݴ洢
void SeqQueueDe(SeqQueue* ps);//��������ɾ��
void SeqQueueShow(SeqQueue* ps);//�������ݴ�ӡ
QueueElemType SeqQueueBack(SeqQueue* pq);//���ض���β��
QueueElemType SeqQueueFront(SeqQueue* pq);//���ض���ͷ��
void SeqQueueDestroy(SeqQueue* pq);//�������



///////////////////////////////
//���岿��
void SeqQueueInit(SeqQueue* ps)//���г�ʼ��
{
	assert(ps);
	ps->capacity = DEFAULT_QUEUE_SIZE;
	ps->base = (QueueElemType*)malloc(sizeof(QueueElemType) * (DEFAULT_QUEUE_SIZE ));
	ps->first = ps->tail = 0;
}
void SeqQueueEn(SeqQueue* ps, QueueElemType x)//�������ݴ洢
{
	assert(ps);
	if (ps->tail >= ps->capacity)
	{
		printf("��ǰ�����������޷���������\n");
		return;
	}
	ps->base[ps->tail++] = x;
}
void SeqQueueDe(SeqQueue* ps)//��������ɾ��
{
	if (ps->first==ps->tail)
	{
		printf("��ǰ������û�п���ɾ����Ԫ��\n");
		return;
	}
	ps->first++;
}
void SeqQueueShow(SeqQueue* ps)//�������ݴ�ӡ
{
	for (int i=ps->first;i<ps->tail;i++)
	{
		printf("%d<-",ps->base[i]);
	}
	printf("over.\n");
}
void SeqQueueDestroy(SeqQueue* pq)//�������
{
	free(pq->base);
	pq->base = NULL;
	pq->capacity = pq->first = pq->tail = 0;
}
QueueElemType SeqQueueBack(SeqQueue* pq)//���ض���β��
{
	assert(pq && pq->first!=pq->tail);
	return (pq->base[pq->tail-1]);
}


QueueElemType SeqQueueFront(SeqQueue* pq)//���ض���ͷ��
{
	assert(pq && pq->first != pq->tail);
	return (pq->base[pq->first]);
}

*/





#endif // /*_QUEUE_H_*/

