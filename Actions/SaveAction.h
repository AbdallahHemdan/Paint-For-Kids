#pragma once
#include"Action.h"
class SaveAction : public Action
{
private:
	string FileName;   
	int FigCnt;
public:
	SaveAction(ApplicationManager *pApp, int FigCount);
	virtual void ReadActionParameters();
	virtual void Execute();
	void SavePlayMode();
};

