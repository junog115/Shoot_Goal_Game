#pragma once
#ifndef __SCREEN_H__
#define __SCREEN_H__

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(short x, short y, std::string strPrint);
void SetColor(unsigned short color);


#endif