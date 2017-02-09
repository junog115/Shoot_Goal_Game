#include "stdafx.h"

Player MainPlayer;
Ball PlayerBall;

string g_string;

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

	PlayerBall.SetBallPosition();
	
	g_string = "플레이어의 위치 " + to_string(MainPlayer.GetPlayerX()) + ", " + to_string(MainPlayer.GetPlayerY());
}

void Render()
{
	ScreenClear();
	ScreenPrint(0, 0, g_string);

	MainPlayer.PrintPlayer();
	PlayerBall.PrintBall();

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
			PlayerBall.ShootBall(MainPlayer);
			break;

		case 'q':
			cout << "게임을 종료합니다." << endl;
			exit(0);

		default:
			break;
		}
	}
}