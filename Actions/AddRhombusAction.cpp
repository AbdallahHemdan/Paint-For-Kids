#include "AddRhombusAction.h"

// Implementation of Constructor of AddRhomBus Class  
AddRhombusAction::AddRhombusAction(ApplicationManager * pApp, int filled, bool sound, int &mode)
	:Action(pApp), FilledOnce1(filled), Sound(sound)
{
	mode = 1;
}

// Read Function to Read Parameters From The User
void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Print a Message To the User To Get Center Point 
	pOut->PrintMessage("New Rhombus: Click at center");

	if (Sound)
		PlaySound(TEXT("Sounds\\Rhombus.wav"), NULL, SND_ASYNC);

	//Read The Center Point 
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

	if (FilledOnce1 == 0)
		RhombusGfxInfo.isFilled = false;
	else
		RhombusGfxInfo.isFilled = true;

	//Get Drawing, Filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	// Clear Status Bar
	pOut->ClearStatusBar();

}

//Add Rhombus to the ApplicationManager To Execute it 
void AddRhombusAction::Execute(){

	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *Rh = new CRhombus(P1, RhombusGfxInfo);

	//Add the Rhombus to the List of figures
	pManager->AddFigure(Rh);

	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage(Rh->PrintInfo(pOut));
}
