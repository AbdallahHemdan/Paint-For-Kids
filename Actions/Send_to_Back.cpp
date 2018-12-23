#include "Send_to_Back.h"

// Constructor of AddEllipse Action Class
Send_to_Back::Send_to_Back(ApplicationManager *pApp, CFigure* s) : Action(pApp), Selected(s)
{}

//Read Function to Read Ellipse parameters
void Send_to_Back::ReadActionParameters()
{}

//Add Ellipse to the ApplicationManager To Execute it 
void Send_to_Back::Execute()
{
	Output *pOut = pManager->GetOutput();
	if (Selected != NULL)
	{
		pManager->Send_Back(Selected);
		pManager->set_LastMessage("Sent to Back");
	}
	else
		pManager->set_LastMessage("Please, Select a figure");

}