#include "CLine.h"

int CLine::LineCnt = 0;
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	LineCnt++;
	FigGfxInfo.Resize_Factor = 1;
}

CLine::CLine() {}
void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}

double CLine::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool CLine::InFig(int x, int y)
{
	double A = area(x, y, Point1.x, Point1.y, Point2.x, Point2.y);
	if (A >= 0 && A <= 1000 && (x >= min(Point1.x, Point2.x) && x <= max(Point1.x, Point2.x) && y >= min(Point1.y, Point2.y) && y <= max(Point1.y, Point2.y)))
	{
		return true;
	}
	return false;
}
void CLine::Select(CFigure *tmp)
{
	CLine *line = dynamic_cast<CLine *> (tmp);
	line->SetSelected(1);
	line->Draw(pOut);
}
void CLine::Save(ofstream &OutFile)
{

	OutFile << "Line\t"
		<< ID << "\t" << this->Point1.x << "\t" << this->Point1.y << "\t"
		<< this->Point2.x << "\t" << this->Point2.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getColor(this->FigGfxInfo.FillClr) << "\t";
	else
		OutFile << "NON-FILLED\t";
	OutFile << this->FigGfxInfo.Resize_Factor << "\n";
}
void CLine::SetID(int ind)
{
	ID = ind;
}

void CLine::Load(ifstream &Infile)
{
	string s;
	Infile >> this->ID >> this->Point1.x >> this->Point1.y
		>> this->Point2.x >> this->Point2.y;

	Infile >> s;
	this->FigGfxInfo.DrawClr = GetStrinColor(s);

	Infile >> s;
	if (s == "NON-FILLED")
		this->FigGfxInfo.isFilled = false;
	else
	{
		this->FigGfxInfo.FillClr = GetStrinColor(s);
		this->FigGfxInfo.isFilled = true;
	}
	Infile >> this->FigGfxInfo.Resize_Factor;
	this->FigGfxInfo.BorderWdth = 100;
	this->Selected = false;
	this->setStored();
}

Point CLine::D_B_P(Point &P, Output* pOut) const
{
	Point P2;
	if (Point1.x <= Point2.x && Point1.y <= Point2.y)
	{
		P2.x = P.x + abs(Point1.x - Point2.x);
		P2.y = P.y + abs(Point1.y - Point2.y);
	}
	else if (Point1.x > Point2.x && Point1.y > Point2.y)
	{
		P2.x = P.x; P2.y = P.y;
		P.x = P2.x + abs(Point1.x - Point2.x);
		P.y = P2.y + abs(Point1.y - Point2.y);
	}
	else if (Point1.x >= Point2.x && Point1.y <= Point2.y)
	{
		P2.x = P.x - abs(Point1.x - Point2.x);
		P2.y = P.y + abs(Point1.y - Point2.y);
	}
	else if (Point1.x <= Point2.x && Point1.y >= Point2.y)
	{
		P2.x = P.x; P2.y = P.y;
		P.x = P2.x - abs(Point1.x - Point2.x);
		P.y = P2.y + abs(Point1.y - Point2.y);
	}
	pOut->DrawLine(P, P2, FigGfxInfo);
	return P2;
}

void CLine::Resize(float)
{
	if (FigGfxInfo.Resize_Factor == .5) FigGfxInfo.Resize_Factor = -1;
	else if (FigGfxInfo.Resize_Factor == .25) FigGfxInfo.Resize_Factor = -(4.0 / 3);

	Point O;
	O.x = (Point1.x + Point2.x) / 2;
	O.y = (Point1.y + Point2.y) / 2;

	if (Point1.x <= O.x)
		Point1.x -= (O.x - Point1.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Point1.x += (Point1.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Point2.x <= O.x)
		Point2.x -= (O.x - Point2.x) * FigGfxInfo.Resize_Factor / 2;
	else
		Point2.x += (Point2.x - O.x) * FigGfxInfo.Resize_Factor / 2;

	if (Point1.y <= O.y)
		Point1.y -= (O.y - Point1.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Point1.y += (Point1.y - O.y) * FigGfxInfo.Resize_Factor / 2;

	if (Point2.y <= O.y)
		Point2.y -= (O.y - Point2.y) * FigGfxInfo.Resize_Factor / 2;
	else
		Point2.y += (Point2.y - O.y) * FigGfxInfo.Resize_Factor / 2;
}

string CLine::PrintInfo(Output* pOut) 
{
	string id = to_string(ID);
	string x1 = to_string(Point1.x);
	string y1 = to_string(Point1.y);
	 string x2 = to_string(Point2.x);
	 string y2 = to_string(Point2.y);
	string clr = getColor(this->FigGfxInfo.DrawClr);
	if(FigGfxInfo.isFilled)
	{
	string clrF = getColor(this->FigGfxInfo.FillClr);
	return ("Line - ID:"+id+" Point1: ("+x1+", "+y1+")"+" Point2: ("+x2+", "+y2+")"+" DrawColor: "+" DrawColor: "+clr+ " FillCoror: "+clrF);
	}
	else
		return ("Line - ID:"+id+" Point1: ("+x1+", "+y1+")"+" Point2: ("+x2+", "+y2+")"+" DrawColor: "+clr+" FillColor: NON-Filled");
}