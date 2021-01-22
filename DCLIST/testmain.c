#include "DClist.h"

void menu()
{
	printf("********************************************\n");
	printf("* [0] quit_system      [1] push_back       *\n");
	printf("* [2] push_front       [3] show_list       *\n");
	printf("* [4] pop_back         [5] pop_front       *\n");
	printf("* [6] length           [*7] capacity       *\n");
	printf("* [8] insert_val       [*9] insert_pos     *\n");
	printf("* [10] delete_val      [*11] delete_pos    *\n");
	printf("* [12] find            [13] sort           *\n");
	printf("* [14] reverse         [15] remove_all     *\n");
	printf("* [16] clear           [17] destroy       *\n");
	printf("* [*18] find_binary                        *\n");
	printf("********************************************\n");

}

int main()
{
	//和往常一样，要使用有头双循环链表，首先需要生成一个自己的有头双循环链表
	DCList mylist;
	DCListNode* pos;
	//有了自己的双循环链表，则需要进行初始化
	DCListInit(&mylist);

	//定义将会使用的参数
	ElemType item;

	int select = 1;
	while (select)
	{	
		menu();
		printf("请选择您要使用的功能\n");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("当前程序已经退出\n");
			break;
		case 1://实现尾插法
			printf("请输入您要插入的数字（以-1结尾）\n");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist,item);
			}
			break;
		case 2://实现头插
			printf("请输入您要插入的数字（以-1结尾）\n");
			ElemType item;
			while (scanf("%d",&item),item!=-1)
			{
				DCListPushFront(&mylist,item);
			}
			break;
		case 3://实现数据打印
			DCListShow(&mylist);
			break;
		case 4://实现尾部删除
			DCListPopBack(&mylist);
			break;
		case 5://实现头部删除
			DCListPopFront(&mylist);
			break;
		case 6://返回当前数据长度
			printf("当前数据长度为: %d \n",DCListLength(&mylist));
			break;
		case 8://按值插入
			printf("请输入您要插入的数据（以-1结束）\n");
			while (scanf("%d",&item),item!=-1)
			{
				DCListInvByValu(&mylist,item);
			}			
			break;
		case 10://按值删除
			printf("请输入您要删除的数字\n");
			scanf("%d", &item);
			DCListDelyValu(&mylist, item);
			break;
		case 12:
			printf("请输入您要查找的数字\n");
			scanf("%d", &item);
			pos=DCListFind(&mylist,item);
			if (pos == NULL)
				printf("您输入的数据不存在\n");
			else
				printf("您输入的数据 %d 存在\n",item);
			break;
		case 13://对链表进行排序
			DCListSort(&mylist);
			break;
		case 14://实现链表的转置
			DCListRevers(&mylist);
			break;
		case 15://删除所有与给定值相同的数据
			printf("请输入您要删除的数据\n");
			scanf("%d",item);
			DCListRemoveAll(&mylist,item);
			break;
		case 16:
			DCListClean(&mylist);//实现链表的清除
			break;
		case 17:
			DCListDestroy(&mylist);//实现链表的摧毁——头节点也一并清理
			break;


















		}

		system("pause");
		system("cls");

	}




























}