#include"contact.h"

void add(Contact* ct)
{
	//判断当前的通讯录的容量是否足够
	if (ct->index == MAX)
	{
		printf("内存不足\n");
	}
	else 
	{
	//执行信息的添加
	printf("请输入您的姓名\n");
	scanf("%s",(ct->data)[ct->index].name);
	printf("请输入您的性别\n");
	scanf("%s", (ct->data)[ct->index].sex);
	printf("请输入您的年龄\n");
	scanf("%d", &((ct->data)[ct->index].age));
	printf("请输入您的电话\n");
	scanf("%s", (ct->data)[ct->index].tele);
	printf("请输入您的地址\n");
	scanf("%s", (ct->data)[ct->index].addr);
	ct->index++;
	printf("增加成功\n");
	}
	
}
void show(Contact* ct)
{
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-15s\n",
		"name", "age", "sex", "tele", "addr");
	for (int i = 0; i < ct->index; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-15s\n",
			ct->data[i].name, 
			ct->data[i].sex,
			ct->data[i].age, 
			ct->data[i].tele,
			ct->data[i].addr);
	}
}
int find_the_boy(Contact *ct, char* name)
{
	for (int i = 0; i < ct->index; i++)
	{
		if (strcmp(ct->data[i].name, name)==0)
		{
			return i;
		}
	}
	return -1;
}
int find_the_boy_by_num(Contact* ct, char* tel)
{
	for (int i = 0; i < ct->index; i++)
	{
		if (strcmp(ct->data[i].tele, tel ) == 0)
		{
			return i;
		}
	}
	return -1;
}
void delete(Contact* ct)
{
	printf("请问您要删除哪一个用户\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s",name); 
	//找到当前的指定用户
	int sub_num = find_the_boy(ct, name);
	if (sub_num == -1)
	{
		printf("查无此人\n");
	}
	else 
	{
	for (int i = sub_num ; i < (ct->index)-1; i++)
	{
		ct->data[i] = ct->data[i + 1];
	}
	ct->index--;
	printf("删除成功\n");
	}
}
void search(Contact* ct) 
{
	printf("**************************\n");
	printf("***请输入您要查找的方式***\n");
	printf("***  1. 号码  2. 姓名  ***\n");
	printf("**************************\n");
	int c = 0;
	scanf("%d", &c);
		int sub_num = 0;//返回的用户下标
		switch (c)
		{
		case 1:
			printf("请输入您要查找的号码\n");
			char tel[MAX_TELE] = { 0 };
			scanf("%s", tel);
			 sub_num=find_the_boy_by_num(ct, tel);
			if (sub_num == -1)
			{
				printf("查无此人\n");
			}
			else
			{
				printf("%-20s\t%-5s\t%-5s\t%-12s\t%-15s\n",
					"name", "age", "sex", "tele", "addr");
				printf("%-20s\t%-5s\t%-5d\t%-12s\t%-15s\n",
					ct->data[sub_num].name,
					ct->data[sub_num].sex,
					ct->data[sub_num].age,
					ct->data[sub_num].tele,
					ct->data[sub_num].addr);
			}
			
			break;
		case 2:
			printf("请输入您要查找的姓名\n");
			char name[MAX_NAME] = { 0 };
			scanf("%s",name);
			 sub_num = find_the_boy(ct, name);
			if (sub_num == -1)
			{
				printf("查无此人\n");
			}
			else
			{
				printf("%-20s\t%-5s\t%-5s\t%-12s\t%-15s\n",
					"name", "age", "sex", "tele", "addr");
				printf("%-20s\t%-5s\t%-5d\t%-12s\t%-15s\n",
					ct->data[sub_num].name,
					ct->data[sub_num].sex,
					ct->data[sub_num].age,
					ct->data[sub_num].tele,
					ct->data[sub_num].addr);
			}
			break;
		default:
			break;
		}
	}
void modify(Contact* ct)
{
	printf("请输入您需要修改的用户名\n");
	char name[MAX_NAME] = { 0 };
	scanf("%s", name);
	int sub_num = find_the_boy(ct, name);
	if (sub_num == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-15s\n",
		"name", "age", "sex", "tele", "addr");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-15s\n",
		ct->data[sub_num].name,
		ct->data[sub_num].sex,
		ct->data[sub_num].age,
		ct->data[sub_num].tele,
		ct->data[sub_num].addr); 

		printf("请输入性别\n");
		scanf("%s", (ct->data)[sub_num].sex);
		printf("请输入年龄\n");
		scanf("%d", &((ct->data)[sub_num].age));
		printf("请输入电话\n");
		scanf("%s", (ct->data)[sub_num].tele);
		printf("请输入地址\n");
		scanf("%s", (ct->data)[sub_num].addr);

		printf("修改完毕\n");

	}
	
}
	
void clear(Contact* ct)
{
	ct->index = 0;
}

int cmp_name (const void* e1, const void* e2) 
{
	PeoInFo* e1_p = (PeoInFo*)e1;
	PeoInFo* e2_p = (PeoInFo*)e2;
	return strcmp(e1_p->name,e2_p->name);
}
void sort(Contact* ct)
{
	//按照姓名排序
	qsort(ct->data,ct->index,sizeof(ct->data[0]),cmp_name);
}

void save(Contact* ct)
{
	FILE* pFile;
	pFile = fopen("my_contact.txt", "wb");
	if (pFile != NULL)
	{	
		fputs("%-20s\t%-5s\t%-5d\t%-12s\t%-15s\n", pFile);
		//for (int i = 0; i < ct->index; i++)
		//{
		////	fputs(
		////		ct->data[i].name,
		////		ct->data[i].sex,
		////		ct->data[i].age,
		////		ct->data[i].tele,
		////		ct->data[i].addr, pFile);
		//}
			
	}
		fwrite(ct->data, sizeof(ct->data[0]), ct->index, pFile);
	fclose(pFile);

	//printf("%s", ct->data[0]);
}