#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

class Player
{
	// 중심 좌표, 이동 좌표, 기준 좌표
	int nCenterX, nCenterY;
	int nMoveX, nMoveY;
	int nPrintX, nPrintY;
	// Player Character 모습 및 길이
	char sPlayerForm[11] = "┖━●━┚";
	int nPlayerLength;
	// 최대로 움직일 수 있는 우측 X 좌표
	int nMaxMoveX = 40;

public:
	Player()
	{
		nCenterX = 4;
		nCenterY = 0;
		nMoveX = 20;
		nMoveY = 20;
		nPrintX = nMoveX - nCenterX;
		nPrintY = nMoveX - nCenterY;
		nPlayerLength = strlen(sPlayerForm);
	}

	void PlayerMoveLeft(void);
	void PlayerMoveRight(void);
	void PrintPlayer(void);
	int GetPlayerX(void);
	int GetPlayerY(void);
};

#endif