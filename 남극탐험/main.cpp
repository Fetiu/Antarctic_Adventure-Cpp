/*
	�����̸�: main.cpp
	�ۼ�����: ���� ���� �Լ�
	�ۼ�����: 2016.5.10
*/


#include"control.h"//�ܼ� ��� �����ϴ� ����� ��� ���⿡ ���Ե�.
#include"Game.h"
#include"Character.h"
#include <stdlib.h>
#include <time.h>
//#include"Sound.h"

int main() {

	srand((unsigned int)time(NULL));
	Game game;
		
	game.startMenu();
	//Ű ������ ���� ����

	game.selectAvatar();//ĳ���� ����

	while (game.action != GAME_QUIT) {

		game.setNextStage();

		game.mapMenu();

		game.playStage();
	}

	return 0;
}
//ĳ���� �迭 �ھ� �׸���>������ ��ֹ� �迭 �ڰ�> �ٽ� ������ ĳ���� �׸��鼭 ��ֹ��� �浹�ߴ��� �Ǵ�.
//��ֹ��� �迭�� �ڰ� �׸��� �׸����� ���� ĳ���͸� ���߿� �׸��⿡ ��������.
