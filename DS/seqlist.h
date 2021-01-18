#include"sysutil.h"
//�궨��
#define ElemType int 
#define SEQLIST_DEFAULT_SIZE 8
//����˳���
typedef struct Seqlist
{
	ElemType* base;//��������Ҫ������ָ��
	size_t capacity;//��ǰ�Ľṹ������
	size_t size;//��ǰ�洢Ԫ�صĸ���

}Seqlist;
//��������
void SeqlistInit(Seqlist * pst);//��ʼ���ṹ��
void SeqListPushBack(Seqlist* pst, ElemType x);//β�巨
bool IsFull(Seqlist* pst);//����
void SeqListShow(Seqlist* pst);//չʾ���е�����
void SeqListPushFront(Seqlist* pst, ElemType x);//ͷ�巨
int  SeqlistLength(Seqlist* pst);//�ж����Ա���
void SeqlistPopBack(Seqlist* pst);//β��ɾ��
bool IsEmpty(Seqlist* pst);//�жϵ�ǰ�����Ա��Ƿ�Ϊ��
void SeqlistSort(Seqlist* pst);//�������Ա�����
void SeqlistPopFront(Seqlist* pst );//����ͷ��ɾ��
int  SeqlistCapacity(Seqlist* pst);//�ж����Ա������
void SeqlistClear(Seqlist* pst);//�������Ա����
int  SeqlistFind(Seqlist* pst,ElemType x);//����ָ�������ݣ����������±�
void SeqlistDelebyVal(Seqlist* pst, ElemType x);//����ֵ������ɾ�� 
void SeqlistDelebyPos(Seqlist* pst, ElemType p);//���յ�ַ������ɾ��


/*==============================================================*/

//���岿��
void SeqlistInit(Seqlist* pst)//��ʼ���ṹ��
{
	assert(pst);//��������Ƿ�Ϊ��
	pst->base = (ElemType *)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base);//�Ƿ񿪱ٳɹ�
	//��ʼ�������ڴ�ռ�
	memset(pst->base,0,sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}


bool IsFull(Seqlist* pst)
{
	return (pst ->size >=pst->capacity );
}


void SeqListPushBack(Seqlist* pst,ElemType x)//β�巨
{
	assert(pst);
	//����֮ǰ�ж����Ա��Ƿ�����
	if (IsFull(pst))
	{
		printf("���Ա�������%d ����β�����롣\n",x);
		return;
	}
	pst->base[pst->size++] = x;
}


void SeqListShow(Seqlist* pst)
{
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}


void SeqListPushFront(Seqlist* pst, ElemType x)
{
	assert(pst);
	if (IsFull(pst))
	{
		printf("���Ա�������%d ����ͷ�����롣\n", x);
		return;
	}
	for (int i = pst->size; i > 0; i--)
	{
		pst->base[i] = pst->base[i-1];
	}
	pst->base[0] = x;
	pst->size++;
}


int  SeqlistLength(Seqlist* pst)
{
	assert(pst);
	return pst->size;
}


bool IsEmpty(Seqlist* pst)
{
	return (pst->size == 0);
}


void SeqlistPopBack(Seqlist* pst)
{
	assert(pst );
	//β��ɾ��֮ǰ����Ҫ�ж��Ƿ����ݽṹΪ��

	if (IsEmpty(pst))
	{
		printf("��ǰ�����Ա�Ϊ�գ������Խ���ɾ��\n");
		return;
	}
	pst->size--;
}


void SeqlistSort(Seqlist* pst)//�������Ա�����
{
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
		//�жϴ�С
			if (pst->base[j] > pst->base[j + 1])
			{
				ElemType temp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = temp;
			}

		}
	}
}


void SeqlistPopFront(Seqlist* pst)//����ͷ��ɾ��
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("��ǰ���Ա��е�����Ϊ�գ����ܽ���ɾ��\n");
		return;
	}
	for (int i = 1; i < pst->size; i++)
	{
		pst->base[i - 1] = pst->base[i];
	}
	pst->size--;
}

int SeqlistCapacity(Seqlist* pst) 
{
	return(pst->capacity);
}


void SeqlistClear(Seqlist* pst)
{
	pst->size = 0;
}


int SeqlistFind(Seqlist* pst,ElemType x)
{
	for (int i = 0; i < pst->size; i++)
	{
		if (pst->base[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqlistDelebyVal(Seqlist* pst, ElemType x)
{
	//ɾ��֮ǰ�жϵ�ǰ���Ƿ����
	if (SeqlistFind(pst, x) == -1)
	{
		printf("��ǰ�������ڣ��޷�ɾ��\n");
	}
	else
	{
		for (int i = SeqlistFind(pst, x); i < pst->size; i++)
		{
			pst->base[i] = pst->base[i+1];
		}
		pst->size--;
	}
}


void SeqlistDelebyPos(Seqlist* pst, ElemType p)
{
//ɾ��֮ǰ���ж�λ���Ƿ����
	if (p > pst->size - 1|| p < 0)
	{
		printf("�����ַ��С������\n");
	}
	else
	{
		for (int i = p; i < pst->size; i++)
		{
			pst->base[i] = pst->base[i + 1];
		}
		pst->size--;
	}

}