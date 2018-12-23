#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp, int *flag, int *flag1, GfxInfo *SelGfxInfo, bool sound)
		: Action(pApp), SelectFlag(flag), PasteFlag(flag1), SelectGfxInfo(SelGfxInfo), Sound(sound)
{}
void SelectAction::ReadActionParameters()
{
	//We need a pointer to the input and output class as a reference
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (Sound)
		PlaySound(TEXT("Sounds\\Select.wav"), NULL, SND_ASYNC);

	//select a point on the figure wanted
	pOut->PrintMessage("Select a figure ^_^ ");

	pIn->GetPointClicked(P.x, P.y);

}
void SelectAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = false; //false as long as the click is in wrong place
		pOut->PrintMessage("Please, Choose a valid Point");
		while (!flag)
		{
			pIn->GetPointClicked(P.x, P.y); //Get Pasting Point
			if (!(P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}
	}
	pOut->ClearStatusBar();

	CFigure* fig = pManager->GetFigure(P.x, P.y);
	
	pManager->set_Clipboard(NULL);

	if(fig != NULL)
	{
		if (fig->IsSelected())
		{
			fig->SetSelected(false);
			pManager->set_selected(NULL);
			*SelectFlag = 2;     
			if (*PasteFlag == 1)
			{
				fig->ChngDrawClr(SelectGfxInfo->DrawClr);
				fig->ChngFillClr(SelectGfxInfo->FillClr);
			}
		}
		else
		{
			pManager->set_LastMessage(fig->PrintInfo(pOut));
			fig->SetSelected(true);
			pManager->set_selected(fig);
			*SelectFlag = 1;
		}
		pManager->Unselect(fig);
		fig->assignStored();
	}
	else
	{
		pManager->set_LastMessage("No Shape to be selected");
		pManager->Unselect(fig);
		pManager->set_selected(NULL);
	}	
}
