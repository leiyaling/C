#include"game.h"
void menu()
{
	printf("********   1.play    ********\n");
	printf("*****************************\n");
	printf("********   0.exit    ********\n");
	printf("*****************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	init_board(board, ROW, COL);
	//��ӡ����
	display_board(board, ROW,  COL);
	//�жϣ�1�����Ӯ ����* 2������Ӯ ����#  3��ƽ�� ����Q 4����Ϸ���� ����C
	while (1)
	{
		player_move(board, ROW, COL);
		display_board(board, ROW, COL);
    //�ж�����Ƿ�Ӯ
		ret=is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		computer_move(board, ROW, COL);
		display_board(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}	

		if (ret == '*')
			printf("���Ӯ\n");
		else if (ret == '#')
			printf("����Ӯ\n");
		else if (ret == 'Q')
			printf("ƽ��\n");
	
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
	    menu();
		printf("������>>\n");
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
				printf("�����������������\n");
				break;
		}
			
	} 
	while (input);
	return 0;
}
