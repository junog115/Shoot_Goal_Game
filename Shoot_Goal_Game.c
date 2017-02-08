#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "screen.h"

#define MAXCONSOLEX 40
#define MAXCONSOLEY 20

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
	g_sPlayer.nMoveY = MAXCONSOLEY;
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
			if ((g_sPlayer.nPrintX <= 0) || ((g_sPlayer.nPrintX + g_nPlayerLength) > MAXCONSOLEX))
			{
				if (g_sPlayer.nMoveX <= 0)
				{
					break;
				}
				else
				{
					g_sPlayer.nMoveX = g_sPlayer.nMoveX - 2;
				}
			}
			else
			{
				g_sPlayer.nMoveX--;
			}
			break;

		case 'l':
			if ((g_sPlayer.nPrintX < 0) || ((g_sPlayer.nPrintX + g_nPlayerLength) >= MAXCONSOLEX))
			{
				if ((g_sPlayer.nMoveX + 2) == MAXCONSOLEX)
				{
					break;
				}
				else
				{
					g_sPlayer.nMoveX = g_sPlayer.nMoveX + 2;
				}
			}
			else
			{
				g_sPlayer.nMoveX++;
			}
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

	if (g_sPlayer.nPrintX < 0)
	{
		ScreenPrint(0, g_sPlayer.nPrintY, &g_sPlayerForm[g_sPlayer.nPrintX * -1]);
	}
	else if ((g_sPlayer.nPrintX + g_nPlayerLength) > 40)
	{
		char sPlayerCutForm[10] = { 0 };

		strncat(sPlayerCutForm, g_sPlayerForm, (g_nPlayerLength - ((g_sPlayer.nPrintX + g_nPlayerLength) - MAXCONSOLEX)));

		ScreenPrint(g_sPlayer.nPrintX, g_sPlayer.nPrintY, sPlayerCutForm);
	}
	else
	{
		ScreenPrint(g_sPlayer.nPrintX, g_sPlayer.nPrintY, g_sPlayerForm);
	}

	ScreenFlipping();
}

void Release()
{

}
