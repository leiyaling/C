#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include <stdlib.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 50
#define DEFAULT_SZ 3
#define INC_SZ 2
struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char telephone[MAX_TELE];
	char address[MAX_ADDR];
};
//¾²Ì¬°æ±¾
//struct Contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//};
struct Contact
{
	struct PeoInfo* data;
	int sz;
	int capacity;
};
void  InitContact(struct Contact* pc);
void AddContact(struct Contact* pc);
void ShowContact(const struct Contact* pc);
void DelContact(struct Contact* pc);
void SearchContact(struct Contact* pc);
void ModifyContact(struct Contact* pc);
void SortContact(struct Contact* pc);
void LoadContact(struct Contact* pc);
void DestroyContact(struct Contact* pc);
void SaveContact(struct Contact* pc);