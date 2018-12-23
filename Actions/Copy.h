#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

class Copy : public Action
{
	CFigure *Copied;
	bool Sound;
public:
	Copy(ApplicationManager *pApp, CFigure *fig, int *, bool);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};