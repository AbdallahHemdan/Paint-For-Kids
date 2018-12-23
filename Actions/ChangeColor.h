#pragma once

#include "Action.h"
#include"..\Figures\CFigure.h"

class ChangeColor :public Action{

private:
	// Pointer To Selected Figure 
	CFigure **Selected;
	Point P; // To change the colors as long as Color Bar is Opened

	// Flag To Check The Color Mode ( Red,Green,....)
	// Flag Pointer To Check The Mode ( Drawing , Filling )
	int CFLAG, *DrawOrFill, *FilledOnce, *Mode;
public:
	// Constructor For The Change Color Class 
	ChangeColor(ApplicationManager *pApp, CFigure **, int, int*, int*, int *);

	// ReafThe Action Parameters
	virtual void ReadActionParameters();

	//Add Change Color to the ApplicationManager
	virtual void Execute();

	// Change Color Destructor
	~ChangeColor();
};

