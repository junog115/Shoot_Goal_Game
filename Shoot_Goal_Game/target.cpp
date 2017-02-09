#include "stdafx.h"

void Target::PrintTarget(void)
{
	ScreenPrint(nPrintX, nPrintY, sTargetForm);
}

void Target::MoveTarget(void)
{
	clock_t CurTime = clock();
	
	if((CurTime - OldTime) >= MoveTime)
	{
		OldTime = CurTime;
		if(bTargetDirection == true)
		{
			if(nPrintX == MAXLEFTX)
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
			if((nPrintX + nTargetLength) == MAXRIGHTX)
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

void Target::ChangeTargetSpeed(clock_t Speed)
{
	MoveTime = Speed;
}

void Target::ChangeTargetSize(int nSize)
{
	sTargetForm.erase(2, 2 + (nTargetLength - nSize));
	nTargetLength = sTargetForm.length();
}

bool Target::IsAttackTarget(Ball Attacker)
{
	if(Attacker.GetBallY() == nPrintY)
	{
		if(Attacker.GetBallX() > nPrintX && Attacker.GetBallY() < (nPrintX + nTargetLength))
		{
			return true;
		}
	}
	return false;
}

void Target::Reset(void)
{
	nPrintX = 10;
	nPrintY = 2;
	MoveTime = 200;
	OldTime = clock();
	sTargetForm = "□----------------□";
	nTargetLength = sTargetForm.length();
}

