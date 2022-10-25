#pragma warning (disable : 4996)
#include "map.h"
#include "function.h"

int full_map_1[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_1];
int full_map_2[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_2];
int full_map_3[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_3];

/* --------����--------- */
int MapMovX = 0;		// �� x��
int stage = 0;			// �������� 
int running = 1;		// ������ Ȯ��
int end = 1;			// ���� ���� Ȯ��
int checkpoint = 0;		// üũ����Ʈ
int jump_check = -7;	// ���� Ȯ��
int spring_check = 0;	// ������ üũ
int play_sound_selection = 0;	// ���� üũ

extern int menu;			// ���� ���� �ʱⰪ


// ĳ����(�⺻)
char E_Location[16][12] = {
	16, 16, 15, 16, 16, 16, 16, 15, 16, 16, 16, 16,
	16, 15, 4, 15, 16, 16, 15, 4, 15, 16, 16, 16,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	15, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 16,
	15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 16,
	15, 15, 15, 15, 0, 4, 4, 0, 15, 15, 15, 16,
	16, 15, 15, 15, 15, 4, 4, 15, 15, 15, 16, 16,
	16, 16, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16,
	15, 15, 16, 15, 15, 15, 15, 15, 16, 15, 15, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 15, 15, 15, 16, 15, 15, 15, 16, 16, 16,
	16, 16, 15, 15, 16, 16, 16, 15, 15, 16, 16, 16
};
// ĳ����(����)
char E_jump_Location[16][12] = {
	16, 16, 15, 16, 16, 16, 16, 15, 16, 16, 16, 16,
	16, 15, 4, 15, 16, 16, 15, 4, 15, 16, 16, 16,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	15, 15, 0, 15, 15, 15, 15, 15, 0, 15, 15, 16,
	15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 16,
	15, 15, 15, 15, 0, 4, 4, 0, 15, 15, 15, 16,
	16, 15, 15, 15, 15, 4, 4, 15, 15, 15, 16, 16,
	15, 16, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16,
	15, 15, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	16, 16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 15, 15, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 15, 15, 15, 16, 15, 15, 15, 16, 16, 16,
	16, 16, 15, 15, 16, 16, 16, 15, 15, 16, 16, 16
};
// ĳ����(����)
char E_death_Location[16][12] = {
	16, 16, 15, 16, 16, 16, 16, 15, 16, 16, 16, 16,
	16, 15, 4, 15, 16, 16, 15, 4, 15, 16, 16, 16,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	15, 15, 0, 0, 15, 15, 15, 0, 0, 15, 15, 16,
	15, 15, 15, 15, 15, 0, 0, 15, 15, 15, 15, 16,
	15, 15, 15, 15, 0, 4, 4, 0, 15, 15, 15, 16,
	16, 15, 15, 15, 15, 4, 4, 15, 15, 15, 16, 16,
	15, 16, 15, 15, 15, 15, 15, 15, 15, 16, 16, 15,
	15, 15, 16, 15, 15, 15, 15, 15, 16, 16, 15, 15,
	16, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16,
	16, 16, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 16, 15, 15, 15, 15, 15, 16, 16, 16, 16,
	16, 16, 15, 15, 15, 16, 15, 15, 15, 16, 16, 16,
	16, 16, 15, 15, 16, 16, 16, 15, 15, 16, 16, 16
};



