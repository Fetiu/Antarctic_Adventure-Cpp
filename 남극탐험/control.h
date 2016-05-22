/*
	�����̸�: control.h
	�ۼ�����: ���� ��� ���� �Լ� ����
	�ۼ�����: 2016.5.10
*/
#pragma once

#include<iostream>	//�ܼ� ���������
#include<conio.h> //kbhit, getch ����
#include<Windows.h>	//Sleep, �ܼ� Ŀ�� ����
//��ü�� �����ؾ� �ϱ⿡ ��ü�� Ŭ������ ��Ŭ���
#include"Element.h"

using namespace std;

#define ESC 27 
#define LEFT 75 
#define RIGHT 77 
#define DOWN 80 
#define UP 72

enum { MOVE_LEFT = 0, MOVE_RIGHT, IDLE, CROUCH,JUMP, STAGE_CLEAR, GAME_QUIT };

#define PIT 4
#define FLAG 5
#define FISH 6

//class controller{
//public:
//};


void gotoxy(int x, int y);//��ǥ �̵� �Լ�
//void playSound(string wav); ���ڶ��� �缱���� �ȵǴ����
void setColor(int color_num);//���� �����Լ�. <����> �ѹ� ���� ����ϸ� �� ���� ��� ������.
/* �Ű������� ���� ���� �޶���	
0.������ 1.����	2.����� 3.û�ϻ� 4.���� 5.���ֻ�9.�Ķ� A.C.���� F.���	*/
int getKey();

bool collision(const Element *a,int board[][38]);//������Ʈ ���� �����ε� �ϴ°� ���ΰ�...�Ф�

void copyArr(int(*arr1)[11], const int(*arr2)[11]);	//arr2�� ������ arr1�� �������.
//memcpy�� ��ü.

