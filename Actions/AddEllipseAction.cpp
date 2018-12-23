#include "AddEllipseAction.h"

// Costructor For AddEllipseAction Class 
AddEllipseAction::AddEllipseAction(ApplicationManager * pApp, int filled, bool sound, int &mode)
	:Action(pApp), FilledOnce1(filled), Sound(sound)
{
	mode = 1;
}

// Read Function To Read Actions Parameter 
void AddEllipseAction::ReadActionParameters(){

	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Print a Message To User To Get a Point Click 
	pOut->PrintMessage("New Ellipse: Click at Center");

	if (Sound)
		PlaySound(TEXT("Sounds\\Ellipse.wav"), NULL, SND_ASYNC);
	//Read center and store in center C
	pIn->GetPointClicked(C.x, C.y);

	if (C.y < UI.StatusBarHeight || C.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0; //false as long as the click is in wrong place
		pOut->PrintMessage("Please, Choose a valid place");
		while (!flag)
		{
			pIn->GetPointClicked(C.x, C.y); //Get Pasting Point
			if (!(C.y < UI.StatusBarHeight || C.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}

	if (FilledOnce1 == 0)
		EllipseGfxInfo.isFilled = false;
	else
		EllipseGfxInfo.isFilled = true;

	//Get Drawing, Filling Colors and Pen Width From The Interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	// Clear Status Bar 
	pOut->ClearStatusBar();
}

//Add Ellipse to the ApplicationManager To Execute it 
void AddEllipseAction::Execute()
{
	Output *pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create an Ellipse with the Parameters Read From The User
	CEllipse *E = new CEllipse(C, EllipseGfxInfo);

	//Add the Ellipse To The List of Figures
	pManager->AddFigure(E);
	pManager->set_LastMessage(E->PrintInfo(pOut));
}
