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
	//������һ����Ҫʹ����ͷ˫ѭ������������Ҫ����һ���Լ�����ͷ˫ѭ������
	DCList mylist;
	DCListNode* pos;
	//�����Լ���˫ѭ����������Ҫ���г�ʼ��
	DCListInit(&mylist);

	//���彫��ʹ�õĲ���
	ElemType item;

	int select = 1;
	while (select)
	{	
		menu();
		printf("��ѡ����Ҫʹ�õĹ���\n");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("��ǰ�����Ѿ��˳�\n");
			break;
		case 1://ʵ��β�巨
			printf("��������Ҫ��������֣���-1��β��\n");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist,item);
			}
			break;
		case 2://ʵ��ͷ��
			printf("��������Ҫ��������֣���-1��β��\n");
			ElemType item;
			while (scanf("%d",&item),item!=-1)
			{
				DCListPushFront(&mylist,item);
			}
			break;
		case 3://ʵ�����ݴ�ӡ
			DCListShow(&mylist);
			break;
		case 4://ʵ��β��ɾ��
			DCListPopBack(&mylist);
			break;
		case 5://ʵ��ͷ��ɾ��
			DCListPopFront(&mylist);
			break;
		case 6://���ص�ǰ���ݳ���
			printf("��ǰ���ݳ���Ϊ: %d \n",DCListLength(&mylist));
			break;
		case 8://��ֵ����
			printf("��������Ҫ��������ݣ���-1������\n");
			while (scanf("%d",&item),item!=-1)
			{
				DCListInvByValu(&mylist,item);
			}			
			break;
		case 10://��ֵɾ��
			printf("��������Ҫɾ��������\n");
			scanf("%d", &item);
			DCListDelyValu(&mylist, item);
			break;
		case 12:
			printf("��������Ҫ���ҵ�����\n");
			scanf("%d", &item);
			pos=DCListFind(&mylist,item);
			if (pos == NULL)
				printf("����������ݲ�����\n");
			else
				printf("����������� %d ����\n",item);
			break;
		case 13://�������������
			DCListSort(&mylist);
			break;
		case 14://ʵ�������ת��
			DCListRevers(&mylist);
			break;
		case 15://ɾ�����������ֵ��ͬ������
			printf("��������Ҫɾ��������\n");
			scanf("%d",item);
			DCListRemoveAll(&mylist,item);
			break;
		case 16:
			DCListClean(&mylist);//ʵ����������
			break;
		case 17:
			DCListDestroy(&mylist);//ʵ������Ĵݻ١���ͷ�ڵ�Ҳһ������
			break;


















		}

		system("pause");
		system("cls");

	}




























}