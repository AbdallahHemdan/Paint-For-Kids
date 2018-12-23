#include "SwitchToPlay.h"
#include "SaveAction.h"
#include <fstream>

SwitchToPlay::SwitchToPlay(ApplicationManager *pApp, int &mode) :Action(pApp)
{
	mode = 3;
}

void SwitchToPlay::ReadActionParameters()
{
	Output *pOut = pManager->GetOutput();
	pManager->set_LastMessage("Welcome to Play Mode");
}

void SwitchToPlay::Execute()
{
	Output *pOut = pManager->GetOutput();

	ReadActionParameters();

	pManager->set_selected(NULL);
	pManager->Unselect(NULL);

	pManager->CallSave();
}

SwitchToPlay::~SwitchToPlay()
{
}
