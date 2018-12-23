#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


class Delete :
	public Action
{
	bool Sound;
	CFigure* deleted;
public:

	Delete(ApplicationManager *, CFigure *, bool);
	virtual void ReadActionParameters();
	virtual void Execute();

	~Delete();

};

