#pragma once

#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include"control.h"	//setColor, goto���� �Ǿ�����.element�� ����Ǿ��ϹǷ�.
//#include"Game.h"


class Output {	//�ð�ȭ ��ü
public:
	void printStartMenu();
	void printFrame();
	void fixOnBoard(const Element* a);
	void draw();
	//���� ����, �Ÿ�, �ð� �����ϴ� ���� �����. �ؿ� ����ϴ� �Լ��� �����.
	int board[22][38];// �����̺� �Ϸ��׷��µ�... ���̾ƿ��� ���� �����ؾ��ϴϱ�..?
};

#endif //!__OUTPUT_H__