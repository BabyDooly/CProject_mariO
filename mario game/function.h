#pragma once

/* --------�Լ�--------- */
void start_setup();						// ������ �޴� ���� 
void Write();							// �����ڵ忡 ���� ������
void start_game(int stage);				// ���� ��ŸƮ
int MovMorio(int valueX, int valueY);	// ������ ������
void Mov_Safe(int valueX, int valueY);	// Mov ���� �� �����̴� ���� �ٿ��� �ٽ� �õ�
int death(int valueX, int valueY);		// ���� Ȯ��
int CanIJump();							// ���� ���� Ȯ��
void GameOver();						// ���� ����
void End();								// ���� ��
void play_sound(int num);				// ���� 1
void play_sound_(int num);				// ���� 2

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