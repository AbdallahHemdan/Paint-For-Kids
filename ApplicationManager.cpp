#include "ApplicationManager.h"

//Constructor
ApplicationManager::ApplicationManager() : mode(0), PasteFlag(2), SelectFlag(2)
{
	UI.Sound = 1;
	FilledOnce = 0;
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	ON_OFF_SOUND = 1;

	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case SELECT:
			pAct = new SelectAction(this, &SelectFlag, &PasteFlag, &SelectGfxInfo, ON_OFF_SOUND);
			break;

		case COPY:
			pAct = new Copy(this, SelectedFig, &PasteFlag, ON_OFF_SOUND);
			break;

		case CUT:
			pAct = new Cut(this, SelectedFig, &PasteFlag, &SelectFlag, ON_OFF_SOUND);
			break;

		case PASTE:
			pAct = new Paste(this, Clipboard, PasteFlag, &SelectFlag, ON_OFF_SOUND);
			break;

		case SAVE:
			pAct = new SaveAction(this, FigCount);
			break;

		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;

		case LOAD:
			pAct = new LoadAction(this, &mode); // 0
			break;

		case PICK_TYPE:
			pAct = new PickType(this);
			break;

		case PICK_COLOR:
			pAct = new PickColor(this);
			break;

		case TO_FIGURE:
			mode = 1; set_LastMessage("");
			break;

		case TO_PLAY:
			pAct = new SwitchToPlay(this, mode); // 3
			break;

		case TO_DRAW:
			pAct = new SwitchToDraw(this, &mode); // 0
			break;

		case TO_SIZE:
			mode = 4;
			break;

		case DRAW_RECT:
			pAct = new AddRectAction(this, FilledOnce, ON_OFF_SOUND, mode); // 1
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this, FilledOnce, ON_OFF_SOUND, mode); // 1
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this, FilledOnce, ON_OFF_SOUND, mode); // 1
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this, FilledOnce, ON_OFF_SOUND, mode); // 1
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this, FilledOnce, ON_OFF_SOUND, mode); // 1
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChangeColor(this, &SelectedFig, 0, &DORF, &FilledOnce, &mode); // 2
			break;

		case CHNG_FILL_CLR:
			pAct = new ChangeColor(this, &SelectedFig, 10, &DORF, &FilledOnce, &mode); // 2
			break;

		case WHITE1:
			pAct = new ChangeColor(this, &SelectedFig, 1, &DORF, &FilledOnce, &mode);
			break;

		case BLACK1:
			pAct = new ChangeColor(this, &SelectedFig, 2, &DORF, &FilledOnce, &mode);
			break;

		case RED1:
			pAct = new ChangeColor(this, &SelectedFig, 3, &DORF, &FilledOnce, &mode);
			break;

		case GREEN1:
			pAct = new ChangeColor(this, &SelectedFig, 4, &DORF, &FilledOnce, &mode);
			break;

		case BLUE1:
			pAct = new ChangeColor(this, &SelectedFig, 5, &DORF, &FilledOnce, &mode);
			break;

		case BACK: case BACK1: case BACK2:
			mode = 0;
			break;

		case DELETE1:
			pAct = new Delete(this, SelectedFig, ON_OFF_SOUND);
			break;

		case SOUND:
			pAct = new Sound(this, &ON_OFF_SOUND);
			break;

		case RESIZE:
			pAct = new ResizeAction(this, SelectedFig);
			break;

		case SEND_TO_BACK:
			pAct = new Send_to_Back(this, SelectedFig);
			break;

		case BRING_TO_FRONT:
			pAct = new Bring_to_Front(this, SelectedFig);
			break;

		case EXIT:
			pAct = new Exit(this, ON_OFF_SOUND);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
		FigList[FigCount] = pFig;
		FigList[FigCount]->SetID(FigCount+1); //set the ID of wach figure because we need it on saving figure
		FigCount++;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for(int i = FigCount - 1; i >= 0; i--)
		if (FigList[i]->InFig(x, y))
		{
			FigList[i]->PrintInfo(pOut);
			return FigList[i];
		}
	return NULL;
}

void ApplicationManager::set_selected(CFigure* fig)   //set the selcted figure. We need it on copy, cut, paste and delete actions
{
	SelectedFig = fig;
}

