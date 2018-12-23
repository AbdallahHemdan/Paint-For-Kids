#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	static int RectCnt;
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual bool InFig(int, int);
	virtual void Select(CFigure *);
	void Draw(Output* pOut) const;
	Point D_B_P(Point, Output *) const;
	virtual void Save(ofstream &OutFile);
	virtual void SetID(int ind);
	virtual void Load(ifstream &Infile);
	virtual string PrintInfo(Output* pOut) ;
	virtual void Resize(float);
};

#endif