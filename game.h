#pragma once
#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//标准棋盘
#define ROW 9
#define COL 9

//拓展棋盘
#define ROWS ROW+2
#define COLS COL+2

//简单模式 设置10个地雷
#define Easy_count 10

//声明
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
//初始化棋盘，更具期棋盘的功能初始化'0'、'*'

void DisplayBoard(char board[ROWS][COLS], int row, int col);
//打印棋盘

void SetMine(char board[ROWS][COLS], int row, int col);
//设置地雷

void find_Mine(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//显示周围地雷的数量

int flag(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//旗帜

void spread(char land_mine[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);
//展开
