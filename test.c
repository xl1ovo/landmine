#include "game.h"

void menu()
{
	printf("\n");
	printf("======|      扫雷      |======\n");
	printf("======|     1.play     |======\n");
	printf("======|     0.exit     |======\n");
}

void game()
{
	int ret = 1;
	int ret2 = 1;//旗帜
	int c = 0;
	int x = 0;
	int y = 0;

	char land_mine[ROWS][COLS] = { 0 };
	//创建一个存放地雷的棋盘
	char show_board[ROWS][COLS] = { 0 };
	//创建一个存放地雷位置信息的棋盘
	InitBoard(land_mine, ROWS, COLS, '0');
	//初始化存放地雷的棋盘
	InitBoard(show_board, ROWS, COLS, '*');
	//初始化存放地雷位置信息的棋盘
	//设置地雷
	//DisplayBoard(show_board, ROW, COL);
	SetMine(land_mine, ROW, COL);
	DisplayBoard(show_board, ROW, COL);
	//DisplayBoard(land_mine, ROW, COL);


	//1.1版本
	do
	{
		printf("请选择接下来的动作: >\n1.探查地雷   2.在确认的地雷位置插上地雷\n");
		scanf("%d", &c);

		if (c == 2)
		{
			printf("请输入需要 插下旗帜 的坐标:>");
			scanf("%d %d", &x, &y);
			ret2 = flag(land_mine, show_board, x, y);

			if (ret2 == 2)
				break;
		}
		else if (c == 1)
		{
			find_Mine(land_mine, show_board, ROWS, COLS);
		}

	} while (ret);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	//设置随机地雷生成点
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("      游戏开始!    \n");
			printf(" Good luck to you!\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选着错误，请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}
