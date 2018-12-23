#include "ChangeColor.h"
#include "..\ApplicationManager.h"

// Constructor For Change Color Class To initalize The Class Data Members
ChangeColor::ChangeColor(ApplicationManager *pApp, CFigure **fig, int CFlag, int* drawORfill, int *Filledonce, int *mode) : Action(pApp), Selected(fig),
CFLAG(CFlag), DrawOrFill(drawORfill), FilledOnce(Filledonce)
{ 
	*mode = 2;
	Mode = mode;
}

// Read Action parameters To Read Actions Parameters
void  ChangeColor::ReadActionParameters() {

	// Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	// Print a Message To The User To Set a Color To Change The Figure Color
	pOut->PrintMessage("Please Select a Color To change The Figure ");
}

//Add Change Color to the ApplicationManager To Execute it 
void ChangeColor::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Donot Change UI.FillColor if line's DrawColor Change
	CLine *line = dynamic_cast<CLine *> (*Selected); 

	// Check If The User Successfully Select a Figure 
	if (*Selected != NULL)
	{
		if (CFLAG == 0)
		{
			ReadActionParameters();
			*DrawOrFill = 1;
		}
		else if (CFLAG == 10)
		{
			ReadActionParameters();
			*DrawOrFill = 2;
		}
		// Check If The Mode if Change Drawing Color
		else if (*DrawOrFill == 1)
		{
			// Change The Drawing Color To White
			if (CFLAG == 1)
			{
				(*Selected)->ChngDrawClr(WHITE);
				if(line)
					(*Selected)->ChngFillClr(WHITE);
				UI.DrawColor = WHITE;
			}

			// Change The Drawing Color To Black
			else if (CFLAG == 2)
			{
				(*Selected)->ChngDrawClr(BLACK);
				if (line)
					(*Selected)->ChngFillClr(BLACK);
				UI.DrawColor = BLACK;
			}

			// Change The Drawing Color To Red
			else if (CFLAG == 3)
			{
				(*Selected)->ChngDrawClr(RED);
				if (line)
					(*Selected)->ChngFillClr(RED);
				UI.DrawColor = RED;
			}

			// Change The Drawing Color To Green 
			else if (CFLAG == 4)
			{
				(*Selected)->ChngDrawClr(GREEN);
				if (line)
					(*Selected)->ChngFillClr(GREEN);
				UI.DrawColor = GREEN;
			}

			// Change The Drawing Color To Blue
			else if (CFLAG == 5)
			{
				(*Selected)->ChngDrawClr(BLUE);
				if (line)
					(*Selected)->ChngFillClr(BLUE);
				UI.DrawColor = BLUE;
			}
			pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
			(*Selected)->SetSelected(false);
			pManager->UpdateInterface();
		}
		// Check If The Mode if Change Filling Color
		else if (*DrawOrFill == 2) 
		{
			// Change The Filling Color To White
			if (CFLAG == 1) 
			{
				(*Selected)->ChngFillClr(WHITE);
				if (line)
					(*Selected)->ChngDrawClr(WHITE);
				UI.FillColor = WHITE;
			}

			// Change The Filling Color To Black
			else if (CFLAG == 2) 
			{
				(*Selected)->ChngFillClr(BLACK);
				if (line)
					(*Selected)->ChngDrawClr(BLACK);
				UI.FillColor = BLACK;
			}

			// Change The Filling Color To Red
			else if (CFLAG == 3)
			{
				(*Selected)->ChngFillClr(RED);
				if (line)
					(*Selected)->ChngDrawClr(RED);
				UI.FillColor = RED;
			}

			// Change The Filling Color To Green
			else if (CFLAG == 4)
			{
				(*Selected)->ChngFillClr(GREEN);
				if (line)
					(*Selected)->ChngDrawClr(GREEN);
				UI.FillColor = GREEN;
			}

			// Change The Filling Color To Blue
			else if (CFLAG == 5) {
				(*Selected)->ChngFillClr(BLUE);
				if (line)
					(*Selected)->ChngDrawClr(BLUE);
				UI.FillColor = BLUE;
			}
			*FilledOnce = 1;
			pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
			(*Selected)->SetSelected(false);
			pManager->UpdateInterface();
		}
		if (CFLAG != 10 && CFLAG != 0)
		{
			pIn->GetPointClicked(P.x, P.y);
			if (P.y < UI.ToolBarHeight)
			{
				if (P.x < UI.MenuItemWidth)
				{
					CFLAG = 1;
					pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
					Execute();
				}
				else if (P.x < UI.MenuItemWidth * 2)
				{
					CFLAG = 2;
					pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
					Execute();
				}
				else if (P.x < UI.MenuItemWidth * 3)
				{
					CFLAG = 3;
					pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
					Execute();
				}
				else if (P.x < UI.MenuItemWidth * 4)
				{
					CFLAG = 4;
					pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
					Execute();
				}
				else if (P.x < UI.MenuItemWidth * 5)
				{
					CFLAG = 5;
					pManager->set_LastMessage((*Selected)->PrintInfo(pOut));
					Execute();
				}
				else if (P.x < UI.MenuItemWidth * 6)
				{
					(*Selected)->setStored();
					pManager->set_selected(NULL);
					pManager->ExecuteAction(BACK);
					pManager->set_LastMessage("");
					return;
				}
			}
		}		
	}

	// Print A Message To The User To Ask Him To Check Selecting The Figure 
	else
	{
		pManager->set_LastMessage("Please Sure To Selecting a Figure");
		*Mode = 0;
	}
}

// Destructor Of Change Color Function
ChangeColor::~ChangeColor()
{}
