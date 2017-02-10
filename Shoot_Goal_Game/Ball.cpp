#include "stdafx.h"

void Ball::SetBallPosition(Player MainPlayer)
{
	if (IsReady == false)
	{
		clock_t CurTime;

		CurTime = clock();
		if (nMoveY <= (MAXUPY + 3))
		{
			nMoveX = MainPlayer.GetPlayerX();
			nMoveY = MainPlayer.GetPlayerY();
			nMoveY--;

			IsReady = !IsReady;
		}
		else if (CurTime - OldTime >= MoveTime)
		{
			OldTime = CurTime;
			nMoveY--;
		}
	}
	else
	{
		nMoveX = MainPlayer.GetPlayerX();
		nMoveY = MainPlayer.GetPlayerY();
		nMoveY--;
	}
}

void Ball::PrintBall(void)
{
	ScreenPrint(nMoveX, nMoveY, sBallForm);
}


void Ball::ShootBall(void)
{
	if (IsReady == true)
	{
		OldTime = clock();
		nTryShoot++;
		IsReady = !IsReady;
	}
}

void Ball::DownBallSpeed(clock_t Speed)
{
	MoveTime += Speed;
}

int Ball::GetBallX(void)
{
	return nMoveX;
}

int Ball::GetBallY(void)
{
	return nMoveY;
}

int Ball::GetTryShoot(void)
{
	return nTryShoot;
}

bool Ball::GetIsReady(void)
{
	return IsReady;
}

void Ball::ResetTryNumber(void)
{
	nTryShoot = 0;
}

void Ball::Reset(void)
{
	IsReady = true;
	nMoveX = 20;
	nMoveY = 19;
	MoveTime = 100;
	sBallForm = "◎";
	nTryShoot = 0;
}