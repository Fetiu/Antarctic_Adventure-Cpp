#pragma once

#ifndef __GROUND_H__
#define __GROUND_H__

class Ground {
public:
	Ground(int(*board)[38]);
	void updateGround(int(*board)[38]);
	int stage;//�ۺ�? ���߿� �̽��Ϳ��׷� �ٸ�������������?

	const static int landscape[3][22][38];
private:
	int shape = 0;
};

#endif// !__GROUND_H__
