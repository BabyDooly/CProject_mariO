#pragma warning (disable : 4996)
#include "function.h"
#include "map.h"

/* -------- 블럭 --------- */
extern char block1_1[BLACK_HEIGHT][BLACK_WIDTH];	// 하늘 
extern char block1_2[BLACK_HEIGHT][BLACK_WIDTH];	// 파도 
extern char block1_3[BLACK_HEIGHT][BLACK_WIDTH];	// 바다 배경 
extern char block1_4[BLACK_HEIGHT][BLACK_WIDTH];	// 돌
extern char block1_5[BLACK_HEIGHT][BLACK_WIDTH];	// 떨어지는 돌   
extern char block1_6[BLACK_HEIGHT][BLACK_WIDTH];	// 부서지는 돌 
extern char block1_7[BLACK_HEIGHT][BLACK_WIDTH];	// 투명 돌 
extern char block1_8[BLACK_HEIGHT][BLACK_WIDTH];	// 굴뚝 위 
extern char block1_9[BLACK_HEIGHT][BLACK_WIDTH];	// 굴뚝 아래 
extern char block1_10[BLACK_HEIGHT][BLACK_WIDTH];	// 굴뚝 옆 뚜껑 
extern char block1_11[BLACK_HEIGHT][BLACK_WIDTH];	// 굴뚝 옆 기둥 
extern char block1_12[BLACK_HEIGHT][BLACK_WIDTH];	// 세이브 깃발
extern char block1_13[BLACK_HEIGHT][BLACK_WIDTH];	// 코인
extern char block1_14[BLACK_HEIGHT][BLACK_WIDTH];	// 가짜 코인
extern char block1_15[BLACK_HEIGHT][BLACK_WIDTH];	// 산호초
extern char block1_16[BLACK_HEIGHT][BLACK_WIDTH];	// 산호초R 
extern char block1_17[BLACK_HEIGHT][BLACK_WIDTH];	// 몬스터1 (물고기 입 벌린거) 
extern char block1_18[BLACK_HEIGHT][BLACK_WIDTH];	// 몬스터2 (오징어 내려갈때) 
extern char block1_19[BLACK_HEIGHT][BLACK_WIDTH];	// 몬스터3 (입) 밑에 숨어있다가 깜짝등장 
extern char block1_20[BLACK_HEIGHT][BLACK_WIDTH];	// 몬스터3 (입 큰거) 몸통 
extern char block1_21[BLACK_HEIGHT][BLACK_WIDTH];	// 몬스터3 (입 큰거) 꼬리 
extern char block1_22[BLACK_HEIGHT][BLACK_WIDTH * 4];	// 바다 배경(1x4)
extern char block1_23[BLACK_HEIGHT][BLACK_WIDTH * 5];	// 바다 배경(1x5)
extern char block1_24[BLACK_HEIGHT][BLACK_WIDTH * 2];	// 바다 배경(1x2)
extern char block1_25[BLACK_HEIGHT][BLACK_WIDTH * 2];	// 떨어지는 블럭(1x2)
extern char block1_26[BLACK_HEIGHT][BLACK_WIDTH * 3];	// 떨어지는 블럭(1x3)
extern char block1_27[BLACK_HEIGHT][BLACK_WIDTH * 4];	// 떨어지는 블럭(1x4)
extern char block1_28[BLACK_HEIGHT][BLACK_WIDTH * 3];	// 바다 배경(1x3)
extern char block1_29[BLACK_HEIGHT][BLACK_WIDTH];		// 몬스터2 (오징어 올라갈때)
extern char block1_30[BLACK_HEIGHT][BLACK_WIDTH];		// 몬스터1 (물고기 입 모은거) 
extern char block1_31[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH];	// 몬스터3 (상어)
extern char block1_32[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH * 2];	// 몬스터3 (상어 2마리)
extern int map_1[MAP_HEIGHT][MAP_WIDTH_1];
extern int full_map_1[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_1];

/* -------- 변수 --------- */
extern int MapMovX;		// 맵 x축
extern int stage;		// 스테이지 
extern int running;		// 죽은지 확인
extern int end;			// 게임 종료 확인
extern int checkpoint;	// 체크포인트
extern int jump_check;	// 점프 확인
extern int play_sound_selection;	// 사운드 체크
extern int menu;		// 레벨 선택 초기값
extern char E_Location[16][12], E_jump_Location[16][12], E_death_Location[16][12];	// 마리오캐릭터


/* -------- 구조체 --------- */
extern struct Pos mario;		// 마리오 위치
struct Pos check_point_1[2], coin_1[29], broken_block_1_1x2[2], broken_block_1_1x4, broken_block_1_1x5, 
	down_block_1_1x2[2], down_block_1_1x3[2], down_block_1_1x4[3], head_block_1[28], monster_fish_1[11], 
	monster_squid_1[11] , monster_squid_y_1[11], monster_shark_1[2], monster_shark_2_1[3];	// 블럭 구조체

