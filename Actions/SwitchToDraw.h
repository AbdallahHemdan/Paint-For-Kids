#pragma once
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class SwitchToDraw : public Action
{
private:
	string FileName;
	int *Mode;
public:
	SwitchToDraw(ApplicationManager *, int *);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToDraw();
};