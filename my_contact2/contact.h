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
	int index ;//�û����±�λ
	//int capacity;//��ǰ���û���
	PeoInFo data[MAX];
} Contact;

//������Ӻ���
void add (Contact * ct);
//չʾ��ǰ��ͨѶ¼
void show(Contact * ct);
//ɾ����ǰ�û�
void delete(Contact * ct);
//�ҵ���ǰָ���û�
int find_the_boy(Contact * ct, char* name);
//���ҵ�ǰ�û�
void search(Contact * ct);
//�ú�����ҵ�ǰ�û�
int find_the_boy_by_num(Contact* ct, char* tel);
//�޸ĵ�ǰ�û�
void modify(Contact * ct);
//��������û�
void clear(Contact* ct);
//����
void sort(Contact* ct);
//���浽�ļ�����
void save(Contact* ct);