/* --------���� ����ü--------- */
struct Pos mario;
extern struct Pos down_block_1_1x2[2], down_block_1_1x3[2], down_block_1_1x4[3], monster_fish_1[11], monster_squid_1[11], monster_shark_1[2], monster_shark_2_1[3];		// ��������1 ������ �ִ� ����ü
extern struct Pos monster_2[14], monster_floower_2[2], monster_pillar_2[2], monster_fly_2[2];	// ��������2 ������ �ִ� ����ü
extern struct Pos long_block_3, monster_3[2], monster_fly_3[4], monster_jump_3;					// ��������3 ������ �ִ� ����ü
int main() {
	int pressedKey;
	start_setup();	// ���� ����
	do{
		mciSendString("play MUSIC\\BGM.mp3", NULL, 0, NULL);	// �������
		menu = 0;
		stage = 0;
		checkpoint = 0;
		while (1){
			menu_setup();		// �޴� ����
			menu_Coloring();	// �޴� color �迭 ����
			Write();
			MenuSelect();		// �޴� üũ

			// Ű���� �Է��� �����Ǹ�
			if (kbhit()) {
				pressedKey = getch(); // �ƽ�Ű �ڵ� ���� ��������
				switch (pressedKey) { // �Է¹��� Ű�� �ش��ϴ� ������ �����Ѵ�.
				case 119:	menu--;	break;// W
				case 115:	menu++; break;// S
				case 13:	// ���Ͱ�
					mciSendString("stop MUSIC\\BGM.mp3", NULL, 0, NULL);
					mciSendString("play MUSIC\\Enter.wav", NULL, 0, NULL);
					if (menu == 0)	stage = 3;
					if (menu == 1)	stage = 1;
					if (menu == 2)	stage = 2;
					if (menu == 3)	stage = 4;
					Sleep(1000);
					break;
				}
				if (pressedKey == 13)	break;
			}
		}

		// �ʱ� ������ ��ġ ����
		MapMovX = 0;
		mario.X = 0;
		mario.Y = 93;

		// �������� ����
		switch (stage) {
		case 1:	start_game(1);	break;
		case 2:	start_game(2);	break;
		case 3:	start_game(3);	break;
		default:	break;
		}

		PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
		mciSendString("stop MUSIC\\stage3.mp3", NULL, 0, NULL);
		mciSendString("stop MUSIC\\gameover.mp3", NULL, 0, NULL);
		mciSendString("stop MUSIC\\complete.wav", NULL, 0, NULL);

		if (end == 0)
			return 0;
	} while (1);
}

void start_game(int stage) {
	switch (stage) {
	case 1:
		_beginthread(Stage1_Input, 0, (void*)0);		// Ű���� ��
		_beginthread(Stage1_move_thread, 0, (void*)0);
		Stage1_check_point();
		while (1) {
			Stage1_Coloring();
			Write();

			// �� ������ ���� ����
			if (mario.X >= 3700) {
				Sleep(5000);
				break;
			}

			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}
		}
		break;
	case 2:
		_beginthread(Stage2_Input, 0, (void*)0);
		_beginthread(Stage2_move_thread, 0, (void*)0);
		Stage2_check_point();
		while (1) {
			Stage2_Coloring();
			Write();

			// �� ������ ���� ����
			if (mario.X >= 3799) {
				Sleep(5000);
				break;
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}
		}
		break;

	case 3:
		_beginthread(Stage3_Input, 0, (void*)0);
		_beginthread(Stage3_move_thread, 0, (void*)0);
		Stage3_check_point();
		while (1) {
			Stage3_Coloring();
			Write();

			// �� ������ ���� ����
			if (stage == 3 && mario.X >= 5240) {
				Sleep(5000);
				break;
			}
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				mciSendString("stop MUSIC\\stage3.mp3", NULL, 0, NULL);
				break;
			}
		}
	default:	break;
	}
}

// ������ ����
void start_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;
	printf("���ǻ��� : �ܼ� �۾� ����� 8��Ʈ�� �������ּ���. �� ���α׷��� 1920*1080 100������ ����ȭ �Ǿ��ֽ��ϴ�.");
	getch();
	// �����ڵ� ����� ����
	_setmode(_fileno(stdout), _O_U16TEXT);
	// �ܼ� â ũ�� ����
	system("mode con cols=320 lines=120");

	// �����ڵ� ���� ����
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0; x < PRINT_FULL_WIDTH; x++)
			wprintf(L"\u2580");
		wprintf(L"\n");
	}
}

// �����ڵ忡 ���� ������
void Write() {
	COORD coord = { 0, 0 };
	DWORD written[PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH];
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color, PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH, coord, written);
}

