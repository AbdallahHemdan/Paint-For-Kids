#ifndef CRHOMBUS_H
#define CRHOMBUS_H

#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center, P;

public:
	static int RhoCnt;
	CRhombus(Point, GfxInfo FigureGfxInfo);
	CRhombus();
	virtual void Draw(Output* pOut) const;
	virtual bool InFig(int, int);
	virtual void Select(CFigure*);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual void SetID(int ind);
	virtual string PrintInfo(Output* pOut) ;
	virtual void Resize(float);
};

#endif