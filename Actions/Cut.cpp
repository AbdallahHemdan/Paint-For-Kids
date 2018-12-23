#include "Cut.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Cut::Cut(ApplicationManager *pApp, CFigure *fig, int *flag, int *flag1, bool sound)
	: Action(pApp), cut(fig), SelectFlag(flag1), Sound(sound)
{
	if(*flag != 1)
		CutORCopy = *flag = 1;
	else 
		CutORCopy = 0;
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pManager->set_LastMessage("You Cut the Selected figure -/-");

	if (Sound)
		PlaySound(TEXT("Sounds\\Cut.wav"), NULL, SND_ASYNC);

}

void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (*SelectFlag == 1)
	{
		ReadActionParameters();
		if(CutORCopy == 1)
			cut->setStored();

		cut->ChngDrawClr(GREY);
		cut->ChngFillClr(GREY);

		pManager->set_Clipboard(cut);
	}
	else
		pManager->set_LastMessage("Firstly, Select a figure -_-");
}

Cut::~Cut()
{
}
