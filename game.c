#include "game.h"


//1.0版本
//此下为1.0版本

//存放地雷的棋盘，初始化棋盘为'0'
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------扫雷游戏------\n");
}


//设置地雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	//count为地雷
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//计算周围的地雷个数
int GetMine_Count(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y] +
		board[x - 1][y - 1] +
		board[x][y - 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] +
		board[x][y + 1] +
		board[x - 1][y + 1] - 8 * '0');
}


//后续需要升级 1. 标记功能 2. 展开一片功能 3.地雷的数量记录

//1.1版本
//插旗
int flag(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
{
	int mine = 10;
	if (show_board[x][y] == '*')
	{
		show_board[x][y] = '@';//@为插旗子的地方方上一个旗帜

		DisplayBoard(show_board, ROW, COL);//显示

		if (land_mine[x][y] == '1')
		{
			mine--;
			printf("%d\n", mine);
			if (mine == 0)
			{
				return 2;
			}
			return 1;//还有地雷
		}
		return 1;
	}
	else
	{
		printf("坐标非法，请重新选择");
	}
}
//展开的实现

//该坐标不是雷，且没有被排查过
//
//该坐标周围没有雷
//该坐标的附近一旦有雷，则不要进入展开函数，遍历附近格子数得到附近8格地雷数量


//
void spread(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
{
	int set_x = 0;
	int set_y = 0;
	int count = 0;

	if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
	{
		for (set_x = -1; set_x <= 1; set_x++)
		{
			for (set_y = -1; set_y <= 1; set_y++)
			{
				//如果这个位置不是雷
				if (land_mine[x + set_x][y + set_y] == '0')
				{
					count = GetMine_Count(land_mine, set_x + x, set_y + y);
					if (count == 0)
					{
						if (show_board[set_x + x][set_y + y] == '*')
						{
							show_board[set_x + x][set_y + y] = ' ';
							spread(land_mine, show_board, set_x + x, set_y + y);
						}
					}
					else
					{
						show_board[set_x + x][set_y + y] = count + '0';
					}

				}
			}
		}
	}
}

//探查地雷
void find_Mine(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int c = 0;
	int ret = 1;

	while (win < row * col - Easy_count)
	{
		printf("1.排查\n2.旗帜\n");
		scanf("%d", &c);
		if (c == 1)
		{
			printf("请输入需要 排查 的坐标:>");
			scanf("%d %d", &x, &y);
		}
		if (c == 2)
		{
			printf("请输入需要 插下旗帜 的坐标:>");
			scanf("%d %d", &x, &y);
			ret = flag(land_mine, show_board, x, y);
			if (ret == 2)
				break;
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show_board[x][y] != '*')
			{
				printf("该坐标已经被排查过，请勿重复排查\n");
			}
			else
			{
				if (land_mine[x][y] == '1')//如果是雷
				{
					printf("You're a robot\n你被炸死了\n");
					DisplayBoard(land_mine, ROW, COL);
					break;
				}
				else//如果不是雷
				{
					spread(land_mine, show_board, x, y);
					DisplayBoard(show_board, ROW, COL);
				}
			}
		}
		else
		{
			printf("坐标输入非法，请重新输入:>");
		}
	}
	if (win == row * col - Easy_count)
	{
		printf("NICE!扫雷成功\n");
		DisplayBoard(land_mine, ROW, COL);
	}
}