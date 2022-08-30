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
	//列号
	for (j = 0; j <= col; j++)
	{
		printf(" %d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//行号
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
	//找出71个非雷的位置，游戏结束
	//踩雷，游戏结束
	int win = 0;int x, y = 0;
	while (win<row*col- EASY_COUNT)
	{
			printf("请输入排雷的坐标：>");
			scanf_s("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] == '*')
				{
					if (mine[x][y] == '1')
					{
						printf("很遗憾，你被炸死了\n");
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
					printf("该坐标已经被排查过了\n");
				}
				
			}
			else
			{
				printf("坐标非法，请重新输入：>\n");
			}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		display_board(mine, ROW, COL);
	}
	
}
