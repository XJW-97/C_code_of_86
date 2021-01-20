#include "list.h"


void menu()//�˵���ӡ����
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
	//�ɻ�֮ǰ��Ҫ����һ���Լ�������
	SList mylist;
	//�����Լ�����������Ҫ���г�ʼ��
	SLIstInit(&mylist);
	//������ʹ�õĲ���Ԫ��
	ElemType item, key;
	int pos;
	SListNode* p;

	int select = 1;
	while (select)
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("�������˳�\n");
			break;

		case 1:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
				SListPushBack(&mylist, item);
			break;
		case 2:
			printf("������Ҫ���������(��-1����):>");
			while (scanf("%d", &item), item != -1)  //���ű��ʽ
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
			printf("��Ϊ: %d\n", SListLength(&mylist));
			break;
		/*case 7:
			//printf("�������Ϊ:>%d\n", SeqListCapacity(&mylist));
			break;
		*/
		case 8:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, item);
			break;
		/*case 9:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		*/
		case 10:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			break;
		/*case 11:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;*/
		case 12:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ%d������.\n", key);
			else
				printf("Ҫ���ҵ�ֵ%d����.\n", key);
			break;
		/*case 13:
			//SeqListSort(&mylist);
			break;
		*/
		case 14:
			SListReverse(&mylist);
			break;
		/*case 15:
			printf("������Ҫɾ����ֵ:>");
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