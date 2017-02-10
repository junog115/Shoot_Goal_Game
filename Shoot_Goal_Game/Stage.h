#pragma once

class Stage
{
	int nStage;
	int nHit;

public:
	Stage()
	{
		nStage = 1;
		nHit = 0;
	}

	void UpHitNumber(void);
	void ReSetHitNumber(void);
	int GetHitNumber(void);
	int GetStageNumber(void);
	void Stage::ChangeNextStage(Ball &PlayerBall, Target &PlayerTarget);
	void Reset(void);
};
