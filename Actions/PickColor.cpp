#include "PickColor.h"


PickColor::PickColor(ApplicationManager *pApp) :Action(pApp)
{}

void PickColor::ReadActionParameters()
{
	//Get a Pointer to the Input Interfaces
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(P.x, P.y); //Get user's click
}

void PickColor::Execute()
{
	ActionType ActType;
	Output*pOut = pManager->GetOutput();
	Input*pIn = pManager->GetInput();

	Result = 0;
	pManager->CallLoad();

	int type = pManager->RandomColor(Result);

	if (type == 1)
		pManager->set_LastMessage("Pick all White shapes:> Let's GO ");
	else if (type == 2)
		pManager->set_LastMessage("Pick all Red shapes:> Let's GO ");
	else if (type == 3)
		pManager->set_LastMessage("Pick all Green shapes:> Let's GO ");
	else if (type == 4)
		pManager->set_LastMessage("Pick all blue shapes:> Let's GO ");
	else if (type == 5)
		pManager->set_LastMessage("Pick all black shapes:> Let's GO "); 
	else if (type == 0)
		pManager->set_LastMessage("Please Draw some Filled shapes ");

	pManager->UpdateInterface();

	if (type != 0)
	{
		int i, AllCounter = 0;
		int Res = Result;

		for (i = 0; i < 200;)
		{
			if (Result == 0)
				break;

			ReadActionParameters();

			if (P.y >= 0 && P.y <= UI.ToolBarHeight)
			{
				if (P.x < UI.MenuItemWidth)
					ActType = PICK_TYPE;
				else if (P.x < UI.MenuItemWidth * 2)
					ActType = PICK_COLOR;
				else if (P.x < UI.MenuItemWidth * 3)
					ActType = TO_DRAW;
				else if (P.x < UI.MenuItemWidth * 4)
					ActType = EXIT;
				else
					continue;
				pManager->ExecuteAction(ActType);
				return;
			}
			else if (P.y > UI.height - UI.StatusBarHeight)
				continue;

			picky = pManager->GetFigure(P.x, P.y);

			if (picky != NULL)
			{
				i++;

				picky->SetGfxInfo(pickGfxInfo);

				if (type == 1 && pickGfxInfo.FillClr == WHITE)
					Result--;
				else if (type == 2 && pickGfxInfo.FillClr == RED)
					Result--;
				else if (type == 3 && pickGfxInfo.FillClr == GREEN)
					Result--;
				else if (type == 4 && pickGfxInfo.FillClr == BLUE)
					Result--;
				else if (type == 5 && pickGfxInfo.FillClr == BLACK)
					Result--;

				pManager->Loop(picky);
				pManager->UpdateInterface();
				picky = NULL;
			}
			AllCounter++;
		}
		pManager->set_LastMessage(to_string(Res) + " Correct & " + to_string(AllCounter - Res) + " InCorrect");
	}
}
PickColor::~PickColor()
{
}

