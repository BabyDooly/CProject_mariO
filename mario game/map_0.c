#pragma warning (disable : 4996)
#include "map.h"


// 하늘 10x20 (case1)
char block_sky[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// 벽 10x20 (case2)
char block_wall[BLACK_HEIGHT][BLACK_WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{7,12,12,12,12,12,12,12,12,12,12,12,12,12,0,7,12,12,12,0},
	{7,12,12,12,12,12,12,12,12,12,12,12,12,12,0,7,0,12,12,0},
	{7,12,12,12,12,12,12,12,12,12,12,12,12,0,7,12,0,0,0,12},
	{7,12,12,12,12,12,12,12,12,12,12,12,12,0,7,12,12,12,12,0},
	{7,12,12,12,12,12,12,12,12,12,12,12,0,7,12,12,12,12,12,0},
	{7,0,0,7,12,12,12,12,12,12,12,12,0,7,12,12,12,12,12,0},
	{7,12,12,12,0,0,7,12,12,12,12,0,7,12,12,12,12,12,12,0},
	{7,12,12,12,12,12,0,7,12,12,0,7,12,12,12,12,12,12,12,0},
	{12,0,0,0,0,0,0,0,0,12,7,0,0,0,0,0,0,0,0,12},

};


// "S" (case3)
char block_S[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,0,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,0,8,8,8,8},
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,0,0,8,8,8},
};
// "U" (case4)
char block_U[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,8,8,8,8,8,8,8,8,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,0,0,8,8,8},
};
// "P" (case5)
char block_P[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,0,0,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
};
// "E" (case6)
char block_E[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
};
// "R" (case7)
char block_R[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,7,7,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,7,7,0,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,7,7,0,8},
};

// 회색 블록 (case 8)
char block_gray[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};

// 마_1 (case 9)
char block_M1[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
};

// 마_2 (case 10)
char block_M2[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,0,8,8,8},
	{0,0,0,0,0,0,0,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
};

// 마_3 (case 11)
char block_M3[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};

// 마_4 (case 12)
char block_M4[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,7,7,7,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,00,0},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{7,7,7,7,7,7,7,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{0,0,0,0,0,0,0,0,0,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};

// 리_1 (case 13)
char block_R1[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};
// 리_2 (case 14)
char block_R2[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{0,0,0,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
};
// 리_3 (case 15)
char block_R3[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};
// 리_4 (case 16)
char block_R4[BLACK_HEIGHT][BLACK_WIDTH] = {
	{7,7,7,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{0,0,0,0,0,0,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,0,8,8,8},
	{0,0,0,0,0,0,0,0,0,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};

// O_1 (case 17)
char block_O1[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,8,0,0,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,7,7,7,7,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,7,7,7,0,0,0,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,7,7,7,7,7,7},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,7,7,0,0,0,0,0},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,7,7,0,8,8,8,8},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,0,0,8,8,8},
};
// O_2 (case 18)
char block_O2[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8},
	{0,0,0,0,0,0,0,0,0,7,7,7,7,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,7,7,7,8,8,8,8,8,8},
	{7,7,7,7,7,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{0,0,0,0,7,7,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{8,7,7,7,7,0,0,8,8,8,8,7,7,7,0,8,8,8,8,8},
};
// O_3 (case 19)
char block_O3[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,7},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,7},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,7},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,7},
	{8,8,8,8,8,8,7,7,7,0,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,7,7,7,7,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7},
	{8,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},

};
// O_4 (case 20)
char block_O4[BLACK_HEIGHT][BLACK_WIDTH] = {
	{7,0,0,0,0,0,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{7,0,8,8,8,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{7,0,8,8,8,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{0,0,8,8,8,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{7,8,8,8,8,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{0,0,8,8,8,8,8,8,8,8,8,7,7,7,0,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,7,7,7,7,0,0,8,8,8,8,8},
	{7,7,7,7,7,7,7,7,7,7,7,0,0,0,8,8,8,8,8,8},
	{0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},

};

// "b" (case 21)
char block_b[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,0,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,0,8,8,8},
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,0,8,8,8},
};

// "r" (case7)
char block_r[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,0,7,7,0,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,7,7,0,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,7,7,0,8,8},
	{8,8,8,8,8,0,0,8,8,8,8,8,8,8,8,8,0,0,8,8},
};

// "o" (case3)
char block_o[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,0,0,8,8,8},
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,8,8},
};

