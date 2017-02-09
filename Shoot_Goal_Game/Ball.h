#ifndef __BALL_H__
#define __BALL_H__

class Ball
{
	// 공의 상태 (준비, 슛)	
	// 이동 좌표			
	// 이동 시간 간격		
	// 이전 이동 시간
	bool IsReady;	// true = 준비, false = 발사 중
	int nMoveX;
	int nMoveY;
	clock_t MoveTime;
	clock_t OldTime;

	// 공의 모양
	std::string sBallForm = "◎";

public:
	Ball()
	{
		IsReady = true;
		nMoveX = 20;
		nMoveY = 19;
		MoveTime = 100;
	}

	void SetBallPosition(Palyer MainPlayer);
	void PrintBall(void);
	void ShootBall(void);

};


#endif