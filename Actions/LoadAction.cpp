#include "LoadAction.h"
#include<fstream>
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\\Output.h"


LoadAction::LoadAction(ApplicationManager *pApp, int *mode) : Action(pApp)
{
	*mode = 0;
	Mode = mode;
}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();   //Get a pointer to the Output class
	Input* pIn = pManager->GetInput();     //Get a pointer to Input Class

	pOut->PrintMessage("Please write the file name :) ");
	FileName = pIn->GetSrting(pOut);     //get the file name
}

void LoadAction::Execute()
{
	ifstream InFile;         //object of ifstream class
	bool flag = false;
	Output* pOut = pManager->GetOutput();   //Point to OutPut
	Input* pIn = pManager->GetInput();      //Pointer to Input
	string name, DrawClr, FillClr;
	int Cnt;
	CFigure* fig;

	ReadActionParameters();   //read the inputs
	
	InFile.open(FileName+".txt"); //open the file on the disk with FileName name and .txt exetension
	pOut->ClearDrawArea();    //Clear current graph

	if (InFile.fail())       //Check if the FileName is a valid name
	{
		pManager->set_LastMessage("Invalid Name");
		return;
	}
	
	InFile>>DrawClr>>FillClr;     //Read the Current FillColor and DrawColor
	UI.DrawColor = pManager->ConvertToColor(DrawClr);  //Convert them
	UI.FillColor = pManager->ConvertToColor(FillClr);  //To Color type
	pManager->LoadFig();        //Delete The figure list
	InFile>>Cnt;    //read the Number of Figures
	while(Cnt)            //For each line on the file we will read it and determine its type
	{
		InFile>>name;

		if (name == "Rectangle")
			fig = new CRectangle;
		else if (name == "Line")
			fig = new CLine;
		else if (name == "Triangle")
			fig = new CTriangle;
		else if (name == "Ellipse")
			fig = new CEllipse;
		else if (name == "Rhombus")
			fig = new CRhombus;

		fig->Load(InFile);  //Now we created the object and we should load it
		pManager->AddFigure(fig); //Add to the figure list
		Cnt--; //decrease the count 
	}
	pManager->UpdateInterface();     //Draw the figure list
	pManager->set_LastMessage("Graph Loaded Successfully");
	pOut->ClearStatusBar(); 
	pOut->CreateStatusBar();
}

void LoadAction::LoadPlayMode()
{
	*Mode = 3;
	FileName = "PlayMode";

	Output* pOut = pManager->GetOutput();
	ifstream InFile;         //object of ifstream class
	string DrawClr, FillClr, name;
	int Cnt;
	CFigure* fig;

	InFile.open(FileName + ".txt"); //open the file on the disk with FileName name and .txt exetension
	InFile >> DrawClr >> FillClr;     //Read the Current FillColor and DrawColor
	UI.DrawColor = pManager->ConvertToColor(DrawClr);  //Convert them
	UI.FillColor = pManager->ConvertToColor(FillClr);  //To Color type
	pManager->LoadFig();        //Delete The figure list
	InFile >> Cnt;    //read the Number of Figures
	
	while (Cnt)            //For each line on the file we will read it and determine its type
	{
		InFile >> name;

		if (name == "Rectangle")
			fig = new CRectangle;
		else if (name == "Line")
			fig = new CLine;
		else if (name == "Triangle")
			fig = new CTriangle;
		else if (name == "Ellipse")
			fig = new CEllipse;
		else if (name == "Rhombus")
			fig = new CRhombus;

		fig->Load(InFile);  //Now we created the object and we should load it
		pManager->AddFigure(fig); //Add to the figure list
		Cnt--; //decrease the count 
	}
	pManager->UpdateInterface();     //Draw the figure list
}