// 스테이지1 셋팅
void Stage1_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;

	// full_map1에 대입
	for (y = 0; y < MAP_HEIGHT; y++) {
		for (b_y = 0; b_y < BLACK_HEIGHT; b_y++) {
			input_x = 0;
			for (x = 0; x < MAP_WIDTH_1; x++) {
				for (b_x = 0; b_x < BLACK_WIDTH; b_x++) {
					switch (*(*(map_1 + y) + x)) {
					case 1:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_1 + b_y) + b_x);	break;
					case 2:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_2 + b_y) + b_x);	break;
					case 3:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_3 + b_y) + b_x);	break;
					case 4:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_4 + b_y) + b_x);	break;
					case 5:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_5 + b_y) + b_x);	break;
					case 6:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_6 + b_y) + b_x);	break;
					case 7:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_7 + b_y) + b_x);	break;
					case 8:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_8 + b_y) + b_x);	break;
					case 9:		*(*(full_map_1 + input_y) + input_x) = *(*(block1_9 + b_y) + b_x);	break;
					case 10:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_10 + b_y) + b_x);	break;
					case 11:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_11 + b_y) + b_x);	break;
					case 12:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_12 + b_y) + b_x);	break;
					case 13:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_13 + b_y) + b_x);	break;
					case 14:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_14 + b_y) + b_x);	break;
					case 15:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_15 + b_y) + b_x);	break;
					case 16:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_16 + b_y) + b_x);	break;
					case 17:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_17 + b_y) + b_x);	break;
					case 18:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_18 + b_y) + b_x);	break;
					case 19:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_19 + b_y) + b_x);	break;
					case 20:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_20 + b_y) + b_x);	break;
					case 21:	*(*(full_map_1 + input_y) + input_x) = *(*(block1_21 + b_y) + b_x);	break;
					}
					input_x++;
				}
			}
			input_y++;
		}
	}

	// 게임 블럭 / 몬스터 생성
	for (int i = 0; i < 2; i++){
		check_point_1[i].flag = 1;
		broken_block_1_1x2[i].flag = 1;
	}

	check_point_1[0].X = 1200;
	check_point_1[0].Y = 100;

	check_point_1[1].X = 2220;
	check_point_1[1].Y = 50;

	for (int i = 0; i < 29; i++) {
		if (i == 12 || i == 14 || i == 23)	coin_1[i].Y = 40;
		if (i == 0 || i == 15  || i == 17 || i == 18 || i == 24)	coin_1[i].Y = 50;
		if (i == 16 || i == 21 || i == 22)	coin_1[i].Y = 60;
		if (i >= 4  && i <= 7)				coin_1[i].Y = 70;
		if (i == 1 || i == 3 || i == 20)	coin_1[i].Y = 80;
		if (i == 2 || i == 19)				coin_1[i].Y = 90;
		if (i >= 25 && i <= 28)				coin_1[i].Y = 95;
		if (i >= 8 && i <= 11)				coin_1[i].Y = 100;

		coin_1[i].flag = 1;
	}
	coin_1[13].Y = 20;

	coin_1[0].X = 60;
	coin_1[1].X = 120;
	coin_1[2].X = 880;
	coin_1[3].X = 880;
	coin_1[4].X = 880;
	coin_1[5].X = 1340;
	coin_1[6].X = 1360;
	coin_1[7].X = 1380;
	coin_1[8].X = 1940;
	coin_1[9].X = 1960;
	coin_1[10].X = 2100;
	coin_1[11].X = 2120;
	coin_1[12].X = 2340;
	coin_1[13].X = 2380;
	coin_1[14].X = 2400;
	coin_1[15].X = 2620;
	coin_1[16].X = 2640;
	coin_1[17].X = 2920;
	coin_1[18].X = 2940;
	coin_1[19].X = 3040;
	coin_1[20].X = 3120;
	coin_1[21].X = 3220;
	coin_1[22].X = 3240;
	coin_1[23].X = 3560;
	coin_1[24].X = 3600;
	coin_1[25].X = 1620;
	coin_1[26].X = 1640;
	coin_1[27].X = 1680;
	coin_1[28].X = 1700;

	broken_block_1_1x2[0].X = 1620;
	broken_block_1_1x2[0].Y = 110;

	broken_block_1_1x2[1].X = 1680;
	broken_block_1_1x2[1].Y = 110;

	broken_block_1_1x4.X = 440;
	broken_block_1_1x4.Y = 50;
	broken_block_1_1x4.flag = 1;

	broken_block_1_1x5.X = 1620;
	broken_block_1_1x5.Y = 30;
	broken_block_1_1x5.flag = 1;

	for (int i = 0; i < 28; i++) {
		if (i >= 15 && i <= 27)
			head_block_1[i].Y = 40;
		if (i >= 0 && i <= 4)
			head_block_1[i].Y = 50;
		if (i >= 5 && i <= 14)
			head_block_1[i].Y = 80;

		head_block_1[i].flag = 0;
	}
	coin_1[13].Y = 20;

	head_block_1[0].X = 840;
	head_block_1[1].X = 860;
	head_block_1[2].X = 880;
	head_block_1[3].X = 900;
	head_block_1[4].X = 920;
	head_block_1[5].X = 1140;
	head_block_1[6].X = 1160;
	head_block_1[7].X = 1180;
	head_block_1[8].X = 1200;
	head_block_1[9].X = 1220;
	head_block_1[10].X = 1240;
	head_block_1[11].X = 1620;
	head_block_1[12].X = 1640;
	head_block_1[13].X = 1680;
	head_block_1[14].X = 1700;
	head_block_1[15].X = 3020;
	head_block_1[16].X = 3040;
	head_block_1[17].X = 3060;
	head_block_1[18].X = 3080;
	head_block_1[19].X = 3100;
	head_block_1[20].X = 3120;
	head_block_1[21].X = 3140;
	head_block_1[22].X = 3160;
	head_block_1[23].X = 3180;
	head_block_1[24].X = 3200;
	head_block_1[25].X = 3220;
	head_block_1[26].X = 3240;
	head_block_1[27].X = 3260;



	down_block_1_1x2[0].X = 2360;
	down_block_1_1x2[0].Y = 50;
	down_block_1_1x2[0].flag = 1;
	down_block_1_1x2[0].mov = 1;

	down_block_1_1x2[1].X = 3420;
	down_block_1_1x2[1].Y = 40;
	down_block_1_1x2[1].flag = 1;
	down_block_1_1x2[1].mov = 1;

	down_block_1_1x3[0].X = 1200;
	down_block_1_1x3[0].Y = 40;
	down_block_1_1x3[0].flag = 1;
	down_block_1_1x3[0].mov = 1;

	down_block_1_1x3[1].X = 2540;
	down_block_1_1x3[1].Y = 30;
	down_block_1_1x3[1].flag = 1;
	down_block_1_1x3[1].mov = 1;

	down_block_1_1x4[0].X = 1480;
	down_block_1_1x4[0].Y = 30;
	down_block_1_1x4[0].flag = 1;
	down_block_1_1x4[0].mov = 1;

	down_block_1_1x4[1].X = 2700;
	down_block_1_1x4[1].Y = 20;
	down_block_1_1x4[1].flag = 1;
	down_block_1_1x4[1].mov = 1;

	down_block_1_1x4[2].X = 2880;
	down_block_1_1x4[2].Y = 40;
	down_block_1_1x4[2].flag = 1;
	down_block_1_1x4[2].mov = 1;

	monster_fish_1[0].X = 860;
	monster_fish_1[0].Y = 100;
	monster_fish_1[0].flag = 1;

	monster_fish_1[1].X = 880;
	monster_fish_1[1].Y = 100;
	monster_fish_1[1].flag = 1;

	monster_fish_1[2].X = 900;
	monster_fish_1[2].Y = 100;
	monster_fish_1[2].flag = 1;

	monster_fish_1[3].X = 1740;
	monster_fish_1[3].Y = 40;
	monster_fish_1[3].flag = 1;

	monster_fish_1[4].X = 1790;
	monster_fish_1[4].Y = 20;
	monster_fish_1[4].flag = 1;

	monster_fish_1[5].X = 1800;
	monster_fish_1[5].Y = 45;
	monster_fish_1[5].flag = 1;

	monster_fish_1[6].X = 1820;
	monster_fish_1[6].Y = 60;
	monster_fish_1[6].flag = 1;

	monster_fish_1[7].X = 2360;
	monster_fish_1[7].Y = 100;
	monster_fish_1[7].flag = 1;

	monster_fish_1[8].X = 2400;
	monster_fish_1[8].Y = 85;
	monster_fish_1[8].flag = 1;

	monster_fish_1[9].X = 2440;
	monster_fish_1[9].Y = 70;
	monster_fish_1[9].flag = 1;

	monster_fish_1[10].X = 2740;
	monster_fish_1[10].Y = 60;
	monster_fish_1[10].flag = 1;

	monster_squid_1[0].X = 340;
	monster_squid_1[0].Y = 60;
	monster_squid_y_1[0].Y = 60;
	monster_squid_1[0].flag = 0;
	monster_squid_1[0].mov = 1;

	monster_squid_1[1].X = 400;
	monster_squid_1[1].Y = 40;
	monster_squid_y_1[1].Y = 40;
	monster_squid_1[1].flag = 0;
	monster_squid_1[1].mov = 1;

	monster_squid_1[2].X = 1000;
	monster_squid_1[2].Y = 40;
	monster_squid_y_1[2].Y = 40;
	monster_squid_1[2].flag = 0;
	monster_squid_1[2].mov = 1;

	monster_squid_1[3].X = 1040;
	monster_squid_1[3].Y = 20;
	monster_squid_y_1[3].Y = 20;
	monster_squid_1[3].flag = 0;
	monster_squid_1[3].mov = 1;

	monster_squid_1[4].X = 1300;
	monster_squid_1[4].Y = 40;
	monster_squid_y_1[4].Y = 40;
	monster_squid_1[4].flag = 0;
	monster_squid_1[4].mov = 1;

	monster_squid_1[5].X = 1400;
	monster_squid_1[5].Y = 60;
	monster_squid_y_1[5].Y = 60;
	monster_squid_1[5].flag = 1;
	monster_squid_1[5].mov = 1;

	monster_squid_1[6].X = 1860;
	monster_squid_1[6].Y = 40;
	monster_squid_y_1[6].Y = 40;
	monster_squid_1[6].flag = 1;
	monster_squid_1[6].mov = 1;

	monster_squid_1[7].X = 2220;
	monster_squid_1[7].Y = 70;
	monster_squid_y_1[7].Y = 70;
	monster_squid_1[7].flag = 1;
	monster_squid_1[7].mov = 1;

	monster_squid_1[8].X = 2260;
	monster_squid_1[8].Y = 10;
	monster_squid_y_1[8].Y = 10;
	monster_squid_1[8].flag = 1;
	monster_squid_1[8].mov = 1;

	monster_squid_1[9].X = 2960;
	monster_squid_1[9].Y = 30;
	monster_squid_y_1[9].Y = 30;
	monster_squid_1[9].flag = 1;
	monster_squid_1[9].mov = 1;

	monster_squid_1[10].X = 2980;
	monster_squid_1[10].Y = 70;
	monster_squid_y_1[10].Y = 70;
	monster_squid_1[10].flag = 1;
	monster_squid_1[10].mov = 1;

	monster_shark_1[0].X = 3040;
	monster_shark_1[0].Y = 93;
	monster_shark_1[0].flag = 0;
	monster_shark_1[0].mov = 1;

	monster_shark_1[1].X = 3120;
	monster_shark_1[1].Y = 93;
	monster_shark_1[1].flag = 0;
	monster_shark_1[1].mov = 1;

	monster_shark_2_1[0].X = 1940;
	monster_shark_2_1[0].Y = 93;
	monster_shark_2_1[0].flag = 0;
	monster_shark_2_1[0].mov = 1;

	monster_shark_2_1[1].X = 2100;
	monster_shark_2_1[1].Y = 93;
	monster_shark_2_1[1].flag = 0;
	monster_shark_2_1[1].mov = 1;

	monster_shark_2_1[2].X = 3220;
	monster_shark_2_1[2].Y = 93;
	monster_shark_2_1[2].flag = 0;
	monster_shark_2_1[2].mov = 1;
	
	running = 1;	// 살아있음(죽은지 체크)

	// 사운드 재생 
	PlaySound("MUSIC\\stage1.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// color 배열 셋팅
void Stage1_Coloring() {
	int x, y, i;
	// 맵 넣기
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0 + MapMovX; x < MapMovX + PRINT_FULL_WIDTH; x++) 
			color[y * PRINT_FULL_WIDTH + x - MapMovX] = full_map_1[y][x] | full_map_1[y][x] * 16;
	}

	// 체크 포인트
	for (i = 0; i < 2; i++) {
		if (!(check_point_1[i].X >= MapMovX - 20 && check_point_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (check_point_1[i].X + x - MapMovX < 0 || check_point_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (check_point_1[i].flag == 1)
					color[(check_point_1[i].Y + y) * PRINT_FULL_WIDTH + check_point_1[i].X + x - MapMovX] = block1_12[y][x] | block1_12[y][x] * 16;	// 체크포인트
			}
		}
	}

	// 코인
	for (i = 0; i < 29; i++) {
		if (!(coin_1[i].X >= MapMovX - 20 && coin_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (coin_1[i].X + x - MapMovX < 0 || coin_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (coin_1[i].flag == 1)
					color[(coin_1[i].Y + y) * PRINT_FULL_WIDTH + coin_1[i].X + x - MapMovX] = block1_13[y][x] | block1_13[y][x] * 16;	// 코인

				else if (coin_1[i].flag == 2)
					color[(coin_1[i].Y + y) * PRINT_FULL_WIDTH + coin_1[i].X + x - MapMovX] = block1_14[y][x] | block1_14[y][x] * 16;	// 코인
			}
		}
	}

	// 머리 부딪치면 생기는 블럭
	for (i = 0; i < 28; i++) {
		if (!(head_block_1[i].X >= MapMovX - 20 && head_block_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (head_block_1[i].X + x - MapMovX < 0 || head_block_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (head_block_1[i].flag == 1)
					full_map_1[y + head_block_1[i].Y][x + head_block_1[i].X] = block1_7[y][x];		// 벽돌
			}
		}
	}

	// 밟으면 부서지는 블럭(1x2)
	for (i = 0; i < 2; i++) {
		if (!(broken_block_1_1x2[i].X >= MapMovX && broken_block_1_1x2[i].X <= PRINT_FULL_WIDTH + MapMovX - 40))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (broken_block_1_1x2[i].X + x - MapMovX < 0 || broken_block_1_1x2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_1_1x2[i].flag == 0)
					full_map_1[y + broken_block_1_1x2[i].Y][x + broken_block_1_1x2[i].X] = block1_24[y][x];		// 배경
			}
		}
	}

	// 밟으면 부서지는 블럭(1x4)
	for (i = 0; i < 1; i++) {
		if (!(broken_block_1_1x4.X >= MapMovX && broken_block_1_1x4.X <= PRINT_FULL_WIDTH + MapMovX -80))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 4; x++) {
				if (broken_block_1_1x4.X + x - MapMovX < 0 || broken_block_1_1x4.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_1_1x4.flag == 0)
					full_map_1[y + broken_block_1_1x4.Y][x + broken_block_1_1x4.X] = block1_22[y][x];		// 배경
			}
		}
	}

	// 밟으면 부서지는 블럭(1x5)
	for (i = 0; i < 1; i++) {
		if (!(broken_block_1_1x5.X >= MapMovX && broken_block_1_1x5.X <= PRINT_FULL_WIDTH + MapMovX - 100))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 5; x++) {
				if (broken_block_1_1x5.X + x - MapMovX < 0 || broken_block_1_1x5.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_1_1x5.flag == 0)
					full_map_1[y + broken_block_1_1x5.Y][x + broken_block_1_1x5.X] = block1_23[y][x];		// 배경
			}
		}
	}

	// 떨어지는 블럭(1x2)
	for (int i = 0; i < 2; i++) {
		if (!(down_block_1_1x2[i].X >= MapMovX && down_block_1_1x2[i].X <= PRINT_FULL_WIDTH + MapMovX - 40))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {

				if (down_block_1_1x2[i].flag == 1)
					color[(down_block_1_1x2[i].Y + y) * PRINT_FULL_WIDTH + down_block_1_1x2[i].X + x - MapMovX] = (block1_25[y][x] != 16 ? block1_25[y][x] : full_map_1[y + down_block_1_1x2[i].Y][x + down_block_1_1x2[i].X]) | (block1_25[y][x] != 16 ? block1_25[y][x] : full_map_1[y + down_block_1_1x2[i].Y][x + down_block_1_1x2[i].X]) * 16;
						
				if (down_block_1_1x2[i].mov == 0 && i == 0)
					full_map_1[y + 50][x + 2360] = block1_24[y][x];		// 배경	
				else if (down_block_1_1x2[i].mov == 0 && i == 1)
					full_map_1[y + 40][x + 3420] = block1_24[y][x];		// 배경	
			}
		}
	}

	// 떨어지는 블럭(1x3)
	for (int i = 0; i < 2; i++) {
		if (!(down_block_1_1x3[i].X >= MapMovX && down_block_1_1x3[i].X <= PRINT_FULL_WIDTH + MapMovX - 60))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 3; x++) {

				if (down_block_1_1x3[i].flag == 1)
					color[(down_block_1_1x3[i].Y + y) * PRINT_FULL_WIDTH + down_block_1_1x3[i].X + x - MapMovX] = (block1_26[y][x] != 16 ? block1_26[y][x] : full_map_1[y + down_block_1_1x3[i].Y][x + down_block_1_1x3[i].X]) | (block1_26[y][x] != 16 ? block1_26[y][x] : full_map_1[y + down_block_1_1x3[i].Y][x + down_block_1_1x3[i].X]) * 16;

				if (down_block_1_1x3[i].mov == 0 && i == 0)
					full_map_1[y + 40][x + 1200] = block1_28[y][x];		// 배경	
				else if (down_block_1_1x3[i].mov == 0 && i == 1)
					full_map_1[y + 30][x + 2540] = block1_28[y][x];		// 배경	
			}
		}
	}

	// 떨어지는 블럭(1x4)
	for (int i = 0; i < 3; i++) {
		if (!(down_block_1_1x4[i].X >= MapMovX && down_block_1_1x4[i].X <= PRINT_FULL_WIDTH + MapMovX - 80))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 4; x++) {

				if (down_block_1_1x4[i].flag == 1)
					color[(down_block_1_1x4[i].Y + y) * PRINT_FULL_WIDTH + down_block_1_1x4[i].X + x - MapMovX] = (block1_27[y][x] != 16 ? block1_27[y][x] : full_map_1[y + down_block_1_1x4[i].Y][x + down_block_1_1x4[i].X]) | (block1_27[y][x] != 16 ? block1_27[y][x] : full_map_1[y + down_block_1_1x4[i].Y][x + down_block_1_1x4[i].X]) * 16;

				if (down_block_1_1x4[i].mov == 0 && i == 0)
					full_map_1[y + 30][x + 1480] = block1_22[y][x];		// 배경	
				else if (down_block_1_1x4[i].mov == 0 && i == 1)
					full_map_1[y + 20][x + 2700] = block1_22[y][x];		// 배경	
				else if (down_block_1_1x4[i].mov == 0 && i == 2)
					full_map_1[y + 40][x + 2880] = block1_22[y][x];		// 배경	
			}
		}
	}

	// 몬스터(오징어)
	for (int i = 0; i < 11; i++) {
		if (!(monster_squid_1[i].X >= MapMovX - 20 && monster_squid_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_squid_1[i].X + x - MapMovX < 0 || monster_squid_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				// 몬스터(오징어 위로)
				if (monster_squid_1[i].flag == 1)
					color[(monster_squid_1[i].Y + y) * PRINT_FULL_WIDTH + monster_squid_1[i].X + x - MapMovX] = (block1_29[y][x] != 1 ? block1_29[y][x] : full_map_1[y + monster_squid_1[i].Y][x + monster_squid_1[i].X]) | (block1_29[y][x] != 1 ? block1_29[y][x] : full_map_1[y + monster_squid_1[i].Y][x + monster_squid_1[i].X]) * 16;
				// 몬스터(오징어 아래로)
				else
					color[(monster_squid_1[i].Y + y) * PRINT_FULL_WIDTH + monster_squid_1[i].X + x - MapMovX] = (block1_18[y][x] != 1 ? block1_18[y][x] : full_map_1[y + monster_squid_1[i].Y][x + monster_squid_1[i].X]) | (block1_18[y][x] != 1 ? block1_18[y][x] : full_map_1[y + monster_squid_1[i].Y][x + monster_squid_1[i].X]) * 16;
			}
		}
	}

	// 몬스터(물고기)
	for (int i = 0; i < 11; i++) {
		if (!(monster_fish_1[i].X >= MapMovX - 20 && monster_fish_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_fish_1[i].X + x - MapMovX < 0 || monster_fish_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;
				if (monster_fish_1[i].flag == 1)
					color[(monster_fish_1[i].Y + y) * PRINT_FULL_WIDTH + monster_fish_1[i].X + x - MapMovX] = (block1_17[y][x] != 1 ? block1_17[y][x] : full_map_1[y + monster_fish_1[i].Y][x + monster_fish_1[i].X]) | (block1_17[y][x] != 1 ? block1_17[y][x] : full_map_1[y + monster_fish_1[i].Y][x + monster_fish_1[i].X]) * 16;
				else
					color[(monster_fish_1[i].Y + y) * PRINT_FULL_WIDTH + monster_fish_1[i].X + x - MapMovX] = (block1_30[y][x] != 1 ? block1_30[y][x] : full_map_1[y + monster_fish_1[i].Y][x + monster_fish_1[i].X]) | (block1_30[y][x] != 1 ? block1_30[y][x] : full_map_1[y + monster_fish_1[i].Y][x + monster_fish_1[i].X]) * 16;
			}
		}
	}

	// 몬스터(상어)
	for (int i = 0; i < 2; i++) {
		if (!(monster_shark_1[i].X >= MapMovX - 20 && monster_shark_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_shark_1[i].X + x - MapMovX < 0 || monster_shark_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_shark_1[i].flag == 1)
					color[(monster_shark_1[i].Y + y) * PRINT_FULL_WIDTH + monster_shark_1[i].X + x - MapMovX] = (block1_31[y][x] != 1 ? block1_31[y][x] : full_map_1[y + monster_shark_1[i].Y][x + monster_shark_1[i].X]) | (block1_31[y][x] != 1 ? block1_31[y][x] : full_map_1[y + monster_shark_1[i].Y][x + monster_shark_1[i].X]) * 16;
			}
		}
	}

	// 몬스터(상어 2마리)
	for (int i = 0; i < 3; i++) {
		if (!(monster_shark_2_1[i].X >= MapMovX - 20 && monster_shark_2_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (monster_shark_2_1[i].X + x - MapMovX < 0 || monster_shark_2_1[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_shark_2_1[i].flag == 1)
					color[(monster_shark_2_1[i].Y + y) * PRINT_FULL_WIDTH + monster_shark_2_1[i].X + x - MapMovX] = (block1_32[y][x] != 1 ? block1_32[y][x] : full_map_1[y + monster_shark_2_1[i].Y][x + monster_shark_2_1[i].X]) | (block1_32[y][x] != 1 ? block1_32[y][x] : full_map_1[y + monster_shark_2_1[i].Y][x + monster_shark_2_1[i].X]) * 16;
			}
		}
	}

	// 마리오
	for (y = 0; y < 16; y += 2) {
		for (x = 0; x < 12; x++) {
			
			// 마지막 문에 들어가면 출력 X
			if (x + mario.X >= 3700)
				continue;

			// 죽을때
			if (running == 0)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_death_Location[y][x] != 16 ? E_death_Location[y][x] : full_map_1[y / 2 + mario.Y][x + mario.X]) | (E_death_Location[y + 1][x] != 16 ? E_death_Location[y + 1][x] : full_map_1[y / 2 + mario.Y][x + mario.X]) * 16;
			// 기본
			else
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_Location[y][x] != 16 ? E_Location[y][x] : full_map_1[y / 2 + mario.Y][x + mario.X]) | (E_Location[y + 1][x] != 16 ? E_Location[y + 1][x] : full_map_1[y / 2 + mario.Y][x + mario.X]) * 16;
		}
	}
}