// ������ ������
int MovMorio(int valueX, int valueY) {
	int x, y;
	// �̻� üũ (�̻������� ����, return)
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 12; x++) {
			switch (stage) {

			case 1:
				Stage1_block_check();
				// ���� üũ
				if (death(valueX, valueY) == 1) {
					GameOver();
					Stage1_check_point();
				}
				// ���� ����
				if (mario.X > 3652 && end == 1) {
					end = 0;
					End();
				}

				// �� �����°� Ȯ��
				if (full_map_1[y + mario.Y - valueY][x + mario.X + valueX] != 1 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;

			case 2:
				Stage2_block_check();
				// ���� üũ
				if (death(valueX, valueY) == 1) {
					GameOver();
					Stage2_check_point();
				}

				// �������� ��߱��� ������
				if ((full_map_2[y + mario.Y][x + mario.X + 1] == 13 || full_map_2[y + mario.Y][x + mario.X - 1] == 13) && end == 1) {
					end = 0;
					End();
				}
				// ���� ����
				if (mario.X > 3760 &&end == 1) {
					end = 0;
					End();
				}

				// �� �����°� Ȯ��
				if (full_map_2[y + mario.Y - valueY][x + mario.X + valueX] != 9 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;

			case 3:
				Stage3_block_check();
				// ���� üũ
				if (death(valueX, valueY) == 1){
					GameOver();
					Stage3_check_point();
				}

				// �������� ��߱��� ������
				if ((full_map_3[y + mario.Y][x + mario.X + 1] == 13 || full_map_3[y + mario.Y][x + mario.X - 1] == 13) && end == 1) {
					end = 0;
					End();
				}

				// �� �����°� Ȯ��
				if (full_map_3[y + mario.Y - valueY][x + mario.X + valueX] != 0 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;
			}
		}
	}

	// ������ �̵�
	mario.Y -= valueY;
	mario.X += valueX;

	// ���̷ΰ� �� �߰��� ������ �� �̵�
	if (mario.X + 6 - PRINT_FULL_WIDTH / 2 > MapMovX)
		MapMovX = mario.X + 6 - (PRINT_FULL_WIDTH / 2);
	return 0;
}

int death(int valueX, int valueY) {
	int x, y, i = 0;
	// �̻� üũ (�̻������� ����, return)
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 12; x++) {
			switch (stage) {
			case 1:
				// ���ۿ� ������
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				
				// ����(�����) 
				for (i = 0; i < 11; i++) {
					if (mario.X + valueX >= monster_fish_1[i].X - 8 && mario.X + valueX < monster_fish_1[i].X + 15 && mario.Y - valueY > monster_fish_1[i].Y - 5 && mario.Y - valueY < monster_fish_1[i].Y + 12)
						return 1;
				}

				// ����(��¡��) 
				for (i = 0; i < 11; i++) {
					if (mario.X + valueX >= monster_squid_1[i].X - 5 && mario.X + valueX < monster_squid_1[i].X + 16 && mario.Y - valueY > monster_squid_1[i].Y - 6 && mario.Y - valueY < monster_squid_1[i].Y + 12)
						return 1;
				}
				
				// ����(���)
				for (i = 0; i < 2; i++) {
					if (monster_shark_1[i].flag == 1 && mario.X + valueX > monster_shark_1[i].X - 7 && mario.X + valueX < monster_shark_1[i].X + 20 && mario.Y - valueY > monster_shark_1[i].Y - 8 && mario.Y - valueY < monster_shark_1[i].Y + 22)
						return 1;
				}

				// ����(��� 2����)
				for (i = 0; i < 3; i++) {
					if (monster_shark_2_1[i].flag == 1 && mario.X + valueX > monster_shark_2_1[i].X - 7 && mario.X + valueX < monster_shark_2_1[i].X + 40 && mario.Y - valueY > monster_shark_2_1[i].Y - 8 && mario.Y - valueY < monster_shark_2_1[i].Y + 22)
						return 1;
				}

				
				// ��ȣ�� ������
				if (full_map_1[y + mario.Y - valueY][x + mario.X + valueX] == 6)
					return 1;
				

				// �������� ��(1x2)
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > down_block_1_1x2[i].X - 10 && mario.X + valueX < down_block_1_1x2[i].X + 38 && mario.Y - valueY > down_block_1_1x2[i].Y && mario.Y - valueY < down_block_1_1x2[i].Y + 10)
						return 1;
				}

				// �������� ��(1x3) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > down_block_1_1x3[i].X - 10 && mario.X + valueX < down_block_1_1x3[i].X + 58 && mario.Y - valueY > down_block_1_1x3[i].Y && mario.Y - valueY < down_block_1_1x3[i].Y + 10)
						return 1;
				}

				// �������� ��(1x4)
				for (i = 0; i < 3; i++) {
					if (mario.X + valueX > down_block_1_1x4[i].X - 10 && mario.X + valueX < down_block_1_1x4[i].X + 78 && mario.Y - valueY > down_block_1_1x4[i].Y && mario.Y - valueY < down_block_1_1x4[i].Y + 10)
						return 1;
				}
				break;	
				

			case 2:
				// ���ۿ� ������
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				// ������ ��� �ϴ� ���� �ð���
				if (y + mario.Y - valueY < 4 && spring_check == 1)
					return 1;
				
				// ����(����) 
				for (i = 0; i < 14; i++){
					if (mario.X + valueX >= monster_2[i].X - 14 && mario.X + valueX < monster_2[i].X + 15 && mario.Y - valueY > monster_2[i].Y - 5 && mario.Y - valueY < monster_2[i].Y + 7)
						return 1;
				}
				
				// ����(���) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX >= monster_pillar_2[i].X - 8 && mario.X + valueX < monster_pillar_2[i].X + 18 && mario.Y - valueY > monster_pillar_2[i].Y - 6 && mario.Y - valueY < monster_pillar_2[i].Y + 12)
						return 1;
				}

				// ����(����)
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > monster_fly_2[i].X - 12 && mario.X + valueX < monster_fly_2[i].X + 20 && mario.Y - valueY > monster_fly_2[i].Y - 8 && mario.Y - valueY < monster_fly_2[i].Y + 12)
						return 1;
				}

				// ����(���β�) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX >= monster_floower_2[i].X - 10 && mario.X + valueX < monster_floower_2[i].X + 16 && mario.Y - valueY > monster_floower_2[i].Y - 6 && mario.Y - valueY < monster_floower_2[i].Y + 8)
						return 1;
				}
				
				break;
				
			case 3:
				// ���ۿ� ������
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				// �ϴ� ���� �ð���
				if (y + mario.Y - valueY <= 0)
					return 1;
				
				// �������� �� ���� �ε�ĥ��
				if (mario.X + valueX > long_block_3.X - 12 && mario.X + valueX < long_block_3.X + 20 && mario.Y - valueY == long_block_3.Y + 121)
					return 1;
				// ����(�Ϲ�)
				for (i = 0; i < 2; i++){
					if (mario.X + valueX > monster_3[i].X - 12 && mario.X + valueX < monster_3[i].X + 20 && mario.Y - valueY > monster_3[i].Y - 8 && mario.Y - valueY < monster_3[i].Y + 12)
						return 1;
				}
				// ����(����)
				for (i = 0; i < 4; i++) {
					if (mario.X + valueX > monster_fly_3[i].X - 12 && mario.X + valueX < monster_fly_3[i].X + 20 && mario.Y - valueY > monster_fly_3[i].Y - 8 && mario.Y - valueY < monster_fly_3[i].Y + 12)
						return 1;
				}
				// ����(����)
				if (mario.X + valueX > monster_jump_3.X - 12 && mario.X + valueX < monster_jump_3.X + 20 && mario.Y - valueY > monster_jump_3.Y - 8 && mario.Y - valueY < monster_jump_3.Y + 12)
					return 1;
					
				break;
		
			}
		}
	}
	return 0;
}
// Mov ���� �� �����̴� ���� �ٿ��� �ٽ� �õ�
void Mov_Safe(int valueX, int valueY) {
	// Mov ����
	if (MovMorio(valueX, valueY) == 0)
		return;

	while (!(valueX == 0 && valueY == 0)) {
		if (!MovMorio((valueX > 0 ? --valueX : (valueX < 0 ? ++valueX : valueX)), (valueY > 0 ? --valueY : (valueY < 0 ? ++valueY : valueY))))
			break;
	}
	return;
}