// "s" (case3)
char block_s[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,7,7,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,8,0,0,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8},
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,7,7,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,7,7,0,8,8,8,8,8,8,8,7,7,0,8,8,8},
	{8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,0,0,7,7,8},
	{8,8,8,8,8,8,0,0,0,0,0,0,0,0,0,0,8,8,0,0},
};

// 아래 여백채우기 블록 (case 25)
char block_emp1[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
};

// 위 여백채우기 블록 (case 26)
char block_emp2[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// 오른쪽 여백채우기 블록 (case 27)
char block_emp3[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
};

// 왼쪽 여백채우기 블록 (case 45)
char block_emp4[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
};


// 오른쪽 아래 여백 채우기 (case 30)
char block_cornerR_Down[BLACK_HEIGHT][BLACK_WIDTH] = {
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,0,0,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,9,0,9,9,9,9,9,9,9},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// 오른쪽 위 여백 채우기 (case 46)
char block_cornerR_Up[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,0,0,8,0,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,9,0,9,9,9,9,9,9,9},
	{8,8,8,8,8,8,8,8,8,8,8,0,0,9,9,9,9,9,9,9},
};
// 왼쪽 위 여백 채우기 (case 47)
char block_cornerL_Up[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,0,0,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
};
// 왼쪽 아래 여백 채우기 (case 48)
char block_cornerL_Down[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,0,0,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// 녹색기둥1 (case 31)
char block_G1[BLACK_HEIGHT][BLACK_WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
	{0,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,2,2,2},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,6,2,6,6},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
// 녹색기둥2 (case 32)
char block_G2[BLACK_HEIGHT][BLACK_WIDTH] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,2,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,2,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,2,6,6,0},
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
// 녹색기둥3 (case 33)
char block_G3[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
	{9,9,0,6,6,6,2,2,6,6,6,6,6,6,6,6,6,6,2,6},
};
// 녹색기둥4 (case 34)
char block_G4[BLACK_HEIGHT][BLACK_WIDTH] = {
	{6,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,6,0,9,9},
	{6,2,2,2,2,2,2,2,2,2,2,2,2,6,2,6,6,0,9,9},
};

// "EA" (case 35)
char block_EA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,15,9,9,9,9,15,15,15,15,9,9,9},
	{9,15,15,0,0,0,0,0,0,0,9,9,15,15,0,0,15,15,0,9},
	{9,15,15,0,9,9,9,9,9,9,9,15,15,15,0,9,15,15,15,0},
	{9,15,15,15,15,15,15,15,15,9,9,15,15,15,15,15,15,15,15,0},
	{9,15,15,0,0,0,0,0,0,0,9,15,15,0,0,0,0,15,15,0},
	{9,15,15,0,9,9,9,9,9,9,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,15,15,15,15,15,15,9,9,15,15,0,9,9,9,15,15,0},
	{9,9,0,0,0,0,0,0,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "SY" (case 36)
char block_SY[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,15,15,15,15,15,15,9,9,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,0,0,0,15,15,0,9,15,15,0,0,9,9,15,15,0},
	{9,15,15,0,9,9,9,9,0,0,9,9,15,15,0,0,15,15,0,0},
	{9,9,15,15,15,15,15,15,9,9,9,9,15,15,15,15,15,15,0,9},
	{9,9,9,0,0,0,0,15,15,0,9,9,9,9,15,15,0,0,0,9},
	{9,15,15,9,9,9,9,15,15,0,9,9,9,9,15,15,0,9,9,9},
	{9,9,15,15,15,15,15,15,0,0,9,9,9,9,15,15,0,9,9,9},
	{9,9,9,0,0,0,0,0,0,9,9,9,9,9,9,0,0,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "N" (case 37)
char block_N[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,9,9,9,9,15,15,9},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,15,0,9,9,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,15,15,0,9,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,0,15,15,0,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,0,9,15,15,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,0,9,9,15,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,15,15,0,9,9,9,15,15,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "OR" (case 38)
char block_OR[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,15,15,15,15,15,15,9,9,9,15,15,15,15,15,15,15,9,9},
	{9,15,15,0,0,0,0,15,15,0,9,15,15,0,0,0,0,15,15,0},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,15,15,15,15,15,0,9},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,0,0,15,15,0,9},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,15,15,15,15,15,15,0,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,9,0,0,0,0,0,0,9,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "MA" (case 39)
