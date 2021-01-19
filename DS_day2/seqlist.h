#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include"sysutil.h"


//宏定义
#define ElemType int 
#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 4

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
//void SeqlistInsertByVal(Seqlist* pst, ElemType Val,ElemType PosVal);//按值插入
void SeqlistInsertByVal(Seqlist* pst, ElemType Val);//按值插入
void SeqlistInsertByPos(Seqlist* pst, ElemType Val, ElemType pos);//按地址插入
void SeqlistReverse(Seqlist* pst);//进行转置
void SeqlistRemoveAll(Seqlist* pst, ElemType Val);//删除所有相同的数据
int  SeqlistFindBinary(Seqlist* pst, ElemType Val);//二分查找
void SeqlistDestroy(Seqlist* pst);//销毁
/*==============================================================*/

//定义部分

//下划线代表这个函数只能是内部函数
bool _Inc(Seqlist* pst)//进行扩容
{
	assert(pst);
	//申请空间
	ElemType* new_base = (ElemType*)malloc(sizeof(ElemType) * (pst->capacity * 2));
	//判断是否有效
	if (new_base == NULL)
	{
		printf("扩容失败\n");
		return false;
	}
	//拷贝数据
	memcpy(new_base, pst->base, sizeof(ElemType) * pst->capacity);
	//释放旧空间
	free(pst->base);
	//重新指向
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}

/*bool _Inc(Seqlist *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQLIST_INC_SIZE));
	if(new_base == NULL)
	{
		printf("扩容失败.\n");
		return false;
	}
	pst->base = new_base;
	pst->capacity += SEQLIST_INC_SIZE;
	return true;
}
*/

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


bool IsFull(Seqlist* pst)//判断是否为空
{
	return (pst ->size >=pst->capacity );
}


void SeqListPushBack(Seqlist* pst,ElemType x)//尾插法
{
	assert(pst);
	//插入之前判断线性表是否满了
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("线性表已满，%d 不能尾部插入。\n",x);
		return;
	}
	pst->base[pst->size++] = x;
}


void SeqListShow(Seqlist* pst)//打印所有数据
{
	assert(pst);
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}


void SeqListPushFront(Seqlist* pst, ElemType x)//头插法
{
	assert(pst);
	if (IsFull(pst) && !_Inc(pst))
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


int  SeqlistLength(Seqlist* pst)//返回线性表长度
{
	assert(pst);
	return pst->size;
}


bool IsEmpty(Seqlist* pst)//判断是否为空
{
	return (pst->size == 0);
}


void SeqlistPopBack(Seqlist* pst)//尾删法
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

int SeqlistCapacity(Seqlist* pst) //返回当前线性表的容量
{
	return(pst->capacity);
}


void SeqlistClear(Seqlist* pst)//进行数据清零
{
	pst->size = 0;
}


int SeqlistFind(Seqlist* pst,ElemType x)//查找所需数据
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

void SeqlistDelebyVal(Seqlist* pst, ElemType x)//按值删除数据
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


void SeqlistDelebyPos(Seqlist* pst, ElemType p)//按地址删除数据
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


void SeqlistInsertByVal(Seqlist* pst, ElemType Val)//按值插入数据
{
//插入前先判满
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("当前线性表已满，无法完成插入\n");
		return;
	}
	else
	{
		//插入之前要保证当前的线性表是有序的
		//首先进行排序
		SeqlistSort(pst);
		//然后进行插入

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
/*void SeqlistInsertByVal(Seqlist* pst, ElemType Val, ElemType PosVal)//按值插入
{
//插入之前判断线性表是否为满
	if (IsFull(pst))
	{
		printf("线性表已满，不可插入\n");
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

void SeqlistInsertByPos(Seqlist* pst, ElemType Val, ElemType pos)//按地址插入数据
{
//插入之前先判满
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("线性表为满，不可进行插入\n");
		return;
	}
//然后判断输入的位置是否合理
	if (pos<0 || pos > pst->size - 1)
	{
		printf("输入的位置不在范围内，请重新输入\n");
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


void SeqlistReverse(Seqlist* pst)//进行数据转置
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

void SeqlistRemoveAll(Seqlist* pst, ElemType Val)//相同数据的清除 
{
	if (SeqlistFind(pst, Val) == -1)
	{
		printf("当前线性表中没有指定数据\n");
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

int  SeqlistFindBinary(Seqlist* pst, ElemType Val)//二分查找
{
	assert(pst);
	//首先进行排序，保证当前的数据有序
	SeqlistSort(pst);
	//进行二分查找
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