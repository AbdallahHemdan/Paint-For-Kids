#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include "..\Figures\CRectangle.h"
#include "..\ApplicationManager.h"

// Add Rectangle Action class
class AddRectAction : public Action
{
private:
	// Two Point To Represent Rectangle Corners 
	Point P1, P2;
	bool Sound;
	int FilledOnce1;
	// Object of Graphical Struct ( Contain Fill, Drawing Color, Border Width )
	GfxInfo RectGfxInfo;
public:
	// Add Rect Action Constructor
	AddRectAction(ApplicationManager *pApp, int, bool, int &);

	// Reads Rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

#endif