#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H


#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhombusAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\AddEllipseAction.h"

#include"Actions\SaveAction.h"
#include"Actions\SaveByType.h"
#include"Actions\LoadAction.h"

#include "GUI\Output.h"
#include "GUI\Input.h"
#include "GUI\UI_Info.h"

#include "Actions\PickType.h"
#include "Actions\PickColor.h"
#include "Actions\SwitchToDraw.h"
#include "Actions\SwitchToPlay.h"

#include "Actions\Delete.h"
#include"Actions\Exit.h"

#include <random>

#include "DEFS.h"

#include "Actions\ChangeColor.h"

#include"Actions\SelectAction.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"

#include "Actions\Sound.h"
#include <Windows.h>
#include <mmsystem.h>

#include "Actions\ResizeAction.h"
#include "Actions\Send_to_Back.h"
#include "Actions\Bring_to_Front.h"

#include "GUI\input.h"
#include "GUI\output.h"
#include "GUI\UI_Info.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int mode, PasteFlag, DORF, SelectFlag;
	float Resize_Factor;
	int FigCount, FilledOnce;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	string LastMessage;
	bool ON_OFF_SOUND;  // Sond Flag To check if The Sound is On Or Not

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	GfxInfo SelectGfxInfo;
	GfxInfo pickGfxInfo;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int, int) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output

	void UpdateInterface() const;	//Redraws all the drawing window

	void Loop(CFigure*);
	void Unselect(CFigure *);   //Unselect all figures except a paritcular figure
	void set_selected(CFigure *); //Setting Selected
	void set_Clipboard(CFigure *); // Setting Clipboard
	void set_LastMessage(string); // saving the last message
	int CntFig(ActionType); //get the type number of figures
	
	string ConvertToString(color c);   //Convert from Color Type to String Type
	color ConvertToColor(string s);

	void SaveFig(ofstream &Out);  //function to call Save Function for each figure
	void Save_By_Type(ActionType pAct, ofstream &Out); //function to call Save Function for each figure but for a particular type
	void LoadFig();  //clean the FigList
	void CallLoad();
	void CallSave();

	int RandomType(int &);
	int RandomColor(int &);

	void Resize();
	void Send_Back(CFigure*);
	void Bring_Front(CFigure*);
};

#endif