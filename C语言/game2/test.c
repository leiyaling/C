#include "game.h"

void menu()
{
	printf("*******************\n");
	printf("****** 1.play *****\n");
	printf("*******************\n");
	printf("****** 0.exit *****\n");
	printf("*******************\n");
}
void game()
{
	//���������������Ϣ
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	//mineȫ����ʼ��Ϊ��0��
	//showȫ����ʼ��Ϊ��*��
	init_board(mine, ROWS, COLS,'0');
	init_board(show, ROWS, COLS,'*');
	//��ӡ����
	//display_board(mine, ROW, COL);
	//display_board(show, ROW, COL);
	
	//������
	set_mine(mine, ROW, COL);
	//ɨ��
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);

	find_mine(mine,show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("������:>");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("����������������룺>\n");
				break;

		}
		
	} while (input);
	return 0;
}