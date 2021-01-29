#ifndef _TREE_H_
#define _TREE_H_
#include"Sysutil.h"

//���ȶ������ڵ��Ԫ������
#define TreeElemType char
//�������ν��
typedef struct BinTreeNode
{
	TreeElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;
//���������
typedef struct BinTreeNode* BinTree;

//����
void BinTreeCreate_1(BinTree* t);//������������
BinTree BinTreeCreate_2();
BinTree BinTreeCreate_3(const char* str, int* i);

void PreOrder(BinTree* t);//ǰ�����
void InOrder(BinTree* t);//�������
void PostOrder(BinTree* t);//�������

size_t Size(BinTree t);//��ڵ����
size_t Height(BinTree t);//�����ĸ߶�
BinTreeNode* Find(BinTree t, TreeElemType key);//����ָ���ڵ�
BinTreeNode* Parent(BinTree t, BinTreeNode* s);//����ָ���ڵ�ĸ��ڵ�


BinTree Clone(BinTree t);//�������Ŀ�¡
bool    Equal(BinTree t1, BinTree t2);//�ж��������Ƿ����


///////////////////////////
//����
void BinTreeCreate_1(BinTree* t)//�������Ķ��� 
//*tֻ��һ��ָ�룬��û�о����ָ��ĳһ���ռ䣬��˲���ʹ��*t->data ���и�ֵ
{
	TreeElemType item;
	scanf("%c",&item);//�������н�����������
	if (item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));//����������ָ��ָ������λ�� 
		assert(*t);
		(*t)->data = item;
		BinTreeCreate_1(&((*t)->leftChild));
		BinTreeCreate_1(&((*t)->rightChild));
	}
}

BinTree BinTreeCreate_2()//�������Ķ���2
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


BinTree BinTreeCreate_3(const char* str, int* i)//�������Ķ���3
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
		(*i)++;//������ # ��ʱ�򷵻� NULL ��û��ǰ��
		new_node->rightChild = BinTreeCreate_3(str, i);
		//����Ҫ(*i)++����Ϊ�ұ߸�ֵ�ɹ���ֱ�ӷ��ظ��ڵ㼴��
		return new_node;
	}
}
void PreOrder(BinTree* t)//ǰ�����
{
	if ((*t)!=NULL)
	{
		printf("%c",(*t)->data );
		PreOrder(&((*t)->leftChild));
		PreOrder(&((*t)->rightChild));
	}
}

void InOrder(BinTree* t)//�������
{
	if ((*t) != NULL)
	{
		InOrder(&((*t)->leftChild));
		printf("%c", (*t)->data);
		InOrder(&((*t)->rightChild));
	}

}
void PostOrder(BinTree* t)//�������
{
	if ((*t) != NULL)
	{	
		PostOrder(&((*t)->leftChild));
		PostOrder(&((*t)->rightChild));
		printf("%c", (*t)->data);
	}

}
size_t Size(BinTree t)//��ڵ����
{
	if (t == NULL)
		return 0;
	else
		return (Size(t->leftChild) + Size(t->rightChild))+1;
}

size_t Height(BinTree t)//�����ĸ߶�
{
	if (t == NULL)
		return 0;
	else
		return (Height(t->leftChild) > Height(t->rightChild) ? Height(t->leftChild) : Height(t->rightChild)) + 1;
}
BinTreeNode* Find(BinTree t, TreeElemType key)//����ָ������
{
	BinTreeNode* p;
	if (t == NULL)
		return NULL;
	else
	{
		if (t->data == key)
			return t;//��ʾ�ҵ���
		else//û�ҵ�����t�������к������н��в���
		{
			p = Find(t->leftChild, key);//����ʱ�������н�����ߵĲ��ҽ��
			if (p == NULL)//��ʾ���û���ҵ�
				return Find(t->rightChild, key);//��Ȼ���û�ҵ����ͷ����ұߵļ����
			else//��ʱ��ʾ����ҵ��ˣ���ô����Ҫ�����ұ߲��ң�ֱ�ӽ��з���
				return p;
		}
	}
}

BinTreeNode* Parent(BinTree t, BinTreeNode* s)//����ָ���ڵ�ĸ��ڵ�
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
BinTree Clone(BinTree t)//�������Ŀ�¡	
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
bool Equal(BinTree t1, BinTree t2)//�ж��������Ƿ����(�������������Ƿ����)
{
	if (t1 == NULL && t2 == NULL)
		return true;
	//�������һ��Ϊ�գ�����t1Ϊ�գ��޷�����t1->data����
	//��˻��迼��һ��Ϊ��һ����Ϊ�յ����
	if ( t1==NULL|| t2==NULL )
		return false;
	else
	{
		//if ((t1->data==t2->data)&&Equal(t1->leftChild, t2->leftChild) && Equal(t1->rightChild, t2->rightChild))
		//	return true;
		//else
		//	return false;
		//�ȼ���
		return ((t1->data == t2->data)
			&& Equal(t1->leftChild, t2->leftChild)
			&& Equal(t1->rightChild, t2->rightChild));
	}
}





#endif/*_TREE_H_*/
