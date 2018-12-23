#include "CTriangle.h"

int CTriangle::TriCnt = 0;
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	FigGfxInfo.Resize_Factor = 1;
	TriCnt++;
}
CTriangle::CTriangle(){}

void CTriangle::Draw(Output *pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool CTriangle::InFig(int x, int y)              //Function to inform me if the point in the figure or not
{
	float A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	float A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == A1 + A2 + A3)
	{
		return true;
	}
	return false;
}

void CTriangle::Select(CFigure *tmp)
{
	CTriangle *tri = dynamic_cast<CTriangle *> (tmp);
	tri->SetSelected(1);
	tri->Draw(pOut);
}

void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "Triangle\t"
		<< ID << "\t" << this->Corner1.x << "\t" << this->Corner1.y << "\t"
		<< this->Corner2.x << "\t" << this->Corner2.y << "\t"
		<< this->Corner3.x << "\t" << this->Corner3.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getColor(this->FigGfxInfo.FillClr) << "\t";
	else
		OutFile << "NON-FILLED\t";
	OutFile << this->FigGfxInfo.Resize_Factor << "\n";
}

void CTriangle::SetID(int ind)
{
	ID = ind;
}

void CTriangle::Load(ifstream &Infile)
{
	string s;
	Infile >> this->ID >> this->Corner1.x >> this->Corner1.y
		>> this->Corner2.x >> this->Corner2.y
		>> this->Corner3.x >> this->Corner3.y;

	Infile >> s;
	this->FigGfxInfo.DrawClr = GetStrinColor(s);

	Infile >> s;
	if (s == "NON-FILLED")
		this->FigGfxInfo.isFilled = false;
	else
	{
		this->FigGfxInfo.isFilled = true;
		this->FigGfxInfo.FillClr = GetStrinColor(s);
	}
	Infile >> this->FigGfxInfo.Resize_Factor;
	this->FigGfxInfo.BorderWdth = 100;
	this->Selected = false;
	this->setStored();
}

Point* CTriangle::D_B_P(Point P, Output *pOut) const
{
	Point ReturnPs[2];
	if (Corner1.y <= Corner2.y && Corner1.y <= Corner3.y)
	{
		ReturnPs[0].x = P.x - (Corner1.x - Corner2.x);
		ReturnPs[0].y = P.y - (Corner1.y - Corner2.y);

		ReturnPs[1].x = P.x - (Corner1.x - Corner3.x);
		ReturnPs[1].y = P.y - (Corner1.y - Corner3.y);
	}
	else if (Corner2.y <= Corner1.y && Corner2.y <= Corner3.y)
	{
		ReturnPs[0].x = P.x - (Corner2.x - Corner1.x);
		ReturnPs[0].y = P.y - (Corner2.y - Corner1.y);

		ReturnPs[1].x = P.x - (Corner2.x - Corner3.x);
		ReturnPs[1].y = P.y - (Corner2.y - Corner3.y);
	}
	else if (Corner3.y <= Corner1.y && Corner3.y <= Corner2.y)
	{
		ReturnPs[0].x = P.x - (Corner3.x - Corner1.x);
		ReturnPs[0].y = P.y - (Corner3.y - Corner1.y);

		ReturnPs[1].x = P.x - (Corner3.x - Corner2.x);
		ReturnPs[1].y = P.y - (Corner3.y - Corner2.y);
	}
	pOut->DrawTri(P, ReturnPs[0], ReturnPs[1], FigGfxInfo);

	return ReturnPs;
}

void CTriangle::Resize(float)
{
	if (FigGfxInfo.Resize_Factor == .5) FigGfxInfo.Resize_Factor = -1;
	else if (FigGfxInfo.Resize_Factor == .25) FigGfxInfo.Resize_Factor = -(4.0 / 3);

	Point O;
	O.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	O.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	if (Corner1.x <= O.x)
		Corner1.x -= (O.x - Corner1.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner1.x += (Corner1.x - O.x) * FigGfxInfo.Resize_Factor / 2;
	
	if (Corner2.x <= O.x)
		Corner2.x -= (O.x - Corner2.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner2.x += (Corner2.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Corner3.x <= O.x)
		Corner3.x -= (O.x - Corner3.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner3.x += (Corner3.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Corner1.y <= O.y)
		Corner1.y -= (O.y - Corner1.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner1.y += (Corner1.y - O.y) * FigGfxInfo.Resize_Factor / 2;

	if (Corner2.y <= O.y)
		Corner2.y -= (O.y - Corner2.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner2.y += (Corner2.y - O.y) * FigGfxInfo.Resize_Factor / 2;

	if (Corner3.y <= O.y)
		Corner3.y -= (O.y - Corner3.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Corner3.y += (Corner3.y - O.y) * FigGfxInfo.Resize_Factor / 2;
}

string CTriangle::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x1 = to_string(Corner1.x);
	string y1 = to_string(Corner1.y);
	string x2 = to_string(Corner2.x);
	string y2 = to_string(Corner2.y);
	string x3 = to_string(Corner3.x);
	string y3 = to_string(Corner3.y);
	string clr = getColor(this->FigGfxInfo.DrawClr);
	if(FigGfxInfo.isFilled)
	{
	string clrF = getColor(this->FigGfxInfo.FillClr);
	return ("Triangle - ID:"+id+" Corner1: ("+x1+", "+y1+")"+" Corner2: ("+x2+", "+y2+")"+" Corner3: ("+x3+", "+y3+")"+" DrawColor: "+clr+ " FillCoror: "+clrF);
	}
	else
		return ("Triangle - ID:"+id+" Corner1: ("+x1+", "+y1+")"+" Corner2: ("+x2+", "+y2+")"+" Corner3: ("+x3+", "+y3+")"+" DrawColor: "+clr+" FillColor: NON-Filled");
}