#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9

//多出两行两列用来存放 行号列号 和计算边界的雷数（防止越界）
#define ROWS ROW+2
#define COLS ROW+2

#define EASY_COUNT 10


//初始化棋盘
void init_board(char board[ROWS][COLS],int row,int col,char set);

//打印棋盘
void display_board(char board[ROWS][COLS], int row, int col);

//布置雷
void set_mine(char mine[ROWS][COLS], int row, int col);

//排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);