char block_MA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,9,9,9,9,15,15,9,9,9,9,15,15,15,15,9,9,9},
	{9,15,15,15,9,9,15,15,15,0,9,9,15,15,0,0,15,15,0,9},
	{9,15,15,15,15,15,15,15,15,0,9,15,15,15,0,9,15,15,15,0},
	{9,15,15,0,15,15,0,15,15,0,9,15,15,15,15,15,15,15,15,0},
	{9,15,15,0,15,15,0,15,15,0,9,15,15,0,0,0,0,15,15,0},
	{9,15,15,0,9,0,0,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,0,0,9,9,9,9,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "L" (case 40)
char block_L[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,15,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,0,0,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "HA" (case 41)
char block_HA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,15,15,9,9,9,9,15,15,9,9,9,9,15,15,15,15,9,9,9},
	{9,15,15,0,9,9,9,15,15,0,9,9,15,15,0,0,15,15,0,9},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,15,0,9,15,15,15,0},
	{9,15,15,15,15,15,15,15,15,0,9,15,15,15,15,15,15,15,15,0},
	{9,15,15,0,0,0,0,15,15,0,9,15,15,0,0,0,0,15,15,0},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,0,0,9,9,9,9,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "RD" (case 42)
char block_RD[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,9,9, 9,15,15,15,15,15,15,9,9,9},
	{9,15,15,0,0,0,0,15,15,0, 9,15,15,0,0,0,0,15,15,0},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,15,15,15,15,15,0,9, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,0,0,15,15,0,9, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,15,15,15,15,0,0,0},
	{9,9,0,0,9,9,9,9,0,0, 9,9,9,0,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// 가짜 골인 지점 위쪽 다이아몬드 (case 43)
char block_NoDia[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,12,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,12,15,12,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,12,15,15,15,12,0,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,12,15,15,15,15,15,12,0,9,9,9,9,9,9},
	{9,9,9,9,9,12,15,15,15,15,15,15,15,12,0,9,9,9,9,9},
	{9,9,9,9,9,9,12,15,15,15,15,15,12,0,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,12,15,15,15,12,0,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,12,15,12,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,12,0,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,9,9,9,9,9,9,9,9,9},
};

// 가짜 골인 지점 막대기 (case 44)
char block_NoGoal[BLACK_HEIGHT][BLACK_WIDTH] = {                       
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,15,15,15,0,9,9,9,9,9,9,9,9},
};

