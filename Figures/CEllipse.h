#ifndef CELLI_H
#define CELLI_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center, P;
public:
	static int ElliCnt;                      //static variable to determine the number of objects
	CEllipse(Point, GfxInfo FigureGfxInfo);
	CEllipse();                              //default constructor, We need it to Load
	virtual void Draw(Output *pOut) const;  //draw the figure 
	virtual bool InFig(int, int);          //check if the point on the figure or not
	virtual void Select(CFigure*);
	virtual void Save(ofstream &OutFile); //save the figure
	virtual void SetID(int ind);          //set the id
	virtual void Load(ifstream &Infile);  //Load the figure
	virtual string PrintInfo(Output* pOut);
	virtual void Resize(float);
};

#endif