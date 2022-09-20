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
		printf("通讯录已满，无法添加数据\n");
		return;
	}

	//增加人的信息
	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].telephone);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].address);

	pc->sz++;
	printf("成功增加联系人\n");
}
void ShowContact(const struct Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-5s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话号码", "地址");
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
	printf("请输入需要删除人的名字：>");
	scanf("%s", name);
	//查找一下要删除的人是否存在
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("需要删除的人不存在");
	else
	{
		int j = 0;
		for (j = ret; j < pc->sz - 1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		pc->sz--;
		printf("成功删除联系人");
	}
}
void SearchContact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入需要查找的名字：>");
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
			printf("找不到这个名字\n");
		}
	}

}
void ModifyContact(struct Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入需要修改的人的名字：>\n");
	int ret = FindByName(pc, name);
	if (ret == -1)
		printf("需要删除的人不存在");
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].telephone);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->sz].address);
	}
}
//按照名字排序
int CmpByName(const void* e1, const void* e2)
{
	return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}
//按照年龄排序
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