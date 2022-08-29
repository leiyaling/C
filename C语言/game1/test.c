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
	//初始化数组
	init_board(board, ROW, COL);
	//打印棋盘
	display_board(board, ROW,  COL);
	//判断：1、玩家赢 返回* 2、电脑赢 返回#  3、平局 返回Q 4、游戏继续 返回C
	while (1)
	{
		player_move(board, ROW, COL);
		display_board(board, ROW, COL);
    //判断玩家是否赢
		ret=is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		computer_move(board, ROW, COL);
		display_board(board, ROW, COL);
		//判断电脑是否赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}	

		if (ret == '*')
			printf("玩家赢\n");
		else if (ret == '#')
			printf("电脑赢\n");
		else if (ret == 'Q')
			printf("平局\n");
	
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
	    menu();
		printf("请输入>>\n");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}
			
	} 
	while (input);
	return 0;
}
