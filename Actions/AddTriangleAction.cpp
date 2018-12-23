#include "AddTriangleAction.h"

// Constructor For AddTriangle Class
AddTriangleAction::AddTriangleAction(ApplicationManager * pApp, int filled, bool sound, int &mode)
	:Action(pApp), FilledOnce1(filled), Sound(sound)
{
	mode = 1;
}

// Read Function To Read Actions Parameter 
void AddTriangleAction::ReadActionParameters(){

	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Print a Message For The User to Get First Corner Point
	pOut->PrintMessage("New Triangle: Click at first corner");

	if (Sound)
		PlaySound(TEXT("Sounds\\Triangle.wav"), NULL, SND_ASYNC);

	// Read First corner Point and Store in Point P1
	pIn->GetPointClicked(P1.x, P1.y);

	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong plce
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(P1.x, P1.y); //Get Pasting Point
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	// Print a Message For The User To Get Second Corner Point
	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read Second Corner and Store in Point P2
	pIn->GetPointClicked(P2.x, P2.y);

	if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong plce
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(P2.x, P2.y); //Get Pasting Point
			if (!(P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	// Print a Message To Get Third Corner Point
	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read The Third Corner Point and Store in Point P3
	pIn->GetPointClicked(P3.x, P3.y);
	
	if (P3.y < UI.StatusBarHeight || P3.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong plce
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(P3.x, P3.y); //Get Pasting Point
			if (!(P3.y < UI.StatusBarHeight || P3.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	if (FilledOnce1 == 0)
		TriangleGfxInfo.isFilled = false;
	else
		TriangleGfxInfo.isFilled = true;

	//Get Drawing, Filling Colors and Pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	// Clear Status Bar
	pOut->ClearStatusBar();
}

//Add Triangle to the ApplicationManager To Execute it 
void AddTriangleAction::Execute(){

	//This Action Needs to Read Some Parameters first
	ReadActionParameters();

	//Create a Triangle with the Parameters readed from the user
	CTriangle *T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add The Triangle to the list of figures
	pManager->AddFigure(T);

	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage(T->PrintInfo(pOut));
}
