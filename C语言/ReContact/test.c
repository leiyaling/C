#include"Contact.h"
void menu()
{
	printf("******   1.add        2.del      *******\n");
	printf("******   3.search     4.modify   *******\n");
	printf("******   5.show       6.sort     *******\n");
	printf("******   0.exit                  *******\n");
}

//ö��
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
	//����ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do {
		menu();
		printf("��ѡ��>>");
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
			printf("�����ļ��ɹ�\n");
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
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