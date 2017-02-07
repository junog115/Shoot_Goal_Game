#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"

typedef struct _PLAYER
{
	// 중심 좌표, 이동 좌표, 기준 좌표
	int nCenterX, nCenterY;
	int nMoveX, nMoveY;
	int nPrintX, nPrintY;
}PLAYER;

PLAYER g_sPlayer;
char g_sPlayerForm[] = "┖━●━┚";
int g_nPlayerLength;
char g_sPrintPlayerPosition[40] = { 0 };


void Init();
void Update();
void Render();
void Release();

int main(void)
{
	ScreenInit();
	Init();

	while (1)
	{
		Update();

		Render();
	}


	void Release();
	ScreenRelease();

}

void Init()
{
	g_sPlayer.nCenterX = 4;
	g_sPlayer.nCenterY = 0;
	g_sPlayer.nMoveX = 20;
	g_sPlayer.nMoveY = 20;
	g_sPlayer.nPrintX = (g_sPlayer.nMoveX - g_sPlayer.nCenterX);
	g_sPlayer.nPrintY = (g_sPlayer.nMoveY);
	g_nPlayerLength = strlen(g_sPlayerForm);
}

void Update()
{
	if (kbhit())
	{
		switch (getch())
		{
		case 'j':
			g_sPlayer.nMoveX--;
			break;

		case 'l':
			g_sPlayer.nMoveX++;
			break;

		case 'q':
			exit(0);

		default:
			break;
		}
	}
	
	g_sPlayer.nPrintX = (g_sPlayer.nMoveX - g_sPlayer.nCenterX);
	g_sPlayer.nPrintY = (g_sPlayer.nMoveY);
	
	sprintf(g_sPrintPlayerPosition, "주인공의 위치 : %d, %d", g_sPlayer.nMoveX, g_sPlayer.nMoveY);

}

void Render()
{
	ScreenClear();
	//출력 파트 
	ScreenPrint(0, 0, g_sPrintPlayerPosition);

	ScreenPrint(g_sPlayer.nPrintX, g_sPlayer.nPrintY, g_sPlayerForm);
	ScreenFlipping();
}

void Release()
{

}
