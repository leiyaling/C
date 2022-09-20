#include"Contact.h"
void menu()
{
	printf("******   1.add        2.del      *******\n");
	printf("******   3.search     4.modify   *******\n");
	printf("******   5.show       6.sort     *******\n");
	printf("******   0.exit                  *******\n");
}
void test()
{
	int input = 0;
	struct Contact con;
	InitContact(&con);
	do {
		menu();
		printf("ÇëÑ¡Ôñ£º>>");
		scanf_s("%d", &input);
		switch(input)
		{
			case 1:
				AddContact(&con);
				break;
			case 2:
				DelContact(&con);
				break;
			case 3:
				SearchContact(&con);
				break;
			case 4:
				ModifyContact(&con);
				break;
			case 5:
				ShowContact(&con);
				break;
			case 6:
				SortContact(&con);
				break;
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