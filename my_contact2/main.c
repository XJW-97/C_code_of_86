#include "contact.h"

//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
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
	//初始化通讯录
	Contact ct;
	memset(&ct, 0, sizeof(ct));
	ct.index = 0;
//	ct.capacity = 0;
	while (input)
	{//首先添加打印菜单
		menu();
	//选择需要的服务
		printf("请输入您需要的服务:");
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
			printf("服务到此结束\n");
			break;
		}

	}
	return 0;
}