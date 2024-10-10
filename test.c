#include "game.h"

void menu()
{
	printf("\n");
	printf("======|      ɨ��      |======\n");
	printf("======|     1.play     |======\n");
	printf("======|     0.exit     |======\n");
}

void game()
{
	int ret = 1;
	int ret2 = 1;//����
	int c = 0;
	int x = 0;
	int y = 0;

	char land_mine[ROWS][COLS] = { 0 };
	//����һ����ŵ��׵�����
	char show_board[ROWS][COLS] = { 0 };
	//����һ����ŵ���λ����Ϣ������
	InitBoard(land_mine, ROWS, COLS, '0');
	//��ʼ����ŵ��׵�����
	InitBoard(show_board, ROWS, COLS, '*');
	//��ʼ����ŵ���λ����Ϣ������
	//���õ���
	//DisplayBoard(show_board, ROW, COL);
	SetMine(land_mine, ROW, COL);
	DisplayBoard(show_board, ROW, COL);
	//DisplayBoard(land_mine, ROW, COL);


	//1.1�汾
	do
	{
		printf("��ѡ��������Ķ���: >\n1.̽�����   2.��ȷ�ϵĵ���λ�ò��ϵ���\n");
		scanf("%d", &c);

		if (c == 2)
		{
			printf("��������Ҫ �������� ������:>");
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
	//��������������ɵ�
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("      ��Ϸ��ʼ!    \n");
			printf(" Good luck to you!\n");
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�Ŵ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}
