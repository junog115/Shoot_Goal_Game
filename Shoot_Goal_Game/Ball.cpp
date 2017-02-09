#include "stdafx.h"

void Ball::SetBallPosition(Player MainPlayer)
{
	if(IsReady == true)
	{
		nMoveX = MainPlayer.GetPlayerX();
		nMoveY = MainPlayer.GetPlayerY();
		nMoveY--;
	}
	else
	{
		clock_t CurTime;

		CurTime = clock();
		if(CurTime - OldTime >= MoveTime)
		{
			OldTime = CurTime;
			if(nMoveY <= 2)
			{
				nMoveX = MainPlayer.GetPlayerX();
				nMoveY = MainPlayer.GetPlayerY();
				nMoveY--;

				IsReady = !IsReady;
			}
			else
			{
				nMoveY--;
			}
		}
	}
}

void Ball::PrintBall(void)
{
	ScreenPrint(nMoveX, nMoveY, sBallForm);
}


void Ball::ShootBall(void)
{
	if(IsReady == true)
	{
		OldTime = clock();
		IsReady = !IsReady;
	}
}