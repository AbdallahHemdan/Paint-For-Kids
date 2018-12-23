#include "AddRectAction.h"

// Costructor For AddRectAction Class 
AddRectAction::AddRectAction(ApplicationManager * pApp, int filled, bool sound, int &mode)
	:Action(pApp), FilledOnce1(filled), Sound(sound)
{
	mode = 1;
}

// Read Function to Read Parameters From The User
void AddRectAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Print a Message To User To Get a First Point Click
	pOut->PrintMessage("New Rectangle: Click at first corner");

	if(Sound)
		PlaySound(TEXT("Sounds\\Rectangle.wav"), NULL, SND_ASYNC);

	//Read First Corner Point and Store in Point P1
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

	// Print a Message To User To Get a Second Point Click
	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read The Second Corner and Store in point P2
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

	if (FilledOnce1 == 0)
		RectGfxInfo.isFilled = false;
	else
		RectGfxInfo.isFilled = true;

	//Get Drawing, Filling Colors and Pen Width From The Interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	// Clear Status Bar
	pOut->ClearStatusBar();
}

//Execute Function To Add Rect to the ApplicationManager To Execute it
void AddRectAction::Execute()
{
	//This Action Needs to Read Some Parameters First
	ReadActionParameters();

	//Create a Rectangle with the Parameters Read from the user
	CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);

	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage(R->PrintInfo(pOut));
}
