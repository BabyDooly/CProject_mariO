#pragma once

/* --------함수--------- */
void start_setup();						// 실행전 메뉴 셋팅 
void Write();							// 유니코드에 색깔 입히기
void start_game(int stage);				// 게임 스타트
int MovMorio(int valueX, int valueY);	// 마리오 움직임
void Mov_Safe(int valueX, int valueY);	// Mov 실패 시 움직이는 값을 줄여서 다시 시도
int death(int valueX, int valueY);		// 데스 확인
int CanIJump();							// 이중 점프 확인
void GameOver();						// 게임 오버
void End();								// 게임 끝
void play_sound(int num);				// 음악 1
void play_sound_(int num);				// 음악 2

/* --------Stage1--------- */
void Stage1_setup();
void Stage1_Coloring();
void Stage1_block_check();
void Stage1_check_point();
void Stage1_Input(void* arg);
void Stage1_move_thread(void* args);


/* --------Stage2--------- */
void Stage2_setup();
void Stage2_Coloring();
void Stage2_block_check();
void Stage2_check_point();
void Stage2_Input(void* arg);
void Stage2_move_thread(void* args);


/* --------Stage3--------- */
void Stage3_setup();
void Stage3_Coloring();
void Stage3_block_check();
void Stage3_check_point();
void Stage3_Input(void* arg);
void Stage3_move_thread(void* args);

/* --------mumu--------- */
void menu_setup();
void menu_Coloring();
void MenuSelect();