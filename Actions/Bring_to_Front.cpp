#include "Bring_to_Front.h"

// Constructor of AddEllipse Action Class
Bring_to_Front::Bring_to_Front(ApplicationManager *pApp, CFigure* s) : Action(pApp), Selected(s)
{}

//Read Function to Read Ellipse parameters
void Bring_to_Front::ReadActionParameters()
{}

//Add Ellipse to the ApplicationManager To Execute it 
void Bring_to_Front::Execute()
{
	Output *pOut = pManager->GetOutput();
	if (Selected != NULL)
	{
		pManager->Bring_Front(Selected);
		pOut->PrintMessage("Bring to Front");
		pManager->set_LastMessage("Brought to Front");
	}
	else
	{
		pOut->PrintMessage("Please, Select a figure");
		pManager->set_LastMessage("Please, Select a figure");
	}
}