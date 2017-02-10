#include "stdafx.h"

Player MainPlayer;
Ball PlayerBall;
Target PlayerTarget;
Stage PlayerStage;

void Init();
void Update();
void Render();
void Release();

string sHitNumber;
string sStage;
string NoticeKey = " 'J' : Left  |  'L' : Right  |  'K' : Shoot  \n\n 'R' : Reset  |  'Q' : Quit ";
string sLoose = "You are Fail (Reset : 'R'  |  Quit : 'Q')";
string sTryShoot;

void KeyProcess(void);
enum GameState { Play = 1, Loose = 2, MainScreen = 3 };
GameState PlayInfo = Play;

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

	// 과녁을 맞췄는지 판별
	if (PlayerTarget.IsAttackTarget(PlayerBall) == true)
	{
		PlayerStage.UpHitNumber();
		PlayerBall.SetBallPosition(MainPlayer);
	}
	
	// 패배 판정 
	if ((PlayerBall.GetTryShoot()) == MAXTRYNUMBER)
	{
		if ((PlayerBall.GetIsReady() == true) && (PlayerStage.GetHitNumber() <= 3) )
		{
			PlayInfo = Loose;
		}
	}

	// 과녁을 3번 맞췄는지 판별
	if (PlayerStage.GetHitNumber() == 3)
	{
		PlayerStage.ChangeNextStage(PlayerBall, PlayerTarget);
	}

	// 우측 메뉴에 출력할 데이터 
	sTryShoot = "Try : " + to_string(PlayerBall.GetTryShoot()) + " / " + to_string(MAXTRYNUMBER);
	sStage = "Stage : " + to_string(PlayerStage.GetStageNumber());
	sHitNumber = "Hit target : " + to_string(PlayerStage.GetHitNumber()) + " / 3";

	PlayerTarget.MoveTarget();
	PlayerBall.SetBallPosition(MainPlayer);
}

void Render()
{
	ScreenClear();

	switch (PlayInfo)
	{
	case Play:
		ScreenPrint(MAXRIGHTX + 3, MAXUPY + 3, sStage);
		ScreenPrint(MAXRIGHTX + 3, MAXUPY + 5, sHitNumber);
		ScreenPrint(MAXRIGHTX + 3, MAXUPY + 7, sTryShoot);

		MainPlayer.PrintPlayer();
		PlayerBall.PrintBall();
		PlayerTarget.PrintTarget();

		ScreenPrint(MAXLEFTX, MAXDOWNY, NoticeKey);
		break;
	case Loose:
		ScreenPrint((MAXRIGHTX / 2) + 10, MAXDOWNY / 2, sLoose);
			break;

	case MainScreen:

		break;

	default:
		break;
	}

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
			PlayInfo = Play;
			MainPlayer.Reset();
			PlayerBall.Reset();
			PlayerTarget.Reset();
			PlayerStage.Reset();
			break;

		case 'q':
			exit(0);

		default:
			break;
		}
	}
}

