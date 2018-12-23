#pragma once
#include"Action.h"

#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include<fstream>

class SaveByType : public Action
{
private:
	string FileName;  
	ActionType pAct;  //we need to know which figure the yuser choosed
public:
	SaveByType(ApplicationManager *pApp);  // non-default constructor
	virtual void ReadActionParameters(); //read parameters from the user
	virtual void Execute(); //execute the action
};

