#include"Game.h"

#include<time.h>
#include<stdlib.h>
#include<iomanip>

void Game::startMenu() {
	graphic.printBorder();

	PlaySound(TEXT("Opening.wav"), NULL, SND_FILENAME | SND_ASYNC);

	graphic.printStartMenu();
}

void Game::selectAvatar() {//ĳ���� ���� �޴� ����..
	avatar = new Character(14, 11);// makePenguin();
}

void Game::playStage() {
	static int speed_cnt = 0;
	speed = 20;
	wipeInfo();

	PlaySound(TEXT("Main_Bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	land = new Ground(graphic.getBoard());

	destination = rand() % 1000 + 1000;	///������ ����

	while (action != STAGE_CLEAR) {

		printCurrentInfo();	//���� �������� ���

		makeHoles();

		moveCloser();	//��ֹ� �̵�


		action = getKey();//������ ����

		avatar->action = action;// ���� ���� ��� ��ü�� �־���

		avatar->movePos();	//������ �������� ĳ���� ��ǥ�̵�. ������ �������ÿ� ����� ��� 1�� ���ϹǷ� �浹�� �Ͼ�� ����.
		avatar->motionPrint(&graphic,speed);//������ �������� ��µ� ��� ������, ���忡 �����Ų��


		update(); //���� ȭ�� ������Ʈ
		Sleep(speed);

		//if (speed_cnt==speed) {
//		if (avatar->getCollide()) {
//			speed++;	//���ǵ� ����
//		}
//		if(speed>0)speed--;	//���ǵ� ����
//		speed_cnt = 0;
//	}
		speed_cnt++;
		distance++;
		if(speed_cnt%10==9&&speed>15)speed-=2;
		if (distance == 50/*destination*/) action = STAGE_CLEAR;

	}
	PlaySound(NULL, 0, 0);
	clearedStage++;
}

void Game::makeHoles() {
	static int holeTime = timer + rand() % 5;	//���� �ð��� �������� ������ �ð���ŭ ���Ŀ� ��Ÿ����.

	//�ð������ϸ� �� �ð��� �Ǽ��� ����ĥ��� ������ �������� �ʴ� ������ �߻���..ī��Ʈ��?

	if (pit != nullptr) {	//hole�� ����� �����ٸ�.
		if (pit->getY() == 18) {	//�ٴڿ� ��Ҵ��� �Ǵ�.
			delete[] pit;	//delete��Ų�ٰ� nullptr�� ������ �ʴ´�!
			pit = nullptr;

			holeTime = timer + rand() % 5 + 3;
		}
	}

	if (timer == holeTime) {	//�����̰� ����������ϴ� Ÿ�̹��̶�� ���� ��ġ�� ����.
		pit = new Hole(2 * (rand() % 4 + 5));
	}

}


void Game::moveCloser(){

	if (pit != nullptr)
		pit->motionPrint(&graphic);
	//�̰��� �����۵鵵 ���� ������� �߰�.
	
}

void Game::printCurrentInfo() {
	static time_t start_time = time(NULL);

	timer = (int)time(NULL) - start_time;
	setColor(0x0F);
	gotoxy(3, 24); 
	cout <<"�ð� - "<<setw(5) <<timer;

	gotoxy(3, 28);
	cout << "�ӵ�                             ";
	gotoxy(9, 28);
	for (int i = 0; i < (30 - speed) / 2; i++)
		cout << "��";

	gotoxy(3, 26);
	cout << "������ - " << setw(5) << destination<<"m";

	rest = destination - distance;

	gotoxy(33, 26);
	cout << "�����Ÿ� - " << setw(5) << rest<<"m";

	
}


void Game::update() {
	graphic.drawScreen();
	land->updateGround(graphic.getBoard());//����� �Ϸ�� �ڿ� �ٽ� �ʱ�ȭ�� ������.
}


void Game::setNextStage() {
	switch (clearedStage) {
	case 0:
		nextStage = 1;
		break;
	case 1:
		nextStage = 2;
		break;
	}
}

void Game::printMapInfo() {
	setColor(0x0F);

	gotoxy(35, 24); cout << "ANTARCTICA";

	if (clearedStage != 0) {
		for (int cnt = 0; cnt < 10; cnt++) {
			gotoxy(30, 28); 
			cout << " �������� " << clearedStage << " Ŭ����!";
			Sleep(100);
			gotoxy(30, 28);
			cout << "                                    ";
			Sleep(50);
		}
		gotoxy(22, 28);
		cout << " �������� " << nextStage << "(��)�� Ȱ��ȭ �Ǿ����ϴ�.";
		Sleep(5000);
		gotoxy(22, 28);
		cout << "                                         ";
	}
}

void Game::mapMenu() {
	PlaySound(TEXT("Menu_Bgm.wav"), NULL, SND_FILENAME | SND_ASYNC );
	antarctica->updateMap(graphic.getBoard());

	wipeInfo();

	while (action != SELECT&&action != JUMP) {
		action = getKey();//������ ����
		graphic.drawScreen();
		printMapInfo();
	}
	

	wipeInfo();
	readyScreen();
	graphic.CircleFade(Ground::landscape[0]);
};

void Game::wipeInfo() {
	setColor(0x0F);
	for (int y = 24; y < 29; y++) {
		gotoxy(2, y); cout << "                                                                            ";
	}
}
void Game::readyScreen() {
	graphic.resetBoard();
	graphic.drawScreen();

	gotoxy(38, 24);
	cout << "STAGE " << nextStage;
	gotoxy(38, 27);
	cout << "LOADING";
	Sleep(700);
	gotoxy(37, 27);
	cout << ".LOADING.";
	Sleep(700);
	gotoxy(36, 27);
	cout << "..LOADING..";
	Sleep(700);
	gotoxy(35, 27);
	cout << "...LOADING...";
	Sleep(700);

	gotoxy(35, 27);
	cout << "   START !    ";
}

