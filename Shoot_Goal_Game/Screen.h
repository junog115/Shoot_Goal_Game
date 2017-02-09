#pragma once
#ifndef __SCREEN_H__
#define __SCREEN_H__

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(int x, int y, std::string strPrint);
void SetColor(unsigned short color);


#endif