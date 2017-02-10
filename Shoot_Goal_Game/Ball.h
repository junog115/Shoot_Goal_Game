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
	int nTryShoot;
	// 공의 모양
	std::string sBallForm;

public:
	Ball()
	{
		IsReady = true;
		nMoveX = 20;
		nMoveY = 19;
		MoveTime = 100;
		sBallForm = "◎";
		nTryShoot = 0;
	}

	void SetBallPosition(Player MainPlayer);
	void DownBallSpeed(clock_t Speed);
	void PrintBall(void);
	void ShootBall(void);
	int GetBallX(void);
	int GetBallY(void);
	int GetTryShoot(void);
	bool GetIsReady(void);
	void ResetTryNumber(void);
	void Reset(void);
};


#endif