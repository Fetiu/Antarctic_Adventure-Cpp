#pragma once

#ifndef __ELEMENT_H__

#define __ELEMENT_H__

class Element 
{	//������ ��Ҹ� �����ϴ� �߻� Ŭ����. �浹,���� �Լ��� ��ü ������ �����Ҷ� ���!!
public:
	Element(int _X, int _Y) :x(_X), y(_Y) { shape = 0; }
	int action;// ��� ���� ����� ����Ǵ� ����. ĳ���ʹ� Ű������ ����ϰŰ�, ����̳� ������ �Ÿ��� ���� ����� ���̴�.
	virtual void movePos() = 0; //��ӽ�Ű�� �������̵� �ɺκ�.�߿���������.
	int presentForm[9][11] = { 0 };
	int getX() const { return x; }
	int getY() const { return y; }
protected:
	int shape;//�迭�� �������� �ܺ��Լ��� ��絵 �˷���߰ڳ�?...
	int x, y;	//������ ����� ��ǥ�� �����ϴ� �Լ��� ����Լ�. ���� Ŭ���� ������ ��������ֱ�!
				//int previousForm[9][11] = { 0 };
};
//visualizer, conceptualizer

#endif // !__ELEMENT_H__
