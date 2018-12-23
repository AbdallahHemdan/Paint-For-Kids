#pragma once
#include"Action.h"

#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"

class SelectAction : public Action
{
private:
	Point P;
	int *SelectFlag, *PasteFlag;
	bool Sound;
	GfxInfo *SelectGfxInfo;
public:
	SelectAction(ApplicationManager* pApp, int *, int *, GfxInfo *, bool);
	virtual void ReadActionParameters();
	virtual void Execute();

};

