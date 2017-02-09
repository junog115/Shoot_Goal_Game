#include "stdafx.h"

Player MainPlayer;
Ball PlayerBall;
Target PlayerTarget;

int g_nHit = 0;
string sHitNumber;
string NoticeKey = 
" 'J' : Left  |  'L' : Right  |  'K' : Shoot  \n\n 'R' : Reset  |  'Q' : Quit ";


void Init();
void Update();
void Render();
void Release();

void KeyProcess(void);

int _tmain(int argc, _TCHAR* argv[])
{
	ScreenInit();
	Init();

	while (1)
	{
		Update();

		Render();
	}

	Release();
	ScreenRelease();

	return 0;
}

void Init()
{

}

void Update()
{
	KeyProcess();

	if (PlayerTarget.IsAttackTarget(PlayerBall) == true)
	{
		g_nHit++;
		PlayerBall.SetBallPosition(MainPlayer);
	}
	sHitNumber = "Hit target : " + to_string(g_nHit);

	PlayerTarget.MoveTarget();
	PlayerBall.SetBallPosition(MainPlayer);
}

void Render()
{
	ScreenClear();
	ScreenPrint(MAXRIGHTX + 3, MAXUPY + 3, sHitNumber);

	MainPlayer.PrintPlayer();
	PlayerBall.PrintBall();
	PlayerTarget.PrintTarget();

	ScreenPrint(MAXLEFTX, MAXDOWNY, NoticeKey);

	ScreenFlipping();
}

void Release()
{

}

void KeyProcess(void)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'j':
			MainPlayer.PlayerMoveLeft();
			break;

		case 'l':
			MainPlayer.PlayerMoveRight();
			break;

		case 'k':
			PlayerBall.ShootBall();
			break;

		case 'r':
			MainPlayer.Reset();
			PlayerBall.Reset();
			PlayerTarget.Reset();
			g_nHit = 0;
			break;

		case 'q':
			cout << "게임을 종료합니다." << endl;
			exit(0);

		default:
			break;
		}
	}
}