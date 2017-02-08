#ifndef __SCREEN_H__
#define __SCREEN_H__

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint( int x, int y, char* string );
void SetColor( unsigned short color );


#endif