// "선택된 EA" 10번칼라 (case49)
char block_Sel_EA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,10,10,10,10,10,10,10,10,9,9,9,9,10,10,10,10,9,9,9},
	{9,10,10,0,0,0,0,0,0,0,9,9,10,10,0,0,10,10,0,9},
	{9,10,10,0,9,9,9,9,9,9,9,10,10,10,0,9,10,10,10,0},
	{9,10,10,10,10,10,10,10,10,9,9,10,10,10,10,10,10,10,10,0},
	{9,10,10,0,0,0,0,0,0,0,9,10,10,0,0,0,0,10,10,0},
	{9,10,10,0,9,9,9,9,9,9,9,10,10,0,9,9,9,10,10,0},
	{9,10,10,10,10,10,10,10,10,9,9,10,10,0,9,9,9,10,10,0},
	{9,9,0,0,0,0,0,0,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "선택된 SY" 10번칼라 (case50)
char block_Sel_SY[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,10,10,10,10,10,10,9,9,9,10,10,0,9,9,9,10,10,0},
	{9,10,10,0,0,0,0,10,10,0,9,10,10,0,0,9,9,10,10,0},
	{9,10,10,0,9,9,9,9,0,0,9,9,10,10,0,0,10,10,0,0},
	{9,9,10,10,10,10,10,10,9,9,9,9,10,10,10,10,10,10,0,9},
	{9,9,9,0,0,0,0,10,10,0,9,9,9,9,10,10,0,0,0,9},
	{9,10,10,9,9,9,9,10,10,0,9,9,9,9,10,10,0,9,9,9},
	{9,9,10,10,10,10,10,10,0,0,9,9,9,9,10,10,0,9,9,9},
	{9,9,9,0,0,0,0,0,0,9,9,9,9,9,9,0,0,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "선택된 N" 14번칼라 (case51)
char block_Sel_N[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,9,9,9,9,14,14,9},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,14,0,9,9,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,14,14,0,9,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,0,14,14,0,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,0,9,14,14,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,0,9,9,14,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,14,14,0,9,9,9,14,14,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "선택된 OR" 14번칼라 (case52)
char block_Sel_OR[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,14,14,14,14,14,14,9,9,9,14,14,14,14,14,14,14,9,9},
	{9,14,14,0,0,0,0,14,14,0,9,14,14,0,0,0,0,14,14,0},
	{9,14,14,0,9,9,9,14,14,0,9,14,14,0,9,9,9,14,14,0},
	{9,14,14,0,9,9,9,14,14,0,9,14,14,14,14,14,14,14,0,9},
	{9,14,14,0,9,9,9,14,14,0,9,14,14,0,0,0,14,14,0,9},
	{9,14,14,0,9,9,9,14,14,0,9,14,14,0,9,9,9,14,14,0},
	{9,9,14,14,14,14,14,14,0,0,9,14,14,0,9,9,9,14,14,0},
	{9,9,9,0,0,0,0,0,0,9,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "선택된 MA" 14번칼라 (case53)
char block_Sel_MA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,9,9,9,9,14,14,9,9,9,9,14,14,14,14,9,9,9},
	{9,14,14,14,9,9,14,14,14,0,9,9,14,14,0,0,14,14,0,9},
	{9,14,14,14,14,14,14,14,14,0,9,14,14,14,0,9,14,14,14,0},
	{9,14,14,0,14,14,0,14,14,0,9,14,14,14,14,14,14,14,14,0},
	{9,14,14,0,14,14,0,14,14,0,9,14,14,0,0,0,0,14,14,0},
	{9,14,14,0,9,0,0,14,14,0,9,14,14,0,9,9,9,14,14,0},
	{9,14,14,0,9,9,9,14,14,0,9,14,14,0,9,9,9,14,14,0},
	{9,9,0,0,9,9,9,9,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "선택된 L" 14번칼라 (case54)
char block_Sel_L[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,14,14,14,14,14,14,14,14,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,0,0,0,0,0,0,0,9,9,9,9,9,9,9,9,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "선택된 HA" 12번칼라 (case55)
char block_Sel_HA[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,12,12,9,9,9,9,12,12,9,9,9,9,12,12,12,12,9,9,9},
	{9,12,12,0,9,9,9,12,12,0,9,9,12,12,0,0,12,12,0,9},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,12,0,9,12,12,12,0},
	{9,12,12,12,12,12,12,12,12,0,9,12,12,12,12,12,12,12,12,0},
	{9,12,12,0,0,0,0,12,12,0,9,12,12,0,0,0,0,12,12,0},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,0,9,9,9,12,12,0},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,0,9,9,9,12,12,0},
	{9,9,0,0,9,9,9,9,0,0,9,9,0,0,9,9,9,9,0,0},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};
