#pragma once
#include "Action.h"
#include "..\\ApplicationManager.h"

class Send_to_Back : public Action
{
	CFigure *Selected;
public:
	// Constructor of AddEllipse Action Class
	Send_to_Back(ApplicationManager *pApp, CFigure*);

	//Read Function to Read Ellipse parameters
	virtual void ReadActionParameters();

	//Add Ellipse to the ApplicationManager To Execute it 
	virtual void Execute();
};

