#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H

#include "Action.h"
#include "..\Figures\CLine.h"
#include "..\ApplicationManager.h"

//Add Line Action class
class AddLineAction : public Action 
{
private:
	// Two Points Represent Line Corners
	Point P1, P2;
	bool Sound;
	int FilledOnce1;
	// Object of Graphical Struct ( Contain Fill,Drawing Color , Border Width )
	GfxInfo LineGfxInfo;
public:
	// Line Constructor
	AddLineAction(ApplicationManager *pApp, int, bool, int &);

	//Read Function to Read Line Parameters
	virtual void ReadActionParameters();

	//Execute Function To Add Line to the ApplicationManager
	virtual void Execute();
};

#endif