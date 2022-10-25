#pragma warning (disable : 4996)
#include "function.h"
#include "map.h"

/* -------- 블럭 --------- */
extern char block3_1[BLACK_HEIGHT][BLACK_WIDTH];	// 배경
extern char block3_2[BLACK_HEIGHT][BLACK_WIDTH];	// 일반벽돌
extern char block3_3[BLACK_HEIGHT][BLACK_WIDTH];	// 땅블럭 
extern char block3_4[BLACK_HEIGHT][BLACK_WIDTH];	// 매끈한 벽돌
extern char block3_5[BLACK_HEIGHT][BLACK_WIDTH];	// 투명블럭
extern char block3_6[BLACK_HEIGHT][BLACK_WIDTH];	// 위로 올라가면 부서지는 블럭
extern char block3_7[BLACK_HEIGHT][BLACK_WIDTH];	// 기둥1
extern char block3_8[BLACK_HEIGHT][BLACK_WIDTH];	// 기둥2
extern char block3_9[BLACK_HEIGHT][BLACK_WIDTH];	// 기둥3
extern char block3_10[BLACK_HEIGHT][BLACK_WIDTH];	// 기둥4
extern char block3_11[BLACK_HEIGHT][BLACK_WIDTH];	// 빨간블럭
extern char block3_12[BLACK_HEIGHT][BLACK_WIDTH];	// 세이브 포인트
extern char block3_13[BLACK_HEIGHT][BLACK_WIDTH];	// 스프링
extern char block3_14[BLACK_HEIGHT][BLACK_WIDTH];	// 가짜 골인 지점 기둥 막대기
extern char block3_15[BLACK_HEIGHT][BLACK_WIDTH];	// 가짜 골인 지점 위쪽 다이아몬드
extern char block3_16[BLACK_HEIGHT][BLACK_WIDTH];	// 진짜 골인 지점 위쪽 다이아몬드
extern char block3_17[BLACK_HEIGHT][BLACK_WIDTH];	// 일정시간이 지난 후 부서짐  
extern char block3_18[BLACK_HEIGHT][BLACK_WIDTH];	// 밟으면 뒤로 튕겨저 나감
extern char block3_19[3][BLACK_WIDTH];				// 가시블럭 
extern char block3_20[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH * 2];	// 밟으면 움직이는 일자 블럭
extern char block3_21[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH * 2];	// 밟으면 움직이는 일자 블럭 0
extern char block3_22[BLACK_HEIGHT * 12][BLACK_WIDTH];		// 세로로 긴 블럭 
extern char block3_23[BLACK_HEIGHT + 2][BLACK_WIDTH * 3];	// 밟으면 떨어지는 3칸 블럭
extern char block3_24[BLACK_HEIGHT + 2][BLACK_WIDTH * 3];	// 밟으면 떨어지는 3칸 블럭 0
extern char block3_25[BLACK_HEIGHT][BLACK_WIDTH * 2];	// 시간 지나면 부서지는 블럭 0 
extern char block3_26[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문1
extern char block3_27[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문2
extern char block3_28[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문3
extern char block3_29[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문4
extern char block3_30[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문5
extern char block3_31[BLACK_HEIGHT][BLACK_WIDTH];		// 라운드 종료 문6
extern char block3_32[BLACK_HEIGHT][BLACK_WIDTH];		// 몬스터
extern char block3_33[BLACK_HEIGHT][BLACK_WIDTH];		// 날아오는 괴물
extern char block3_34[BLACK_HEIGHT][BLACK_WIDTH];		// 주인공이 점프하면 같이 점프하는 괴물
extern int map_3[MAP_HEIGHT][MAP_WIDTH_3];
extern int full_map_3[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_3];


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
struct Pos Thorn_3[2], Spring_3, not_block_3[12], broken_block_3[6], time_broken_block_3, head_broken_block_3[7], step_up_block_3, step_down_block_3, step_back_block_3,
	 down_block_3[4], long_block_3, check_point_3[2], monster_3[2], monster_fly_3[4], monster_jump_3;	// 블럭 구조체

// 스테이지3 셋팅
void Stage3_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;

	// full_map에 대입
	for (y = 0; y < MAP_HEIGHT; y++) {
		for (b_y = 0; b_y < BLACK_HEIGHT; b_y++) {
			input_x = 0;
			for (x = 0; x < MAP_WIDTH_3; x++) {
				for (b_x = 0; b_x < BLACK_WIDTH; b_x++) {
					switch (*(*(map_3 + y) + x)) {
					case 1:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_1 + b_y) + b_x);	break;
					case 2:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_2 + b_y) + b_x);	break;
					case 3:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_3 + b_y) + b_x);	break;
					case 4:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_4 + b_y) + b_x);	break;
					case 5:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_5 + b_y) + b_x);	break;
					case 6:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_6 + b_y) + b_x);	break;
					case 7:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_7 + b_y) + b_x);	break;
					case 8:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_8 + b_y) + b_x);	break;
					case 9:		*(*(full_map_3 + input_y) + input_x) = *(*(block3_9 + b_y) + b_x);	break;
					case 10:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_10 + b_y) + b_x);	break;
					case 11:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_11 + b_y) + b_x);	break;
					case 12:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_12 + b_y) + b_x);	break;
					case 13:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_13 + b_y) + b_x);	break;
					case 14:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_14 + b_y) + b_x);	break;
					case 15:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_15 + b_y) + b_x);	break;
					case 16:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_16 + b_y) + b_x);	break;
					case 17:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_17 + b_y) + b_x);	break;
					case 18:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_18 + b_y) + b_x);	break;
					case 19:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_19 + b_y) + b_x);	break;
					case 20:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_20 + b_y) + b_x);	break;
					case 21:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_21 + b_y) + b_x);	break;
					case 22:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_22 + b_y) + b_x);	break;
					case 23:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_23 + b_y) + b_x);	break;
					case 24:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_24 + b_y) + b_x);	break;
					case 25:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_25 + b_y) + b_x);	break;
					case 26:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_26 + b_y) + b_x);	break;
					case 27:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_27 + b_y) + b_x);	break;
					case 28:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_28 + b_y) + b_x);	break;
					case 29:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_29 + b_y) + b_x);	break;
					case 30:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_30 + b_y) + b_x);	break;
					case 31:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_31 + b_y) + b_x);	break;
					case 32:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_32 + b_y) + b_x);	break;
					case 33:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_33 + b_y) + b_x);	break;
					case 34:	*(*(full_map_3 + input_y) + input_x) = *(*(block3_34 + b_y) + b_x);	break;
					}
					input_x++;
				}
			}
			input_y++;
		}
	}


	// 게임 블럭 / 몬스터 생성
	
	Thorn_3[0].X = 180;
	Thorn_3[0].Y = 88;
	Thorn_3[0].flag = 0;

	Thorn_3[1].X = 360;
	Thorn_3[1].Y = 88;
	Thorn_3[1].flag = 0;

	Spring_3.X = 4220;
	Spring_3.Y = 110;

	not_block_3[0].X = 240;
	not_block_3[0].Y = 40;
	not_block_3[0].flag = 0;

	not_block_3[1].X = 560;
	not_block_3[1].Y = 80;
	not_block_3[1].flag = 0;

	not_block_3[2].X = 1020;
	not_block_3[2].Y = 50;
	not_block_3[2].flag = 0;

	not_block_3[3].X = 1600;
	not_block_3[3].Y = 60;
	not_block_3[3].flag = 0;

	not_block_3[4].X = 2120;
	not_block_3[4].Y = 90;
	not_block_3[4].flag = 0;

	not_block_3[5].X = 2860;
	not_block_3[5].Y = 80;
	not_block_3[5].flag = 0;

	not_block_3[6].X = 2880;
	not_block_3[6].Y = 50;
	not_block_3[6].flag = 0;

	not_block_3[7].X = 3880;
	not_block_3[7].Y = 50;
	not_block_3[7].flag = 0;

	not_block_3[8].X = 4140;
	not_block_3[8].Y = 80;
	not_block_3[8].flag = 0;

	not_block_3[9].X = 4160;
	not_block_3[9].Y = 60;
	not_block_3[9].flag = 0;

	not_block_3[10].X = 4180;
	not_block_3[10].Y = 40;
	not_block_3[10].flag = 0;

	not_block_3[11].X = 4340;
	not_block_3[11].Y = 100;
	not_block_3[11].flag = 0;

	broken_block_3[0].X = 880;
	broken_block_3[0].Y = 80;
	broken_block_3[0].flag = 1;

	broken_block_3[1].X = 3300;
	broken_block_3[1].Y = 110;
	broken_block_3[1].flag = 1;

	broken_block_3[2].X = 0;
	broken_block_3[2].Y = 110;
	broken_block_3[2].flag = 1;

	broken_block_3[3].X = 20;
	broken_block_3[3].Y = 110;
	broken_block_3[3].flag = 1;

	broken_block_3[4].X = 40;
	broken_block_3[4].Y = 110;
	broken_block_3[4].flag = 1;

	broken_block_3[5].X = 60;
	broken_block_3[5].Y = 110;
	broken_block_3[5].flag = 1;

	time_broken_block_3.X = 4520;
	time_broken_block_3.Y = 90;
	time_broken_block_3.flag = 1;

	head_broken_block_3[0].X = 3840;
	head_broken_block_3[0].Y = 80;
	head_broken_block_3[0].flag = 1;

	head_broken_block_3[1].X = 3860;
	head_broken_block_3[1].Y = 80;
	head_broken_block_3[1].flag = 1;

	head_broken_block_3[2].X = 3880;
	head_broken_block_3[2].Y = 80;
	head_broken_block_3[2].flag = 1;

	head_broken_block_3[3].X = 3900;
	head_broken_block_3[3].Y = 80;
	head_broken_block_3[3].flag = 1;

	head_broken_block_3[4].X = 3920;
	head_broken_block_3[4].Y = 80;
	head_broken_block_3[4].flag = 1;

	head_broken_block_3[5].X = 3940;
	head_broken_block_3[5].Y = 80;
	head_broken_block_3[5].flag = 1;

	head_broken_block_3[6].X = 3960;
	head_broken_block_3[6].Y = 80;
	head_broken_block_3[6].flag = 1;

	down_block_3[0].X = 2080;
	down_block_3[0].Y = 108;

	down_block_3[1].X = 3320;
	down_block_3[1].Y = 108;

	down_block_3[2].X = 3620;
	down_block_3[2].Y = 108;

	down_block_3[3].X = 4320;
	down_block_3[3].Y = 108;

	long_block_3.X = 2740;
	long_block_3.Y = -120;
	long_block_3.flag = 0;

	step_up_block_3.X = 1800;
	step_up_block_3.Y = 89;

	step_down_block_3.X = 1910;
	step_down_block_3.Y = 68;

	step_back_block_3.X = 4600;
	step_back_block_3.Y = 90;

	check_point_3[0].X = 1200;
	check_point_3[0].Y = 70;
	check_point_3[0].flag = 1;

	check_point_3[1].X = 3420;
	check_point_3[1].Y = 70;
	check_point_3[1].flag = 1;

	monster_3[0].X = 950;
	monster_3[0].Y = 82;
	monster_3[0].flag = 0;

	monster_3[1].X = 5160;
	monster_3[1].Y = 0;
	monster_3[1].flag = 0;

	monster_fly_3[0].X = 3180;
	monster_fly_3[0].Y = 52;
	monster_fly_3[0].flag = 1;

	monster_fly_3[1].X = 3120;
	monster_fly_3[1].Y = 65;
	monster_fly_3[1].flag = 1;

	monster_fly_3[2].X = 3080;
	monster_fly_3[2].Y = 75;
	monster_fly_3[2].flag = 1;

	monster_fly_3[3].X = 3100;
	monster_fly_3[3].Y = 95;
	monster_fly_3[3].flag = 1;

	monster_jump_3.X = 3220;
	monster_jump_3.Y = 100;


	running = 1;	// 살아있음(죽은지 체크)

	// 사운드 재생 
	mciSendString("play MUSIC\\stage3.mp3", NULL, 0, NULL);
}

