#pragma once

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

//template <typename s>

void playBGM(const char * wav,bool loop) {
	(loop = true) ?
		PlaySound(TEXT(wav), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP)
		: PlaySound(TEXT(wav), NULL, SND_FILENAME | SND_ASYNC);//�������� ���� ��� �ݺ����X
}