#include"game.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void display_board(char board[ROW][COL], int row, int col)
{
	
	//    |   |   
	// ---|---|---
	//    |   |   
	// ---|---|---
	//    |   |
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		//printf(" %c | %c | %c ")
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				//printf("---|---|---")
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		
		printf("\n");
	}
}

//玩家下棋
void player_move(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("玩家走：\n");
	scanf_s("%d%d", &x, &y);
	//非法坐标
	//坐标被占有
	if (x > 0 && x <= row && y>0 && y <= col)
	{
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
		}
		else
		{
			printf("坐标已被占用，请重新输入：\n");
		}
	}
	else
	{
		printf("坐标不正确\n");
	}


}
//电脑随机下棋
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("电脑走：\n");
	//使用rand前要调用srand
	//生成的随机数%3余数在0-2
	int x = rand()%row;
	int y = rand()%col;
	while (1)
	{
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if(' ' == board[i][j])
				return 0;
		}
	}
	return 1;
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&& board[i][0]!=' ')
			{
				return board[i][0];
			}
	}
	//三列
	for (i = 0; i < col; i++)
		{
			
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			{
				return board[0][i];
			}
			
		}	
	//两对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		{
				return board[0][0];
		}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		{
				return board[0][0];
		}
	//判断是否平局
	if (1 == is_full(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}