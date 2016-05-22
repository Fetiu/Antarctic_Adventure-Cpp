#include"Output.h"//OutputŬ���� ���� �Ǿ�����.

enum{SKY=0,};

void Output::printFrame() {
	system("mode con:cols=80 lines=31");//���ũ�� Ű���

	setColor(0x0F);
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 24; j++) {
			gotoxy(i * 2, j);
			if (j == 0) {
				if (i == 0) cout << "��";
				else if (i == 39)cout << "��";
				else cout << "��";
			}
			else if (j == 23) {
				if (i == 0) cout << "��";
				else if (i == 39)cout << "��";
				else cout << "��";
			}
			else if (i == 0 || i == 39)	cout << "��";
		}
	}

	gotoxy(0, 23);	cout << "��";
	gotoxy(78, 23); cout << "��";

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 6; j++) {
			gotoxy(i * 2, j + 24);
			if (j == 5) {
				if (i == 0) cout << "��";
				else if (i == 39)cout << "��";
				else cout << "��";
			}
			else if (i == 0 || i == 39)	cout << "��";

		}
	}

}

void Output::printStartMenu() {
	for (int i = 0; i < 38; i++) {
		for (int j = 0; j < 22; j++) {
			gotoxy((i+1) * 2, j+1);
			if (j > 6 && j < 16) {
				setColor(0xF0);
				cout << "  ";
			}
			else {
				setColor(0x9F);
				cout << "��";
			}
		}
		Sleep(5);
	}

	setColor(0xF1);//���� ������ ���� ������ �̷��� �밡�� �Ҽ��ۿ� ����...�Ф�
	gotoxy(8, 9);
	cout << "����    ����  " << endl; gotoxy(8, 10);
	cout << "����    ������" << endl; gotoxy(8, 11);
	cout << "��������������" << endl; gotoxy(8, 12);
	cout << "������������  " << endl; gotoxy(8, 13);
	cout << "  ����������  " << endl; gotoxy(8, 14);
	cout << "  ����������  " << endl; gotoxy(8, 15);
	cout << "  ����������  " << endl; gotoxy(8, 16);

	gotoxy(25, 9);
	cout << "  ����������  " << endl; gotoxy(25, 10);
	cout << "  ����������  " << endl; gotoxy(25, 11);
	cout << "        ����  " << endl; gotoxy(25, 12);
	cout << "��������������" << endl; gotoxy(25, 13);
	cout << "��������������" << endl; gotoxy(25, 14);
	cout << "  ����������  " << endl; gotoxy(25, 15);
	cout << "        ����  " << endl; gotoxy(25, 16);

	gotoxy(42, 9);
	cout << "������������  " << endl; gotoxy(42, 10);
	cout << "��  ����������" << endl; gotoxy(42, 11);
	cout << "��  ����������" << endl; gotoxy(42, 12);
	cout << "������������  " << endl; gotoxy(42, 13);
	cout << "  ����������  " << endl; gotoxy(42, 14);
	cout << "  ����������  " << endl; gotoxy(42, 15);
	cout << "  ����������  " << endl; gotoxy(42, 16);
	gotoxy(58, 8);
	cout << "  ��������      " << endl; gotoxy(58, 9);
	cout << "��������������" << endl; gotoxy(58, 10);
	cout << "��������������" << endl; gotoxy(58, 11);
	cout << "  ������������" << endl; gotoxy(58, 12);
	cout << "   ������ ����" << endl; gotoxy(58, 13);
	cout << "    ����������" << endl; gotoxy(58, 14);
	cout << "    ����������" << endl; gotoxy(58, 15);
	cout << "    ����������" << endl; gotoxy(58, 16);

	setColor(0x0F);


	while (!_kbhit()) {
		gotoxy(22, 26);
		cout << " �����Ϸ��� �ƹ�Ű�� ��������...";
		Sleep(300);
		gotoxy(22, 26);
		cout << "                                ";
		Sleep(300);
	}

}


void Output::fixOnBoard(const Element* a) {
	//��ü�� �޾ƿͼ� ȭ�� �迭 ���� ������Ŵ. 
	//�����ϱ� ���� ���� ����Ʈ �ؾ��ϴ� �� ��ġ�� ���� �̹� �ִٸ�, �浹

	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 11; i++) {
			if (a->presentForm[j][i])//a�������� �迭�ӿ� 0�̾ƴ� ���� �����Ѵٸ�
				board[a->getY() + j][a->getX() + i] = a->presentForm[j][i];
		}
}
//�̰� set��ü �������� �־�ξ ����������...�׷��� �Ǹ� ���带 ����ΰ�
//�� ��ü�� �޾ƿͼ� ��½�Ű�� �ɵ�...�ϴ�! �� �ٵ�


void Output::draw() {
	for (int j = 0; j < 22; j++)
		for (int i = 0; i < 38; i++) {
			gotoxy((i + 1) * 2, j + 1);
			switch (board[j][i])
			{
			case 0: setColor(0xBF); cout << "��"; break;//�ϴ�
			case 1: 
			case 2:setColor(0x10); cout << "��"; break;//��� ��ü
			case 3:setColor(0x18); cout << "��"; break;//��� ���
			case 4:setColor(0x18); cout << "��"; break;//��� �ݻ�
			case 5:break;
			case 7: setColor(0x9F); cout << "  "; break;//�ٴ�
			case 8: setColor(0xF0); cout << "  "; break;//����
			case 9: setColor(0xF3); cout << "��"; break;//������
			}
		}
}