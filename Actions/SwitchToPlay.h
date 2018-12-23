#pragma once
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class SwitchToPlay : public Action
{
private:
	string FileName;

public:
	SwitchToPlay(ApplicationManager *, int &);

	virtual void ReadActionParameters();
	virtual void Execute();
	~SwitchToPlay();
};