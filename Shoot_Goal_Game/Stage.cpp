#include "stdafx.h"

void Stage::UpHitNumber(void)
{
	nHit++;
}

void Stage::ReSetHitNumber(void)
{
	nHit = 0;
}

int Stage::GetHitNumber(void)
{
	return nHit;
}

int Stage::GetStageNumber(void)
{
	return nStage;
}

void Stage::ChangeNextStage(Ball &PlayerBall, Target &PlayerTarget)
{
	if ((nStage % 3) == 0)
	{
		PlayerTarget.DownTargetSize(1);
	}
	else if ((nStage % 3) == 2)
	{
		PlayerBall.DownBallSpeed(30);
	}
	else if ((nStage % 3) == 1)
	{
		PlayerTarget.UpTargetSpeed(35);
	}
	ReSetHitNumber();
	nStage++;
	PlayerBall.ResetTryNumber();
}

void Stage::Reset(void)
{
	nStage = 1;
	nHit = 0;
}