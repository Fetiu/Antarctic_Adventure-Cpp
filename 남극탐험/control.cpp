/*
 	�����̸�: control.cpp
 	�ۼ�����: ���� ��� ���� �Լ� ����
 	�ۼ�����: 2016.5.10
*/

#include"control.h"

void cursorInvisible()
{
	CONSOLE_CURSOR_INFO Cinfo = { 0, };
	Cinfo.dwSize = 1;
	Cinfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cinfo);
}

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cursorInvisible();
}

void setColor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int getKey() {
	int keyValue, act;
	act = IDLE;
	if (_kbhit() != 0) //Ű���带 �������� Ȯ���� 
	{
		keyValue = _getch();
		if (keyValue == 224) //Ư�� Ű�� ������ �� ���ۿ� 2Byte�� �߻���, ù��° ��(2����Ʈ�� ù1����Ʈ)�� 224���� �߻��ϰ� �ι�° ��(�ι�° ����Ʈ)�� Ư��Ű�� ���� �ٸ�.
		{
			keyValue = _getch(); //Ư�� Ű�� Ȯ���ϱ� ���� 2���� _getch()�Լ��� ȣ���ؾ� ��
		}
		
		switch (keyValue)
		{
		case ENTER:
			act = SELECT;
			break;
		case ESC:
			act = GAME_QUIT;
			break;
		case LEFT:
			act = MOVE_LEFT;
			break;
		case RIGHT:
			act = MOVE_RIGHT;
			break;
		case DOWN:
			act = CROUCH;
			break;
		case UP:
			act = JUMP;
			break;
		default:
			break;
		}
	}
	return act;
}

void copyArr( int(*arr1)[11],const int(*arr2)[11])
{
	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 11; i++)
			arr1[j][i] = arr2[j][i];
}

bool collision(const Element *a, int board[][38]) {//�����ε��� ���ΰ�...
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 11; j++) {
			if ((a->presentForm[i][j] == 2 || a->presentForm[i][j]>3) //��� ���� ���� �浹 �Ǵ� �κ��̰�,
				&& board[a->getY() + i][a->getX() + j] != 8)		//������ ��� ���� 8�� �ƴ϶��(���� ���� �ƴ϶��)
				return true;
		}

	return false;
}
//�浹�� ��ü�� ����?...�� �̹� �ִ� ������ ����� ���� �Է��ϰ� ���� ��ü�� ��.
//���� �浹�� ��� Ŭ�������� ��ȯ�Ѵٸ� ������ Ȱ���� ���ϼ� ����������?