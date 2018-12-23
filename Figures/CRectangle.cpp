#include "CRectangle.h"

int CRectangle::RectCnt = 0;
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	RectCnt++;
	FigGfxInfo.Resize_Factor = 1;
}

CRectangle::CRectangle(){}

bool CRectangle::InFig(int x, int y)
{
	if ((x >= min(Corner1.x, Corner2.x) && x <= max(Corner1.x, Corner2.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y)))
	{
		return true;
	}
	return false;
}

void CRectangle::Draw(Output *pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Select(CFigure *tmp)
{
	CRectangle *rect = dynamic_cast<CRectangle *> (tmp);
	rect->SetSelected(1);
	rect->Draw(pOut);
}

void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "Rectangle\t"
		<< ID << "\t" << this->Corner1.x << "\t" << this->Corner1.y << "\t"
		<< this->Corner2.x << "\t" << this->Corner2.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getColor(this->FigGfxInfo.FillClr) << "\t";
	else
		OutFile << "NON-FILLED\t";
	OutFile << this->FigGfxInfo.Resize_Factor << "\n";
}

void CRectangle::SetID(int ind)
{
	ID = ind;
}

void CRectangle::Load(ifstream &Infile)
{
	string s;
	Infile >> ID >> Corner1.x >> Corner1.y
		>> Corner2.x >> Corner2.y;

	Infile >> s;
	FigGfxInfo.DrawClr = GetStrinColor(s);

	Infile >> s;
	if (s == "NON-FILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = GetStrinColor(s);
		FigGfxInfo.isFilled = true;
	}
	Infile >> this->FigGfxInfo.Resize_Factor;
	Selected = false;
	this->setStored();
}

Point CRectangle::D_B_P(Point P, Output *pOut) const
{
	Point P2;
	P2.x = P.x + abs(Corner1.x - Corner2.x);
	P2.y = P.y + abs(Corner1.y - Corner2.y); 

	pOut->DrawRect(P, P2, FigGfxInfo);
	return P2;
}

void CRectangle::Resize(float)
{
	if (FigGfxInfo.Resize_Factor == .5) FigGfxInfo.Resize_Factor = -1;
	else if (FigGfxInfo.Resize_Factor == .25) FigGfxInfo.Resize_Factor = -(4.0 / 3);

	Point O;
	O.x = (Corner1.x + Corner2.x) / 2;
	O.y = (Corner1.y + Corner2.y) / 2;

	if (Corner1.x <= O.x)
		Corner1.x -= (O.x - Corner1.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner1.x += (Corner1.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Corner2.x <= O.x)
		Corner2.x -= (O.x - Corner2.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner2.x += (Corner2.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Corner1.y <= O.y)
		Corner1.y -= (O.y - Corner1.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner1.y += (Corner1.y - O.y) * FigGfxInfo.Resize_Factor / 2;

	if (Corner2.y <= O.y)
		Corner2.y -= (O.y - Corner2.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner2.y += (Corner2.y - O.y) * FigGfxInfo.Resize_Factor / 2;
}

string CRectangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Corner1.x);
	string y1 = to_string(Corner1.y);
	string x2 = to_string(Corner2.x);
	string y2 = to_string(Corner2.y);
	string clr = getColor(this->FigGfxInfo.DrawClr);
	if(FigGfxInfo.isFilled)
	{
	string clrF = getColor(this->FigGfxInfo.FillClr);
	return ("Rectangle - ID:"+id+" Corner1: ("+x1+", "+y1+")"+" Corner2: ("+x2+", "+y2+")"+" DrawColor: "+" DrawColor: "+clr+ " FillCoror: "+clrF);
	}
	else
		return ("Rectangle - ID:"+id+" Corner1: ("+x1+", "+y1+")"+" Corner2: ("+x2+", "+y2+")"+" DrawColor: "+clr+" FillColor: NON-Filled");
}