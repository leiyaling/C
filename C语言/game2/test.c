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
	//设计两个数组存放信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组
	//mine全部初始化为‘0’
	//show全部初始化为‘*’
	init_board(mine, ROWS, COLS,'0');
	init_board(show, ROWS, COLS,'*');
	//打印棋盘
	//display_board(mine, ROW, COL);
	//display_board(show, ROW, COL);
	
	//布置雷
	set_mine(mine, ROW, COL);
	//扫雷
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
		printf("请输入:>");
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
				printf("输入错误，请重新输入：>\n");
				break;

		}
		
	} while (input);
	return 0;
}