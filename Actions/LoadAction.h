#pragma once
#include "Action.h"
class LoadAction : public Action
{
private:
	string FileName;                  //We need a name to create a file on the disk
	int *Mode;
public:
	
	LoadAction(ApplicationManager *pApp, int *);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();
	void LoadPlayMode();
};

