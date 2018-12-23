#include "AddLineAction.h"

// The Implementation of Add Line Action 
AddLineAction::AddLineAction(ApplicationManager * pApp, int filled, bool sound, int &mode)
	:Action(pApp), FilledOnce1(filled), Sound(sound)
{
	mode = 1;
}

// Read Function To Read Actions Parameter
void AddLineAction::ReadActionParameters() {

	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Print a Message To User To Get The First Point Click
	pOut->PrintMessage("New Line: Click at first point");

	if (Sound)
		PlaySound(TEXT("Sounds\\Line.wav"), NULL, SND_ASYNC);

	//Read The First Point and Store in Point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0; //false as long as the click is in wrong place
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	// Print a Message To User To Get The Second Point Click
	pOut->PrintMessage("New Line: Click at Second point");

	//Read The Second point and store in Point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0; //false as long as the click is in wrong place
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(P2.x, P2.y); //Get Pasting Point
			if (!(P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}

	//Get Drawing Colors and Pen Width From the Interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();

	// Clear Status Bar
	pOut->ClearStatusBar();
}

//Add Line to the ApplicationManager To Execute it
void AddLineAction::Execute() {

	//This Action Needs to Read some Parameters First
	ReadActionParameters();

	LineGfxInfo.isFilled = false;
	LineGfxInfo.FillClr = BLUE;

	//Create a Line With the Parameters Read From The User
	CLine *L = new CLine(P1, P2, LineGfxInfo);

	//Add The Line to The List of Figures
	pManager->AddFigure(L);

	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage(L->PrintInfo(pOut));
}
