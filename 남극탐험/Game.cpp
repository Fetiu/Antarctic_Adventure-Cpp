#include"Game.h"


void Game::startMenu() {
	graphic.printFrame();

	PlaySound(TEXT("Opening.wav"), NULL, SND_FILENAME | SND_ASYNC);

	graphic.printStartMenu();
}

void Game::selectAvatar() {//ĳ���� ���� �޴� ����..
	avatar = new Character(14, 12);// makePenguin();
}

void Game::playStage() {
	PlaySound(TEXT("Main_Bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (action != STAGE_CLEAR) {


		action = getKey();//������ ����

		avatar->action = action;// ���� ���� ��� ��ü�� �־���

		avatar->movePos();	//������ �������� ĳ���� ��ǥ�̵�. ������ �������ÿ� ����� ��� 1�� ���ϹǷ� �浹�� �Ͼ�� ����.
		avatar->motionPrint(&graphic);//������ �������� ��µ� ��� ������, ���忡 �����Ų��

		update(); //���� ȭ�� ������Ʈ

		Sleep(20);
	}
	PlaySound(NULL, 0, 0);
	stageCleared++;
}


void Game::update() {
	graphic.draw();
	land = new Ground(graphic.board);//����� �Ϸ�� �ڿ� �ٽ� �ʱ�ȭ�� ������.
}


void Game::setNextStage() {
	switch (stageCleared) {
	case 0:
		nextStage = 1;
		break;
	}
}

void Game::mapMenu() {};

