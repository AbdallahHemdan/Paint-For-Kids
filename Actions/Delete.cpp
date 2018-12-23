#include "Delete.h"

Delete::Delete(ApplicationManager *pApp, CFigure *fig, bool sound) :Action(pApp), deleted(fig), Sound(sound)
{}

void  Delete::ReadActionParameters() 
{}

void Delete::Execute() {
	Output* pOut = pManager->GetOutput();
	if (deleted != NULL)
	{
		pManager->set_selected(NULL);

		pManager->Loop(deleted);
		pManager->set_LastMessage("Deleted");
		deleted = NULL;
	}
	else
		pManager->set_LastMessage("Please Check to Select a figure");

	if (Sound)
		PlaySound(TEXT("Sounds\\Delete.wav"), NULL, SND_ASYNC);
}

Delete::~Delete()
{
}
