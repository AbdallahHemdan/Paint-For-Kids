#pragma once
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class PickColor : public Action
{
	CFigure *picky;
	Point P;
	GfxInfo pickGfxInfo;
	int Result;

public:
	PickColor(ApplicationManager *);

	virtual void ReadActionParameters();
	virtual void Execute();
	~PickColor();
};

