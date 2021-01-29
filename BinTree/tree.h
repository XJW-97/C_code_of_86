#ifndef _TREE_H_
#define _TREE_H_
#include"Sysutil.h"

//首先定义树节点的元素类型
#define TreeElemType char
//定义树形结点
typedef struct BinTreeNode
{
	TreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
//定义二叉树
typedef struct BinTreeNode* BinTree;

//声明
void BinTreeCreate_1(BinTree* t);//创建树的声明
BinTree BinTreeCreate_2();
BinTree BinTreeCreate_3(const char* str, int* i);

void PreOrder(BinTree* t);//前序输出
void InOrder(BinTree* t);//中序输出
void PostOrder(BinTree* t);//后序输出

size_t Size(BinTree t);//求节点个数
size_t Height(BinTree t);//求树的高度
BinTreeNode* Find(BinTree t, TreeElemType key);//查找指定节点
BinTreeNode* Parent(BinTree t, BinTreeNode* s);//查找指定节点的父节点


BinTree Clone(BinTree t);//进行树的克隆
bool    Equal(BinTree t1, BinTree t2);//判断两个树是否相等


///////////////////////////
//定义
void BinTreeCreate_1(BinTree* t)//创建树的定义 
//*t只是一个指针，并没有具体的指向某一个空间，因此不能使用*t->data 进行赋值
{
	TreeElemType item;
	scanf("%c",&item);//用来进行接收输入数据
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//将二叉树的指针指向具体的位置 
		assert(*t);
		(*t)->data = item;
		BinTreeCreate_1(&((*t)->leftChild));
		BinTreeCreate_1(&((*t)->rightChild));
	}
}

BinTree BinTreeCreate_2()//创建树的定义2
{
	TreeElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild = BinTreeCreate_2();
		return t;
	}

}


BinTree BinTreeCreate_3(const char* str, int* i)//创建树的定义3
{
	BinTreeNode* new_node;
	if (str[*i] == '#'||str[*i]=='\0')
		return NULL;
	else
	{
		BinTreeNode* new_node;
		new_node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		new_node->data = str[(*i)++];
		new_node->leftChild = BinTreeCreate_3(str, i);
		(*i)++;//当遇到 # 的时候返回 NULL 并没往前走
		new_node->rightChild = BinTreeCreate_3(str, i);
		//不需要(*i)++，因为右边赋值成功后，直接返回根节点即可
		return new_node;
	}
}
void PreOrder(BinTree* t)//前序输出
{
	if ((*t)!=NULL)
	{
		printf("%c",(*t)->data );
		PreOrder(&((*t)->leftChild));
		PreOrder(&((*t)->rightChild));
	}
}

void InOrder(BinTree* t)//中序输出
{
	if ((*t) != NULL)
	{
		InOrder(&((*t)->leftChild));
		printf("%c", (*t)->data);
		InOrder(&((*t)->rightChild));
	}

}
void PostOrder(BinTree* t)//后序输出
{
	if ((*t) != NULL)
	{	
		PostOrder(&((*t)->leftChild));
		PostOrder(&((*t)->rightChild));
		printf("%c", (*t)->data);
	}

}
size_t Size(BinTree t)//求节点个数
{
	if (t == NULL)
		return 0;
	else
		return (Size(t->leftChild) + Size(t->rightChild))+1;
}

size_t Height(BinTree t)//求树的高度
{
	if (t == NULL)
		return 0;
	else
		return (Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) : Height(t->rightChild)) + 1;
}
BinTreeNode* Find(BinTree t, TreeElemType key)//查找指定数据
{
	BinTreeNode* p;
	if (t == NULL)
		return NULL;
	else
	{
		if (t->data == key)
			return t;//表示找到了
		else//没找到，在t的左子列和右子列进行查找
		{
			p = Find(t->leftChild, key);//用临时变量进行接收左边的查找结果
			if (p == NULL)//表示左边没有找到
				return Find(t->rightChild, key);//既然左边没找到，就返回右边的检查结果
			else//此时表示左边找到了，那么不需要进行右边查找，直接进行返回
				return p;
		}
	}
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s)//查找指定节点的父节点
{
	BinTreeNode* p;
	if (t == NULL||t==s)
		return NULL;
	else
	{
		if (t->leftChild == s || t->rightChild == s)
			return t;
		else
		{
			p = Parent(t->leftChild, s);
			if (p != NULL)
				return p;
			return Parent(t->rightChild, s);
		}
	}
}
BinTree Clone(BinTree t)//进行树的克隆	
{
	BinTreeNode* new_node ;
	if (t == NULL)
		return NULL;
	else
	{
		new_node = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(new_node);
		new_node->data = t->data;
		new_node->leftChild = Clone(t->leftChild);
		new_node->rightChild = Clone(t->rightChild);

		return new_node;
	}
}
bool Equal(BinTree t1, BinTree t2)//判断两个树是否相等(两个树的数据是否相等)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	//如果其中一个为空，假设t1为空，无法进行t1->data操作
	//因此还需考虑一个为空一个不为空的情况
	if ( t1==NULL|| t2==NULL )
		return false;
	else
	{
		//if ((t1->data==t2->data)&&Equal(t1->leftChild, t2->leftChild) && Equal(t1->rightChild, t2->rightChild))
		//	return true;
		//else
		//	return false;
		//等价于
		return ((t1->data == t2->data)
			&& Equal(t1->leftChild, t2->leftChild)
			&& Equal(t1->rightChild, t2->rightChild));
	}
}





#endif/*_TREE_H_*/