// ���� ���� Ȯ��
int CanIJump() {
	if (MovMorio(0, -1))
		return 1;

	MovMorio(0, 1);
	return 0;
}


// ���� ����
void GameOver()
{
	int i, k = 0;
	running = 0;
	PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
	mciSendString("stop MUSIC\\stage3.mp3", NULL, 0, NULL);
	mciSendString("stop MUSIC\\complete.wav", NULL, 0, NULL);
	mciSendString("play MUSIC\\gameover.mp3", NULL, 0, NULL);
	
	for (i = 0; i < 10; i++) {
		while (clock() - k < 50) {
			Sleep(1);
			continue;
		}
		k = clock();
		mario.Y -= 1;
	}
	Sleep(50);
	k = 0;
	for (i = 0; i < 60; i++) {
		if (clock() - k < 50) {
			Sleep(1);
			continue;
		}
		k = clock();
		if (mario.Y > PRINT_FULL_HEIGHT - 5){
			break;
		}
		mario.Y += 2;
	}
	Sleep(3000);
	mciSendString("stop MUSIC\\gameover.mp3", NULL, 0, NULL);
	running = 1;
}

// ���� ��
void End() {
	int i = 0;
	PlaySound(NULL, NULL, SND_PURGE | SND_NOWAIT | SND_ASYNC);
	mciSendString("stop MUSIC\\stage3.mp3", NULL, 0, NULL);
	mciSendString("play MUSIC\\complete.wav", NULL, 0, NULL);

	while (1){
		if (clock() - i < 30)
			continue;
		
		i = clock();
		if (stage == 1 && full_map_2[mario.Y + 8][mario.X] != 1)
			break;

		if (stage == 2 && full_map_2[mario.Y + 8][mario.X] != 9)
			break;

		if (stage == 3 && full_map_3[mario.Y + 8][mario.X] != 0)
			break;

		mario.Y++;
	}


	while (1) {
		if (clock() - i < 30)
			continue;

		i = clock();
		if (death(0, 0) == 1) {
			end = 1;
			break;
		}

		if (mario.Y + 7 > PRINT_FULL_HEIGHT - 5) {
			end = 1;
			break;
		}

		if (stage == 1 && mario.X >= 3700)
			break;
		if (stage == 2 && mario.X >= 3799)
			break;
		if (stage == 3 && mario.X >= 5240)
			break;

		mario.X++;
		Mov_Safe(0, -2);
	}
}