// 블럭 체크
void Stage1_block_check() {
	int i;

	// 체크포인트
	for (i = 0; i < 2; i++) {
		if (check_point_1[i].flag && mario.X >= check_point_1[i].X - 2 && mario.X <= check_point_1[i].X + 16 && mario.Y <= check_point_1[i].Y + 12 && mario.Y >= check_point_1[i].Y - 10)
			check_point_1[i].flag = 0;

		if (mario.X >= check_point_1[i].X - 2 && mario.X <= check_point_1[i].X + 16 && mario.Y <= check_point_1[i].Y + 12 && mario.Y >= check_point_1[i].Y - 10)
			checkpoint = i + 1;
	}

	// 코인
	for (i = 0; i < 29; i++) {
		// 코인 크기
		if (coin_1[i].flag == 1 && mario.X >= coin_1[i].X - 7 && mario.X <= coin_1[i].X + 17 && mario.Y <= coin_1[i].Y + 10 && mario.Y >= coin_1[i].Y - 10){
			// 먹으면 죽는 코인
			if ((i == 13 || i == 24)) {
				coin_1[i].flag = 2;
				GameOver();
				Stage1_check_point();
			}

			else if (coin_1[i].flag == 1) {
				// 코인 사운드 재생
				if (play_sound_selection) {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound, 0, (int)3);
				}
				else {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound_, 0, (int)3);
				}
				coin_1[i].flag = 0;
			}
		}
	}

	// 머리 부딪치면 생기는 블럭
	for (i = 0; i < 28; i++) {
		if (head_block_1[i].flag == 0 && mario.X > head_block_1[i].X - 10 && mario.X < head_block_1[i].X + 20 && (mario.Y == head_block_1[i].Y + 12 || mario.Y == head_block_1[i].Y + 13 || mario.Y == head_block_1[i].Y + 14)) {
			head_block_1[i].flag = 1;
			// 사운드 재생
			if (play_sound_selection) {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound, 0, (int)4);
			}
			else {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound_, 0, (int)4);
			}
		}
	}

	// 밟으면 부서지는 블럭 (1X2)
	for (i = 0; i < 2; i++) {
		if (broken_block_1_1x2[i].flag == 1 && mario.X > broken_block_1_1x2[i].X - 7 && mario.X < broken_block_1_1x2[i].X + 40 && mario.Y == broken_block_1_1x2[i].Y - 8)
			broken_block_1_1x2[i].flag = 0;
	}

	// 밟으면 부서지는 블럭 (1X4)
	for (i = 0; i < 1; i++) {
		if (broken_block_1_1x4.flag == 1 && mario.X > broken_block_1_1x4.X - 7 && mario.X < broken_block_1_1x4.X + 80 && mario.Y == broken_block_1_1x4.Y - 8)
			broken_block_1_1x4.flag = 0;
	}

	// 밟으면 부서지는 블럭 (1X5)
	for (i = 0; i < 1; i++) {
		if (broken_block_1_1x5.flag == 1 && mario.X > broken_block_1_1x5.X - 7 && mario.X < broken_block_1_1x5.X + 100 && mario.Y == broken_block_1_1x5.Y - 8)
			broken_block_1_1x5.flag = 0;
	}
}


