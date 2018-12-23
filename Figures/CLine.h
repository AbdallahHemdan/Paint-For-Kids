#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Point1;
	Point Point2;
public:
	static int LineCnt;
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	CLine();
	virtual void Draw(Output* pOut) const;
	virtual bool InFig(int, int);
	double area(int, int, int, int, int, int);
	virtual void Select(CFigure*);
	Point D_B_P(Point &, Output*) const;
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void SetID(int ind);
	virtual string PrintInfo(Output* pOut) ;
	virtual void Resize(float);
};

#endif