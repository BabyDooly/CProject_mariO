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



// 전체맵 세로크기(블럭)
#define MAP_HEIGHT 12

//블럭 크기 10X20
#define BLACK_HEIGHT 10
#define BLACK_WIDTH 20

// 전체맵 세로크기
#define MAP_FULL_HEIGHT MAP_HEIGHT * BLACK_HEIGHT

// 출력 크기(블럭) 12X16
#define PRINT_HEIGHT 12
#define PRINT_WIDTH 16

//출력 크기 120X320
#define PRINT_FULL_HEIGHT PRINT_HEIGHT*BLACK_HEIGHT
#define PRINT_FULL_WIDTH PRINT_WIDTH*BLACK_WIDTH

WORD color[PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH];

// menu 전체맵 가로크기(블럭)
#define MAP_WIDTH_0 16

// menu 전체맵 가로크기
#define MAP_FULL_WIDTH_0 MAP_WIDTH_1 *BLACK_WIDTH

// Stage1 전체맵 가로크기(블럭)
#define MAP_WIDTH_1 194

// Stage1 전체맵 가로크기
#define MAP_FULL_WIDTH_1 MAP_WIDTH_1 *BLACK_WIDTH

// Stage2 전체맵 크기(블럭)
#define MAP_WIDTH_2 201

// Stage2 전체맵 가로크기
#define MAP_FULL_WIDTH_2 MAP_WIDTH_2 *BLACK_WIDTH

// Stage3 전체맵 가로크기(블럭)
#define MAP_WIDTH_3 272

// Stage3 전체맵 가로크기
#define MAP_FULL_WIDTH_3 MAP_WIDTH_3 *BLACK_WIDTH

// 구조체
struct Pos
{
	int X;
	int Y;
	int flag;
	int mov;
};
