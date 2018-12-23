#include "Exit.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"SaveAction.h"
Exit::Exit(ApplicationManager *pApp, bool sound) : Action(pApp), Sound(sound)
{}

void Exit::ReadActionParameters()
{}

void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn  =pManager->GetInput();

	pOut->PrintMessage("Sure? You want to save your graph befor exit? if yes then write Y or any key to exit");
	string s = pIn->GetSrting(pOut);
	if(s == "Y" || s == "y")
	{
		ActionType pAct = SAVE;
		pManager->ExecuteAction(pAct);
	}
	else
	{
		pManager->set_LastMessage("We will miss you :(");
	}

	if (Sound)
		PlaySound(TEXT("Sounds\\Exit.wav"), NULL, SND_ASYNC);
}