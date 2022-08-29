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

//�������
void player_move(char board[ROW][COL], int row, int col)
{
	int x, y = 0;
	printf("����ߣ�\n");
	scanf_s("%d%d", &x, &y);
	//�Ƿ�����
	//���걻ռ��
	if (x > 0 && x <= row && y>0 && y <= col)
	{
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
		}
		else
		{
			printf("�����ѱ�ռ�ã����������룺\n");
		}
	}
	else
	{
		printf("���겻��ȷ\n");
	}


}
//�����������
void computer_move(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�\n");
	//ʹ��randǰҪ����srand
	//���ɵ������%3������0-2
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
	//����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&& board[i][0]!=' ')
			{
				return board[i][0];
			}
	}
	//����
	for (i = 0; i < col; i++)
		{
			
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			{
				return board[0][i];
			}
			
		}	
	//���Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		{
				return board[0][0];
		}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		{
				return board[0][0];
		}
	//�ж��Ƿ�ƽ��
	if (1 == is_full(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}