#pragma warning (disable : 4996)
#include "function.h"
#include "map.h"

/* -------- �� --------- */
extern char block2_0[BLACK_HEIGHT][BLACK_WIDTH];	// �ϴ�
extern char block2_1[BLACK_HEIGHT][BLACK_WIDTH];	// �ٴ�
extern char block2_2[BLACK_HEIGHT][BLACK_WIDTH];	// �Ӹ��� �ε�ġ�� ������ ���
extern char block2_3[BLACK_HEIGHT][BLACK_WIDTH];	// �ٴں�ϰ� �����ϳ� ������ ��� �ν���
extern char block2_4[BLACK_HEIGHT][BLACK_WIDTH];	// ������ �ʴ� ��� �Ӹ��� �ε�ġ�� ��Ÿ��
extern char block2_5[BLACK_HEIGHT][BLACK_WIDTH];	// ���1
extern char block2_6[BLACK_HEIGHT][BLACK_WIDTH];	// ���2
extern char block2_7[BLACK_HEIGHT][BLACK_WIDTH];	// ���3
extern char block2_8[BLACK_HEIGHT][BLACK_WIDTH];	// ���4
extern char block2_9[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��1
extern char block2_10[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��2
extern char block2_11[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��3
extern char block2_12[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��4 
extern char block2_13[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��5
extern char block2_14[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��6
extern char block2_15[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ��� �����
extern char block2_16[BLACK_HEIGHT][BLACK_WIDTH];	// ���� ���� ���� ���̾Ƹ��
extern char block2_17[BLACK_HEIGHT][BLACK_WIDTH];	// �������� ����
extern char block2_18[BLACK_HEIGHT][BLACK_WIDTH * 2];	// ���� (������ �޼ӵ��� �Ʒ��� ������)
extern char block2_19[BLACK_HEIGHT][BLACK_WIDTH];	// ������(������ ������ �ھƿö� ����)check_point_2
extern char block2_20[BLACK_HEIGHT][BLACK_WIDTH];	// ���ú��
extern char block2_21[BLACK_HEIGHT][BLACK_WIDTH];	// ���κ��
extern char block2_22[BLACK_HEIGHT][BLACK_WIDTH];	// ���̺� ���
extern char block2_23[BLACK_HEIGHT][BLACK_WIDTH];	// ����
extern char block2_24[BLACK_HEIGHT][BLACK_WIDTH];	// ����2 (���ƴٴ�)
extern char block2_25[BLACK_HEIGHT * 2 + 2][BLACK_WIDTH * 3];	// ������ �������� �� ��� (3x2 ��)
extern char block2_26[BLACK_HEIGHT * 2][BLACK_WIDTH];		// ������ �μ����� �� ��� (1x2 ��)
extern char block2_27[BLACK_HEIGHT * 2][BLACK_WIDTH * 2];	// ������ �μ����� �� ��� (2x2 ��)
extern char block2_28[BLACK_HEIGHT][BLACK_WIDTH * 3];	// �ܵ� (2x1 ��)
extern char block2_29[BLACK_HEIGHT][BLACK_WIDTH * 2];	// �������� �� ��� (2x1 ��)
extern char block2_30[8][16];	// ����(����)1
extern char block2_31[8][16];	// ����(����)2
extern char block2_32[12][32];	// ����1
extern char block2_33[12][32];	// ����2
extern char block2_34[BLACK_HEIGHT * 2 + 2][BLACK_WIDTH * 3];	// ������ �������� �� (3x2 ��)
extern char block2_35[10][16];	// ����(���β�)1
extern char block2_36[10][16];	// ����(���β�)2
extern char block2_37[12][20];	// ����(���)

char tmp_high[8][16], tmp_low[8][16];

extern int map_2[MAP_HEIGHT][MAP_WIDTH_2];	// ��ü ��
extern int full_map_2[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_2];


int map_2[MAP_HEIGHT][MAP_WIDTH_2];
int full_map_2[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_2];


extern int MapMovX;			// �� x��
extern int stage;			// �������� 
extern int running;			// ������ Ȯ��
extern int end;				// ���� ���� Ȯ��
extern int checkpoint;		// üũ����Ʈ
extern int jump_check;		// ���� Ȯ��
extern int spring_check;	// ������ üũ
extern int play_sound_selection;	// ���� üũ
extern int menu;			// ���� ���� �ʱⰪ


extern char E_Location[16][12], E_jump_Location[16][12], E_death_Location[16][12];	// ������ĳ����
extern struct Pos mario;		// ������ ��ġ

// �� ����ü
struct Pos coin_2[27], check_point_2[3], Thorn_2[4], Spring_2[3], grass_2[5], head_block_2[17], broken_block_2[18], broken_block_2_3x2[3], broken_block_2_1x2[3], broken_block_2_2x2[9],
	step_down_block_2, monster_2[14], monster_floower_2[2], monster_pillar_2[2], monster_fly_2[2], cloud_2[19];

// ��������2 ����
void Stage2_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;

	// full_map�� ����
	for (y = 0; y < MAP_HEIGHT; y++) {
		for (b_y = 0; b_y < BLACK_HEIGHT; b_y++) {
			input_x = 0;
			for (x = 0; x < MAP_WIDTH_2; x++) {
				for (b_x = 0; b_x < BLACK_WIDTH; b_x++) {
					switch (*(*(map_2 + y) + x)) {
					case 0:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_0 + b_y) + b_x);	break;
					case 1:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_1 + b_y) + b_x);	break;
					case 2:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_2 + b_y) + b_x);	break;
					case 3:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_3 + b_y) + b_x);	break;
					case 4:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_4 + b_y) + b_x);	break;
					case 5:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_5 + b_y) + b_x);	break;
					case 6:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_6 + b_y) + b_x);	break;
					case 7:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_7 + b_y) + b_x);	break;
					case 8:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_8 + b_y) + b_x);	break;
					case 9:		*(*(full_map_2 + input_y) + input_x) = *(*(block2_9 + b_y) + b_x);	break;
					case 10:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_10 + b_y) + b_x);	break;
					case 11:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_11 + b_y) + b_x);	break;
					case 12:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_12 + b_y) + b_x);	break;
					case 13:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_13 + b_y) + b_x);	break;
					case 14:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_14 + b_y) + b_x);	break;
					case 15:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_15 + b_y) + b_x);	break;
					case 16:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_16 + b_y) + b_x);	break;
					case 17:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_17 + b_y) + b_x);	break;
					case 18:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_18 + b_y) + b_x);	break;
					case 19:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_19 + b_y) + b_x);	break;
					case 20:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_20 + b_y) + b_x);	break;
					case 21:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_21 + b_y) + b_x);	break;
					case 22:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_22 + b_y) + b_x);	break;
					case 23:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_23 + b_y) + b_x);	break;
					case 24:	*(*(full_map_2 + input_y) + input_x) = *(*(block2_24 + b_y) + b_x);	break;
					}
					input_x++;
				}
			}
			input_y++;
		}
	}

	// ���� �� / ���� ����
	check_point_2[0].X = 660;
	check_point_2[0].Y = 90;
	check_point_2[0].flag = 1;

	check_point_2[1].X = 1620;
	check_point_2[1].Y = 40;
	check_point_2[1].flag = 1;

	check_point_2[2].X = 3200;
	check_point_2[2].Y = 90;
	check_point_2[2].flag = 1;

	coin_2[0].X = 60;
	coin_2[0].Y = 50;
	coin_2[0].flag = 1;

	coin_2[1].X = 80;
	coin_2[1].Y = 50;
	coin_2[1].flag = 1;

	coin_2[2].X = 100;
	coin_2[2].Y = 50;
	coin_2[2].flag = 1;

	coin_2[3].X = 840;
	coin_2[3].Y = 60;
	coin_2[3].flag = 1;

	coin_2[4].X = 840;
	coin_2[4].Y = 70;
	coin_2[4].flag = 1;

	coin_2[5].X = 840;
	coin_2[5].Y = 80;
	coin_2[5].flag = 1;

	coin_2[6].X = 840;
	coin_2[6].Y = 90;
	coin_2[6].flag = 1;

	coin_2[7].X = 860;
	coin_2[7].Y = 60;
	coin_2[7].flag = 1;

	coin_2[8].X = 860;
	coin_2[8].Y = 70;
	coin_2[8].flag = 1;

	coin_2[9].X = 860;
	coin_2[9].Y = 80;
	coin_2[9].flag = 1;

	coin_2[10].X = 860;
	coin_2[10].Y = 90;
	coin_2[10].flag = 1;

	coin_2[11].X = 1240;
	coin_2[11].Y = 90;
	coin_2[11].flag = 1;

	coin_2[12].X = 1360;
	coin_2[12].Y = 90;
	coin_2[12].flag = 1;

	coin_2[13].X = 1260;
	coin_2[13].Y = 50;
	coin_2[13].flag = 1;

	coin_2[14].X = 3140;
	coin_2[14].Y = 90;
	coin_2[14].flag = 1;

	coin_2[15].X = 3160;
	coin_2[15].Y = 90;
	coin_2[15].flag = 1;

	coin_2[16].X = 3180;
	coin_2[16].Y = 90;
	coin_2[16].flag = 1;

	coin_2[17].X = 3480;
	coin_2[17].Y = 80;
	coin_2[17].flag = 1;

	coin_2[18].X = 3480;
	coin_2[18].Y = 90;
	coin_2[18].flag = 1;

	coin_2[19].X = 3500;
	coin_2[19].Y = 80;
	coin_2[19].flag = 1;

	coin_2[20].X = 3500;
	coin_2[20].Y = 90;
	coin_2[20].flag = 1;

	coin_2[21].X = 3520;
	coin_2[21].Y = 80;
	coin_2[21].flag = 1;

	coin_2[22].X = 2680;
	coin_2[22].Y = 90;
	coin_2[22].flag = 1;

	coin_2[23].X = 2700;
	coin_2[23].Y = 90;
	coin_2[23].flag = 1;

	coin_2[24].X = 2720;
	coin_2[24].Y = 90;
	coin_2[24].flag = 1;

	coin_2[25].X = 260;
	coin_2[25].Y = 60;
	coin_2[25].flag = 1;

	coin_2[26].X = 280;
	coin_2[26].Y = 60;
	coin_2[26].flag = 1;

	Thorn_2[0].X = 240;
	Thorn_2[0].Y = 70;
	Thorn_2[0].flag = 1;

	Thorn_2[1].X = 260;
	Thorn_2[1].Y = 60;
	Thorn_2[1].flag = 0;

	Thorn_2[2].X = 280;
	Thorn_2[2].Y = 60;
	Thorn_2[2].flag = 0;

	Thorn_2[3].X = 300;
	Thorn_2[3].Y = 70;
	Thorn_2[3].flag = 1;

	Spring_2[0].X = 2360;
	Spring_2[0].Y = 90;

	Spring_2[1].X = 2600;
	Spring_2[1].Y = 90;

	Spring_2[2].X = 3380;
	Spring_2[2].Y = 90;

	grass_2[0].X = 340;
	grass_2[0].Y = 90;

	grass_2[1].X = 1020;
	grass_2[1].Y = 90;

	grass_2[2].X = 1300;
	grass_2[2].Y = 90;

	grass_2[3].X = 2800;
	grass_2[3].Y = 90;

	grass_2[4].X = 1600;
	grass_2[4].Y = 90;

	head_block_2[0].X = 420;
	head_block_2[0].Y = 70;
	head_block_2[0].flag = 0;

	head_block_2[1].X = 440;
	head_block_2[1].Y = 70;
	head_block_2[1].flag = 0;

	head_block_2[2].X = 460;
	head_block_2[2].Y = 70;
	head_block_2[2].flag = 0;

	head_block_2[3].X = 1120;
	head_block_2[3].Y = 60;
	head_block_2[3].flag = 0;

	head_block_2[4].X = 1580;
	head_block_2[4].Y = 70;
	head_block_2[4].flag = 0;

	head_block_2[5].X = 1980;
	head_block_2[5].Y = 70;
	head_block_2[5].flag = 0;

	head_block_2[6].X = 2000;
	head_block_2[6].Y = 70;
	head_block_2[6].flag = 0;

	head_block_2[7].X = 2020;
	head_block_2[7].Y = 70;
	head_block_2[7].flag = 0;

	head_block_2[8].X = 2040;
	head_block_2[8].Y = 70;
	head_block_2[8].flag = 0;

	head_block_2[9].X = 2060;
	head_block_2[9].Y = 70;
	head_block_2[9].flag = 0;

	head_block_2[10].X = 2160;
	head_block_2[10].Y = 40;
	head_block_2[10].flag = 0;

	head_block_2[11].X = 2400;
	head_block_2[11].Y = 70;
	head_block_2[11].flag = 0;

	head_block_2[12].X = 2560;
	head_block_2[12].Y = 70;
	head_block_2[12].flag = 0;

	head_block_2[13].X = 3080;
	head_block_2[13].Y = 70;
	head_block_2[13].flag = 0;

	head_block_2[14].X = 3420;
	head_block_2[14].Y = 40;
	head_block_2[14].flag = 0;

	head_block_2[15].X = 840;
	head_block_2[15].Y = 50;
	head_block_2[15].flag = 0;

	head_block_2[16].X = 860;
	head_block_2[16].Y = 50;
	head_block_2[16].flag = 0;

	broken_block_2[0].X = 2620;
	broken_block_2[0].Y = 0;
	broken_block_2[0].flag = 1;

	broken_block_2[1].X = 2640;
	broken_block_2[1].Y = 0;
	broken_block_2[1].flag = 1;

	broken_block_2[2].X = 2660;
	broken_block_2[2].Y = 0;
	broken_block_2[2].flag = 1;

	broken_block_2[3].X = 2680;
	broken_block_2[3].Y = 0;
	broken_block_2[3].flag = 1;

	broken_block_2[4].X = 2700;
	broken_block_2[4].Y = 0;
	broken_block_2[4].flag = 1;

	broken_block_2[5].X = 2720;
	broken_block_2[5].Y = 0;
	broken_block_2[5].flag = 1;

	broken_block_2[6].X = 2740;
	broken_block_2[6].Y = 0;
	broken_block_2[6].flag = 1;

	broken_block_2[7].X = 2760;
	broken_block_2[7].Y = 0;
	broken_block_2[7].flag = 1;

	broken_block_2[8].X = 2780;
	broken_block_2[8].Y = 0;
	broken_block_2[8].flag = 1;

	broken_block_2[9].X = 2620;
	broken_block_2[9].Y = 10;
	broken_block_2[9].flag = 1;

	broken_block_2[10].X = 2640;
	broken_block_2[10].Y = 10;
	broken_block_2[10].flag = 1;

	broken_block_2[11].X = 2660;
	broken_block_2[11].Y = 10;
	broken_block_2[11].flag = 1;

	broken_block_2[12].X = 2680;
	broken_block_2[12].Y = 10;
	broken_block_2[12].flag = 1;

	broken_block_2[13].X = 2700;
	broken_block_2[13].Y = 10;
	broken_block_2[13].flag = 1;

	broken_block_2[14].X = 2720;
	broken_block_2[14].Y = 10;
	broken_block_2[14].flag = 1;

	broken_block_2[15].X = 2740;
	broken_block_2[15].Y = 10;
	broken_block_2[15].flag = 1;

	broken_block_2[16].X = 2760;
	broken_block_2[16].Y = 10;
	broken_block_2[16].flag = 1;

	broken_block_2[17].X = 2780;
	broken_block_2[17].Y = 10;
	broken_block_2[17].flag = 1;

	broken_block_2_3x2[0].X = 80;
	broken_block_2_3x2[0].Y = 98;
	broken_block_2_3x2[0].flag = 1;

	broken_block_2_3x2[1].X = 2880;
	broken_block_2_3x2[1].Y = 98;
	broken_block_2_3x2[1].flag = 1;

	broken_block_2_3x2[2].X = 2480;
	broken_block_2_3x2[2].Y = 98;
	broken_block_2_3x2[2].flag = 1;

	broken_block_2_1x2[0].X = 460;
	broken_block_2_1x2[0].Y = 100;
	broken_block_2_1x2[0].flag = 1;

	broken_block_2_1x2[1].X = 3720;
	broken_block_2_1x2[1].Y = 100;
	broken_block_2_1x2[1].flag = 1;

	broken_block_2_1x2[2].X = 840;
	broken_block_2_1x2[2].Y = 100;
	broken_block_2_1x2[2].flag = 1;

	broken_block_2_2x2[0].X = 620;
	broken_block_2_2x2[0].Y = 100;
	broken_block_2_2x2[0].flag = 1;

	broken_block_2_2x2[1].X = 960;
	broken_block_2_2x2[1].Y = 100;
	broken_block_2_2x2[1].flag = 1;

	broken_block_2_2x2[2].X = 1540;
	broken_block_2_2x2[2].Y = 100;
	broken_block_2_2x2[2].flag = 1;

	broken_block_2_2x2[3].X = 2460;
	broken_block_2_2x2[3].Y = 100;
	broken_block_2_2x2[3].flag = 1;

	broken_block_2_2x2[4].X = 3220;
	broken_block_2_2x2[4].Y = 100;
	broken_block_2_2x2[4].flag = 1;

	broken_block_2_2x2[5].X = 3300;
	broken_block_2_2x2[5].Y = 100;
	broken_block_2_2x2[5].flag = 1;

	broken_block_2_2x2[6].X = 3480;
	broken_block_2_2x2[6].Y = 100;
	broken_block_2_2x2[6].flag = 1;

	broken_block_2_2x2[7].X = 2020;
	broken_block_2_2x2[7].Y = 100;
	broken_block_2_2x2[7].flag = 1;

	broken_block_2_2x2[8].X = 2680;
	broken_block_2_2x2[8].Y = 100;
	broken_block_2_2x2[8].flag = 1;

	step_down_block_2.X = 1820;
	step_down_block_2.Y = 60;

	monster_2[0].X = 440;
	monster_2[0].Y = 92;
	monster_2[0].mov = 1;
	monster_2[0].flag = 1;

	monster_2[1].X = 500;
	monster_2[1].Y = 92;
	monster_2[1].mov = 1;
	monster_2[1].flag = 1;

	monster_2[2].X = 1320;
	monster_2[2].Y = 22;
	monster_2[2].mov = -1;
	monster_2[2].flag = 1;

	monster_2[3].X = 1360;
	monster_2[3].Y = 22;
	monster_2[3].mov = -1;
	monster_2[3].flag = 1;

	monster_2[4].X = 1540;
	monster_2[4].Y = 92;
	monster_2[4].mov = -1;
	monster_2[4].flag = 1;

	monster_2[5].X = 1580;
	monster_2[5].Y = 92;
	monster_2[5].mov = -1;
	monster_2[5].flag = 1;

	monster_2[6].X = 2020;
	monster_2[6].Y = 92;
	monster_2[6].mov = 1;
	monster_2[6].flag = 1;

	monster_2[7].X = 2080;
	monster_2[7].Y = 92;
	monster_2[7].mov = -1;
	monster_2[7].flag = 1;

	monster_2[8].X = 2680;
	monster_2[8].Y = 42;
	monster_2[8].mov = -1;
	monster_2[8].flag = 1;

	monster_2[9].X = 2710;
	monster_2[9].Y = 42;
	monster_2[9].mov = -1;
	monster_2[9].flag = 1;

	monster_2[10].X = 2780;
	monster_2[10].Y = 42;
	monster_2[10].mov = -1;
	monster_2[11].flag = 1;

	monster_2[11].X = 3600;
	monster_2[11].Y = 0;
	monster_2[11].mov = -1;
	monster_2[11].flag = 0;

	monster_2[12].X = 3620;
	monster_2[12].Y = 0;
	monster_2[12].mov = -1;
	monster_2[12].flag = 0;

	monster_2[13].X = 3640;
	monster_2[13].Y = 0;
	monster_2[13].mov = -1;
	monster_2[13].flag = 0;

	monster_floower_2[0].X = 552;
	monster_floower_2[0].Y = 71;
	monster_floower_2[0].flag = 2;

	monster_floower_2[1].X = 3412;
	monster_floower_2[1].Y = 71;
	monster_floower_2[1].flag = 2;

	monster_pillar_2[0].X = 170;
	monster_pillar_2[0].Y = 71;
	monster_pillar_2[0].flag = 0;

	monster_pillar_2[1].X = 2130;
	monster_pillar_2[1].Y = 71;
	monster_pillar_2[1].flag = 0;

	monster_fly_2[0].X = 2960;
	monster_fly_2[0].Y = 70;
	monster_fly_2[0].flag = 1;

	monster_fly_2[1].X = 3020;
	monster_fly_2[1].Y = 85;
	monster_fly_2[1].flag = 1;

	cloud_2[0].X = 100;
	cloud_2[0].Y = 10;

	cloud_2[1].X = 300;
	cloud_2[1].Y = 20;

	cloud_2[2].X = 500;
	cloud_2[2].Y = 15;

	cloud_2[3].X = 700;
	cloud_2[3].Y = 10;

	cloud_2[4].X = 900;
	cloud_2[4].Y = 15;

	cloud_2[5].X = 1140;
	cloud_2[5].Y = 20;

	cloud_2[6].X = 1340;
	cloud_2[6].Y = 10;

	cloud_2[7].X = 1500;
	cloud_2[7].Y = 20;

	cloud_2[8].X = 1700;
	cloud_2[8].Y = 15;

	cloud_2[9].X = 1900;
	cloud_2[9].Y = 10;

	cloud_2[10].X = 2100;
	cloud_2[10].Y = 10;

	cloud_2[11].X = 2300;
	cloud_2[11].Y = 20;

	cloud_2[12].X = 2500;
	cloud_2[12].Y = 15;

	cloud_2[13].X = 2900;
	cloud_2[13].Y = 20;

	cloud_2[14].X = 3100;
	cloud_2[14].Y = 15;

	cloud_2[15].X = 3300;
	cloud_2[15].Y = 10;

	cloud_2[16].X = 3500;
	cloud_2[16].Y = 20;

	cloud_2[17].X = 3700;
	cloud_2[17].Y = 15;

	cloud_2[18].X = 3900;
	cloud_2[18].Y = 10;


	running = 1;

	// ���� ��� 
	PlaySound("MUSIC\\stage2.wav", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// color �迭 ����
void Stage2_Coloring() {
	int x, y, i;

	// �� �ֱ�
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0 + MapMovX; x < MapMovX + PRINT_FULL_WIDTH; x++) {
			color[y * PRINT_FULL_WIDTH + x - MapMovX] = full_map_2[y][x] | full_map_2[y][x] * 16;
		}
	}

	// üũ ����Ʈ
	for (i = 0; i < 3; i++) {
		if (!(check_point_2[i].X >= MapMovX - 20 && check_point_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (check_point_2[i].X + x - MapMovX < 0 || check_point_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (check_point_2[i].flag == 1)
					color[(check_point_2[i].Y + y) * PRINT_FULL_WIDTH + check_point_2[i].X + x - MapMovX] = block2_22[y][x] | block2_22[y][x] * 16;	// üũ����Ʈ
			}
		}
	}

	// ���� ��
	for (i = 0; i < 4; i++) {
		if (!(Thorn_2[i].X >= MapMovX - 20 && Thorn_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (Thorn_2[i].X + x - MapMovX < 0 || Thorn_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;
				// ���ú�
				if (Thorn_2[i].flag == 1)
					color[(Thorn_2[i].Y + y) * PRINT_FULL_WIDTH + Thorn_2[i].X + x - MapMovX] = block2_20[y][x] | block2_20[y][x] * 16; 	// ���ú�
			}
		}
	}

	// ����
	for (i = 0; i < 27; i++) {
		if (!(coin_2[i].X >= MapMovX - 20 && coin_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (coin_2[i].X + x - MapMovX < 0 || coin_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (coin_2[i].flag == 1)
					color[(coin_2[i].Y + y) * PRINT_FULL_WIDTH + coin_2[i].X + x - MapMovX] = block2_21[y][x] | block2_21[y][x] * 16;	// ����
				else if(coin_2[i].flag == 0 && (i == 25 || i == 26))
					color[(coin_2[i].Y + y) * PRINT_FULL_WIDTH + coin_2[i].X + x - MapMovX] = block2_20[y][x] | block2_20[y][x] * 16;	// ���ú�
			}
		}
	}

	// �ܵ�
	for (i = 0; i < 5; i++) {
		if (!(grass_2[i].X >= MapMovX - 20 && grass_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 3; x++) {
				if (grass_2[i].X + x - MapMovX < 0 || grass_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				color[(grass_2[i].Y + y) * PRINT_FULL_WIDTH + grass_2[i].X + x - MapMovX] = block2_28[y][x] | block2_28[y][x] * 16;		// �ܵ�
			}
		}
	}

	// �Ӹ� �ε�ġ�� ����� ��
	for (i = 0; i < 17; i++) {
		if (!(head_block_2[i].X >= MapMovX - 20 && head_block_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (head_block_2[i].X + x - MapMovX < 0 || head_block_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;


				if (head_block_2[i].flag == 1)
					full_map_2[y + head_block_2[i].Y][x + head_block_2[i].X] = block2_4[y][x];		// ���
				else
					color[(head_block_2[i].Y + y) * PRINT_FULL_WIDTH + head_block_2[i].X + x - MapMovX] = block2_0[y][x] | block2_0[y][x] * 16;	// ���
			}
		}
	}

	// �Ӹ� �ε�ġ�� �μ����� ��
	for (i = 0; i < 18; i++) {
		if (!(broken_block_2[i].X >= MapMovX - 20 && broken_block_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (broken_block_2[i].X + x - MapMovX < 0 || broken_block_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_2[i].flag == 1)
					color[(broken_block_2[i].Y + y) * PRINT_FULL_WIDTH + broken_block_2[i].X + x - MapMovX] = block2_2[y][x] | block2_2[y][x] * 16;	// �⺻��
			}
		}
	}

	// ������ �������� ��(3x2)
	for (i = 0; i < 3; i++) {
		if (!(broken_block_2_3x2[i].X >= MapMovX - 20 && broken_block_2_3x2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 2 + 2; y++) {
			for (x = 0; x < BLACK_WIDTH * 3; x++) {
				if (broken_block_2_3x2[i].X + x - MapMovX < 0 || broken_block_2_3x2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (mario.X > broken_block_2_3x2[i].X && mario.X < broken_block_2_3x2[i].X + 49 && mario.Y == broken_block_2_3x2[i].Y - 5)
					full_map_2[y + broken_block_2_3x2[i].Y][x + broken_block_2_3x2[i].X] = block2_25[y][x];		// ���
				else
					full_map_2[y + broken_block_2_3x2[i].Y][x + broken_block_2_3x2[i].X] = block2_34[y][x];		// �������� ��
			}
		}
	}

	// ������ �μ����� ��(1x2)
	for (i = 0; i < 3; i++) {
		if (!(broken_block_2_1x2[i].X >= MapMovX - 20 && broken_block_2_1x2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 2; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (broken_block_2_1x2[i].X + x - MapMovX < 0 || broken_block_2_1x2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_2_1x2[i].flag == 0)
					full_map_2[y + broken_block_2_1x2[i].Y][x + broken_block_2_1x2[i].X] = block2_26[y][x];		// ���
			}
		}
	}

	// ������ �μ����� ��(2x2)
	for (i = 0; i < 9; i++) {
		if (!(broken_block_2_2x2[i].X >= MapMovX - 20 && broken_block_2_2x2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT * 2; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (broken_block_2_2x2[i].X + x - MapMovX < 0 || broken_block_2_2x2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (broken_block_2_2x2[i].flag == 0)
					full_map_2[y + broken_block_2_2x2[i].Y][x + broken_block_2_2x2[i].X] = block2_27[y][x];		// ���
			}
		}
	}

	// ������ �������� �� (���� ��)
	for (int i = 0; i < 1; i++){
		if (!(step_down_block_2.X >= MapMovX - 20 && step_down_block_2.X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH * 2; x++) {
				if (mario.X > step_down_block_2.X - 12 && mario.X < step_down_block_2.X + 49 && mario.Y == step_down_block_2.Y - 7)
					full_map_2[y + step_down_block_2.Y][x + step_down_block_2.X] = block2_29[y][x];		// ���
				else
					full_map_2[y + step_down_block_2.Y][x + step_down_block_2.X] = block2_18[y][x];		// �������� ��
			}
		}
	}

	// ����
	for (int i = 0; i < 19; i++) {
		if (!(cloud_2[i].X >= MapMovX - 16 && cloud_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 12; y++) {
			for (x = 0; x < 32; x++) {
				if (cloud_2[i].X + x - MapMovX < 0 || cloud_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				color[(cloud_2[i].Y + y) * PRINT_FULL_WIDTH + cloud_2[i].X + x - MapMovX] = block2_32[y][x] | block2_33[y][x] * 16;	// ����
			}
		}
	}

	// ����(����)
	for (int i = 0; i < 14; i++) {
		if (!(monster_2[i].X >= MapMovX - 16 && monster_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 8; y++) {
			for (x = 0; x < 16; x++) {
				if (monster_2[i].X + x - MapMovX < 0 || monster_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_2[i].flag == 1)
					color[(monster_2[i].Y + y) * PRINT_FULL_WIDTH + monster_2[i].X + x - MapMovX] = block2_30[y][x] | block2_31[y][x] * 16;	// ����(����)
			}
		}
	}

	// ����(���β�)
	for (int i = 0; i < 2; i++) {
		if (!(monster_floower_2[i].X >= MapMovX - 16 && monster_floower_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 10; y++) {
			for (x = 0; x < 16; x++) {
				if (monster_floower_2[i].X + x - MapMovX < 0 || monster_floower_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				// ����(���β� �� ������)
				if (monster_floower_2[i].flag == 1)
					color[(monster_floower_2[i].Y + y) * PRINT_FULL_WIDTH + monster_floower_2[i].X + x - MapMovX] = (block2_35[y][x] != 16 ? block2_35[y][x] : full_map_2[y + monster_floower_2[i].Y][x + monster_floower_2[i].X]) | (block2_35[y][x] != 16 ? block2_35[y][x] : full_map_2[y + monster_floower_2[i].Y][x + monster_floower_2[i].X]) * 16;
				// ����(���β� �� �ٹ���)
				else if (monster_floower_2[i].flag == 0)
					color[(monster_floower_2[i].Y + y) * PRINT_FULL_WIDTH + monster_floower_2[i].X + x - MapMovX] = (block2_36[y][x] != 16 ? block2_36[y][x] : full_map_2[y + monster_floower_2[i].Y][x + monster_floower_2[i].X]) | (block2_36[y][x] != 16 ? block2_36[y][x] : full_map_2[y + monster_floower_2[i].Y][x + monster_floower_2[i].X]) * 16;
			}
		}
	}

	// ����(���)
	for (int i = 0; i < 2; i++) {
		if (!(monster_pillar_2[i].X >= MapMovX - 16 && monster_pillar_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < 12; y++) {
			for (x = 0; x < 20; x++) {
				if (monster_pillar_2[i].X + x - MapMovX < 0 || monster_pillar_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;
				
				if (monster_pillar_2[i].flag == 1)
					color[(monster_pillar_2[i].Y + y) * PRINT_FULL_WIDTH + monster_pillar_2[i].X + x - MapMovX] = (block2_37[y][x] != 16 ? block2_37[y][x] : full_map_2[y + monster_pillar_2[i].Y][x + monster_pillar_2[i].X]) | (block2_37[y][x] != 16 ? block2_37[y][x] : full_map_2[y + monster_pillar_2[i].Y][x + monster_pillar_2[i].X]) * 16; 
			}
		}
	}

	// ����(����)
	for (i = 0; i < 2; i++) {
		if (!(monster_fly_2[i].X >= MapMovX - 20 && monster_fly_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
			continue;

		for (y = 0; y < BLACK_HEIGHT; y++) {
			for (x = 0; x < BLACK_WIDTH; x++) {
				if (monster_fly_2[i].X + x - MapMovX < 0 || monster_fly_2[i].X + x - MapMovX >= PRINT_FULL_WIDTH)
					continue;

				if (monster_fly_2[i].flag == 1)
					color[(monster_fly_2[i].Y + y) * PRINT_FULL_WIDTH + monster_fly_2[i].X + x - MapMovX] = (block2_24[y][x] != 0 ? block2_24[y][x] : full_map_2[y + monster_fly_2[i].Y][x + monster_fly_2[i].X]) | (block2_24[y][x] != 0 ? block2_24[y][x] : full_map_2[y + monster_fly_2[i].Y][x + monster_fly_2[i].X]) * 16;
			}
		}
	}

	// ������ �ֱ�
	for (y = 0; y < 16; y += 2) {
		for (x = 0; x < 12; x++) {
			
			// ������ ���� ���� ��� X
			if (x + mario.X >= 3799)
				continue;
			
			// ������
			if (running == 0)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_death_Location[y][x] != 16 ? E_death_Location[y][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) | (E_death_Location[y + 1][x] != 16 ? E_death_Location[y + 1][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) * 16;
			// ����
			else if (jump_check > -7)
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_jump_Location[y][x] != 16 ? E_jump_Location[y][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) | (E_jump_Location[y + 1][x] != 16 ? E_jump_Location[y + 1][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) * 16;
			// �⺻
			else
				color[(y / 2 + mario.Y) * PRINT_FULL_WIDTH + x + mario.X - MapMovX] = (E_Location[y][x] != 16 ? E_Location[y][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) | (E_Location[y + 1][x] != 16 ? E_Location[y + 1][x] : full_map_2[y / 2 + mario.Y][x + mario.X]) * 16;
		}
	}
}

// �� üũ
void Stage2_block_check() {
	int i;

	// üũ����Ʈ
	for (i = 0; i < 3; i++) {
		if (check_point_2[i].flag && mario.X >= check_point_2[i].X - 2 && mario.X <= check_point_2[i].X + 16 && mario.Y <= check_point_2[i].Y + 12 && mario.Y >= check_point_2[i].Y - 10)
			check_point_2[i].flag = 0;

		if (mario.X >= check_point_2[i].X - 6 && mario.X <= check_point_2[i].X + 20 && mario.Y <= check_point_2[i].Y + 12 && mario.Y >= check_point_2[i].Y - 10)
			checkpoint = i + 1;
	}

	// ����
	for (i = 0; i < 27; i++) {
		if (coin_2[i].flag == 1 && mario.X >= coin_2[i].X - 8 && mario.X <= coin_2[i].X + 18 && mario.Y <= coin_2[i].Y + 12 && mario.Y >= coin_2[i].Y - 10) {
			// ���� ���
			if (play_sound_selection) {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound, 0, (int)3);
			}
			else {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound_, 0, (int)3);
			}
			coin_2[i].flag = 0;
		}
	}
	
	// ���� ��
	for (i = 0; i < 4; i++) {
		// ���� ������ ���ӿ���
		if (Thorn_2[i].flag == 1 && mario.X > Thorn_2[i].X - 8 && mario.X < Thorn_2[i].X + 14 && mario.Y <= Thorn_2[i].Y + 9 && mario.Y >= Thorn_2[i].Y - 9) {
			GameOver();
			Stage2_check_point();
		}
	}


	// �ܵ� ��
	for (i = 0; i < 5; i++) {
		// �״� �ܵ� ������ ���ӿ���
		if (i == 2){
			if (mario.X > grass_2[i].X && mario.X - 4 < grass_2[i].X + 48 && mario.Y <= grass_2[i].Y + 12 && mario.Y >= grass_2[i].Y - 4) {
				GameOver();
				Stage2_check_point();
			}
		}
	}

	// ���� ��
	for (i = 0; i < 19; i++) {
		// ��¥ ���� ������ ���ӿ���
		if (i == 1 || i == 5 || i == 11) {
			if (mario.X > cloud_2[i].X - 12 && mario.X < cloud_2[i].X + 32 && mario.Y <= cloud_2[i].Y + 14 && mario.Y >= cloud_2[i].Y - 8) {
				GameOver();
				Stage2_check_point();
			}
		}
	}
	
	// �Ӹ� �ε�ġ�� ����� ��
	for (i = 0; i < 17; i++) {
		if (head_block_2[i].flag == 0 && mario.X > head_block_2[i].X - 10 && mario.X < head_block_2[i].X + 20 && mario.Y == head_block_2[i].Y + 12) {
			head_block_2[i].flag = 1;
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

	// �Ӹ� �ε�ġ�� �������� ��
	for (i = 0; i < 18; i++) {
		if (broken_block_2[i].flag == 1 && mario.X > broken_block_2[i].X - 10 && mario.X < broken_block_2[i].X + 20 && mario.Y > broken_block_2[i].Y - 8 && mario.Y < broken_block_2[i].Y + 12)
			broken_block_2[i].flag = 0;
	}

	// ������ �μ����� �� (1X2)
	for (i = 0; i < 3; i++) {
		if (broken_block_2_1x2[i].flag == 1 && mario.X > broken_block_2_1x2[i].X - 4 && mario.X < broken_block_2_1x2[i].X + 12 && mario.Y == broken_block_2_1x2[i].Y - 8)
			broken_block_2_1x2[i].flag = 0;
	}

	// ������ �μ����� �� (2X2)
	for (i = 0; i < 9; i++) {
		if (broken_block_2_2x2[i].flag == 1 && mario.X > broken_block_2_2x2[i].X - 4 && mario.X < broken_block_2_2x2[i].X + 32 && mario.Y == broken_block_2_2x2[i].Y - 8)
			broken_block_2_2x2[i].flag = 0;
	}
}

// �����̴� ��
void Stage2_move_thread(void* args) {
	int l = 0, k = 0, i = 0, m = 0, x, y, mo_check = 0;
	while (1)
	{
		if (clock() - l < 20) {
			Sleep(1);
			continue;
		}

		l = clock();

		// �������� ����� ������ ����
		if (stage != 2) 
			break;
		

		// ������
		for (i = 0; i < 3; i++) {
			if (mario.X > Spring_2[i].X - 10 && mario.X < Spring_2[i].X + 18 && mario.Y == Spring_2[i].Y - 7) {
				mciSendString("play spring.wav", NULL, 0, NULL);
				spring_check = 1;
				while (1) {
					if (clock() - k < 10) {
						Sleep(1);
						continue;
					}
					// ������ Y���� 0 �����϶����� 
					if (mario.Y <= 3) {
						spring_check = 0;
						break;
					}

					k = clock();
					mario.Y -= 5;
				}
			}
		}

		// ������ �������� �� (���� ��)
		if (mario.X > step_down_block_2.X - 10 && mario.X < step_down_block_2.X + 49 && mario.Y == step_down_block_2.Y - 6) {
			while (1) {
				if (clock() - k < 10) {
					Sleep(1);
					continue;
				}
				// ���� Y���� PRINT_FULL_HEIGHT������ 
				if (step_down_block_2.Y > PRINT_FULL_HEIGHT)
					break;

				k = clock();
				step_down_block_2.Y += 2;
			}
		}

		// ������ �������� �� (3X2)
		for (i = 0; i < 3; i++) {
			if (broken_block_2_3x2[i].flag == 1 && mario.X > broken_block_2_3x2[i].X && mario.X < broken_block_2_3x2[i].X + 49 && mario.Y == broken_block_2_3x2[i].Y - 6)
				while (1) {
					if (clock() - k < 25) {
						Sleep(1);
						continue;
					}
					// ���� Y���� PRINT_FULL_HEIGHT������ 
					if (broken_block_2_3x2[i].Y > PRINT_FULL_HEIGHT)
						break;

					k = clock();
					broken_block_2_3x2[i].Y += 2;
				}
		}

		// ����(���)
		for (i = 0; i < 2; i++) {
			if (mario.X > monster_pillar_2[i].X - 20 && mario.X < monster_pillar_2[i].X + 28 && mario.Y < monster_pillar_2[i].Y - 14) {
				monster_pillar_2[i].flag = 1;
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
					if (clock() - k < 20) {
						Sleep(1);
						continue;
					}

					// ���� Y���� 0 �����϶����� 
					if (monster_pillar_2[i].Y <= 1) {
						monster_pillar_2[i].flag = 0;
						break;
					}

					k = clock();
					monster_pillar_2[i].Y -= 3;
				}
			}
		}

		// ����(���β�)
		for (i = 0; i < 2; i++) {
			if (mario.X > monster_floower_2[i].X - 20 && mario.X < monster_floower_2[i].X + 28 && mario.Y == monster_floower_2[i].Y - 9) {
				monster_floower_2[i].flag = 1;
				// ���� ���
				if (play_sound_selection) {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound, 0, (int)5);
				}
				else {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound_, 0, (int)5);
				}
				while (1) {
					if (clock() - k < 30) {
						Sleep(1);
						continue;
					}

					// ���Դٰ� �ٽ� ����
					if (monster_floower_2[i].Y < 61)
						monster_floower_2[i].flag = 0;
					else if (monster_floower_2[i].flag == 1)
						monster_floower_2[i].Y -= 1;


					if (monster_floower_2[i].Y > 71 && monster_floower_2[i].flag == 0) {
						monster_floower_2[i].flag = 2;
						break;
					}
					else if (monster_floower_2[i].flag == 0)
						monster_floower_2[i].Y += 1;
					k = clock();
				}
			}
		}

		// ����(����)
		for (i = 0; i < 2; i++) {
			if (!(monster_fly_2[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_fly_2[i].X <= PRINT_FULL_WIDTH + MapMovX))
				continue;

			// ���� Y���� ������ 
			if (monster_fly_2[i].X <= MapMovX - 20 || death(0, 0) == 1) {
				monster_fly_2[i].flag = 0;
				monster_fly_2[i].X = -200;
				monster_fly_2[i].Y = -200;
			}
			monster_fly_2[i].X -= 2;
		}


		// ����(����) 
		for (i = 0; i < 14; i++) {
			if (i == 11 && !(monster_2[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_2[i].X <= PRINT_FULL_WIDTH + MapMovX - 50))
				continue;
			else if ((i == 11 || i == 12 || i == 13) && !(monster_2[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_2[i].X <= PRINT_FULL_WIDTH + MapMovX - 30))
				continue;
			else if (!(monster_2[i].X >= MapMovX - PRINT_FULL_WIDTH && monster_2[i].X <= PRINT_FULL_WIDTH + MapMovX + 16))
				continue;

			monster_2[i].flag = 1;

			// �� �ΰ����� ���� ���� ������ �Դٰ���
			for (y = 0; y < 8; y++) {
				for (x = 0; x < 16; x++) {
					if (full_map_2[y + monster_2[i].Y][x + monster_2[i].X + monster_2[i].mov] != 9) {
						monster_2[i].mov = (monster_2[i].mov < 0 ? 1 : -1);
						x = 16;
						y = 8;
						mo_check = !mo_check;
					}
				}
			}

			if (mo_check) {
				mo_check = !mo_check;
				i--;
				continue;
			}

			monster_2[i].X += monster_2[i].mov;


			// �� �ƴϸ� ������ ��������
			for (y = 0; y < 8; y++) {
				for (x = 0; x < 16; x++) {
					if (full_map_2[y + monster_2[i].Y + 1][x + monster_2[i].X] != 9) {
						x = 16;
						y = 8;
						mo_check = !mo_check;
					}
				}
			}

			if (mo_check) {
				mo_check = !mo_check;
				continue;
			}
			monster_2[i].Y += 2;
		}

		for (i = 0; i < 14; i++) {
			if (!(monster_2[i].X >= MapMovX - 16 && monster_2[i].X <= PRINT_FULL_WIDTH + MapMovX - 128))
				continue;
			//�������� ���� ������
			if (mario.X >= monster_2[i].X - 15 && mario.X < monster_2[i].X + 16 && mario.Y == monster_2[i].Y - 8) {
				// ���� ���
				if (play_sound_selection) {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound, 0, (int)2);
				}
				else {
					play_sound_selection = !play_sound_selection;
					_beginthread(play_sound_, 0, (int)2);
				}
				monster_2[i].X = -200;
				monster_2[i].Y = -200;
				jump_check = (jump_check < 0 ? jump_check + 19 : jump_check);
			}
			// ����(����) ���� ������ ����
			if (monster_2[i].Y > PRINT_FULL_HEIGHT - 10) {
				monster_2[i].X = -200;
				monster_2[i].Y = -200;
			}
		}

		// ����(����) ������
		if (clock() - m > 500) {
			for (y = 0; y < 8; y++) {
				for (x = 0; x < 16; x++) {
					tmp_high[y][x] = block2_30[y][x];
					tmp_low[y][x] = block2_31[y][x];
				}
			}
			for (y = 0; y < 8; y++) {
				for (x = 0; x < 16; x++) {
					block2_30[y][x] = tmp_high[y][15 - x];
					block2_31[y][x] = tmp_low[y][15 - x];
				}
			}
			m = clock();
		}
	}
}

// üũ����Ʈ
void Stage2_check_point() {
	// üũ����Ʈ�� ���鼭 ��������2 ����
	Stage2_setup();
	switch (checkpoint) {
	case 0:
		MapMovX = 0;
		mario.X = 0;
		mario.Y = 90;
		break;
	case 1:
		MapMovX = 580;
		mario.X = 660;
		mario.Y = 90;
		break;
	case 2:
		MapMovX = 1540;
		mario.X = 1620;
		mario.Y = 40;
		break;
	case 3:
		MapMovX = 3140;
		mario.X = 3200;
		mario.Y = 90;
		break;
	case 4:
		MapMovX = 3580;
		mario.X = 3680;
		mario.Y = 90;
		break;

	}
}

// Ű����
void Stage2_Input(void* arg) {
	int i = 0;
	while (1) {
		// �ð� �Լ� ����Ͽ��� �ӵ� ����
		if (clock() - i < 22)
			continue;
		i = clock();

		// �������� ����� ������ ����
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000 || stage != 2) 
			break;
		

		if ((GetAsyncKeyState('W') & 0x8000) && CanIJump() && jump_check == -7) {
			jump_check = 22;
			if (play_sound_selection) {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound, 0, (int)1);
			}
			else {
				play_sound_selection = !play_sound_selection;
				_beginthread(play_sound_, 0, (int)1);
			}
		}

		if (GetAsyncKeyState('A') & 0x8000) {
			Mov_Safe(-2, 0);
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
