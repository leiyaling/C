#define _CRT_SECURE_NO_WARNINGS 11


#include"Contact.h"
void  InitContact(struct Contact* pc)
{
	assert(pc);
	memset(pc->data, 0, 100 * sizeof(struct PeoInfo));
	pc->sz = 0;
}
void AddContact(struct Contact* pc)
{
	assert(pc);
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷��������\n");
		return;
	}

	//�����˵���Ϣ
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].telephone);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].address);

	pc->sz++;
	printf("�ɹ�������ϵ��\n");
}
void ShowContact(const struct Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰����", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-5s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].telephone,
			pc->data[i].address);
	}
}
static int  FindByName(const struct Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;

}
void DelContact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("��������Ҫɾ���˵����֣�>");
	scanf("%s", name);
	//����һ��Ҫɾ�������Ƿ����
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("��Ҫɾ�����˲�����");
	else
	{
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("�ɹ�ɾ����ϵ��");
	}
}
void SearchContact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("��������Ҫ���ҵ����֣�>");
	scanf("%s", name);

	int i = 0;
	for (i = 0; i < pc->sz - 1; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			printf("%-5s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name,
				pc->data[i].sex,
				pc->data[i].age,
				pc->data[i].telephone,
				pc->data[i].address);
		}
		else
		{
			printf("�Ҳ����������\n");
		}
	}

}
void ModifyContact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("��������Ҫ�޸ĵ��˵����֣�>\n");
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("��Ҫɾ�����˲�����");
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("�������Ա�:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("����������:>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("������绰:>");
		scanf("%s", pc->data[pc->sz].telephone);
		printf("�������ַ:>");
		scanf("%s", pc->data[pc->sz].address);
	}
}
//������������
int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
//������������
int CmpByAge(const void* e1, const void* e2)
{
	return(((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age);
}
void SortContact(struct Contact* pc)
{
	assert(pc);
	//qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByAge);
	qsort(pc->data, pc->sz, sizeof(struct PeoInfo), CmpByName);
}