#include "contact.h"

//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
void menu()
{
	printf("*****************************\n");
	printf("**** 1. Add     2. Del   ****\n");
	printf("**** 3. Search  4. Mod   ****\n");
	printf("**** 5. Show    6. Cls   ****\n");
	printf("**** 7. Sort    8. Save  ****\n");
	printf("**** 9. Quit             ****\n");
	printf("*****************************\n");
}
enum Option
{
	Quit,
	Add,
	Del,
	Search,
	Mod,
	Show,
	Cls,
	Sort,
	Save

};

int main()
{
	int input = 1;
	//��ʼ��ͨѶ¼
	Contact ct;
	memset(&ct, 0, sizeof(ct));
	ct.index = 0;
//	ct.capacity = 0;
	while (input)
	{//������Ӵ�ӡ�˵�
		menu();
	//ѡ����Ҫ�ķ���
		printf("����������Ҫ�ķ���:");
		scanf("%d",&input);
		switch (input)
		{
		case Add:
			add(&ct);
			break;
		case Del:
			delete(&ct);
			break;
		case Search:
			search(&ct);
			break;
		case Mod:
			modify(&ct);
			break;
		case Show:
			show(&ct);
			break;
		case Cls:
			clear(&ct);
			break;
		case Sort:
			sort(&ct);
			break;
		case Save:
			save(&ct);
			break;
		default:
			input = 0;
			printf("���񵽴˽���\n");
			break;
		}

	}
	return 0;
}