void ApplicationManager::set_Clipboard(CFigure *clip) //the clipboard to store on it figures temporary
{
	Clipboard = clip;
}

void ApplicationManager::set_LastMessage(string s)
{
	LastMessage = s;
}

void ApplicationManager::Unselect(CFigure *fig)  // Select the last figures ONLY
{
	for (int i = 0; i<FigCount; ++i)
		if (FigList[i] != fig)
		{
			FigList[i]->SetSelected(false);
			FigList[i]->assignStored();
		}
}

void ApplicationManager::SaveFig(ofstream &Out)   //Call the Save function for each Figure
{
	set_selected(NULL);
	Unselect(NULL);
	for(int i=0; i<FigCount; ++i)
		FigList[i]->Save(Out);
}

string ApplicationManager::ConvertToString(color c)   //Convert from Color Type to String Type
{
	if(c==BLACK) return "BLACK";
	else if(c==WHITE) return "WHITE";
	else if(c==BLUE) return "BLUE";
	else if(c==RED) return "RED";
	else if(c==YELLOW) return "YELLOW";
	else if(c==GREEN) return "GREEN";
	else if(c==LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	else if(c==MAGENTA) return "MAGENTA";
	else if(c==TURQUOISE) return "TURQUOISE";
	return "COLOR";
}

color ApplicationManager::ConvertToColor(string s)
{
	if (s == "BLACK")
		return BLACK;
	if (s == "BLUE")
		return BLUE;
	if (s == "WHITE")
		return WHITE;
	if (s == "RED")
		return RED;
	if (s == "YELLOW")
		return YELLOW;
	if (s == "GREEN")
		return GREEN;
	if (s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if (s == "MAGENTA")
		return MAGENTA;
	if (s == "TURQUOISE")
		return TURQUOISE;
	return BLACK;
}

void ApplicationManager::CallLoad()
{
	LoadAction load(this, &mode);
	load.LoadPlayMode();
}

void ApplicationManager::CallSave()
{
	SaveAction save(this, FigCount);
	save.SavePlayMode();
}

void ApplicationManager::Save_By_Type(ActionType pAct, ofstream &Out) //Examine the type of the Action and according to it
{                                                                     //Cal the Save Function
	switch(pAct)
	{
	case DRAW_LINE:
		for(int i=0; i<FigCount; ++i)
			if(dynamic_cast<CLine*> (FigList[i]) != NULL)
				FigList[i]->Save(Out);
		break;

	case DRAW_RECT:
		for(int i=0; i<FigCount; ++i)
			if(dynamic_cast<CRectangle*> (FigList[i]) != NULL)
				FigList[i]->Save(Out);
		break;

	case DRAW_TRI:
		for(int i=0; i<FigCount; ++i)
			if(dynamic_cast<CTriangle*> (FigList[i]) != NULL)
				FigList[i]->Save(Out);
		break;

	case DRAW_RHOMBUS:
		for(int i=0; i<FigCount; ++i)
			if(dynamic_cast<CRhombus*> (FigList[i]) != NULL)
				FigList[i]->Save(Out);
		break;

	case DRAW_ELLIPSE:
		for(int i=0; i<FigCount; ++i)	
			if(dynamic_cast<CEllipse*> (FigList[i]) != NULL)
				FigList[i]->Save(Out);
		break;

	case BACK1:
		pOut->CreateDrawToolBar();
		break;
	}	
}

void ApplicationManager::Loop(CFigure* deleted) {
	for (int i = 0; i < FigCount; i++)
		if (deleted == FigList[i])
		{
			delete FigList[i];
			FigList[i] = NULL;
			PasteFlag = SelectFlag = 0;
			FigCount--;
			for (int j = i; j < FigCount; j++)
				FigList[j] = FigList[j + 1];
			break;
		}
}

int ApplicationManager::CntFig(ActionType pAct)   //Examine the type of the Action and according to it
{                                                 //return the number of that type figures to me
	switch(pAct)
	{
	case DRAW_LINE:
		return CLine::LineCnt;
	case DRAW_RECT:
		return CRectangle::RectCnt;
	case DRAW_TRI:
		return CTriangle::TriCnt;
	case DRAW_RHOMBUS:
		return CRhombus::RhoCnt;
	case DRAW_ELLIPSE:
		return CEllipse::ElliCnt;
	}
	return 0;
}

void ApplicationManager::LoadFig()  //for each figure FigList, make it points to NULL 
{
	for(int i=0; i<FigCount; ++i)
		FigList[i]=NULL;
	FigCount = 0;
}

void ApplicationManager::Send_Back(CFigure *swapped)
{
	CFigure *temp = swapped;
	int Swapped_index;
	for (int i = 0; i < FigCount; i++)
		if (swapped == FigList[i])
		{
			Swapped_index = i;
			break;
		}
	
	for (int i = Swapped_index; i > 0; i--)
		FigList[i] = FigList[i - 1];
	FigList[0] = temp;
}

void ApplicationManager::Bring_Front(CFigure* swapped)
{
	CFigure *temp = swapped;
	int Swapped_index;
	for (int i = 0; i < FigCount; i++)
		if (swapped == FigList[i])
			Swapped_index = i;

	for (int i = Swapped_index; i < FigCount - 1; i++)
		FigList[i] = FigList[i + 1];
	FigList[FigCount - 1] = temp;
}

//==================================================================================//
//                          Play Mode Functions ^_^                                 //
//==================================================================================//
int ApplicationManager::RandomType(int &Result)
{
	int type1(0);
	if (FigCount != 0)
	{
		int type = rand() % FigCount + 0;

		if (dynamic_cast<CLine*>(FigList[type]) != NULL)
			type1 = 1;
		else if (dynamic_cast<CRectangle*>(FigList[type]) != NULL)
			type1 = 2;
		else if (dynamic_cast<CRhombus*>(FigList[type]) != NULL)
			type1 = 3;
		else if (dynamic_cast<CEllipse*>(FigList[type]) != NULL)
			type1 = 4;
		else if (dynamic_cast<CTriangle*>(FigList[type]) != NULL)
			type1 = 5;

		for (int i = 0; i < FigCount; i++)
			if (type1 == 1 && dynamic_cast<CLine*>(FigList[i]) != NULL)
				Result++;
			else if (type1 == 2 && dynamic_cast<CRectangle*>(FigList[i]) != NULL)
				Result++;
			else if (type1 == 3 && dynamic_cast<CRhombus*>(FigList[i]) != NULL)
				Result++;
			else if (type1 == 4 && dynamic_cast<CEllipse*>(FigList[i]) != NULL)
				Result++;
			else if (type1 == 5 && dynamic_cast<CTriangle*>(FigList[i]) != NULL)
				Result++;
	}
	return type1;
}

int ApplicationManager::RandomColor(int &Result)
{
	int type1(0);
	int count =10* FigCount;
	if (FigCount != 0)
	{
		do
		{
			int type = rand() % FigCount + 0;
			FigList[type]->SetGfxInfo(pickGfxInfo);
			count--;
		} while (!pickGfxInfo.isFilled&&count>=0);
		

		if (pickGfxInfo.isFilled)
		{
			if (pickGfxInfo.FillClr == WHITE)
				type1 = 1;
			else if (pickGfxInfo.FillClr == RED)
				type1 = 2;
			else if (pickGfxInfo.FillClr == GREEN)
				type1 = 3;
			else if (pickGfxInfo.FillClr == BLUE)
				type1 = 4;
			else if (pickGfxInfo.FillClr == BLACK)
				type1 = 5;


			for (int i = 0; i < FigCount; i++)
			{
				FigList[i]->SetGfxInfo(pickGfxInfo);

				if (type1 == 1 && pickGfxInfo.FillClr == WHITE)
					Result++;
				else if (type1 == 2 && pickGfxInfo.FillClr == RED)
					Result++;
				else if (type1 == 3 && pickGfxInfo.FillClr == GREEN)
					Result++;
				else if (type1 == 4 && pickGfxInfo.FillClr == BLUE)
					Result++;
				else if (type1 == 5 && pickGfxInfo.FillClr == BLACK)
					Result++;
			}
		}
	}
	return type1;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)-

	if (mode == 0)
		pOut->CreateDrawToolBar();
	else if (mode == 1)
		pOut->CreateShapesBar();
	else if (mode == 2)
		pOut->CreateColorsBar();
	else if (mode == 3)
		pOut->CreatePlayToolBar();
	else if (mode == 4)
		pOut->CreateSizeBar();
	pOut->ClearStatusBar();
	pOut->PrintMessage(LastMessage);
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}