// ��Ȱ�� �뷡 ����� ���� 2�� ����
void play_sound(int num) {
	if (num == 1)	// ����
		mciSendString("play MUSIC\\jump.wav", NULL, 0, NULL);
	else if (num == 2)	// ���� ������
		mciSendString("play MUSIC\\stomp.wav", NULL, 0, NULL);
	else if (num == 3)	// ����
		mciSendString("play MUSIC\\coin.wav", NULL, 0, NULL);
	else if (num == 4)	// �Ӹ� �ε�ġ�� ����� ��
		mciSendString("play MUSIC\\head_block.wav", NULL, 0, NULL);
	else if (num == 5)	// ���β�
		mciSendString("play MUSIC\\monster1.wav", NULL, 0, NULL);
	else if (num == 6)	// ��� ����
		mciSendString("play MUSIC\\monster2.wav", NULL, 0, NULL);
	else if (num == 7)	// ���
		mciSendString("play MUSIC\\monster3.wav", NULL, 0, NULL);
	else if (num == 8)	// ��������3
		mciSendString("play MUSIC\\stage3.mp3 repeat", NULL, 0, NULL);
}

void play_sound_(int num){
	if (num == 1)
		mciSendString("play MUSIC\\jump_.wav", NULL, 0, NULL);
	else if (num == 2)
		mciSendString("play MUSIC\\stomp_.wav", NULL, 0, NULL);
	else if (num == 3)
		mciSendString("play MUSIC\\coin_.wav", NULL, 0, NULL);
	else if (num == 4)
		mciSendString("play MUSIC\\head_block_.wav", NULL, 0, NULL);
	else if (num == 5)
		mciSendString("play MUSIC\\monster1_.wav", NULL, 0, NULL);
	else if (num == 6)
		mciSendString("play MUSIC\\monster2_.wav", NULL, 0, NULL);
	else if (num == 7)
		mciSendString("play MUSIC\\monster3_.wav", NULL, 0, NULL);
}
