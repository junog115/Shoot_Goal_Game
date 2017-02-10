#include "stdafx.h"

void Target::PrintTarget(void)
{
	ScreenPrint(nPrintX, nPrintY, sTargetForm);
}

void Target::MoveTarget(void)
{
	clock_t CurTime = clock();

	if ((CurTime - OldTime) >= MoveTime)
	{
		OldTime = CurTime;
		if (bTargetDirection == true)
		{
			if (nPrintX == MAXLEFTX)
			{
				bTargetDirection = !bTargetDirection;
				nPrintX++;
			}
			else
			{
				nPrintX--;
			}
		}
		else
		{
			if ((nPrintX + nTargetLength) == MAXRIGHTX)
			{
				bTargetDirection = !bTargetDirection;
				nPrintX--;
			}
			else
			{
				nPrintX++;
			}
		}
	}
}

void Target::UpTargetSpeed(clock_t Speed)
{
	MoveTime -= Speed;
}

void Target::DownTargetSize(int nSize)
{
	if ((nTargetLength - nSize) > 4)
	{
		sTargetForm.erase(2, 1 + nSize);
		nTargetLength = sTargetForm.length();
	}
}

bool Target::IsAttackTarget(Ball Attacker)
{
	if (Attacker.GetBallY() == nPrintY)
	{
		if (Attacker.GetBallX() > (nPrintX + 1) && Attacker.GetBallX() < (nPrintX + nTargetLength - 2))
		{
			return true;
		}
	}
	return false;
}

void Target::Reset(void)
{
	nPrintX = 10;
	nPrintY = 3;
	MoveTime = 200;
	OldTime = clock();
	sTargetForm = "□-----------□";
	nTargetLength = sTargetForm.length();
}

