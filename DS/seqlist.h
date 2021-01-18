#include"sysutil.h"
//宏定义
#define ElemType int 
#define SEQLIST_DEFAULT_SIZE 8
//构建顺序表
typedef struct Seqlist
{
	ElemType* base;//我们所需要的数据指针
	size_t capacity;//当前的结构体容量
	size_t size;//当前存储元素的个数

}Seqlist;
//声明部分
void SeqlistInit(Seqlist * pst);//初始化结构体
void SeqListPushBack(Seqlist* pst, ElemType x);//尾插法
bool IsFull(Seqlist* pst);//判满
void SeqListShow(Seqlist* pst);//展示所有的数据
void SeqListPushFront(Seqlist* pst, ElemType x);//头插法
int  SeqlistLength(Seqlist* pst);//判断线性表长度
void SeqlistPopBack(Seqlist* pst);//尾部删除
bool IsEmpty(Seqlist* pst);//判断当前的线性表是否为空
void SeqlistSort(Seqlist* pst);//进行线性表排序
void SeqlistPopFront(Seqlist* pst );//进行头部删除
int  SeqlistCapacity(Seqlist* pst);//判断线性表的容量
void SeqlistClear(Seqlist* pst);//进行线性表清除
int  SeqlistFind(Seqlist* pst,ElemType x);//查找指定的数据，并返回其下标
void SeqlistDelebyVal(Seqlist* pst, ElemType x);//按照值来进行删除 
void SeqlistDelebyPos(Seqlist* pst, ElemType p);//按照地址来进行删除


/*==============================================================*/

//定义部分
void SeqlistInit(Seqlist* pst)//初始化结构体
{
	assert(pst);//传入参数是否不为空
	pst->base = (ElemType *)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base);//是否开辟成功
	//初始化整个内存空间
	memset(pst->base,0,sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}


bool IsFull(Seqlist* pst)
{
	return (pst ->size >=pst->capacity );
}


void SeqListPushBack(Seqlist* pst,ElemType x)//尾插法
{
	assert(pst);
	//插入之前判断线性表是否满了
	if (IsFull(pst))
	{
		printf("线性表已满，%d 不能尾部插入。\n",x);
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
		printf("线性表已满，%d 不能头部插入。\n", x);
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
	//尾部删除之前，需要判断是否数据结构为空

	if (IsEmpty(pst))
	{
		printf("当前的线性表为空，不可以进行删除\n");
		return;
	}
	pst->size--;
}


void SeqlistSort(Seqlist* pst)//进行线性表排序
{
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
		//判断大小
			if (pst->base[j] > pst->base[j + 1])
			{
				ElemType temp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = temp;
			}

		}
	}
}


void SeqlistPopFront(Seqlist* pst)//进行头部删除
{
	assert(pst);
	if (IsEmpty(pst))
	{
		printf("当前线性表中的数据为空，不能进行删除\n");
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
	//删除之前判断当前数是否存在
	if (SeqlistFind(pst, x) == -1)
	{
		printf("当前数不存在，无法删除\n");
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
//删除之前先判断位置是否合理
	if (p > pst->size - 1|| p < 0)
	{
		printf("输入地址大小不合理\n");
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