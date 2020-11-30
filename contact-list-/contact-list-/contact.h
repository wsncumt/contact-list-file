#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <search.h>
#include <stdlib.h>

//ͨѶ¼������20���˵���Ϣ
//����+�绰+��ַ+QQ+�Ա�+����
//���ܣ���ɾ����ţ��˳�����

//#define MAX 20

#define DEFAULT_SIZE 2
#define INC 1

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 15
#define MAX_SEX 5

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;//���ڼ�¼ͨѶ¼����ϵ�˵ĸ�����������ɾ����ʾ
//}Contact;

typedef struct Contact
{
	PeoInfo* data;
	int sz;//���ڼ�¼ͨѶ¼����ϵ�˵ĸ�����������ɾ����ʾ
	int capacity;//��¼ͨѶ¼�������������������
}Contact;

//��������

void InitContact(Contact* pc);//��ʼ��ͨѶ¼
void add_contact(Contact* pc);//���һ���˵���Ϣ
void del_contact(Contact* pc);
void search_contact(const Contact* pc);
void modify_contact(Contact* pc);
void sort_contact(Contact* pc);
void show_contact(const Contact* pc);//��ʾͨѶ¼�����Ϣ
void destroy_contact(Contact* pc);//����ͨѶ¼
void save_contact(const Contact* pc);//��ͨѶ¼���浽�ļ���
void load_contact(Contact* pc);//�����ļ���ͨѶ¼��
void check_capacity(Contact* pc);