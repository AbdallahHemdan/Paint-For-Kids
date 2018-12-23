#ifndef ADD_TRIANGLE_ACTION_H
#define ADD_TRIANGLE_ACTION_H

#include "Action.h"

#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"

//Add Triangle Action class
class AddTriangleAction : public Action
{
private:
	// Three Points Represent Triangle Corners
	Point P1, P2, P3;
	bool Sound;
	int FilledOnce1;
	// Object of Graphical Struct ( Contain Fill,Drawing Color , Border Width )
	GfxInfo TriangleGfxInfo;
public:
	// Constructor For Add Triangel Class 
	AddTriangleAction(ApplicationManager *pApp, int, bool, int &);

	//Reads Triangle Parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif