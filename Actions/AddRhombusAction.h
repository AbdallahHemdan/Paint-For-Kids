#ifndef ADD_RHOMBUS_ACTION_H
#define ADD_RHOMBUS_ACTION_H

#include "Action.h"
#include "..\Figures\CRhombus.h"
#include "..\ApplicationManager.h"

//Add Rectangle Action class
class AddRhombusAction : public Action
{
private:
	// Point Represent Rhombus Center 
	Point P1;
	bool Sound;
	int FilledOnce1;
	// Object of Graphical Struct ( Contain Fill,Drawing Color , Border Width )
	GfxInfo RhombusGfxInfo;
public:
	// Constructor For Add Rhombus Class
	AddRhombusAction(ApplicationManager *pApp, int, bool, int &);

	//Reads Rhombus Parameters
	virtual void ReadActionParameters();

	//Add Rhombus to the ApplicationManager
	virtual void Execute();
};

#endif