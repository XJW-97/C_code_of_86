#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include"sysutil.h"


//�궨��
#define ElemType int 
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

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
//void SeqlistInsertByVal(Seqlist* pst, ElemType Val,ElemType PosVal);//��ֵ����
void SeqlistInsertByVal(Seqlist* pst, ElemType Val);//��ֵ����
void SeqlistInsertByPos(Seqlist* pst, ElemType Val, ElemType pos);//����ַ����
void SeqlistReverse(Seqlist* pst);//����ת��
void SeqlistRemoveAll(Seqlist* pst, ElemType Val);//ɾ��������ͬ������
int  SeqlistFindBinary(Seqlist* pst, ElemType Val);//���ֲ���
void SeqlistDestroy(Seqlist* pst);//����
/*==============================================================*/

//���岿��

//�»��ߴ����������ֻ�����ڲ�����
bool _Inc(Seqlist* pst)//��������
{
	assert(pst);
	//����ռ�
	ElemType* new_base = (ElemType*)malloc(sizeof(ElemType) * (pst->capacity * 2));
	//�ж��Ƿ���Ч
	if (new_base == NULL)
	{
		printf("����ʧ��\n");
		return false;
	}
	//��������
	memcpy(new_base, pst->base, sizeof(ElemType) * pst->capacity);
	//�ͷžɿռ�
	free(pst->base);
	//����ָ��
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}

/*bool _Inc(Seqlist *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if(new_base == NULL)
	{
		printf("����ʧ��.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}
*/

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


bool IsFull(Seqlist* pst)//�ж��Ƿ�Ϊ��
{
	return (pst ->size >=pst->capacity );
}


void SeqListPushBack(Seqlist* pst,ElemType x)//β�巨
{
	assert(pst);
	//����֮ǰ�ж����Ա��Ƿ�����
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("���Ա�������%d ����β�����롣\n",x);
		return;
	}
	pst->base[pst->size++] = x;
}


void SeqListShow(Seqlist* pst)//��ӡ��������
{
	assert(pst);
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}


void SeqListPushFront(Seqlist* pst, ElemType x)//ͷ�巨
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
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


int  SeqlistLength(Seqlist* pst)//�������Ա���
{
	assert(pst);
	return pst->size;
}


bool IsEmpty(Seqlist* pst)//�ж��Ƿ�Ϊ��
{
	return (pst->size == 0);
}


void SeqlistPopBack(Seqlist* pst)//βɾ��
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

int SeqlistCapacity(Seqlist* pst) //���ص�ǰ���Ա������
{
	return(pst->capacity);
}


void SeqlistClear(Seqlist* pst)//������������
{
	pst->size = 0;
}


int SeqlistFind(Seqlist* pst,ElemType x)//������������
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

void SeqlistDelebyVal(Seqlist* pst, ElemType x)//��ֵɾ������
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


void SeqlistDelebyPos(Seqlist* pst, ElemType p)//����ַɾ������
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


void SeqlistInsertByVal(Seqlist* pst, ElemType Val)//��ֵ��������
{
//����ǰ������
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("��ǰ���Ա��������޷���ɲ���\n");
		return;
	}
	else
	{
		//����֮ǰҪ��֤��ǰ�����Ա��������
		//���Ƚ�������
		SeqlistSort(pst);
		//Ȼ����в���

		for (int i = 0 ; i < pst->size; i++)
		{
			
			if (pst->base[i] > Val )
			{
				for (int j = pst->size; j >i ; j--)
				{
					pst->base[j] = pst->base[j-1];
				}
				pst->base[i] = Val;
				pst->size++;
				break;
			}
			else if (i == pst->size - 1 && pst->base[i] < Val)
			{
				pst->base[pst->size] = Val;
				pst->size++;
			}
		}

	}
}
/*void SeqlistInsertByVal(Seqlist* pst, ElemType Val, ElemType PosVal)//��ֵ����
{
//����֮ǰ�ж����Ա��Ƿ�Ϊ��
	if (IsFull(pst))
	{
		printf("���Ա����������ɲ���\n");
		return;
	}
	else
	{
		for (int i = pst->size; i > SeqlistFind(pst, PosVal); i--)
		{
			pst->base[i] = pst->base[i-1];
		}
		pst->base[SeqlistFind(pst, PosVal)] = Val;
		pst->size++;
	}
}
*/

void SeqlistInsertByPos(Seqlist* pst, ElemType Val, ElemType pos)//����ַ��������
{
//����֮ǰ������
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("���Ա�Ϊ�������ɽ��в���\n");
		return;
	}
//Ȼ���ж������λ���Ƿ����
	if (pos<0 || pos > pst->size - 1)
	{
		printf("�����λ�ò��ڷ�Χ�ڣ�����������\n");
		return;
	}
	else
	{
		for (int i = pst->size ; i > pos ; i--)
		{
			pst->base[i] = pst->base[i - 1];
		}
		pst->base[pos] = Val;
		pst->size++;
	}
}


void SeqlistReverse(Seqlist* pst)//��������ת��
{
	int star, end;
	star = 0;
	end = pst->size - 1;
	while (star < end)
	{
		ElemType temp = pst->base[star];
		pst->base[star] = pst->base[end];
		pst->base[end] = temp;
		star++;
		end--;
	}
}

void SeqlistRemoveAll(Seqlist* pst, ElemType Val)//��ͬ���ݵ���� 
{
	if (SeqlistFind(pst, Val) == -1)
	{
		printf("��ǰ���Ա���û��ָ������\n");
		return;
	}
	else
	{
		for (int i = 0; i < pst->size; i++)
		{
			if (pst->base[i] == Val)
			{
				for (int j = i; j < pst->size; j++)
				{
					pst->base[j] = pst->base[j + 1];
				}
				pst->size--;
				i--;
			}
		}
	}
}

int  SeqlistFindBinary(Seqlist* pst, ElemType Val)//���ֲ���
{
	assert(pst);
	//���Ƚ������򣬱�֤��ǰ����������
	SeqlistSort(pst);
	//���ж��ֲ���
	int star, mid, end;
	star = 0;
	end = pst->size - 1;
	
	while (star <= end)
	{
		mid = (star + end) / 2;
		if (pst->base[mid] == Val)
		{
			return mid;
		}
		else if (pst->base[mid] > Val)
		{
			end = mid-1;
		}
		else if (pst->base[mid] < Val)
		{
			star = mid+1;
		}
	}
	return -1;
}

void SeqlistDestroy(Seqlist* pst)
{
	assert(pst);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

#endif /* _SEQLIST_H_ */