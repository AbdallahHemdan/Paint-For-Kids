#pragma once
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"



class PickType : public Action
{
	CFigure *picky;
	Point P;
	int Result;

public:
	PickType(ApplicationManager *);

	virtual void ReadActionParameters();
	virtual void Execute();
	~PickType();
};

