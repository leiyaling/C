#include"game.h"


void init_board(char board[ROWS][COLS], int row, int col, char set)
{
	int i,j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}
void display_board(char board[ROWS][COLS], int row, int col)
{
	
	int i, j = 0;
	//�к�
	for (j = 0; j <= col; j++)
	{
		printf(" %d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//�к�
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			
			 printf(" %c ",board[i][j]);
		}
		printf("\n");
	}
}
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
				count--;
			}
		
	}
	
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return(mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');

}
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//'2'-'0'=50-48=2
	//�ҳ�71�����׵�λ�ã���Ϸ����
	//���ף���Ϸ����
	int win = 0;int x, y = 0;
	while (win<row*col- EASY_COUNT)
	{
			printf("���������׵����꣺>");
			scanf_s("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] == '*')
				{
					if (mine[x][y] == '1')
					{
						printf("���ź����㱻ը����\n");
						display_board(mine, ROW, COL);
						break;
					}
					else {
							int count = get_mine_count(mine, x, y);
							show[x][y] = count + '0';
							display_board(show, ROW, COL);
							win++;
					}
				}
				else
				{
					printf("�������Ѿ����Ų����\n");
				}
				
			}
			else
			{
				printf("����Ƿ������������룺>\n");
			}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		display_board(mine, ROW, COL);
	}
	
}
