#include "list.h"


void menu()//菜单打印函数
{
	printf("********************************************\n");
	printf("* [1] push_back        [2] push_front      *\n");
	printf("* [3] show_list        [0] quit_system     *\n");
	printf("* [4] pop_back         [5] pop_front       *\n");
	printf("* [6] length           [*7] capacity       *\n");
	printf("* [8] insert_val       [*9] insert_pos      *\n");
	printf("* [10] delete_val      [*11] delete_pos     *\n");
	printf("* [12] find            [13] sort           *\n");
	printf("* [14] reverse         [15] remove_all     *\n");
	printf("* [16] clear           [*17] destroy       *\n");
	printf("* [*18] find_binary                         *\n");
	printf("********************************************\n");
}

int main()
{
	//干活之前需要创建一个自己的链表
	SList mylist;
	//有了自己的链表，则需要进行初始化
	SLIstInit(&mylist);
	//创建待使用的操作元素
	ElemType item, key;
	int pos;
	SListNode* p;

	int select = 1;
	while (select)
	{
		menu();
		printf("请选择:>");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("程序已退出\n");
			break;

		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)  //逗号表达式
				SListPushFront(&mylist, item);
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			break;
		case 5:
			SListPopFront(&mylist);
			break;
		case 6:
			printf("表长为: %d\n", SListLength(&mylist));
			break;
		/*case 7:
			//printf("表的容量为:>%d\n", SeqListCapacity(&mylist));
			break;
		*/
		case 8:
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		/*case 9:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		*/
		case 10:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		/*case 11:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;*/
		case 12:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值%d不存在.\n", key);
			else
				printf("要查找的值%d存在.\n", key);
			break;
		/*case 13:
			//SeqListSort(&mylist);
			break;
		*/
		case 14:
			SListReverse(&mylist);
			break;
		/*case 15:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			//SeqListRemoveAll(&mylist, key);
			break;*/
		case 16:
			SListClear(&mylist);
			break;


		//SListDestroy(&mylist);
		}
		system("pause");
		system("cls");
	}

	return 0;
}