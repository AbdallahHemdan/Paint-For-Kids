#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class Paste : public Action
{
	int PasteFlag, *SelectFlag;
	Point P;
	bool Sound;
	CFigure *pasted;
	GfxInfo FigGfxInfo;
public:
	Paste(ApplicationManager *, CFigure *, int, int *, bool);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Paste();
};

