#include "stdafx.h"

void Player::PlayerMoveLeft(void)
{
	if ((nPrintX <= MAXLEFTX) || ((nPrintX + nPlayerLength) > MAXRIGHTX))
	{
		if (nMoveX <= MAXLEFTX)
		{
			return;
		}
		else
		{
			nMoveX = nMoveX - 2;
		}
	}
	else
	{
		nMoveX--;
	}

	nPrintX = nMoveX - nCenterX;
}

void Player::PlayerMoveRight(void)
{
	if ((nPrintX < MAXLEFTX) || (nPrintX + nPlayerLength) >= MAXRIGHTX)
	{
		if ((nMoveX + 2) == MAXRIGHTX)
		{
			return;
		}
		else
		{
			nMoveX = nMoveX + 2;
		}
	}
	else
	{
		nMoveX++;
	}

	nPrintX = nMoveX - nCenterX;
}

void Player::PrintPlayer(void)
{
	if (nPrintX < MAXLEFTX)
	{
		ScreenPrint(MAXLEFTX, nPrintY, &sPlayerForm[nPrintX * -1]);
	}
	else if ((nPrintX + nPlayerLength) > MAXRIGHTX)
	{
		string sPlayerCutForm(sPlayerForm);
		sPlayerCutForm.erase(nPlayerLength - ((nPrintX + nPlayerLength) - MAXRIGHTX), nPlayerLength);

		ScreenPrint(nPrintX, nPrintY, sPlayerCutForm);
	}
	else
	{
		ScreenPrint(nPrintX, nPrintY, sPlayerForm);
	}
}

int Player::GetPlayerX(void)
{
	return nMoveX;
}

int Player::GetPlayerY(void)
{
	return nMoveY;
}

void Player::Reset(void)
{
	nCenterX = 4;
	nCenterY = 0;
	nMoveX = 20;
	nMoveY = 20;
	nPrintX = nMoveX - nCenterX;
	nPrintY = nMoveX - nCenterY;
	sPlayerForm = "┖━●━┚";
	nPlayerLength = sPlayerForm.length();
}