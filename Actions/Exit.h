#pragma once
#include"Action.h"
class Exit : public Action
{
	bool Sound;
public:
	Exit(ApplicationManager *pApp, bool);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();
};

