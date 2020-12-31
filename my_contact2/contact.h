#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 20
#define MAX_TELE 12
#define MAX 1000

typedef struct PeoInFo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

} PeoInFo;

typedef struct Contact {
	int index ;//用户的下标位
	//int capacity;//当前的用户量
	PeoInFo data[MAX];
} Contact;

//声明添加函数
void add (Contact * ct);
//展示当前的通讯录
void show(Contact * ct);
//删除当前用户
void delete(Contact * ct);
//找到当前指定用户
int find_the_boy(Contact * ct, char* name);
//查找当前用户
void search(Contact * ct);
//用号码查找当前用户
int find_the_boy_by_num(Contact* ct, char* tel);
//修改当前用户
void modify(Contact * ct);
//清除所有用户
void clear(Contact* ct);
//排序
void sort(Contact* ct);
//保存到文件夹中
void save(Contact* ct);