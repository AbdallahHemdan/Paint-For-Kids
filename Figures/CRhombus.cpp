#include "CRhombus.h"

int CRhombus::RhoCnt = 0;
CRhombus::CRhombus(Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = C;
	RhoCnt++;
	P.x = P.y = 50;
	FigGfxInfo.Resize_Factor = 1;
}

CRhombus::CRhombus()
{
	P.x = 50;
	P.y = 50;
}

void CRhombus::Draw(Output *pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	pOut->DrawRho(Center, P, FigGfxInfo, Selected);
}

double area1(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool CRhombus::InFig(int x, int y)
{
	int y1 = Center.y - P.x, y2 = Center.y + P.y, x1 = Center.x - P.x, x2 = Center.x + P.y;
	double A = .5 * abs(P.x) * 2 * abs(P.y) * 2;
	double A1 = area1(x, y, x2, Center.y, Center.x, y1);
	double A2 = area1(x, y, x2, Center.y, Center.x, y2);
	double A3 = area1(x, y, Center.x, y2, x1, Center.y);
	double A4 = area1(x, y, x1, Center.y, Center.x, y1);
	if (A == A1 + A2 + A3 + A4)
	{
		return true;
	}
	return false;
}

void CRhombus::Select(CFigure *tmp)
{
	CRhombus *rho = dynamic_cast<CRhombus *> (tmp);
	rho->SetSelected(1);
	rho->Draw(pOut);
}
void CRhombus::Save(ofstream &OutFile)
{
	OutFile << "Rhombus\t" << ID << "\t" << this->Center.x << "\t" << this->Center.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\t";
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getColor(this->FigGfxInfo.FillClr) << "\t";
	else
		OutFile << "NON-FILLED\t";
	//OutFile << this->FigGfxInfo.Resize_Factor << "\n";
	OutFile << this->P.x << "\t" << this->P.y << "\n";
}
void CRhombus::SetID(int ind)
{
	ID = ind;
}

void CRhombus::Load(ifstream &Infile)
{
	string s;
	Infile >> this->ID >> this->Center.x >> this->Center.y;

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
	Infile >> this->P.x >> this->P.y;
	this->FigGfxInfo.BorderWdth = 100;
	this->Selected = false;
	this->setStored();
}

void CRhombus::Resize(float size)
{
	P.x *= size;
	P.y = P.x;
}

string CRhombus::PrintInfo(Output* pOut)
{
	string id = to_string(ID);
	string x = to_string(Center.x);
	string y = to_string(Center.y);
	string clr = getColor(this->FigGfxInfo.DrawClr);

	if(FigGfxInfo.isFilled)
	{
	pOut->PrintMessage(" - FillColor: ");
	string clrF = getColor(this->FigGfxInfo.FillClr);
	return ("Ellipse -ID: "+id+" Center: ("+x+", "+y+") DrawColor:"+clr+" FillColor: "+clrF);
	}
	else
		return ("Ellipse -ID: "+id+" Center: ("+x+", "+y+") DrawColor:"+clr+" FillColor: NON-Filled");
}