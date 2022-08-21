#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Menu()
{
	printf("* * * * * * * * * * * * * * * * * * *\n");
	printf("* * * * 1.game  * * *  0.exit * * *\n");
	printf("* * * * * * * * * * * * * * * * * * *\n");
}
void game()
{
	int ret=rand()%100+1;
	int number = 0;
	while (1)
	{
		printf("请再输入一个数字:");
		scanf_s("%d", &number);
		if (number > ret)
			printf("猜大了！\n");
		else if (number < ret)
			printf("猜小了！\n");
		else
		{
			printf("猜对了！\n");
			break;
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input=0;
	
	do
	{
		Menu();
		printf("请选择:>");
		scanf_s("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
			
		
	} while (input);
	return 0;
}
