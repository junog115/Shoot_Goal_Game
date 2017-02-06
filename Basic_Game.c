#include <stdio.h>
#include <conio.h>

int g_nFrameCount;

void Init();
void KeyProcess(int nKey);
void Update();
void Render();
void Release();

int main(void)
{
	clock_t CurTime, OldTime;
	

	Init();			// 초기화

	while(1)
	{
		OldTime = clock();

		if(_kbhit())
		{
			KeyProcess(_getch())
		}

		Update();	// 데이터 갱신
		Render();	// 화면 출력
		while(1)
		{
			CurTime = clock();

			if( CurTime - OldTime > 33 )
			{
				break;
			} 
		}

		g_nFrameCount++;

	}

	Release();		// 해제

	return 0;
}

void Init()
{

}

void KeyProcess(int nKey)
{
	nKey = _getch();
	
	if(nKey == 'q')		// 게임 종료
	{
		break;
	}
	else
	{
		switch( nKey )
		{
			case "j":
				
				break;

			case "i":
				
				break;
		}
	}
}


void Update()
{

}
void Render()
{

}
void Release()
{

}


// 한 장면을 출력하는데 33millisecond 미만이면 대기 상태에 있게하고, 아니면 출력을 하도록 하게하면 된다. 
