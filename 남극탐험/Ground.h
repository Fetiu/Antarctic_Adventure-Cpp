#pragma once

#ifndef __GROUND_H__
#define __GROUND_H__

class Ground {
public:
	Ground(int(*board)[38]);
	int stage;//�ۺ�? ���߿� �̽��Ϳ��׷� �ٸ�������������?

private:
	int shape = 0;
	const static int landscape[3][22][38];
};

#endif// !__GROUND_H__
