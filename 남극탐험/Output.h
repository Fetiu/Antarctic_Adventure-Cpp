
#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include"control.h"	//setColor, goto���� �Ǿ�����.element�� ����Ǿ��ϹǷ�.
#include<string>
//#include"Game.h"
//class Game;

class Output {	//�ð�ȭ ��ü
public:
	void printStartMenu();
	void printBorder();
	void fixOnBoard(const Element* object);
	void CircleFade(const int(*nextScreen)[38]);
	void drawScreen();
	int (*getBoard())[38]{ return board; }	//������ �迭 �����ϴ� �Լ�
	void resetBoard() { memset(board, -1, sizeof(int) * 22 * 38); }
	//���� ����, �Ÿ�, �ð� �����ϴ� ���� �����. �ؿ� ����ϴ� �Լ��� �����.
private:
	int board[22][38];// �����̺� �Ϸ��׷��µ�... ���̾ƿ��� ���� �����ؾ��ϴϱ�..?
};

#endif //!__OUTPUT_H__