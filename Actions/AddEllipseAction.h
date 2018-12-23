#ifndef ADD_ELLIPSE_ACTION_H
#define ADD_ELLIPSE_ACTION_H

#include "Action.h"
#include "..\Figures\CEllipse.h"
#include "..\ApplicationManager.h"

// Add Ellipse Action class
class AddEllipseAction : public Action
{
private:
	// A Point For Ellipse Center
	Point C;
	bool Sound;
	int FilledOnce1;
	// Object of Graphical Struct ( Contain Fill,Drawing Color , Border Width )
	GfxInfo EllipseGfxInfo;
public:
	// Constructor of AddEllipse Action Class
	AddEllipseAction(ApplicationManager *pApp, int, bool, int &);

	//Read Function to Read Ellipse parameters
	virtual void ReadActionParameters();

	//Add Ellipse to the ApplicationManager To Execute it 
	virtual void Execute();

};

#endif