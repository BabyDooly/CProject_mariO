#pragma warning (disable : 4996)
#include "function.h"
#include "map.h"

/* -------- �� --------- */
extern char block3_1[BLACK_HEIGHT][BLACK_WIDTH];	// ���
extern char block3_2[BLACK_HEIGHT][BLACK_WIDTH];	// �Ϲݺ���
extern char block3_3[BLACK_HEIGHT][BLACK_WIDTH];	// ���� 
extern char block3_4[BLACK_HEIGHT][BLACK_WIDTH];	// �Ų��� ����
extern char block3_5[BLACK_HEIGHT][BLACK_WIDTH];	// �����
extern char block3_6[BLACK_HEIGHT][BLACK_WIDTH];	// ���� �ö󰡸� �μ����� ��
extern char block3_7[BLACK_HEIGHT][BLACK_WIDTH];	// ���1
extern char block3_8[BLACK_HEIGHT][BLACK_WIDTH];	// ���2
extern char block3_9[BLACK_HEIGHT][BLACK_WIDTH];	// ���3
extern char block3_10[BLACK_HEIGHT][BLACK_WIDTH];	// ���4
extern char block3_11[BLACK_HEIGHT][BLACK_WIDTH];	// ������
extern char block3_12[BLACK_HEIGHT][BLACK_WIDTH];	// ���̺� ����Ʈ
extern char block3_13[BLACK_HEIGHT][BLACK_WIDTH];	// ������
extern char block3_14[BLACK_HEIGHT][BLACK_WIDTH];	// ��¥ ���� ���� ��� �����
extern char block3_15[BLACK_HEIGHT][BLACK_WIDTH];	// ��¥ ���� ���� ���� ���̾Ƹ��
extern char block3_16[BLACK_HEIGHT][BLACK_WIDTH];	// ��¥ ���� ���� ���� ���̾Ƹ��
extern char block3_17[BLACK_HEIGHT][BLACK_WIDTH];	// �����ð��� ���� �� �μ���  
extern char block3_18[BLACK_HEIGHT][BLACK_WIDTH];	// ������ �ڷ� ƨ���� ����
extern char block3_19[3][BLACK_WIDTH];				// ���ú� 
extern char block3_20[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH * 2];	// ������ �����̴� ���� ��
extern char block3_21[BLACK_HEIGHT * 3 - 5][BLACK_WIDTH * 2];	// ������ �����̴� ���� �� 0
extern char block3_22[BLACK_HEIGHT * 12][BLACK_WIDTH];		// ���η� �� �� 
extern char block3_23[BLACK_HEIGHT + 2][BLACK_WIDTH * 3];	// ������ �������� 3ĭ ��
extern char block3_24[BLACK_HEIGHT + 2][BLACK_WIDTH * 3];	// ������ �������� 3ĭ �� 0
extern char block3_25[BLACK_HEIGHT][BLACK_WIDTH * 2];	// �ð� ������ �μ����� �� 0 
extern char block3_26[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��1
extern char block3_27[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��2
extern char block3_28[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��3
extern char block3_29[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��4
extern char block3_30[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��5
extern char block3_31[BLACK_HEIGHT][BLACK_WIDTH];		// ���� ���� ��6
extern char block3_32[BLACK_HEIGHT][BLACK_WIDTH];		// ����
extern char block3_33[BLACK_HEIGHT][BLACK_WIDTH];		// ���ƿ��� ����
extern char block3_34[BLACK_HEIGHT][BLACK_WIDTH];		// ���ΰ��� �����ϸ� ���� �����ϴ� ����
extern int map_3[MAP_HEIGHT][MAP_WIDTH_3];
extern int full_map_3[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_3];


/* -------- ���� --------- */
extern int MapMovX;		// �� x��
extern int stage;		// �������� 
extern int running;		// ������ Ȯ��
extern int end;			// ���� ���� Ȯ��
extern int checkpoint;	// üũ����Ʈ
extern int jump_check;	// ���� Ȯ��
extern int play_sound_selection;	// ���� üũ
extern int menu;		// ���� ���� �ʱⰪ

extern char E_Location[16][12], E_jump_Location[16][12], E_death_Location[16][12];	// ������ĳ����

/* -------- ����ü --------- */
extern struct Pos mario;		// ������ ��ġ
struct Pos Thorn_3[2], Spring_3, not_block_3[12], broken_block_3[6], time_broken_block_3, head_broken_block_3[7], step_up_block_3, step_down_block_3, step_back_block_3,
	 down_block_3[4], long_block_3, check_point_3[2], monster_3[2], monster_fly_3[4], monster_jump_3;	// �� ����ü

// ��������3 ����
void Stage3_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;

	// full_map�� ����
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


	// ���� �� / ���� ����
	
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


	running = 1;	// �������(������ üũ)

	// ���� ��� 
	mciSendString("play MUSIC\\stage3.mp3", NULL, 0, NULL);
}

// stage3 color �迭 ����
void Stage3_Coloring() {
	int x, y, i;
	// �� �ֱ�
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0 + MapMovX; x < MapMovX + PRINT_FULL_WIDTH; x++) 
			color[y * PRINT_FULL_WIDTH + x - MapMovX] = full_map_3[y][x] | full_map_3[y][x] * 16;
	}

	// üũ ����Ʈ
	for (i = 0; i < 2; i++) {
		if (!(check_point_3[i].X >= MapMovX - 20 && check_point_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (check_point_3[i].X + x - MapMovX < 0 || check_point_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (check_point_3[i].flag == 1)
					color[(check_point_3[i].Y + y) * PRINT_FULL_WIDTH + check_point_3[i].X + x - MapMovX] = block3_12[y][x] | block3_12[y][x] * 16;	// üũ����Ʈ
			}
		}
	}

	// ���� ��
	for (i = 0; i < 2; i++) {
		if (!(Thorn_3[i].X >= MapMovX - 20 && Thorn_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 3; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (Thorn_3[i].X + x - MapMovX < 0 || Thorn_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (Thorn_3[i].flag == 1)
					color[(Thorn_3[i].Y + y) * PRINT_FULL_WIDTH + Thorn_3[i].X + x - MapMovX] = block3_19[y][x] | block3_19[y][x] * 16;		// ���ú�
			}
		}
	}

	// �������� �� ��
	for (y = 0; y < BLACK_HEIGHT * 12; y++) {
		for (x = 0; x < BLACK_WIDTH; x++) {
			if (long_block_3.X + x - MapMovX < 0 || long_block_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
				continue;

			if (long_block_3.flag == 1)
				full_map_3[y + long_block_3.Y][x + long_block_3.X] = block3_22[y][x];			// �� ��
		}
	}

	// ������ �������� �� (���� ��)
	for (i = 0; i < 1; i++) {
		if (!(step_down_block_3.X >= MapMovX - 20 && step_down_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (mario.X > step_down_block_3.X && mario.X < step_down_block_3.X + 47 && mario.Y == step_down_block_3.Y - 5)
					full_map_3[y + step_down_block_3.Y][x + step_down_block_3.X] = block3_21[y][x];		// ���
				else
					full_map_3[y + step_down_block_3.Y][x + step_down_block_3.X] = block3_20[y][x];		// �������� ��
			}
		}
	}

	// ������ �ö󰡴� �� (���� ��)
	for (i = 0; i < 1; i++) {
		if (!(step_up_block_3.X >= MapMovX - 20 && step_up_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 3 - 5; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (mario.X > step_up_block_3.X && mario.X < step_up_block_3.X + 49 && mario.Y == step_up_block_3.Y + 14)
					full_map_3[y + step_up_block_3.Y][x + step_up_block_3.X] = block3_21[y][x];			// ���
				else
					full_map_3[y + step_up_block_3.Y][x + step_up_block_3.X] = block3_20[y][x];			// �ö󰡴� ��
			}
		}
	}

	// ������ �������� �� (3ĭ ��)
	for (i = 0; i < 4; i++) {
		if (!(down_block_3[i].X >= MapMovX - 20 && down_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT + 2; y++) {
			for (x = 0; x < BLACK_WIDTH * 3; x++) {
				if (down_block_3[i].X + x - MapMovX < 0 || down_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (mario.X > down_block_3[i].X && mario.X < down_block_3[i].X + 60 && mario.Y == down_block_3[i].Y - 5)
					full_map_3[y + down_block_3[i].Y][x + down_block_3[i].X] = block3_24[y][x];		// ���
				else
					full_map_3[y + down_block_3[i].Y][x + down_block_3[i].X] = block3_23[y][x];		// �������� 3ĭ ��
			}
		}
	}

	// ������ �μ����� ��
	for (i = 0; i < 6; i++) {
		if (!(broken_block_3[i].X >= MapMovX - 20 && broken_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (broken_block_3[i].X + x - MapMovX < 0 || broken_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_3[i].flag == 0)
					full_map_3[y + broken_block_3[i].Y][x + broken_block_3[i].X] = block3_1[y][x];		// ���
			}
		}
	}

	// �ð��� ������ �μ����� ��
	for (i = 0; i < 1; i++) {
		if (!(time_broken_block_3.X >= MapMovX - 20 && time_broken_block_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (time_broken_block_3.X + x - MapMovX < 0 || time_broken_block_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (time_broken_block_3.flag == 0)
					full_map_3[y + time_broken_block_3.Y][x + time_broken_block_3.X] = block3_25[y][x];		// ���
			}
		}
	}

	// �Ӹ� �ε�ġ�� ����� ��
	for (i = 0; i < 7; i++) {
		if (!(head_broken_block_3[i].X >= MapMovX - 20 && head_broken_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (head_broken_block_3[i].X + x - MapMovX < 0 || head_broken_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (head_broken_block_3[i].flag == 0)
					full_map_3[y + head_broken_block_3[i].Y][x + head_broken_block_3[i].X] = block3_4[y][x];		// ����
			}
		}
	}

	// ���� ��
	for (i = 0; i < 12; i++) {
		if (!(not_block_3[i].X >= MapMovX - 20 && not_block_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (not_block_3[i].X + x - MapMovX < 0 || not_block_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (not_block_3[i].flag == 0)
					color[(not_block_3[i].Y + y) * PRINT_FULL_WIDTH + not_block_3[i].X + x - MapMovX] = block3_1[y][x] | block3_1[y][x] * 16;	// ���					
			}
		}
	}

	// ����1,2
	for (i = 0; i < 2; i++) {
		if (!(monster_3[i].X >= MapMovX - 20 && monster_3[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_3[i].X + x - MapMovX < 0 || monster_3[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_3[i].flag == 1)
					color[(monster_3[i].Y + y) * PRINT_FULL_WIDTH + monster_3[i].X + x - MapMovX] = block3_32[y][x] | block3_32[y][x] * 16;	// ����
			}
		}
	}

	// ���ƿ��� ����
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

	// �����ϴ� ����
	for (i = 0; i < 1; i++) {
		if (!(monster_jump_3.X >= MapMovX - 20 && monster_jump_3.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_jump_3.X + x - MapMovX < 0 || monster_jump_3.X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				color[(monster_jump_3.Y + y) * PRINT_FULL_WIDTH + monster_jump_3.X + x - MapMovX] = block3_34[y][x] | block3_34[y][x] * 16;	// ����
			}
		}
	}
	

	// ������ �ֱ�
	for (y = 0; y < 16; y += 2) {
		for (x = 0; x < 12; x++) {
			// ������ ���� ���� ��� X
			if (x + mario.X >= 5241)
				continue;
			
			// ������
			if (running == 0)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_death_Location[y][x] != 16 ? E_death_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_death_Location[y + 1][x] != 16 ? E_death_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
			// ����
			else if (jump_check > -7)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_jump_Location[y][x] != 16 ? E_jump_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_jump_Location[y + 1][x] != 16 ? E_jump_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
			// �⺻
			else 
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_Location[y][x] != 16 ? E_Location[y][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) | (E_Location[y + 1][x] != 16 ? E_Location[y + 1][x] : full_map_3[y / 2 + mario.Y][x + mario.X]) * 16;
		}
	}
}

// �� üũ
void Stage3_block_check() {
	int i;
	// üũ����Ʈ
	for (i = 0; i < 2; i++) {
		if (check_point_3[i].flag && mario.X >= check_point_3[i].X - 2 && mario.X <= check_point_3[i].X + 16 && mario.Y <= check_point_3[i].Y + 12 && mario.Y >= check_point_3[i].Y - 10)
			check_point_3[i].flag = 0;

		if (mario.X >= check_point_3[i].X - 2 && mario.X <= check_point_3[i].X + 16 && mario.Y <= check_point_3[i].Y + 12 && mario.Y >= check_point_3[i].Y - 10)
			checkpoint = i + 1;
	}

	// ���� ��
	for (i = 0; i < 2; i++) {
		if (Thorn_3[i].flag == 0 && mario.X > Thorn_3[i].X - 10 && mario.X < Thorn_3[i].X + 10 && mario.Y <= Thorn_3[i].Y + 9 && mario.Y >= Thorn_3[i].Y - 9)
			Thorn_3[i].flag = 1;

		// ���� ������ ���ӿ���
		if (mario.X > Thorn_3[i].X - 10 && mario.X < Thorn_3[i].X + 10 && mario.Y <= Thorn_3[i].Y + 9 && mario.Y >= Thorn_3[i].Y - 9) {
			GameOver();
			Stage3_check_point();
		}
	}

	// ���� ��
	for (i = 0; i < 12; i++) { 
		if (not_block_3[i].flag == 0 && mario.X > not_block_3[i].X - 12 && mario.X < not_block_3[i].X + 20 && mario.Y > not_block_3[i].Y - 8 && mario.Y < not_block_3[i].Y + 12)
			not_block_3[i].flag = 1;
	}

	// ������ �μ����� ��
	for (i = 0; i < 6; i++) {
		if (broken_block_3[i].flag == 1 && mario.X > broken_block_3[i].X - 12 && mario.X < broken_block_3[i].X + 20 && mario.Y == broken_block_3[i].Y - 7)
			broken_block_3[i].flag = 0;
	}

	// �Ӹ� �ε�ġ�� ����� ��
	for (i = 0; i < 7; i++) {
		if (head_broken_block_3[i].flag == 1 && mario.X > head_broken_block_3[i].X - 12 && mario.X < head_broken_block_3[i].X + 20 && mario.Y == head_broken_block_3[i].Y + 11) {
			head_broken_block_3[i].flag = 0;
			// ���� ���
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

// �ð��� ���� �����̴� ��
void Stage3_move_thread(void* args) {
	int i = 0, l = 0, k = 0, mo_jump_check = 0;
	while (1) {
		if (clock() - l < 20) 
			continue;
		l = clock();

		// �������� ����� ������ ����
		if (stage != 3) 
			break;
		

		// ����1(��� ����)
		if (mario.X > monster_3[0].X - 20 && mario.X < monster_3[0].X + 28 && mario.Y < monster_3[0].Y - 16 && mario.Y > 0) {
			monster_3[0].flag = 1;
			// ���� ���
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
				

				// ���� Y���� 0 �����϶����� 
				if (monster_3[0].Y <= 1) {
					monster_3[0].flag = 0;
					break;
				}

				k = clock();
				monster_3[0].Y -= 2;
			}
		}

		// ����2(���� ����)
		if (mario.X > monster_3[1].X - 19 && mario.Y > monster_3[1].Y && mario.Y < PRINT_FULL_HEIGHT) {
			monster_3[1].flag = 1;
			while (1) {
				if (clock() - k < 10) 
					continue;
				

				// ���� Y���� ������ 
				if (monster_3[1].Y > PRINT_FULL_HEIGHT - 5) {
					monster_3[1].flag = 0;
					break;
				}

				k = clock();
				monster_3[1].Y += 2;
			}
		}

		// ���ƿ��� ����
		if (mario.X >= 2920) {
			while (1) {
				if (clock() - k < 17) 
					continue;
				
				// ���� X���� MapMovX�϶����� 
				if (monster_fly_3[0].X <= MapMovX - 20 || death(0, 0) == 1)
					break;


				k = clock();
				for (i = 0; i < 4; i++)
					monster_fly_3[i].X -= 2;
			}
		}


		// �����ϴ� ����
		if ((GetAsyncKeyState('W') & 0x8000) && mo_jump_check == 0)
			mo_jump_check = 20;

		// ����Ű�� ��������
		if (mo_jump_check > 0 && monster_jump_3.Y > 10) {
			mo_jump_check--;
			monster_jump_3.Y--;
		}
		else if (monster_jump_3.Y != 100)
			monster_jump_3.Y++;

		// ������
		if (mario.X > Spring_3.X - 10 && mario.X < Spring_3.X + 18 && mario.Y == Spring_3.Y - 9) {
			mciSendString("play spring.wav", NULL, 0, NULL);
			while (1) {
				if (clock() - k < 15) 
					continue;
				
				// ������ Y���� 0 �����϶����� 
				if (mario.Y < 0)
					break;
				k = clock();
				mario.Y -= 5;
			}
		}

		// ������ �ڷ� ���󰡴� ��
		if (mario.X > step_back_block_3.X - 12 && mario.X < step_back_block_3.X + 40 && mario.Y == step_back_block_3.Y - 8) {
			while (1) {
				if (clock() - k < 10) 
					continue;
				
				// ������ X���� ��X�� ���� Ȥ�� ������ ����
				if (mario.X <= MapMovX + 10 || death(0, 0) == 1)
					break;

				k = clock();
				mario.X -= 5;
			}
		}

		// �ð��� ������ �μ����� ��
		if (mario.X > time_broken_block_3.X - 12 && mario.X < time_broken_block_3.X + 40 && mario.Y == time_broken_block_3.Y - 8) {
			k = clock();
			while (1) {
				// 0.5�� �ڿ� �� ������
				if (clock() - k > 500) {
					time_broken_block_3.flag = 0;
					break;
				}
			}
		}

		// �������� �� ��.
		if (long_block_3.X <= PRINT_FULL_WIDTH + MapMovX - 90) {
			long_block_3.flag = 1;
			while (1) {
				if (clock() - k < 13) 
					continue;
				
				// �� ������ Ȥ�� ������ ����
				if (long_block_3.Y == -10 || death(0, 0) == 1)
					break;

				k = clock();
				long_block_3.Y += 1;
			}
		}


		// ������ �������� �� (3ĭ ��)
		for (i = 0; i < 4; i++) {
			if (mario.X > down_block_3[i].X && mario.X < down_block_3[i].X + 60 && mario.Y == down_block_3[i].Y - 5) {
				while (1) {
					if (clock() - k < 20) {
						Sleep(1);
						continue;
					}
					// ���� Y���� PRINT_FULL_HEIGHT������ 
					if (down_block_3[i].Y > PRINT_FULL_HEIGHT)
						break;

					k = clock();
					down_block_3[i].Y += 1;
				}
			}
		}

		// ������ �������� �� (���� ��)
		if (mario.X > step_down_block_3.X && mario.X < step_down_block_3.X + 49 && mario.Y == step_down_block_3.Y - 6)
			step_down_block_3.Y += 2;

		// ������ �ö󰡴� �� (���� ��)
		if (mario.X > step_up_block_3.X && mario.X < step_up_block_3.X + 49 &&  mario.Y == step_up_block_3.Y + 14) {
			mario.Y -= 4;
			step_up_block_3.Y -= 2;
		}
	}
}

// üũ����Ʈ
void Stage3_check_point() {
	// üũ����Ʈ�� ���鼭 ��������3 ����
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


// Ű����
void Stage3_Input(void* arg) {
	int i = 0;
	while (1) {
		// �ð� �Լ� ����Ͽ��� �ӵ� ����
		if (clock() - i < 22)
			continue;

		i = clock();

		// �������� ����� ������ ����
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || stage != 3) 
			break;
		

		if ((GetAsyncKeyState('W') & 0x8000) && CanIJump() && jump_check == -7) {
			jump_check = 20;

			// ���� ���� ���
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


		// ����Ű�� ��������
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