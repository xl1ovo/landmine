#pragma once
#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//��׼����
#define ROW 9
#define COL 9

//��չ����
#define ROWS ROW+2
#define COLS COL+2

//��ģʽ ����10������
#define Easy_count 10

//����
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//��ʼ�����̣����������̵Ĺ��ܳ�ʼ��'0'��'*'

void DisplayBoard(char board[ROWS][COLS], int row, int col);
//��ӡ����

void SetMine(char board[ROWS][COLS], int row, int col);
//���õ���

void find_Mine(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//��ʾ��Χ���׵�����

int flag(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//����

void spread(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//չ��
