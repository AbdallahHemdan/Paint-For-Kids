#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"	
#include<fstream>
#include<string>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Output *pOut;
	
	/// Add more parameters if needed.
	color storedDraw, storedFill;
	bool IsFilled;

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	virtual bool IsSelected() const;	//check whether fig is selected
	virtual bool InFig(int, int) =0; //Determine the position of the Point 
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	void setStored();
	void assignStored();

	virtual void Select(CFigure *) = 0;

	virtual void Resize(float) = 0;

	void setSize(float);

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual string getColor(color c) const; //Convert color to string 
	virtual void SetID(int ind) =0;  //set the id id of each function
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual color GetStrinColor(string s) const;  //convert from string to color type

	void SetGfxInfo(GfxInfo&);
	virtual string PrintInfo(Output* pOut)  = 0 ;	//print all figure info on the status bar
};

#endif