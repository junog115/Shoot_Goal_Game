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
		else if(CurTime - OldTime >= MoveTime)
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
		IsReady = !IsReady;
	}
}

void Ball::ChangeBallSpeed(clock_t Speed)
{
	MoveTime = Speed;
}

int Ball::GetBallX(void)
{
	return nMoveX;
}

int Ball::GetBallY(void)
{
	return nMoveY;
}

void Ball::Reset(void)
{
	IsReady = true;
	nMoveX = 20;
	nMoveY = 19;
	MoveTime = 100;
	sBallForm = "◎";
}