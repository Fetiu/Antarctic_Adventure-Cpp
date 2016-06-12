#include"Character.h"
#include<string>
const int Character::form[5][9][11] =
{
	{//left
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,3,1,1,1,0,0,0 },
		{ 0,1,1,1,1,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,0,0 },
		{ 0,0,0,1,1,1,1,1,0,1,0 },
		{ 0,0,0,2,2,2,2,2,0,0,0 },
		{ 0,0,0,2,2,2,2,2,3,0,0 },
		{ 0,0,2,2,3,0,0,0,0,0,0 }
	},
	{//stand
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,3,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,1,1,1,1,1,1,1,1,1,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,0,2,2,2,2,2,0,0,0 },
		{ 0,0,0,2,2,2,2,2,0,0,0 },
		{ 0,0,2,2,0,0,0,2,2,0,0 }
	},
	{//right
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,3,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,1,1,0 },
		{ 0,0,1,1,1,1,1,1,0,0,0 },
		{ 0,1,0,1,1,1,1,1,0,0,0 },
		{ 0,0,0,2,2,2,2,2,0,0,0 },
		{ 0,0,3,2,2,2,2,2,0,0,0 },
		{ 0,0,0,0,0,0,3,2,2,0,0 }
	},
	{//ready
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,1,1,1,0,0,0,0 },
		{ 0,0,0,1,3,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,1,1,1,1,1,1,1,1,1,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,2,2,0,0,0,2,2,0,0 }
	},
	{//jump
		{ 0,0,0,0,1,1,1,0,0,0,0 },//�︮���� �޸� �̸�� ����.
		{ 0,0,0,1,3,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,1,1,1,1,1,1,1,0,0 },
		{ 0,3,0,1,1,1,1,1,0,3,0 },
		{ 0,0,0,1,1,1,1,1,0,0,0 },
		{ 0,0,0,1,1,3,1,1,0,0,0 },
		{ 0,0,0,1,0,0,0,1,0,0,0 }
	},
};


void Character::motionPrint(Output* graphic,int& speed){

	if (collision(this, graphic->getBoard()) || state_stumble) { //���� �浹�̰ų�, �浹 ���� �����϶�. ���� �켱.
		stumbleMotion();	//�浹 ���� animation?
		speed=26;
	}
	else if (state_jump)
		jumpMotion();	//���� ����
	else if (state_crouch)
		crouchMotion();
	else
		idleMotion();	//���� ĳ���� ����. ���� �������� ���ϸ� ���� ���¸� �켱������ ������ �� ��������.

	memcpy(presentForm, form[shape], sizeof(int) * 9 * 11);//������ ������ ���� ���¿� ����
	graphic->fixOnBoard(this);	//��� ���忡 ���� ��ü ��ġ. ��ǥ�� ���� ��� �ʿ�.
}



void Character::idleMotion() {
	static int shapeCnt = 0;

	if ((shapeCnt % 4) < 2)	//0,1
		shape++;
	else	//2,3
		shape--;

	// ���� ���� ((shapeCnt % 4) < 2) ? shape++ : shape--;

	tmp_shape = shape;	//���������� ���¸� �ӽ÷� �����ص�.
						//�ٸ� ������ ������ ������ �� ���·� �ٽÿ�.
	shapeCnt++; //0,1,2,3,4,5,6,7,8....	
	//ī��Ʈ�� '���߿�' �÷���� ���� ���¿� ���� ���� ���¸� ����� �������ټ� ����.
}



void Character::stumbleMotion() {
	static int stumbleCnt = 0;

	if (stumbleCnt == 0) {
		state_stumble = true;
		shape = (action==MOVE_RIGHT) ? 0 : 2; //������ ���������� �̵� ���̿��ٸ� ��翡 0(����)����.
	}
	else {
		tmp_act = (shape == 0) ? MOVE_LEFT : MOVE_RIGHT;
		//���� �浹�ϴ� ��츦 �����ϱ� ���� ���������� ��ǥ�� �ٲ����� �ʾҴ�.
		//��ǥ�� �Ǵ��� �� �߾ӿ��� �¿�� �Դٰ����ϴ� ���װ� ����.
		if (stumbleCnt == 7) {
			state_stumble = false;
			shape = tmp_shape;	//���¸� ���� �������� ������Ŵ
			stumbleCnt = 0;
			return;		// �ʱ�ȭ ���Ŀ� cnt�� �ٽ� �Ͼ�� �ʵ��� �ߴ� ���Ѿ���.
		}
		else
			(stumbleCnt % 2) ? y-- : y++;	//Ȧ�� �϶��� ����, ¦���϶� �Ʒ���.
	}
	
	stumbleCnt++;
}

void Character::jumpMotion() {	//���� ���۰� ���̸� �����ִ� �Լ�.
	static int jumpCnt = 0;

	if (jumpCnt == 0) {	//������ �����Ҷ� ���¸� 3����.
		shape = 3;
	}
	else if (jumpCnt == 9) {//7
		//y++;
		state_jump = false;
		shape = tmp_shape;	//���¸� ������ �ϴ� �������� ������Ŵ
		jumpCnt = 0;
		return;
	}
	else {
		(jumpCnt < 5) ? y-- : y++;	//4
		if (jumpCnt == 4) y++;
		if (jumpCnt == 5) y--;
		//if (jumpCnt == 6) y--;
		shape = (jumpCnt < 8) ? 4 : 3;	//������ ī��Ʈ�Ǳ������� ���¿� 4����.
	}

	jumpCnt++;
}

void Character::crouchMotion() {

	if (action != CROUCH)	// �켱������ �ؾ� shape=3 ���� ���� ���ټ� ����..
	{
		shape = tmp_shape;
		state_crouch = false;
		return;
	}
	else 
		shape = 3;

	//tmp_act = CROUCH;
}


void Character::movePos() {
	if (state_stumble) action = tmp_act; //���� �����϶� � Ű�� ���� ���ϰ�.

	switch (action)
	{
	case MOVE_LEFT:
		if (x >= 0)	x--;
		break;
	case MOVE_RIGHT:
		if (x < 28)	x++;
		break;
	case IDLE:
		break;
	case CROUCH:
		state_crouch = true;
		break;
	case JUMP:
		state_jump = true;	//������ ������ �������·� ��ȯ.
		//�ߵ��� �¿� Ű�� ������ �ν� �� �� �ִ�.
		//action�� �ϳ��̱⿡ case�ܺο� �ϴ°� �ǹ̰� ����.
		break;
	case STAGE_CLEAR:
		/*���� ������ǥ �����ϸ� ������ ������.*/
	case GAME_QUIT:
		break;
	default:
		break;
	}
}