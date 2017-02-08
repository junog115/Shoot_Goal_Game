#include "stdafx.h"

using namespace std;

Player mainPlayer;
char g_string[100];

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

	sprintf_s(g_string, "플레이어의 위치 : %d, %d", mainPlayer.GetPlayerX(), mainPlayer.GetPlayerY());
}

void Render()
{
	ScreenClear();
	ScreenPrint(0, 0, g_string);

	mainPlayer.PrintPlayer();

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
			mainPlayer.PlayerMoveLeft();
			break;

		case 'l':
			mainPlayer.PlayerMoveRight();
			break;

		case 'q':
			cout << "게임을 종료합니다." << endl;
			exit(0);

		default:
			break;
		}
	}
}