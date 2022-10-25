#pragma warning (disable : 4996)
#include "function.h"
#include "map.h"

/* -------- 블럭 --------- */
char block_sky[BLACK_HEIGHT][BLACK_WIDTH];	// 하늘 10x20 (case1)
char block_wall[BLACK_HEIGHT][BLACK_WIDTH];	// 벽 10x20 (case2)
char block_S[BLACK_HEIGHT][BLACK_WIDTH];	// "S" (case3)
char block_U[BLACK_HEIGHT][BLACK_WIDTH];	// "U" (case4)
char block_P[BLACK_HEIGHT][BLACK_WIDTH];	// "P" (case5)
char block_E[BLACK_HEIGHT][BLACK_WIDTH];	// "E" (case6)
char block_R[BLACK_HEIGHT][BLACK_WIDTH];	// "R" (case7)
char block_gray[BLACK_HEIGHT][BLACK_WIDTH];	// 회색 블록 (case 8)
char block_M1[BLACK_HEIGHT][BLACK_WIDTH];	// 마_1 (case 9)
char block_M2[BLACK_HEIGHT][BLACK_WIDTH];	// 마_2 (case 10)
char block_M3[BLACK_HEIGHT][BLACK_WIDTH];	// 마_3 (case 11)
char block_M4[BLACK_HEIGHT][BLACK_WIDTH];	// 마_4 (case 12)
char block_R1[BLACK_HEIGHT][BLACK_WIDTH];	// 리_1 (case 13)
char block_R2[BLACK_HEIGHT][BLACK_WIDTH];	// 리_2 (case 14)
char block_R3[BLACK_HEIGHT][BLACK_WIDTH];	// 리_3 (case 15)
char block_R4[BLACK_HEIGHT][BLACK_WIDTH];	// 리_4 (case 16)
char block_O1[BLACK_HEIGHT][BLACK_WIDTH];	// O_1 (case 17)
char block_O2[BLACK_HEIGHT][BLACK_WIDTH];	// O_2 (case 18)
char block_O3[BLACK_HEIGHT][BLACK_WIDTH];	// O_3 (case 19)
char block_O4[BLACK_HEIGHT][BLACK_WIDTH];	// O_4 (case 20)
char block_b[BLACK_HEIGHT][BLACK_WIDTH];	// "b" (case 21)
char block_r[BLACK_HEIGHT][BLACK_WIDTH];	// "r" (case7)
char block_o[BLACK_HEIGHT][BLACK_WIDTH];	// "o" (case3)
char block_s[BLACK_HEIGHT][BLACK_WIDTH];	// "s" (case3)
char block_emp1[BLACK_HEIGHT][BLACK_WIDTH];			// 아래 여백채우기 블록 (case 25)
char block_emp2[BLACK_HEIGHT][BLACK_WIDTH];			// 위 여백채우기 블록 (case 26)
char block_emp3[BLACK_HEIGHT][BLACK_WIDTH];			// 오른쪽 여백채우기 블록 (case 27)
char block_emp4[BLACK_HEIGHT][BLACK_WIDTH];			// 왼쪽 여백채우기 블록 (case 45)
char block_cornerR_Down[BLACK_HEIGHT][BLACK_WIDTH];	// 오른쪽 아래 여백 채우기 (case 30)
char block_cornerR_Up[BLACK_HEIGHT][BLACK_WIDTH];	// 오른쪽 위 여백 채우기 (case 46)
char block_cornerL_Up[BLACK_HEIGHT][BLACK_WIDTH];	// 왼쪽 위 여백 채우기 (case 47)
char block_cornerL_Down[BLACK_HEIGHT][BLACK_WIDTH];	// 왼쪽 아래 여백 채우기 (case 48)
char block_G1[BLACK_HEIGHT][BLACK_WIDTH];	// 녹색기둥1 (case 31)
char block_G2[BLACK_HEIGHT][BLACK_WIDTH];	// 녹색기둥2 (case 32)
char block_G3[BLACK_HEIGHT][BLACK_WIDTH];	// 녹색기둥3 (case 33)
char block_G4[BLACK_HEIGHT][BLACK_WIDTH];	// 녹색기둥4 (case 34)
char block_EA[BLACK_HEIGHT][BLACK_WIDTH];	// "EA" (case 35)
char block_SY[BLACK_HEIGHT][BLACK_WIDTH];	// "SY" (case 36)
char block_N[BLACK_HEIGHT][BLACK_WIDTH];	// "N" (case 37)
char block_OR[BLACK_HEIGHT][BLACK_WIDTH];	// "OR" (case 38)
char block_MA[BLACK_HEIGHT][BLACK_WIDTH];	// "MA" (case 39)
char block_L[BLACK_HEIGHT][BLACK_WIDTH];	// "L" (case 40)
char block_HA[BLACK_HEIGHT][BLACK_WIDTH];	// "HA" (case 41)
char block_RD[BLACK_HEIGHT][BLACK_WIDTH];	// "RD" (case 42)
char block_NoDia[BLACK_HEIGHT][BLACK_WIDTH];	// 가짜 골인 지점 위쪽 다이아몬드 (case 43)
char block_NoGoal[BLACK_HEIGHT][BLACK_WIDTH];	// 가짜 골인 지점 막대기 (case 44)
char block_Sel_EA[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 EA" 10번칼라 (case49)
char block_Sel_SY[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 SY" 10번칼라 (case50)
char block_Sel_N[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 N" 14번칼라 (case51)
char block_Sel_OR[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 OR" 14번칼라 (case52)
char block_Sel_MA[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 MA" 14번칼라 (case53)
char block_Sel_L[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 L" 14번칼라 (case54)
char block_Sel_HA[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 HA" 12번칼라 (case55)
char block_Sel_RD[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 RD" 12번칼라 (case56)
char block_SU[BLACK_HEIGHT][BLACK_WIDTH];		// "SU" (case 59)
char block_RV[BLACK_HEIGHT][BLACK_WIDTH];		// "RV" (case 60)
char block_IV[BLACK_HEIGHT][BLACK_WIDTH];		// "IV" (case 61)
char block_AL[BLACK_HEIGHT][BLACK_WIDTH];		// "AL" (case 62)
char block_Sel_SU[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 SU" (case 67)
char block_Sel_RV[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 RV" (case 68)
char block_Sel_IV[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 IV" (case 69)
char block_Sel_AL[BLACK_HEIGHT][BLACK_WIDTH];	// "선택된 AL" (case 70)

int map_0[MAP_HEIGHT][MAP_WIDTH_0];				// 전체 맵 12x16
int full_map_0[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_0];


/* -------- 변수 --------- */
int menu = 0;	// 메뉴 선택 초기값

// 메뉴 color 배열 셋팅
void menu_Coloring() {
	int x, y;
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0 ; x < PRINT_FULL_WIDTH; x++) 
			*(color + (y * PRINT_FULL_WIDTH + x)) = *(*(full_map_0 + y) + x) | *(*(full_map_0 + y) + x) * 16;
	}
}

// 메뉴 셋팅
void menu_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;
	for (y = 0; y < MAP_HEIGHT; y++) {
		for (b_y = 0; b_y < BLACK_HEIGHT; b_y++) {
			input_x = 0;
			for (x = 0; x < MAP_WIDTH_0; x++) {
				for (b_x = 0; b_x < BLACK_WIDTH; b_x++) {
					switch (*(*(map_0 + y) + x)) {
					case 1:		*(*(full_map_0 + input_y) + input_x) = *(*(block_sky + b_y) + b_x);		break;
					case 2:		*(*(full_map_0 + input_y) + input_x) = *(*(block_wall + b_y) + b_x);	break;
					case 3:		*(*(full_map_0 + input_y) + input_x) = *(*(block_S + b_y) + b_x);		break;
					case 4:		*(*(full_map_0 + input_y) + input_x) = *(*(block_U + b_y) + b_x);		break;
					case 5:		*(*(full_map_0 + input_y) + input_x) = *(*(block_P + b_y) + b_x);		break;
					case 6:		*(*(full_map_0 + input_y) + input_x) = *(*(block_E + b_y) + b_x);		break;
					case 7:		*(*(full_map_0 + input_y) + input_x) = *(*(block_R + b_y) + b_x);		break;
					case 8:		*(*(full_map_0 + input_y) + input_x) = *(*(block_gray + b_y) + b_x);	break;
					case 9:		*(*(full_map_0 + input_y) + input_x) = *(*(block_M1 + b_y) + b_x);		break;
					case 10:	*(*(full_map_0 + input_y) + input_x) = *(*(block_M2 + b_y) + b_x);		break;
					case 11:	*(*(full_map_0 + input_y) + input_x) = *(*(block_M3 + b_y) + b_x);		break;
					case 12:	*(*(full_map_0 + input_y) + input_x) = *(*(block_M4 + b_y) + b_x);		break;
					case 13:	*(*(full_map_0 + input_y) + input_x) = *(*(block_R1 + b_y) + b_x);		break;
					case 14:	*(*(full_map_0 + input_y) + input_x) = *(*(block_R2 + b_y) + b_x);		break;
					case 15:	*(*(full_map_0 + input_y) + input_x) = *(*(block_R3 + b_y) + b_x);		break;
					case 16:	*(*(full_map_0 + input_y) + input_x) = *(*(block_R4 + b_y) + b_x);		break;
					case 17:	*(*(full_map_0 + input_y) + input_x) = *(*(block_O1 + b_y) + b_x);		break;
					case 18:	*(*(full_map_0 + input_y) + input_x) = *(*(block_O2 + b_y) + b_x);		break;
					case 19:	*(*(full_map_0 + input_y) + input_x) = *(*(block_O3 + b_y) + b_x);		break;
					case 20:	*(*(full_map_0 + input_y) + input_x) = *(*(block_O4 + b_y) + b_x);		break;
					case 21:	*(*(full_map_0 + input_y) + input_x) = *(*(block_b + b_y) + b_x);		break;
					case 22:	*(*(full_map_0 + input_y) + input_x) = *(*(block_r + b_y) + b_x);		break;
					case 23:	*(*(full_map_0 + input_y) + input_x) = *(*(block_o + b_y) + b_x);		break;
					case 24:	*(*(full_map_0 + input_y) + input_x) = *(*(block_s + b_y) + b_x);		break;
					case 25:	*(*(full_map_0 + input_y) + input_x) = *(*(block_emp1 + b_y) + b_x);	break;
					case 26:	*(*(full_map_0 + input_y) + input_x) = *(*(block_emp2 + b_y) + b_x);	break;
					case 27:	*(*(full_map_0 + input_y) + input_x) = *(*(block_emp3 + b_y) + b_x);	break;
					case 30:	*(*(full_map_0 + input_y) + input_x) = *(*(block_cornerR_Down + b_y) + b_x);	break;
					case 31:	*(*(full_map_0 + input_y) + input_x) = *(*(block_G1 + b_y) + b_x);		break;
					case 32:	*(*(full_map_0 + input_y) + input_x) = *(*(block_G2 + b_y) + b_x);		break;
					case 33:	*(*(full_map_0 + input_y) + input_x) = *(*(block_G3 + b_y) + b_x);		break;
					case 34:	*(*(full_map_0 + input_y) + input_x) = *(*(block_G4 + b_y) + b_x);		break;
					case 35:	*(*(full_map_0 + input_y) + input_x) = *(*(block_EA + b_y) + b_x);		break;
					case 36:	*(*(full_map_0 + input_y) + input_x) = *(*(block_SY + b_y) + b_x);		break;
					case 37:	*(*(full_map_0 + input_y) + input_x) = *(*(block_N + b_y) + b_x);		break;
					case 38:	*(*(full_map_0 + input_y) + input_x) = *(*(block_OR + b_y) + b_x);		break;
					case 39:	*(*(full_map_0 + input_y) + input_x) = *(*(block_MA + b_y) + b_x);		break;
					case 40:	*(*(full_map_0 + input_y) + input_x) = *(*(block_L + b_y) + b_x);		break;
					case 41:	*(*(full_map_0 + input_y) + input_x) = *(*(block_HA + b_y) + b_x);		break;
					case 42:	*(*(full_map_0 + input_y) + input_x) = *(*(block_RD + b_y) + b_x);		break;
					case 43:	*(*(full_map_0 + input_y) + input_x) = *(*(block_NoDia + b_y) + b_x);	break;
					case 44:	*(*(full_map_0 + input_y) + input_x) = *(*(block_NoGoal + b_y) + b_x);	break;
					case 45:	*(*(full_map_0 + input_y) + input_x) = *(*(block_emp4 + b_y) + b_x);	break;
					case 46:	*(*(full_map_0 + input_y) + input_x) = *(*(block_cornerR_Up + b_y) + b_x);		break;
					case 47:	*(*(full_map_0 + input_y) + input_x) = *(*(block_cornerL_Up + b_y) + b_x);		break;
					case 48:	*(*(full_map_0 + input_y) + input_x) = *(*(block_cornerL_Down + b_y) + b_x);	break;
					case 49:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_EA + b_y) + b_x);	break;
					case 50:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_SY + b_y) + b_x);	break;
					case 51:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_N + b_y) + b_x);	break;
					case 52:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_OR + b_y) + b_x);	break;
					case 53:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_MA + b_y) + b_x);	break;
					case 54:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_L + b_y) + b_x);	break;
					case 55:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_HA + b_y) + b_x);	break;
					case 56:	*(*(full_map_0 + input_y) + input_x) = *(*(block_Sel_RD + b_y) + b_x);	break;
					}
					input_x++;
				}
			}
			input_y++;
		}
	}
	
}

// 메뉴 체크
void MenuSelect() {
	if (menu == 3) menu = 0;
	if (menu == -1) menu = 2;

	map_0[6][7] = 35;
	map_0[6][8] = 36;
	map_0[7][6] = 37;
	map_0[7][7] = 38;
	map_0[7][8] = 39;
	map_0[7][9] = 40;
	map_0[8][7] = 41;
	map_0[8][8] = 42;

	if (menu == 0) {
		map_0[6][7] = 49;
		map_0[6][8] = 50;
	}
	else if (menu == 1) {
		map_0[7][6] = 51;
		map_0[7][7] = 52;
		map_0[7][8] = 53;
		map_0[7][9] = 54;
	}
	else if (menu == 2) {
		map_0[8][7] = 55;
		map_0[8][8] = 56;
	}
}
