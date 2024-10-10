#include "game.h"


//1.0�汾
//����Ϊ1.0�汾

//��ŵ��׵����̣���ʼ������Ϊ'0'
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

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------ɨ����Ϸ------\n");
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
	printf("------ɨ����Ϸ------\n");
}


//���õ���
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	//countΪ����
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

//������Χ�ĵ��׸���
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


//������Ҫ���� 1. ��ǹ��� 2. չ��һƬ���� 3.���׵�������¼

//1.1�汾
//����
int flag(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int x, int y)
{
	int mine = 10;
	if (show_board[x][y] == '*')
	{
		show_board[x][y] = '@';//@Ϊ�����ӵĵط�����һ������

		DisplayBoard(show_board, ROW, COL);//��ʾ

		if (land_mine[x][y] == '1')
		{
			mine--;
			printf("%d\n", mine);
			if (mine == 0)
			{
				return 2;
			}
			return 1;//���е���
		}
		return 1;
	}
	else
	{
		printf("����Ƿ���������ѡ��");
	}
}
//չ����ʵ��

//�����겻���ף���û�б��Ų��
//
//��������Χû����
//������ĸ���һ�����ף���Ҫ����չ�����������������������õ�����8���������


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
				//������λ�ò�����
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

//̽�����
void find_Mine(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	int c = 0;
	int ret = 1;

	while (win < row * col - Easy_count)
	{
		printf("1.�Ų�\n2.����\n");
		scanf("%d", &c);
		if (c == 1)
		{
			printf("��������Ҫ �Ų� ������:>");
			scanf("%d %d", &x, &y);
		}
		if (c == 2)
		{
			printf("��������Ҫ �������� ������:>");
			scanf("%d %d", &x, &y);
			ret = flag(land_mine, show_board, x, y);
			if (ret == 2)
				break;
		}
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show_board[x][y] != '*')
			{
				printf("�������Ѿ����Ų���������ظ��Ų�\n");
			}
			else
			{
				if (land_mine[x][y] == '1')//�������
				{
					printf("You're a robot\n�㱻ը����\n");
					DisplayBoard(land_mine, ROW, COL);
					break;
				}
				else//���������
				{
					spread(land_mine, show_board, x, y);
					DisplayBoard(show_board, ROW, COL);
				}
			}
		}
		else
		{
			printf("��������Ƿ�������������:>");
		}
	}
	if (win == row * col - Easy_count)
	{
		printf("NICE!ɨ�׳ɹ�\n");
		DisplayBoard(land_mine, ROW, COL);
	}
}