#include "PickType.h"

PickType::PickType(ApplicationManager *pApp) :Action(pApp)
{}

void PickType::ReadActionParameters()
{
	//Get a Pointer to the Input Interfaces
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(P.x, P.y); //Get user's click
}

void PickType::Execute()
{
	ActionType ActType;
	Output*pOut = pManager->GetOutput();
	Input*pIn = pManager->GetInput();

	Result = 0;
	pManager->CallLoad();

	int type = pManager->RandomType(Result);

	if (type == 1)
		pManager->set_LastMessage("Pick all Lines:> Let's GO ");
	else if (type == 2)
		pManager->set_LastMessage("Pick all Rectangles:> Let's GO ");
	else if (type == 3)
		pManager->set_LastMessage("Pick all Rhombuses:> Let's GO ");
	else if (type == 4)
		pManager->set_LastMessage("Pick all Ellipses:> Let's GO ");
	else if (type == 5)
		pManager->set_LastMessage("Pick all Triangles:> Let's GO ");
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
				CLine* line = dynamic_cast<CLine*>(picky);
				CRectangle* rect = dynamic_cast<CRectangle*>(picky);
				CRhombus* rho = dynamic_cast<CRhombus*>(picky);
				CEllipse* elli = dynamic_cast<CEllipse*>(picky);
				CTriangle* tri = dynamic_cast<CTriangle*>(picky);

				if (line != NULL&&type == 1)
					Result--;
				else if (rect != NULL&&type == 2)
					Result--;
				else if (rho != NULL&&type == 3)
					Result--;
				else if (elli != NULL&&type == 4)
					Result--;
				else if (tri != NULL&&type == 5)
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
PickType::~PickType()
{
}
