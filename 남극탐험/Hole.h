#pragma once
#include"Element.h"

class Hole : public Element //Element���. Element�� ����� �⺻���� ������.
{
public:
	Hole(int rand_x) :Element( rand_x, 3) {}
	//int x, y;
	void movePos();
	void motionPrint(Output* graphic);
private:
	const static int form[5][9][11];
};
