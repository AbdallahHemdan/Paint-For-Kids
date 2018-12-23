#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2, Corner3;
public:
	static int TriCnt;
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	Point* D_B_P(Point, Output *) const;
	virtual bool InFig(int, int);
	virtual void Select(CFigure *tmp);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual string PrintInfo(Output* pOut);
	virtual void SetID(int ind);
	virtual void Resize(float);
};

#endif