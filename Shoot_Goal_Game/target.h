#ifndef __TARGET_H__
#define __TARGET_H__

class Target
{
	int nPrintX, nPrintY;
	bool bTargetDirection;	// true : 좌, false : 우 
	int nTargetLength;
	clock_t MoveTime;
	clock_t	OldTime;

	std::string sTargetForm;

public:
	Target()
	{
		bTargetDirection = true;
		nPrintX = 10;
		nPrintY = 3;
		MoveTime = 200;
		OldTime = clock();
		sTargetForm = "□-----------□";
		nTargetLength = sTargetForm.length();
	}

	void MoveTarget(void);
	void PrintTarget(void);
	void UpTargetSpeed(clock_t Speed);
	void DownTargetSize(int nSize);
	bool IsAttackTarget(Ball Attacker);
	void Reset(void);

};

#endif