#include "Copy.h"

Copy::Copy(ApplicationManager *pApp, CFigure *fig, int *flag, bool sound) : Action(pApp), Copied(fig), Sound(sound)
{
	*flag = 0;
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();

	pManager->set_LastMessage("You have Copied the selected figure -;-");

	if (Sound)
		PlaySound(TEXT("Sounds\\Copy.wav"), NULL, SND_ASYNC);

}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	if (Copied != NULL)
	{
		ReadActionParameters();

		pManager->set_Clipboard(Copied);

		Copied->assignStored();
	}
	else
		pManager->set_LastMessage("Firstly, Selecte a figure -_-");
}


Copy::~Copy()
{
}