// stage3 color 배열 셋팅
void Stage3_Coloring() {
	int x, y, i;
	// 맵 넣기
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0 + MapMovX; x < MapMovX + PRINT_FULL_WIDTH; x++) 
			color[y * PRINT_FULL_WIDTH + x - MapMovX] = full_map_3[y][x] | full_map_3[y][x] * 16;
	}

	// 체크 포인트
	for (i = 0; i < 2; i++) {
		if (!(check_point_3[i].X >= MapMovX - 20 && check_point_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (check_point_3[i].X + x - MapMovX < 0 || check_point_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (check_point_3[i].flag == 1)
					color[(check_point_3[i].Y + y) * PRINT_FULL_WIDTH + check_point_3[i].X + x - MapMovX] = block3_12[y][x] | block3_12[y][x] * 16;	// 체크포인트
			}
		}
	}

	// 가시 블럭
	for (i = 0; i < 2; i++) {
		if (!(Thorn_3[i].X >= MapMovX - 20 && Thorn_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 3; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (Thorn_3[i].X + x - MapMovX < 0 || Thorn_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (Thorn_3[i].flag == 1)
					color[(Thorn_3[i].Y + y) * PRINT_FULL_WIDTH + Thorn_3[i].X + x - MapMovX] = block3_19[y][x] | block3_19[y][x] * 16;		// 가시블럭
			}
		}
	}

	// 떨어지는 긴 블럭
	for (y = 0; y < BLACK_HEIGHT * 12; y++) {
		for (x = 0; x < BLACK_WIDTH; x++) {
			if (long_block_3.X + x - MapMovX < 0 || long_block_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
				continue;

			if (long_block_3.flag == 1)
				full_map_3[y + long_block_3.Y][x + long_block_3.X] = block3_22[y][x];			// 긴 블럭
		}
	}

	// 밟으면 떨어지는 블럭 (일자 블럭)
	for (i = 0; i < 1; i++) {
		if (!(step_down_block_3.X >= MapMovX - 20 && step_down_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (mario.X > step_down_block_3.X && mario.X < step_down_block_3.X + 47 && mario.Y == step_down_block_3.Y - 5)
					full_map_3[y + step_down_block_3.Y][x + step_down_block_3.X] = block3_21[y][x];		// 배경
				else
					full_map_3[y + step_down_block_3.Y][x + step_down_block_3.X] = block3_20[y][x];		// 떨어지는 블럭
			}
		}
	}

	// 밟으면 올라가는 블럭 (일자 블럭)
	for (i = 0; i < 1; i++) {
		if (!(step_up_block_3.X >= MapMovX - 20 && step_up_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (mario.X > step_up_block_3.X && mario.X < step_up_block_3.X + 49 && mario.Y == step_up_block_3.Y + 14)
					full_map_3[y + step_up_block_3.Y][x + step_up_block_3.X] = block3_21[y][x];			// 배경
				else
					full_map_3[y + step_up_block_3.Y][x + step_up_block_3.X] = block3_20[y][x];			// 올라가는 블럭
			}
		}
	}

	// 밟으면 떨어지는 블럭 (3칸 블럭)
	for (i = 0; i < 4; i++) {
		if (!(down_block_3[i].X >= MapMovX - 20 && down_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT + 2; y++) {
			for (x = 0; x < BLACK_WIDTH * 3; x++) {
				if (down_block_3[i].X + x - MapMovX < 0 || down_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (mario.X > down_block_3[i].X && mario.X < down_block_3[i].X + 60 && mario.Y == down_block_3[i].Y - 5)
					full_map_3[y + down_block_3[i].Y][x + down_block_3[i].X] = block3_24[y][x];		// 배경
				else
					full_map_3[y + down_block_3[i].Y][x + down_block_3[i].X] = block3_23[y][x];		// 떨어지는 3칸 블럭
			}
		}
	}

	// 밟으면 부서지는 블럭
	for (i = 0; i < 6; i++) {
		if (!(broken_block_3[i].X >= MapMovX - 20 && broken_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (broken_block_3[i].X + x - MapMovX < 0 || broken_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_3[i].flag == 0)
					full_map_3[y + broken_block_3[i].Y][x + broken_block_3[i].X] = block3_1[y][x];		// 배경
			}
		}
	}

	// 시간이 지나면 부서지는 블럭
	for (i = 0; i < 1; i++) {
		if (!(time_broken_block_3.X >= MapMovX - 20 && time_broken_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (time_broken_block_3.X + x - MapMovX < 0 || time_broken_block_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (time_broken_block_3.flag == 0)
					full_map_3[y + time_broken_block_3.Y][x + time_broken_block_3.X] = block3_25[y][x];		// 배경
			}
		}
	}

	// 머리 부딪치면 생기는 블럭
	for (i = 0; i < 7; i++) {
		if (!(head_broken_block_3[i].X >= MapMovX - 20 && head_broken_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (head_broken_block_3[i].X + x - MapMovX < 0 || head_broken_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (head_broken_block_3[i].flag == 0)
					full_map_3[y + head_broken_block_3[i].Y][x + head_broken_block_3[i].X] = block3_4[y][x];		// 벽돌
			}
		}
	}

	// 투명 블럭
	for (i = 0; i < 12; i++) {
		if (!(not_block_3[i].X >= MapMovX - 20 && not_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (not_block_3[i].X + x - MapMovX < 0 || not_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (not_block_3[i].flag == 0)
					color[(not_block_3[i].Y + y) * PRINT_FULL_WIDTH + not_block_3[i].X + x - MapMovX] = block3_1[y][x] | block3_1[y][x] * 16;	// 배경					
			}
		}
	}

	// 몬스터1,2
	for (i = 0; i < 2; i++) {
		if (!(monster_3[i].X >= MapMovX - 20 && monster_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_3[i].X + x - MapMovX < 0 || monster_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_3[i].flag == 1)
					color[(monster_3[i].Y + y) * PRINT_FULL_WIDTH + monster_3[i].X + x - MapMovX] = block3_32[y][x] | block3_32[y][x] * 16;	// 몬스터
			}
		}
	}

	// 날아오는 괴물
	for (i = 0; i < 4; i++) {
		if (!(monster_fly_3[i].X >= MapMovX - 20 && monster_fly_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_fly_3[i].X + x - MapMovX < 0 || monster_fly_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_fly_3[i].flag == 1)
					color[(monster_fly_3[i].Y + y) * PRINT_FULL_WIDTH + monster_fly_3[i].X + x - MapMovX] = (block3_33[y][x] != 0 ? block3_33[y][x] : full_map_3[y + monster_fly_3[i].Y][x + monster_fly_3[i].X]) | (block3_33[y][x] != 0 ? block3_33[y][x] : full_map_3[y + monster_fly_3[i].Y][x + monster_fly_3[i].X]) * 16;
			}
		}
	}

	// 점프하는 괴물
	for (i = 0; i < 1; i++) {
		if (!(monster_jump_3.X >= MapMovX - 20 && monster_jump_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_jump_3.X + x - MapMovX < 0 || monster_jump_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				color[(monster_jump_3.Y + y) * PRINT_FULL_WIDTH + monster_jump_3.X + x - MapMovX] = block3_34[y][x] | block3_34[y][x] * 16;	// 몬스터
			}
		}
	}
	

	// 마리오 넣기
	for (y = 0; y < 16; y += 2) {
		for (x = 0; x < 12; x++) {
			// 마지막 문에 들어가면 출력 X
			if (x + mario.X >= 5241)
				continue;
			
			// 죽을때
			if (running == 0)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_death_Location[y][x] != 16 ? E_death_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_death_Location[y + 1][x] != 16 ? E_death_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
			// 점프
			else if (jump_check > -7)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_jump_Location[y][x] != 16 ? E_jump_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_jump_Location[y + 1][x] != 16 ? E_jump_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
			// 기본
			else 
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_Location[y][x] != 16 ? E_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_Location[y + 1][x] != 16 ? E_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
		}
	}
}

// 블럭 체크
void Stage3_block_check() {
	int i;
	// 체크포인트
	for (i = 0; i < 2; i++) {
		if (check_point_3[i].flag && mario.X >= check_point_3[i].X - 2 && mario.X <= check_point_3[i].X + 16 && mario.Y <= check_point_3[i].Y + 12 && mario.Y >= check_point_3[i].Y - 10)
			check_point_3[i].flag = 0;

		if (mario.X >= check_point_3[i].X - 2 && mario.X <= check_point_3[i].X + 16 && mario.Y <= check_point_3[i].Y + 12 && mario.Y >= check_point_3[i].Y - 10)
			checkpoint = i + 1;
	}

	// 가시 블럭
	for (i = 0; i < 2; i++) {
		if (Thorn_3[i].flag == 0 && mario.X > Thorn_3[i].X - 10 && mario.X < Thorn_3[i].X + 10 && mario.Y <= Thorn_3[i].Y + 9 && mario.Y >= Thorn_3[i].Y - 9)
			Thorn_3[i].flag = 1;

		// 가시 만나면 게임오버
		if (mario.X > Thorn_3[i].X - 10 && mario.X < Thorn_3[i].X + 10 && mario.Y <= Thorn_3[i].Y + 9 && mario.Y >= Thorn_3[i].Y - 9) {
			GameOver();
			Stage3_check_point();
		}
	}

	// 투명 블럭
	for (i = 0; i < 12; i++) { 
		if (not_block_3[i].flag == 0 && mario.X > not_block_3[i].X - 12 && mario.X < not_block_3[i].X + 20 && mario.Y > not_block_3[i].Y - 8 && mario.Y < not_block_3[i].Y + 12)
			not_block_3[i].flag = 1;
	}

	// 밟으면 부서지는 블럭
	for (i = 0; i < 6; i++) {
		if (broken_block_3[i].flag == 1 && mario.X > broken_block_3[i].X - 12 && mario.X < broken_block_3[i].X + 20 && mario.Y == broken_block_3[i].Y - 7)
			broken_block_3[i].flag = 0;
	}

	// 머리 부딪치면 생기는 블럭
	for (i = 0; i < 7; i++) {
		if (head_broken_block_3[i].flag == 1 && mario.X > head_broken_block_3[i].X - 12 && mario.X < head_broken_block_3[i].X + 20 && mario.Y == head_broken_block_3[i].Y + 11) {
			head_broken_block_3[i].flag = 0;
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
}

// 시간에 따라 움직이는 블럭
void Stage3_move_thread(void* args) {
	int i = 0, l = 0, k = 0, mo_jump_check = 0;
	while (1) {
		if (clock() - l < 20) 
			continue;
		l = clock();

		// 스테이지 종료시 쓰레드 종료
		if (stage != 3) 
			break;
		

		// 몬스터1(기둥 몬스터)
		if (mario.X > monster_3[0].X - 20 && mario.X < monster_3[0].X + 28 && mario.Y < monster_3[0].Y - 16 && mario.Y > 0) {
			monster_3[0].flag = 1;
			// 사운드 재생
			if (play_sound_selection) {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound, 0, (int)6);
			}
			else {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound_, 0, (int)6);
			}
			while (1) {
				if (clock() - k < 25)
					continue;
				

				// 몬스터 Y축이 0 이하일때까지 
				if (monster_3[0].Y <= 1) {
					monster_3[0].flag = 0;
					break;
				}

				k = clock();
				monster_3[0].Y -= 2;
			}
		}

		// 몬스터2(엔딩 몬스터)
		if (mario.X > monster_3[1].X - 19 && mario.Y > monster_3[1].Y && mario.Y < PRINT_FULL_HEIGHT) {
			monster_3[1].flag = 1;
			while (1) {
				if (clock() - k < 10) 
					continue;
				

				// 몬스터 Y축이 땅까지 
				if (monster_3[1].Y > PRINT_FULL_HEIGHT - 5) {
					monster_3[1].flag = 0;
					break;
				}

				k = clock();
				monster_3[1].Y += 2;
			}
		}

		// 날아오는 괴물
		if (mario.X >= 2920) {
			while (1) {
				if (clock() - k < 17) 
					continue;
				
				// 몬스터 X축이 MapMovX일때까지 
				if (monster_fly_3[0].X <= MapMovX - 20 || death(0, 0) == 1)
					break;


				k = clock();
				for (i = 0; i < 4; i++)
					monster_fly_3[i].X -= 2;
			}
		}


		// 점프하는 괴물
		if ((GetAsyncKeyState('W') & 0x8000) && mo_jump_check == 0)
			mo_jump_check = 20;

		// 점프키를 눌렀을때
		if (mo_jump_check > 0 && monster_jump_3.Y > 10) {
			mo_jump_check--;
			monster_jump_3.Y--;
		}
		else if (monster_jump_3.Y != 100)
			monster_jump_3.Y++;

		// 스프링
		if (mario.X > Spring_3.X - 10 && mario.X < Spring_3.X + 18 && mario.Y == Spring_3.Y - 9) {
			mciSendString("play spring.wav", NULL, 0, NULL);
			while (1) {
				if (clock() - k < 15) 
					continue;
				
				// 마리오 Y축이 0 이하일때까지 
				if (mario.Y < 0)
					break;
				k = clock();
				mario.Y -= 5;
			}
		}

		// 밟으면 뒤로 날라가는 블럭
		if (mario.X > step_back_block_3.X - 12 && mario.X < step_back_block_3.X + 40 && mario.Y == step_back_block_3.Y - 8) {
			while (1) {
				if (clock() - k < 10) 
					continue;
				
				// 마리오 X축이 맵X축 까지 혹은 죽을때 까지
				if (mario.X <= MapMovX + 10 || death(0, 0) == 1)
					break;

				k = clock();
				mario.X -= 5;
			}
		}

		// 시간에 지나면 부서지는 블럭
		if (mario.X > time_broken_block_3.X - 12 && mario.X < time_broken_block_3.X + 40 && mario.Y == time_broken_block_3.Y - 8) {
			k = clock();
			while (1) {
				// 0.5초 뒤에 블럭 없어짐
				if (clock() - k > 500) {
					time_broken_block_3.flag = 0;
					break;
				}
			}
		}

		// 떨어지는 긴 블럭.
		if (long_block_3.X <= PRINT_FULL_WIDTH + MapMovX - 90) {
			long_block_3.flag = 1;
			while (1) {
				if (clock() - k < 13) 
					continue;
				
				// 블럭 땅까지 혹은 죽을때 까지
				if (long_block_3.Y == -10 || death(0, 0) == 1)
					break;

				k = clock();
				long_block_3.Y += 1;
			}
		}


		// 밟으면 떨어지는 블럭 (3칸 블럭)
		for (i = 0; i < 4; i++) {
			if (mario.X > down_block_3[i].X && mario.X < down_block_3[i].X + 60 && mario.Y == down_block_3[i].Y - 5) {
				while (1) {
					if (clock() - k < 20) {
						Sleep(1);
						continue;
					}
					// 블럭이 Y축이 PRINT_FULL_HEIGHT때까지 
					if (down_block_3[i].Y > PRINT_FULL_HEIGHT)
						break;

					k = clock();
					down_block_3[i].Y += 1;
				}
			}
		}

		// 밟으면 떨어지는 블럭 (일자 블럭)
		if (mario.X > step_down_block_3.X && mario.X < step_down_block_3.X + 49 && mario.Y == step_down_block_3.Y - 6)
			step_down_block_3.Y += 2;

		// 밟으면 올라가는 블럭 (일자 블럭)
		if (mario.X > step_up_block_3.X && mario.X < step_up_block_3.X + 49 &&  mario.Y == step_up_block_3.Y + 14) {
			mario.Y -= 4;
			step_up_block_3.Y -= 2;
		}
	}
}

// 체크포인트
void Stage3_check_point() {
	// 체크포인트로 가면서 스테이지3 셋팅
	Stage3_setup();
	switch (checkpoint) {
	case 0:
		MapMovX = 0;
		mario.X = 20;
		mario.Y = 20;
		break;
	case 1:
		MapMovX = 1120;
		mario.X = 1200;
		mario.Y = 73;
		break;
	case 2:
		MapMovX = 3340;
		mario.X = 3420;
		mario.Y = 73;
		break;
	case 3:
		MapMovX = 2000;
		mario.X = 2000;
		mario.Y = 103;
		break;

	}
}


// 키보드
void Stage3_Input(void* arg) {
	int i = 0;
	while (1) {
		// 시간 함수 사용하여서 속도 조절
		if (clock() - i < 22)
			continue;

		i = clock();

		// 스테이지 종료시 스레드 종료
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || stage != 3) 
			break;
		

		if ((GetAsyncKeyState('W') & 0x8000) && CanIJump() && jump_check == -7) {
			jump_check = 20;

			// 점프 음악 재생
			if (play_sound_selection){
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound, 0, (int)1);
			}
			else{
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound_, 0, (int)1);
			}
		}

		if (GetAsyncKeyState('A') & 0x8000) {
			Mov_Safe(-2, 0);
		}

		if (GetAsyncKeyState('S') & 0x8000) {
		}

		if (GetAsyncKeyState('D') & 0x8000) {
			Mov_Safe(2, 0);
		}


		// 점프키를 눌렀을때
		if (jump_check > -7) {
			jump_check--;
			if (jump_check > 0) {
				if (MovMorio(0, 2)) {
					MovMorio(0, 1);
					jump_check = -3;
				}
			}
		}
		else
			Mov_Safe(0, -2);
	}
}