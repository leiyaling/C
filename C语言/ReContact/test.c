#include"Contact.h"
void menu()
{
	printf("******   1.add        2.del      *******\n");
	printf("******   3.search     4.modify   *******\n");
	printf("******   5.show       6.sort     *******\n");
	printf("******   0.exit                  *******\n");
}

//枚举
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
void test()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do {
		menu();
		printf("请选择：>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			printf("保存文件成功\n");
			DestroyContact(&con);
			printf("退出通讯录\n");
		default:
			break;

		}


	} while (input);
}
int main()
{
	test();
	return 0;
}