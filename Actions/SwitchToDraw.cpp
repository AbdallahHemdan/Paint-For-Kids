#include "SwitchToDraw.h"
#include "LoadAction.h"
#include <fstream>

SwitchToDraw::SwitchToDraw(ApplicationManager *pApp, int *mode) :Action(pApp)
{
	*mode = 0;
	Mode = mode;
}

void SwitchToDraw::ReadActionParameters()
{
	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage("Welcome to Draw Mode");
}

void SwitchToDraw::Execute()
{
	Output *pOut = pManager->GetOutput();

	ReadActionParameters();
	
	pManager->CallLoad();
	*Mode = 0;
}

SwitchToDraw::~SwitchToDraw()
{
}
