#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Cut : public Action
{
	int *SelectFlag, CutORCopy;
	CFigure *cut;
	bool Sound;
	GfxInfo FigGfxInfo;
public:
	Cut(ApplicationManager *, CFigure *, int *, int *, bool);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};

