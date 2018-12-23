#pragma once
#include "Action.h"
#include"..\ApplicationManager.h"

class Sound :
	public Action
{
	bool *ON_OR_OFF;
	ActionType PACT;
public:
	Sound(ApplicationManager *pApp, bool *);

	virtual void ReadActionParameters();
	virtual void Execute();

	~Sound();
};

