#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"

int g_nFrameCounter = 0;
int g_nCurFrame = 0;
char g_sCurFrame[5];
clock_t curTime, oldTime;

void Init();
void Update();
void Render();
void Release();

int main(void)
{
	ScreenInit();
	Init();			// 초기화

	oldTime = clock();

	while (1)
	{
		Update();	// 데이터 갱신

		Render();	// 화면 출력


	}

	Release();		// 해제
	ScreenRelease();

	return 0;
}

void Init()
{

}

void Update()
{
	curTime = clock();
	if ((curTime - oldTime) >= 1000)
	{
		g_nCurFrame = g_nFrameCounter;
		g_nFrameCounter = 0;

		oldTime = curTime;
	}
	g_nFrameCounter++;
}
void Render()
{
	ScreenClear();
	// 출력 코드

	itoa(g_nCurFrame, g_sCurFrame, 10);
	ScreenPrint(5, 5, g_sCurFrame);

	ScreenFlipping();
}
void Release()
{

}

