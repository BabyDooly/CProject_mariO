#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <io.h>
#include <process.h>
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment(lib,"winmm.lib")



// ��ü�� ����ũ��(��)
#define MAP_HEIGHT 12

//�� ũ�� 10X20
#define BLACK_HEIGHT 10
#define BLACK_WIDTH 20

// ��ü�� ����ũ��
#define MAP_FULL_HEIGHT MAP_HEIGHT * BLACK_HEIGHT

// ��� ũ��(��) 12X16
#define PRINT_HEIGHT 12
#define PRINT_WIDTH 16

//��� ũ�� 120X320
#define PRINT_FULL_HEIGHT PRINT_HEIGHT*BLACK_HEIGHT
#define PRINT_FULL_WIDTH PRINT_WIDTH*BLACK_WIDTH

WORD color[PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH];

// menu ��ü�� ����ũ��(��)
#define MAP_WIDTH_0 16

// menu ��ü�� ����ũ��
#define MAP_FULL_WIDTH_0 MAP_WIDTH_1 *BLACK_WIDTH

// Stage1 ��ü�� ����ũ��(��)
#define MAP_WIDTH_1 194

// Stage1 ��ü�� ����ũ��
#define MAP_FULL_WIDTH_1 MAP_WIDTH_1 *BLACK_WIDTH

// Stage2 ��ü�� ũ��(��)
#define MAP_WIDTH_2 201

// Stage2 ��ü�� ����ũ��
#define MAP_FULL_WIDTH_2 MAP_WIDTH_2 *BLACK_WIDTH

// Stage3 ��ü�� ����ũ��(��)
#define MAP_WIDTH_3 272

// Stage3 ��ü�� ����ũ��
#define MAP_FULL_WIDTH_3 MAP_WIDTH_3 *BLACK_WIDTH

// ����ü
struct Pos
{
	int X;
	int Y;
	int flag;
	int mov;
};