// "선택된 RD" 12번칼라 (case56)
char block_Sel_RD[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,12,12,12,12,12,12,12,9,9,9,12,12,12,12,12,12,9,9,9},
	{9,12,12,0,0,0,0,12,12,0,9,12,12,0,0,0,0,12,12,0},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,0,9,9,9,12,12,0},
	{9,12,12,12,12,12,12,12,0,9,9,12,12,0,9,9,9,12,12,0},
	{9,12,12,0,0,0,12,12,0,9,9,12,12,0,9,9,9,12,12,0},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,0,9,9,9,12,12,0},
	{9,12,12,0,9,9,9,12,12,0,9,12,12,12,12,12,12,0,0,0},
	{9,9,0,0,9,9,9,9,0,0,9,9,9,0,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "SU" (case 59)
char block_SU[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,15,15,15,15,15,15,9,9,9,15,15,9,9,9,9,15,15,9},
	{9,15,15,0,0,0,0,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,9,0,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,15,15,15,15,15,15,9,9,9,15,15,0,9,9,9,15,15,0},
	{9,9,9,0,0,0,0,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,15,15,9,9,9,9,15,15,0,9,15,15,0,9,9,9,15,15,0},
	{9,9,15,15,15,15,15,15,0,0,9,9,15,15,15,15,15,15,0,0},
	{9,9,9,0,0,0,0,0,0,9,9,9,9,0,0,0,0,0,0,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "RV" (case 60)
char block_RV[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,9,9, 9,15,15,9,9,9,9,15,15,9},
	{9,15,15,0,0,0,0,15,15,0, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,0,9,9,9,15,15,0},
	{9,15,15,15,15,15,15,15,0,9, 9,9,15,15,0,9,15,15,0,0},
	{9,15,15,0,0,0,15,15,0,9, 9,9,15,15,0,9,15,15,0,9},
	{9,15,15,0,9,9,9,15,15,0, 9,9,9,15,0,9,15,0,0,9},
	{9,15,15,0,9,9,9,15,15,0, 9,9,9,15,15,15,15,0,9,9},
	{9,9,0,0,9,9,9,9,0,0, 9,9,9,9,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// "IV" (case 61)
char block_IV[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,15,9, 9,15,15,9,9,9,9,15,15,9},
	{9,9,0,0,15,15,0,0,0,0, 9,15,15,0,9,9,9,15,15,0},
	{9,9,9,9,15,15,0,9,9,9, 9,15,15,0,9,9,9,15,15,0},
	{9,9,9,9,15,15,0,9,9,9, 9,9,15,15,0,9,15,15,0,0},
	{9,9,9,9,15,15,0,9,9,9, 9,9,15,15,0,9,15,15,0,9},
	{9,9,9,9,15,15,0,9,9,9, 9,9,9,15,0,9,15,0,0,9},
	{9,15,15,15,15,15,15,15,15,9, 9,9,9,15,15,15,15,0,9,9},
	{9,9,0,0,0,0,0,0,0,0, 9,9,9,9,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// "AL" (case 62)
char block_AL[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,9,9,15,15,15,15,9,9,9, 9,15,15,9,9,9,9,9,9,9},
	{9,9,15,15,0,0,15,15,0,9, 9,15,15,0,9,9,9,9,9,9},
	{9,15,15,15,0,9,15,15,15,0, 9,15,15,0,9,9,9,9,9,9},
	{9,15,15,15,15,15,15,15,15,0, 9,15,15,0,9,9,9,9,9,9},
	{9,15,15,0,0,0,0,15,15,0, 9,15,15,0,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,0,9,9,9,9,9,9},
	{9,15,15,0,9,9,9,15,15,0, 9,15,15,15,15,15,15,15,15,9},
	{9,9,0,0,9,9,9,9,0,0, 9,9,9,0,0,0,0,0,0,0},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// "선택된 SU" (case 67)
char block_Sel_SU[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,9,13,13,13,13,13,13,9,9,9,13,13,9,9,9,9,13,13,9},
	{9,13,13,0,0,0,0,13,13,0,9,13,13,0,9,9,9,13,13,0},
	{9,13,13,0,9,9,9,9,0,0,9,13,13,0,9,9,9,13,13,0},
	{9,9,13,13,13,13,13,13,9,9,9,13,13,0,9,9,9,13,13,0},
	{9,9,9,0,0,0,0,13,13,0,9,13,13,0,9,9,9,13,13,0},
	{9,13,13,9,9,9,9,13,13,0,9,13,13,0,9,9,9,13,13,0},
	{9,9,13,13,13,13,13,13,0,0,9,9,13,13,13,13,13,13,0,0},
	{9,9,9,0,0,0,0,0,0,9,9,9,9,0,0,0,0,0,0,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

// "선택된 RV" (case 68)
char block_Sel_RV[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,13,13,13,13,13,13,13,9,9, 9,13,13,9,9,9,9,13,13,9},
	{9,13,13,0,0,0,0,13,13,0, 9,13,13,0,9,9,9,13,13,0},
	{9,13,13,0,9,9,9,13,13,0, 9,13,13,0,9,9,9,13,13,0},
	{9,13,13,13,13,13,13,13,0,9, 9,9,13,13,0,9,13,13,0,0},
	{9,13,13,0,0,0,13,13,0,9, 9,9,13,13,0,9,13,13,0,9},
	{9,13,13,0,9,9,9,13,13,0, 9,9,9,13,0,9,13,0,0,9},
	{9,13,13,0,9,9,9,13,13,0, 9,9,9,13,13,13,13,0,9,9},
	{9,9,0,0,9,9,9,9,0,0, 9,9,9,9,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// "선택된 IV" (case 69)
char block_Sel_IV[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,13,13,13,13,13,13,13,13,9, 9,13,13,9,9,9,9,13,13,9},
	{9,9,0,0,13,13,0,0,0,0, 9,13,13,0,9,9,9,13,13,0},
	{9,9,9,9,13,13,0,9,9,9, 9,13,13,0,9,9,9,13,13,0},
	{9,9,9,9,13,13,0,9,9,9, 9,9,13,13,0,9,13,13,0,0},
	{9,9,9,9,13,13,0,9,9,9, 9,9,13,13,0,9,13,13,0,9},
	{9,9,9,9,13,13,0,9,9,9, 9,9,9,13,0,9,13,0,0,9},
	{9,13,13,13,13,13,13,13,13,9, 9,9,9,13,13,13,13,0,9,9},
	{9,9,0,0,0,0,0,0,0,0, 9,9,9,9,0,0,0,0,9,9},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};

// "선택된 AL" (case 70)
char block_Sel_AL[BLACK_HEIGHT][BLACK_WIDTH] = {
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
	{9,9,9,13,13,13,13,9,9,9, 9,13,13,9,9,9,9,9,9,9},
	{9,9,13,13,0,0,13,13,0,9, 9,13,13,0,9,9,9,9,9,9},
	{9,13,13,13,0,9,13,13,13,0, 9,13,13,0,9,9,9,9,9,9},
	{9,13,13,13,13,13,13,13,13,0, 9,13,13,0,9,9,9,9,9,9},
	{9,13,13,0,0,0,0,13,13,0, 9,13,13,0,9,9,9,9,9,9},
	{9,13,13,0,9,9,9,13,13,0, 9,13,13,0,9,9,9,9,9,9},
	{9,13,13,0,9,9,9,13,13,0, 9,13,13,13,13,13,13,13,13,9},
	{9,9,0,0,9,9,9,9,0,0, 9,9,9,0,0,0,0,0,0,0},
	{9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9},
};


// 전체 맵 12x16
int map_0[MAP_HEIGHT][MAP_WIDTH_0] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,47,25,25,25,25,25,25,25,25,25,25,46,1,1},
		{1,1,45,3,4,5,6,7,8,8,8,8,8,27,1,1},
		{1,1,45,9,10,13,14,17,18,8,8,8,8,27,1,1},
		{1,1,45,11,12,15,16,19,20,21,22,23,24,27,1,1},
		{1,1,48,26,26,26,26,26,26,26,26,26,26,30,1,1},
		{1,1,43,1,1,1,1,57,58,1,1,1,1,1,1,1},
		{1,1,44,1,1,1,59,60,61,62,1,1,1,1,1,1},
		{1,1,44,1,1,1,1,63,64,1,1,1,1,1,1,1},
		{1,1,44,1,1,1,1,1,1,1,1,1,31,32,1,1},
		{1,1,44,1,1,1,1,1,1,1,1,1,33,34,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
};

int full_map_0[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_0] = { 0 };
