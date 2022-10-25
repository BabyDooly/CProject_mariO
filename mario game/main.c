#pragma warning (disable : 4996)
#include "map.h"
#include "function.h"

int full_map_1[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_1];
int full_map_2[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_2];
int full_map_3[MAP_FULL_HEIGHT][MAP_FULL_WIDTH_3];

/* --------변수--------- */
int MapMovX = 0;		// 맵 x축
int stage = 0;			// 스테이지 
int running = 1;		// 죽은지 확인
int end = 1;			// 게임 종료 확인
int checkpoint = 0;		// 체크포인트
int jump_check = -7;	// 점프 확인
int spring_check = 0;	// 스프링 체크
int play_sound_selection = 0;	// 사운드 체크

extern int menu;			// 레벨 선택 초기값


// 캐릭터(기본)
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
// 캐릭터(점프)
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
// 캐릭터(데스)
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



/* --------데스 구조체--------- */
struct Pos mario;
extern struct Pos down_block_1_1x2[2], down_block_1_1x3[2], down_block_1_1x4[3], monster_fish_1[11], monster_squid_1[11], monster_shark_1[2], monster_shark_2_1[3];		// 스테이지1 죽을수 있는 구조체
extern struct Pos monster_2[14], monster_floower_2[2], monster_pillar_2[2], monster_fly_2[2];	// 스테이지2 죽을수 있는 구조체
extern struct Pos long_block_3, monster_3[2], monster_fly_3[4], monster_jump_3;					// 스테이지3 죽을수 있는 구조체
int main() {
	int pressedKey;
	start_setup();	// 게임 셋팅
	do{
		mciSendString("play MUSIC\\BGM.mp3", NULL, 0, NULL);	// 음악재생
		menu = 0;
		stage = 0;
		checkpoint = 0;
		while (1){
			menu_setup();		// 메뉴 셋팅
			menu_Coloring();	// 메뉴 color 배열 셋팅
			Write();
			MenuSelect();		// 메뉴 체크

			// 키보드 입력이 감지되면
			if (kbhit()) {
				pressedKey = getch(); // 아스키 코드 값을 가져오고
				switch (pressedKey) { // 입력받은 키에 해당하는 동작을 수행한다.
				case 119:	menu--;	break;// W
				case 115:	menu++; break;// S
				case 13:	// 엔터값
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

		// 초기 마리오 위치 지정
		MapMovX = 0;
		mario.X = 0;
		mario.Y = 93;

		// 스테이지 선택
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
		_beginthread(Stage1_Input, 0, (void*)0);		// 키보드 값
		_beginthread(Stage1_move_thread, 0, (void*)0);
		Stage1_check_point();
		while (1) {
			Stage1_Coloring();
			Write();

			// 맵 끝까지 가면 종료
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

			// 맵 끝까지 가면 종료
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

			// 맵 끝까지 가면 종료
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

// 실행전 셋팅
void start_setup() {
	int x, y, b_y = 0, b_x = 0;
	int input_x = 0;
	int input_y = 0;
	printf("유의사항 : 콘솔 글씨 사이즈를 8폰트로 설정해주세요. 이 프로그램은 1920*1080 100배율에 최적화 되어있습니다.");
	getch();
	// 유니코드 선출력 설정
	_setmode(_fileno(stdout), _O_U16TEXT);
	// 콘솔 창 크기 조절
	system("mode con cols=320 lines=120");

	// 유니코드 먼저 실행
	for (y = 0; y < PRINT_FULL_HEIGHT; y++) {
		for (x = 0; x < PRINT_FULL_WIDTH; x++)
			wprintf(L"\u2580");
		wprintf(L"\n");
	}
}

// 유니코드에 색깔 입히기
void Write() {
	COORD coord = { 0, 0 };
	DWORD written[PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH];
	WriteConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color, PRINT_FULL_HEIGHT * PRINT_FULL_WIDTH, coord, written);
}

// 마리오 움직임
int MovMorio(int valueX, int valueY) {
	int x, y;
	// 이상 체크 (이상있으면 종료, return)
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 12; x++) {
			switch (stage) {

			case 1:
				Stage1_block_check();
				// 데스 체크
				if (death(valueX, valueY) == 1) {
					GameOver();
					Stage1_check_point();
				}
				// 게임 종료
				if (mario.X > 3652 && end == 1) {
					end = 0;
					End();
				}

				// 맵 나가는거 확인
				if (full_map_1[y + mario.Y - valueY][x + mario.X + valueX] != 1 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;

			case 2:
				Stage2_block_check();
				// 데스 체크
				if (death(valueX, valueY) == 1) {
					GameOver();
					Stage2_check_point();
				}

				// 마리오가 깃발까지 갔을때
				if ((full_map_2[y + mario.Y][x + mario.X + 1] == 13 || full_map_2[y + mario.Y][x + mario.X - 1] == 13) && end == 1) {
					end = 0;
					End();
				}
				// 게임 종료
				if (mario.X > 3760 &&end == 1) {
					end = 0;
					End();
				}

				// 맵 나가는거 확인
				if (full_map_2[y + mario.Y - valueY][x + mario.X + valueX] != 9 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;

			case 3:
				Stage3_block_check();
				// 데스 체크
				if (death(valueX, valueY) == 1){
					GameOver();
					Stage3_check_point();
				}

				// 마리오가 깃발까지 갔을때
				if ((full_map_3[y + mario.Y][x + mario.X + 1] == 13 || full_map_3[y + mario.Y][x + mario.X - 1] == 13) && end == 1) {
					end = 0;
					End();
				}

				// 맵 나가는거 확인
				if (full_map_3[y + mario.Y - valueY][x + mario.X + valueX] != 0 || y + mario.Y - valueY < 0 || x + mario.X + valueX < 0 || mario.X + valueX - MapMovX < 0)
					return 1;
				break;
			}
		}
	}

	// 마리오 이동
	mario.Y -= valueY;
	mario.X += valueX;

	// 마이로가 맵 중간을 넘으면 맵 이동
	if (mario.X + 6 - PRINT_FULL_WIDTH / 2 > MapMovX)
		MapMovX = mario.X + 6 - (PRINT_FULL_WIDTH / 2);
	return 0;
}

int death(int valueX, int valueY) {
	int x, y, i = 0;
	// 이상 체크 (이상있으면 종료, return)
	for (y = 0; y < 8; y++) {
		for (x = 0; x < 12; x++) {
			switch (stage) {
			case 1:
				// 구멍에 빠질때
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				
				// 몬스터(물고기) 
				for (i = 0; i < 11; i++) {
					if (mario.X + valueX >= monster_fish_1[i].X - 8 && mario.X + valueX < monster_fish_1[i].X + 15 && mario.Y - valueY > monster_fish_1[i].Y - 5 && mario.Y - valueY < monster_fish_1[i].Y + 12)
						return 1;
				}

				// 몬스터(오징어) 
				for (i = 0; i < 11; i++) {
					if (mario.X + valueX >= monster_squid_1[i].X - 5 && mario.X + valueX < monster_squid_1[i].X + 16 && mario.Y - valueY > monster_squid_1[i].Y - 6 && mario.Y - valueY < monster_squid_1[i].Y + 12)
						return 1;
				}
				
				// 몬스터(상어)
				for (i = 0; i < 2; i++) {
					if (monster_shark_1[i].flag == 1 && mario.X + valueX > monster_shark_1[i].X - 7 && mario.X + valueX < monster_shark_1[i].X + 20 && mario.Y - valueY > monster_shark_1[i].Y - 8 && mario.Y - valueY < monster_shark_1[i].Y + 22)
						return 1;
				}

				// 몬스터(상어 2마리)
				for (i = 0; i < 3; i++) {
					if (monster_shark_2_1[i].flag == 1 && mario.X + valueX > monster_shark_2_1[i].X - 7 && mario.X + valueX < monster_shark_2_1[i].X + 40 && mario.Y - valueY > monster_shark_2_1[i].Y - 8 && mario.Y - valueY < monster_shark_2_1[i].Y + 22)
						return 1;
				}

				
				// 산호초 닿을때
				if (full_map_1[y + mario.Y - valueY][x + mario.X + valueX] == 6)
					return 1;
				

				// 떨어지는 블럭(1x2)
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > down_block_1_1x2[i].X - 10 && mario.X + valueX < down_block_1_1x2[i].X + 38 && mario.Y - valueY > down_block_1_1x2[i].Y && mario.Y - valueY < down_block_1_1x2[i].Y + 10)
						return 1;
				}

				// 떨어지는 블럭(1x3) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > down_block_1_1x3[i].X - 10 && mario.X + valueX < down_block_1_1x3[i].X + 58 && mario.Y - valueY > down_block_1_1x3[i].Y && mario.Y - valueY < down_block_1_1x3[i].Y + 10)
						return 1;
				}

				// 떨어지는 블럭(1x4)
				for (i = 0; i < 3; i++) {
					if (mario.X + valueX > down_block_1_1x4[i].X - 10 && mario.X + valueX < down_block_1_1x4[i].X + 78 && mario.Y - valueY > down_block_1_1x4[i].Y && mario.Y - valueY < down_block_1_1x4[i].Y + 10)
						return 1;
				}
				break;	
				

			case 2:
				// 구멍에 빠질때
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				// 스프링 밟고 하늘 높이 올갈때
				if (y + mario.Y - valueY < 4 && spring_check == 1)
					return 1;
				
				// 몬스터(굼바) 
				for (i = 0; i < 14; i++){
					if (mario.X + valueX >= monster_2[i].X - 14 && mario.X + valueX < monster_2[i].X + 15 && mario.Y - valueY > monster_2[i].Y - 5 && mario.Y - valueY < monster_2[i].Y + 7)
						return 1;
				}
				
				// 몬스터(기둥) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX >= monster_pillar_2[i].X - 8 && mario.X + valueX < monster_pillar_2[i].X + 18 && mario.Y - valueY > monster_pillar_2[i].Y - 6 && mario.Y - valueY < monster_pillar_2[i].Y + 12)
						return 1;
				}

				// 몬스터(비행)
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX > monster_fly_2[i].X - 12 && mario.X + valueX < monster_fly_2[i].X + 20 && mario.Y - valueY > monster_fly_2[i].Y - 8 && mario.Y - valueY < monster_fly_2[i].Y + 12)
						return 1;
				}

				// 몬스터(식인꽃) 
				for (i = 0; i < 2; i++) {
					if (mario.X + valueX >= monster_floower_2[i].X - 10 && mario.X + valueX < monster_floower_2[i].X + 16 && mario.Y - valueY > monster_floower_2[i].Y - 6 && mario.Y - valueY < monster_floower_2[i].Y + 8)
						return 1;
				}
				
				break;
				
			case 3:
				// 구멍에 빠질때
				if (y + mario.Y - valueY > PRINT_FULL_HEIGHT - 1)
					return 1;
				// 하늘 높이 올갈때
				if (y + mario.Y - valueY <= 0)
					return 1;
				
				// 떨어지는 긴 막대 부딪칠때
				if (mario.X + valueX > long_block_3.X - 12 && mario.X + valueX < long_block_3.X + 20 && mario.Y - valueY == long_block_3.Y + 121)
					return 1;
				// 몬스터(일반)
				for (i = 0; i < 2; i++){
					if (mario.X + valueX > monster_3[i].X - 12 && mario.X + valueX < monster_3[i].X + 20 && mario.Y - valueY > monster_3[i].Y - 8 && mario.Y - valueY < monster_3[i].Y + 12)
						return 1;
				}
				// 몬스터(비행)
				for (i = 0; i < 4; i++) {
					if (mario.X + valueX > monster_fly_3[i].X - 12 && mario.X + valueX < monster_fly_3[i].X + 20 && mario.Y - valueY > monster_fly_3[i].Y - 8 && mario.Y - valueY < monster_fly_3[i].Y + 12)
						return 1;
				}
				// 몬스터(점프)
				if (mario.X + valueX > monster_jump_3.X - 12 && mario.X + valueX < monster_jump_3.X + 20 && mario.Y - valueY > monster_jump_3.Y - 8 && mario.Y - valueY < monster_jump_3.Y + 12)
					return 1;
					
				break;
		
			}
		}
	}
	return 0;
}
// Mov 실패 시 움직이는 값을 줄여서 다시 시도
void Mov_Safe(int valueX, int valueY) {
	// Mov 성공
	if (MovMorio(valueX, valueY) == 0)
		return;

	while (!(valueX == 0 && valueY == 0)) {
		if (!MovMorio((valueX > 0 ? --valueX : (valueX < 0 ? ++valueX : valueX)), (valueY > 0 ? --valueY : (valueY < 0 ? ++valueY : valueY))))
			break;
	}
	return;
}

// 이중 점프 확인
int CanIJump() {
	if (MovMorio(0, -1))
		return 1;

	MovMorio(0, 1);
	return 0;
}


// 게임 오버
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

// 게임 끝
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

// 원활한 노래 출력을 위해 2개 만듦
void play_sound(int num) {
	if (num == 1)	// 점프
		mciSendString("play MUSIC\\jump.wav", NULL, 0, NULL);
	else if (num == 2)	// 굼바 밟을때
		mciSendString("play MUSIC\\stomp.wav", NULL, 0, NULL);
	else if (num == 3)	// 코인
		mciSendString("play MUSIC\\coin.wav", NULL, 0, NULL);
	else if (num == 4)	// 머리 부딪치면 생기는 블럭
		mciSendString("play MUSIC\\head_block.wav", NULL, 0, NULL);
	else if (num == 5)	// 식인꽃
		mciSendString("play MUSIC\\monster1.wav", NULL, 0, NULL);
	else if (num == 6)	// 기둥 몬스터
		mciSendString("play MUSIC\\monster2.wav", NULL, 0, NULL);
	else if (num == 7)	// 상어
		mciSendString("play MUSIC\\monster3.wav", NULL, 0, NULL);
	else if (num == 8)	// 스테이지3
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
