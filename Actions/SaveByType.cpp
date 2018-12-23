#include "SaveByType.h"

SaveByType::SaveByType(ApplicationManager *pApp) : Action(pApp)
{
	FileName = "TEST_type";   //Default Name if the user failed to enter a valid name
}

void SaveByType::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();  //Pointer to OutPut
	Input* pIn = pManager->GetInput();     //Pointer ro Input

	pOut->PrintMessage("Please choose a figure from the figure bar");   
	pOut->CreateShapesBar();   //To choose a figure we need to display the Shapes Bar 
	pAct = pIn->GetUserAction();  //Get user choose
	if (pAct == BACK1) //Activation of Back Button
	{
		FileName = "";
		pOut->ClearStatusBar();
		return;
	}
	pOut->PrintMessage("Write file name, please");
	FileName = pIn->GetSrting(pOut);  // Get the file name
}

void SaveByType::Execute()
{
	ReadActionParameters();       //Read data

	if (FileName == "")
		return;

	ofstream OutFile; //Object of ofstream class to help us write on the disk
	Output* pOut = pManager->GetOutput(); 
	Input* pIn = pManager->GetInput();

	OutFile.open(FileName+".txt");  //open the file 
	bool flag = false;
	if(OutFile.fail())      //loop to check its a valid name
		flag = true;
	while(flag)
	{
		pOut->PrintMessage("Please write a valid name then press ENTER");
		FileName = pIn->GetSrting(pOut);
		OutFile.open(FileName+".txt");
		if(OutFile.good())
			flag = false;
	}
	OutFile << pManager->ConvertToString(UI.DrawColor) << "\t" << pManager->ConvertToString(UI.FillColor) << "\n"  //start writing with the current DrawColor
		<<pManager->CntFig(pAct)<<"\n";   // and FillColor the write the figure number of the same type
	pManager->Save_By_Type(pAct, OutFile);	//Now lets start the process of saving each figure
	pManager->set_LastMessage("Graph SAVED BY TYPE");  //Done!
	OutFile.close(); //Good By :)
}