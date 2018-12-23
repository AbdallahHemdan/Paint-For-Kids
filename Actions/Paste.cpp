#include "Paste.h"

#include "..\ApplicationManager.h"

#include "AddRectAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Paste::Paste(ApplicationManager *pApp, CFigure *fig, int flag, int *flag1, bool sound)
	: Action(pApp), pasted(fig), PasteFlag(flag), SelectFlag(flag1), Sound(sound)
{}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose a Point to Paste in -;-");

	if (Sound)
		PlaySound(TEXT("Sounds\\Paste.wav"), NULL, SND_ASYNC);

	pIn->GetPointClicked(P.x, P.y); // get Pasting Point
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (*SelectFlag == 1 && (PasteFlag == 0 || PasteFlag == 1))
	{
		ReadActionParameters();

		if (P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight)
		{
			bool flag = false; //false as long as the click is in wrong plce
			pOut->PrintMessage("Please, Choose a valid place");
			while (!flag)
			{
				pIn->GetPointClicked(P.x, P.y); //Get Pasting Point
				if (!(P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight))
					flag = 1;
			}
		}
		pOut->ClearStatusBar();

		Point P2, P3;

		CRectangle *rect = dynamic_cast<CRectangle *> (pasted);
		CLine *line = dynamic_cast<CLine *> (pasted);
		CRhombus *rho = dynamic_cast<CRhombus *> (pasted);
		CTriangle *tri = dynamic_cast<CTriangle *> (pasted);
		CEllipse *elli = dynamic_cast<CEllipse *> (pasted);

		if (rect != NULL)
		{
			rect->SetGfxInfo(FigGfxInfo);
			P2 = rect->D_B_P(P, pOut);
			
			//Create a rectangle with the parameters read from the user
			CRectangle *rect1 = new CRectangle(P, P2, FigGfxInfo);

			if (PasteFlag == 0)
				pManager->AddFigure(rect1);
			else if (PasteFlag == 1)
			{
				swap(*rect, *rect1);
				delete rect1;
				rect = NULL;
				pManager->set_Clipboard(NULL);
				pManager->set_selected(NULL);
			}
		}
		else if (line != NULL)
		{
			P2 = line->D_B_P(P, pOut);
			line->SetGfxInfo(FigGfxInfo);
			//Create a line with the parameters read from the user
			CLine *line1 = new CLine(P, P2, FigGfxInfo);

			if (PasteFlag == 0)
				pManager->AddFigure(line1);
			else if (PasteFlag == 1)
			{
				swap(*line, *line1);
				delete line1;
				line = NULL;
				pManager->set_Clipboard(NULL);
				pManager->set_selected(NULL);
			}
		}
		else if (tri != NULL)
		{
			Point *P23;
			P23 = tri->D_B_P(P, pOut);
			P2 = P23[0];	P3 = P23[1];
			tri->SetGfxInfo(FigGfxInfo);
			//Create a triangle with the parameters read from the user
			CTriangle *tri1 = new CTriangle(P, P2, P3, FigGfxInfo);

			if (PasteFlag == 0)
				pManager->AddFigure(tri1);
			else if (PasteFlag == 1)
			{
				swap(*tri, *tri1);
				delete tri1;
				tri = NULL;
				pManager->set_Clipboard(NULL);
				pManager->set_selected(NULL);
			}
		}
		else if (rho != NULL)
		{
			rho->SetGfxInfo(FigGfxInfo);
			//Create a rhombus with the parameters read from the user
			CRhombus *rho1 = new CRhombus(P, FigGfxInfo);
			rho1->Draw(pOut);
			if (PasteFlag == 0)
				pManager->AddFigure(rho1);
			else if (PasteFlag == 1)
			{
				swap(*rho, *rho1);
				delete rho1;
				rho = NULL;
				pManager->set_Clipboard(NULL);
				pManager->set_selected(NULL);
			}
		}
		else if (elli != NULL)
		{
			elli->SetGfxInfo(FigGfxInfo);
			//Create a ellipse with the parameters read from the user
			CEllipse *elli1 = new CEllipse(P, FigGfxInfo);
	
			elli1->Draw(pOut);

			if (PasteFlag == 0)
				pManager->AddFigure(elli1);
			else if (PasteFlag == 1)
			{
				swap(*elli, *elli1);
				delete elli1;
				elli = NULL;
				pManager->set_Clipboard(NULL);
				pManager->set_selected(NULL);
			}
		}
		if (PasteFlag == 1)
			*SelectFlag = 2;
	}
	else
	{
		pManager->set_LastMessage("Firstly, Select a figure -_-");
		if (Sound)
			PlaySound(TEXT("Sounds\\Paste.wav"), NULL, SND_ASYNC);
	}

}

Paste::~Paste()
{
}
