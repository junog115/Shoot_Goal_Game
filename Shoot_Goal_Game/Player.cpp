#include "stdafx.h"

void Player::PlayerMoveLeft(void)
{
	if ((nPrintX <= 0) || ((nPrintX + nPlayerLength) > nMaxMoveX))
	{
		if (nMoveX <= 0)
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
	if ((nPrintX < 0) || (nPrintX + nPlayerLength) >= nMaxMoveX)
	{
		if ((nMoveX + 2) == nMaxMoveX)
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
	if( nPrintX < 0 )
	{
		ScreenPrint(0, nPrintY, &sPlayerForm[nPrintX * -1]);
	}
	else if ( (nPrintX + nPlayerLength) > nMaxMoveX)
	{
		char sPlayerCutForm[10] = { 0 };

		strncat_s(sPlayerCutForm, sPlayerForm, (nPlayerLength - (( nPrintX + nPlayerLength) - nMaxMoveX)));

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