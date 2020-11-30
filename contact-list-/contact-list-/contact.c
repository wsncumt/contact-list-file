#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void check_capacity(Contact* pc)
{
	if ((pc->sz) == pc->capacity - 1)
	{
		printf("ͨѶ¼�������޷���ӡ���������\n");
		//��������
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			ptr = NULL;
			pc->capacity += INC;
			printf("\nϵͳ��ʾ�����ݳɹ�\n\n");
		}
		else
		{
			perror("�ڴ治��");
			return;
		}
	}
}

void InitContact(Contact* pc)
{
	printf("��ʼ��ͨѶ¼�У����Ե�...\n");
	pc->sz = 0;
	pc->capacity = DEFAULT_SIZE;
	pc->data = (PeoInfo*)malloc(DEFAULT_SIZE * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("��ʼ��ͨѶ¼(malloc)");
		return;
	}

	//����ͨѶ¼����Ϣ
	load_contact(pc);
}

void add_contact(Contact* pc)
{
	check_capacity(pc);
	//if((pc->sz) == pc->capacity)
	//{
	//	printf("ͨѶ¼�������޷���ӡ���ɾ��������ϵ�˺������\n");
	//	//��������
	//	PeoInfo *ptr=(PeoInfo*)realloc(pc->data,(pc->capacity + INC)*sizeof(PeoInfo));
	//	if (ptr != NULL)
	//	{
	//		pc->data = ptr;
	//		ptr = NULL;
	//		pc->capacity += INC;
	//		printf("\nϵͳ��ʾ�����ݳɹ�\n\n");
	//	}
	//	else
	//	{
	//		perror("�����ϵ��(relloc)");
	//		return;
	//	}
	//}
	//else
	//{
	printf("���������֣�>");
	scanf("%s", pc->data[pc->sz].name);
	printf("������绰��>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������QQ��>");
	scanf("%s", pc->data[pc->sz].qq);
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->sz].age));
	pc->sz++;
	printf("��ӳɹ���\n");
	//}

}

static int find_peo(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ����֣�\n");
	scanf("%s", name);
	int i;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;//�ҵ������±�
		}
	}
	return -1;//�Ҳ���
}

//�޸�ָ����ϵ��
void modify_contact(Contact* pc)
{
	int ret = find_peo(pc);
	if (ret == -1)
	{
		printf("δ�ҵ����ˣ����������Ƿ���������ȷ�ϸ���ϵ���Ƿ���ͨѶ¼��\n");
	}
	else
	{
		printf("�������µ����֣�>");
		scanf("%s", pc->data[ret].name);
		printf("�������µĵ绰��>");
		scanf("%s", pc->data[ret].tele);
		printf("�������µĵ�ַ��>");
		scanf("%s", pc->data[ret].addr);
		printf("�������µ�QQ��>");
		scanf("%s", pc->data[ret].qq);
		printf("�������µ��Ա�>");
		scanf("%s", pc->data[ret].sex);
		printf("�������µ����䣺>");
		scanf("%d", &(pc->data[ret].age));
		printf("�޸ĳɹ���\n");
	}
}

//����һ����ϵ��
void search_contact(const Contact* pc)
{
	int ret = find_peo(pc);
	if (ret == -1)
	{
		printf("δ�ҵ����ˣ����������Ƿ���������ȷ�ϸ���ϵ���Ƿ���ͨѶ¼��\n");
	}
	else
	{
		printf("%20s %5s %5s %15s %12s %50s\n", "����", "�Ա�", "����", "QQ", "�绰", "��ַ");
		printf("%20s %5s %5d %15s %12s %50s\n", pc->data[ret].name,
			pc->data[ret].sex,
			pc->data[ret].age,
			pc->data[ret].qq,
			pc->data[ret].tele,
			pc->data[ret].addr
		);
	}
}

//ɾ����ϵ��
void del_contact(Contact* pc)
{
	if (pc->sz <= 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��");
	}
	else
	{
		//����
		int ret = find_peo(pc);
		if (ret == -1)
		{
			printf("δ�ҵ����ˣ����������Ƿ���������ȷ�ϸ���ϵ���Ƿ���ͨѶ¼��\n");
		}
		//ɾ��
		else
		{
			int j;
			for (j = ret; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}

	}
}



//����������
void sort_contact(Contact* pc)
{
	int i, j;
	int flag = 1;
	for (i = 0; (i < pc->sz - 1) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 1;
			}
		}
	}
}

//��ʾ��Ϣ
void show_contact(const Contact* pc)
{
	int i;
	printf("%5s %20s %5s %5s %15s %12s %50s\n", "���", "����", "�Ա�", "����", "QQ", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%5d %20s %5s %5d %15s %12s %50s\n", i + 1, pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].qq,
			pc->data[i].tele,
			pc->data[i].addr
		);
	}
	printf("\n");
}

//����ͨѶ¼���ͷŶ�̬�ڴ�ָ��
void destroy_contact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}

//��ͨѶ¼���浽�ļ���
void save_contact(const Contact* pc)
{
	int i;
	FILE* pfwrite = fopen("Contact.dat", "wb");
	if (pfwrite == NULL)
	{
		perror("Open Contact.txt(write)");
		return;
	}
	else
	{
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data + i, sizeof(PeoInfo), 1, pfwrite);
		}
		printf("ͨѶ¼�ѱ��档\n");
	}
	fclose(pfwrite);
	pfwrite = NULL;
}

void load_contact(Contact* pc)
{
	printf("���ڼ�������...\n");
	PeoInfo tmp = { 0 };
	FILE* pfread = fopen("Contact.dat", "rb");
	if (pfread == NULL)
	{
		perror("Open Contact.txt(read)");
		printf("����ʧ��!\n");
		return;
	}
	else
	{
		//��������
		while (fread(&tmp, sizeof(PeoInfo), 1, pfread))
		{
			check_capacity(pc);
			pc->data[pc->sz] = tmp;
			pc->sz++;
		}
		printf("���ݼ��سɹ���\n");
	}
	fclose(pfread);
	pfread = NULL;

}