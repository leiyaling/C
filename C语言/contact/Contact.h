#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 50

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char telephone[MAX_TELE];
	char address[MAX_ADDR];
};
struct Contact
{
	struct PeoInfo data[MAX];
	int sz;
};
void  InitContact(struct Contact* pc);
void AddContact(struct Contact* pc);
void ShowContact(const struct Contact* pc);
void DelContact(struct Contact* pc);
void SearchContact(struct Contact* pc);
void ModifyContact(struct Contact* pc);
void SortContact(struct Contact* pc);

