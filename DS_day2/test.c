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
{   //�ɻ�֮ǰ��Ҫһ���ṹ��
	Seqlist Mylist;
	//�����Լ��Ľṹ��Ȼ����Ҫ���г�ʼ��
	SeqlistInit(&Mylist);
	ElemType item, item1, key;
	int pos,pos1;
	
	int select = 1;
	while (select)
		{	manu();//��ӡ�˵�
			printf("��ѡ��:>");//ѡ�����
			scanf("%d", &select);
			switch (select)
			{
			case 1://β�巨
				printf("��������Ҫ��������ݣ���-1������");
				while (scanf("%d",&item),item!=-1)
				{
					SeqListPushBack(&Mylist,item);
				}
				break;
			case 2://ͷ�巨
				printf("��������Ҫ��������ݣ���-1������");
				while (scanf("%d", &item), item != -1)
				{
					SeqListPushFront(&Mylist, item);
				}
				break;
			case 3://��ӡȫ��������
				SeqListShow(&Mylist);
				break;
			case 4://β��ɾ��
				SeqlistPopBack(&Mylist);
				break;
			case 5://ͷ��ɾ��
				SeqlistPopFront(&Mylist);
				break;
			case 6://�����
				printf("��ǰ��Ϊ: %d \n",SeqlistLength(&Mylist));
				break;
			case 7://�����ǰ������
				printf("��ǰ���Ա�����Ϊ��%d \n ",SeqlistCapacity(&Mylist));
				break;
			case 8://��ֵ����
				/*printf("��������Ҫ��������֣��Լ�Ҫ���뵽��һ������ǰ\n");
				printf("��Ҫ���������Ϊ��\n");
				scanf("%d",&item);
				printf("��Ҫ�ŵ���һ������ǰ��\n");
				scanf("%d",&item1);
				SeqlistInsertByVal(&Mylist,item,item1);*/
				printf("��������Ҫ���������\n");
				scanf("%d",&item);
				SeqlistInsertByVal(&Mylist,item);
				break;
			case 9://����ַ����
				printf("��������Ҫ��������֣��Լ�Ҫ���뵽��λ��\n");
				printf("��Ҫ���������Ϊ��\n");
				scanf("%d", &item);
				printf("��Ҫ�ŵ���һ��λ�ã�\n");
				scanf("%d", &key);
				SeqlistInsertByPos(&Mylist, item, key);
				break;
			case 10://��ֵɾ��
				printf("������Ҫɾ����ֵ \n");
				scanf("%d",&key);
				SeqlistDelebyVal(&Mylist, key);
				break;
			case 11://��λ��ɾ��
				printf("��������Ҫɾ����λ��\n");
				scanf("%d",&pos);
				SeqlistDelebyPos(&Mylist,pos);
				break;
			case 12://�ҵ�ָ���������������±�
				printf("������Ҫ���ҵ�ֵ  \n");
				scanf("%d", &key);
				int pos = SeqlistFind(&Mylist,key);
				if (pos == -1)
				{
					printf("���Ա���û�е�ǰ����\n");
				}
				else
				{
					printf("��ǰ���������־���λ��Ϊ %d \n",pos);
				}
				break;
			case 13://����
				SeqlistSort(&Mylist);
				break;
			case 14://��������ת��
				SeqlistReverse(&Mylist);
				break;
			case 15://remove_all �Ƴ�������ͬ������
				printf("����������Ҫɾ��������\n");
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
				printf("��������Ҫ���ҵ�����\n");
				scanf("%d",&item);
				int pos1 = SeqlistFindBinary(&Mylist, item);
				if (pos1 == -1)
				{
					printf("���Ա���û�е�ǰ����\n");
				}
				else
				{
					printf("��ǰ���������־���λ��Ϊ %d \n", pos1);
				}
				break;

		}
		system("pause");
		system("cls");
	}
	
}