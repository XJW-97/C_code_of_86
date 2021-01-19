#include "seqlist.h"
void manu()
{	
		printf("********************************************\n");
		printf("* [1] push_back        [2] push_front      *\n");
		printf("* [3] show_list        [0] quit_system     *\n");
		printf("* [4] pop_back         [5] pop_front       *\n");
		printf("* [6] length           [7] capacity        *\n");
		printf("* [8] insert_val       [9] insert_pos      *\n");
		printf("* [10] delete_val      [11] delete_pos     *\n");
		printf("* [12] find            [13] sort           *\n");
		printf("* [14] reverse         [15] remove_all     *\n");
		printf("* [16] clear           [*17] destroy       *\n");
		printf("* [18] find_binary                         *\n");
		printf("********************************************\n");

}
int main()
{   //干活之前需要一个结构体
	Seqlist Mylist;
	//有了自己的结构体然后需要进行初始化
	SeqlistInit(&Mylist);
	ElemType item, item1, key;
	int pos,pos1;
	
	int select = 1;
	while (select)
		{	manu();//打印菜单
			printf("请选择:>");//选择操作
			scanf("%d", &select);
			switch (select)
			{
			case 1://尾插法
				printf("请输入需要插入的数据（以-1结束）");
				while (scanf("%d",&item),item!=-1)
				{
					SeqListPushBack(&Mylist,item);
				}
				break;
			case 2://头插法
				printf("请输入需要插入的数据（以-1结束）");
				while (scanf("%d", &item), item != -1)
				{
					SeqListPushFront(&Mylist, item);
				}
				break;
			case 3://打印全部的数据
				SeqListShow(&Mylist);
				break;
			case 4://尾部删除
				SeqlistPopBack(&Mylist);
				break;
			case 5://头部删除
				SeqlistPopFront(&Mylist);
				break;
			case 6://输出表长
				printf("当前表长为: %d \n",SeqlistLength(&Mylist));
				break;
			case 7://输出当前内容量
				printf("当前线性表容量为：%d \n ",SeqlistCapacity(&Mylist));
				break;
			case 8://按值插入
				/*printf("请输入您要插入的数字，以及要插入到哪一个数字前\n");
				printf("您要插入的数字为：\n");
				scanf("%d",&item);
				printf("您要放到哪一个数字前？\n");
				scanf("%d",&item1);
				SeqlistInsertByVal(&Mylist,item,item1);*/
				printf("请输入您要插入的数字\n");
				scanf("%d",&item);
				SeqlistInsertByVal(&Mylist,item);
				break;
			case 9://按地址插入
				printf("请输入您要插入的数字，以及要插入到的位置\n");
				printf("您要插入的数字为：\n");
				scanf("%d", &item);
				printf("您要放到哪一个位置？\n");
				scanf("%d", &key);
				SeqlistInsertByPos(&Mylist, item, key);
				break;
			case 10://按值删除
				printf("请输入要删除的值 \n");
				scanf("%d",&key);
				SeqlistDelebyVal(&Mylist, key);
				break;
			case 11://按位置删除
				printf("请输入你要删除的位置\n");
				scanf("%d",&pos);
				SeqlistDelebyPos(&Mylist,pos);
				break;
			case 12://找到指定的数，返回其下标
				printf("请输入要查找的值  \n");
				scanf("%d", &key);
				int pos = SeqlistFind(&Mylist,key);
				if (pos == -1)
				{
					printf("线性表中没有当前数字\n");
				}
				else
				{
					printf("当前所查找数字具体位置为 %d \n",pos);
				}
				break;
			case 13://排序
				SeqlistSort(&Mylist);
				break;
			case 14://进行数据转置
				SeqlistReverse(&Mylist);
				break;
			case 15://remove_all 移除所有相同的数据
				printf("请输入你所要删除的数据\n");
				scanf("%d",&item);
				SeqlistRemoveAll(&Mylist, item);
				break;
			case 16:
				SeqlistClear(&Mylist);
				break;
			case 17:
				SeqlistDestroy(&Mylist);
				break;
			case 18:
				printf("请输入您要查找的数据\n");
				scanf("%d",&item);
				int pos1 = SeqlistFindBinary(&Mylist, item);
				if (pos1 == -1)
				{
					printf("线性表中没有当前数字\n");
				}
				else
				{
					printf("当前所查找数字具体位置为 %d \n", pos1);
				}
				break;

		}
		system("pause");
		system("cls");
	}
	
}