// 움직이는 블럭
void Stage1_move_thread(void* args){
	int i = 0, x = 0, y = 0, l = 0, k = 0, m = 0, mo_check = 0;
	while (1){
		if (clock() - l < 20) 
			continue;
		l = clock();

		// 스테이지 종료시 스레드 종료
		if (stage != 1) 
			break;
		
		
		// 떨어지는 블럭 (1X2)
		for (i = 0; i < 2; i++) {
			if (!(down_block_1_1x2[i].X >= MapMovX - PRINT_FULL_WIDTH && down_block_1_1x2[i].X <= PRINT_FULL_WIDTH + MapMovX))
				continue;

			if (mario.X > down_block_1_1x2[i].X - 12 && mario.X < down_block_1_1x2[i].X + 40 && mario.Y > down_block_1_1x2[i].Y + 10 && mario.Y < down_block_1_1x2[i].Y + 80)
				while (1) {
					if (clock() - k < 20) 
						continue;
					
					// 원래 있는 블럭 사라지게하기
					down_block_1_1x2[i].mov = 0;

					// 블럭이 Y축이 PRINT_FULL_HEIGHT때까지 
					if (down_block_1_1x2[i].Y >= 110){
						down_block_1_1x2[i].flag = 0;
						break;
					}

					k = clock();
					down_block_1_1x2[i].Y += 2;
				}
		}

		// 떨어지는 블럭 (1X3)
		for (i = 0; i < 2; i++) {
			if (!(down_block_1_1x3[i].X >= MapMovX - PRINT_FULL_WIDTH && down_block_1_1x3[i].X <= PRINT_FULL_WIDTH + MapMovX))
				continue;

			if (mario.X > down_block_1_1x3[i].X - 12 && mario.X < down_block_1_1x3[i].X + 60 && mario.Y > down_block_1_1x3[i].Y + 10 && mario.Y < down_block_1_1x3[i].Y + 40)
				while (1) {
					if (clock() - k < 20) 
						continue;
					
					// 원래 있는 블럭 사라지게하기
					down_block_1_1x3[i].mov = 0;

					// 블럭이 Y축이 PRINT_FULL_HEIGHT때까지 
					if (down_block_1_1x3[i].Y >= 110) {
						down_block_1_1x3[i].flag = 0;
						break;
					}

					k = clock();
					down_block_1_1x3[i].Y += 2;
				}
		}

		// 떨어지는 블럭 (1X4)
		for (i = 0; i < 3; i++) {
			if (!(down_block_1_1x4[i].X >= MapMovX - PRINT_FULL_WIDTH && down_block_1_1x4[i].X <= PRINT_FULL_WIDTH + MapMovX))
				continue;
			if ((i == 0 && mario.X > down_block_1_1x4[i].X - 12 && mario.X < down_block_1_1x4[i].X + 80 && mario.Y > down_block_1_1x4[i].Y + 10 && mario.Y < down_block_1_1x4[i].Y + 50)
				|| (i == 1 && mario.X > down_block_1_1x4[i].X - 12 && mario.X < down_block_1_1x4[i].X + 80 && mario.Y > down_block_1_1x4[i].Y + 10 && mario.Y < down_block_1_1x4[i].Y + 40)
				|| (i == 2 && mario.X > down_block_1_1x4[i].X - 12 && mario.X < down_block_1_1x4[i].X + 80 && mario.Y > down_block_1_1x4[i].Y + 10 && mario.Y < down_block_1_1x4[i].Y + 80))
				while (1) {
					if (clock() - k < 20) 
						continue;
					
					// 원래 있는 블럭 사라지게하기
					down_block_1_1x4[i].mov = 0;

					// 블럭이 Y축이 PRINT_FULL_HEIGHT때까지 
					if (down_block_1_1x4[i].Y >= 110) {
						down_block_1_1x4[i].flag = 0;
						break;
					}

					k = clock();
					down_block_1_1x4[i].Y += 2;
				}
		}
		
		// 몬스터(상어)
		for (i = 0; i < 2; i++) {
			if (mario.X > monster_shark_1[i].X - 15 && mario.X < monster_shark_1[i].X + 20 && mario.Y < monster_shark_1[i].Y - 9) {
				monster_shark_1[i].flag = 1;
				while (1) {
					if (clock() - k < 15) {
						Sleep(1);
						continue;
					}

					// 나왔다가 다시 들어가기
					if (i == 0 && monster_shark_1[i].Y < 50)
						monster_shark_1[i].mov = 0;
					else if (i == 1 && monster_shark_1[i].Y < 50)
						monster_shark_1[i].mov = 0;
					else if (monster_shark_1[i].mov == 1)
						monster_shark_1[i].Y -= 1;


					if (monster_shark_1[i].Y >= 95 && monster_shark_1[i].mov == 0) {
						monster_shark_1[i].flag = 0;
						break;
					}
					else if (monster_shark_1[i].mov == 0)
						monster_shark_1[i].Y += 1;
					k = clock();
				}
			}
		}
		
		// 몬스터(상어 2마리)
		for (i = 0; i < 3; i++) {
			if (mario.X > monster_shark_2_1[i].X - 15 && mario.X < monster_shark_2_1[i].X + 40 && mario.Y < monster_shark_2_1[i].Y - 9) {
				monster_shark_2_1[i].flag = 1;
				while (1) {
					if (clock() - k < 15) 
						continue;
				
					// 나왔다가 다시 들어가기
					if (i == 2 && monster_shark_2_1[i].Y < 50)
						monster_shark_2_1[i].mov = 0;
					else if ((i == 0 || i == 1) && monster_shark_2_1[i].Y < 50)
						monster_shark_2_1[i].mov = 0;
					else if (monster_shark_2_1[i].mov == 1)
						monster_shark_2_1[i].Y -= 1;

					
					if (monster_shark_2_1[i].Y >= 95 && monster_shark_2_1[i].mov == 0) {
						monster_shark_2_1[i].flag = 0;
						break;
					}
					else if (monster_shark_2_1[i].mov == 0)
						monster_shark_2_1[i].Y += 1;
					k = clock();
				}
			}
		}
		
		
		// 몬스터(오징어)
		for (i = 0; i < 11; i++) {
			if (!(monster_squid_1[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_squid_1[i].X <= PRINT_FULL_WIDTH + MapMovX ))
				continue;

				for (y = 0; y < BLACK_HEIGHT; y++) {
					for (x = 0; x < BLACK_WIDTH; x++) {
						if (monster_squid_y_1[i].Y - (monster_squid_1[i].Y + monster_squid_1[i].mov) < -25 || monster_squid_y_1[i].Y - (monster_squid_1[i].Y + monster_squid_1[i].mov) > 0){
							if (monster_squid_y_1[i].Y - (monster_squid_1[i].Y + monster_squid_1[i].mov) > -25) 
								monster_squid_1[i].flag = 1;
		
							else if (monster_squid_y_1[i].Y - (monster_squid_1[i].Y + monster_squid_1[i].mov) < 0)
								monster_squid_1[i].flag = 0;
								

								monster_squid_1[i].mov = (monster_squid_1[i].mov < 0 ? 1 : -1);
								x = BLACK_WIDTH;
								y = BLACK_HEIGHT;
								mo_check = !mo_check;
												
						}
					}
				}

				if (mo_check) {
					mo_check = !mo_check;
					i--;
					continue;
				}

				monster_squid_1[i].Y += monster_squid_1[i].mov;
		}
		
		// 몬스터(물고기)
		for (i = 0; i < 11; i++) {
			if (!(monster_fish_1[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_fish_1[i].X <= PRINT_FULL_WIDTH + MapMovX))
				continue;
			if (i == 0 || i == 1 || i == 2)
				continue;

			// 몬스터 Y축이 땅까지 
			if (monster_fish_1[i].X <= MapMovX - 20 || death(0, 0) == 1) {
				monster_fish_1[i].flag = 0;
				monster_fish_1[i].X = -200;
				monster_fish_1[i].Y = -200;
			}
			monster_fish_1[i].X -= 1;
		}
		
		// 몬스터(물고기) 움직임
		if (clock() - m > 500) {
			for (i = 0; i < 11; i++){
				monster_fish_1[i].flag++;
				monster_fish_1[i].flag %= 2;
			}
			m = clock();
		}
	}
}

// 체크포인트
void Stage1_check_point() {
	// 체크포인트로 가면서 스테이지1 셋팅
	Stage1_setup();		
	switch (checkpoint) {
	case 0:
		MapMovX = 0;
		mario.X = 0;
		mario.Y = 92;
		break;
	case 1:
		MapMovX = 1100;
		mario.X = 1200;
		mario.Y = 100;
		break;
	case 2:
		MapMovX = 2140;
		mario.X = 2220;
		mario.Y = 50;
		break;
	case 3:
		MapMovX = 2900;
		mario.X = 3000;
		mario.Y = 70;
		break;

	}
}

// 키보드
void Stage1_Input(void* arg) {
	int i = 0;
	while (1) {
		// 시간 함수 사용하여서 속도 조절
		if (clock() - i < 22) 
			continue;
		i = clock();

		// 스테이지 종료시 스레드 종료
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || stage != 1) 
			break;
		

		if ((GetAsyncKeyState('W') & 0x8000)) {
			jump_check = 20;
		}

		if (GetAsyncKeyState('A') & 0x8000) {
			Mov_Safe(-2, 0);
		}

		if (GetAsyncKeyState('D') & 0x8000) {
			Mov_Safe(2, 0);
		}

		// 점프키를 눌렀을때
		if (jump_check > 10) {
			jump_check--;
			if (MovMorio(0, 2)) {
				MovMorio(0, 1);
				jump_check = -3;
			}
		}
		else
			Mov_Safe(0, -1);
	}
}
