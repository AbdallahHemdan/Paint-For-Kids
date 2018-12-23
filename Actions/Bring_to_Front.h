#pragma once
#include "Action.h"
#include "..\\ApplicationManager.h"

class Bring_to_Front : public Action
{
	CFigure *Selected;
public:
	// Constructor of AddEllipse Action Class
	Bring_to_Front(ApplicationManager *pApp, CFigure*);

	//Read Function to Read Ellipse parameters
	virtual void ReadActionParameters();

	//Add Ellipse to the ApplicationManager To Execute it 
	virtual void Execute();
};

