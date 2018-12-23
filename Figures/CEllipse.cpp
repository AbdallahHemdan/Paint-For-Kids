#include "CEllipse.h"
#include<string>
#include<fstream>

int CEllipse::ElliCnt = 0;  //static variable to determine the number of objects
CEllipse::CEllipse(Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = C;
	ElliCnt++;
	FigGfxInfo.Resize_Factor = 1;
	P.x = 80; P.y = 30;
}

CEllipse::CEllipse()
{
	P.x = 80; P.y = 30;
}  //default constructor, We need it to Load

void CEllipse::Draw(Output *pOut) const
{
	//Call Output::DrawEllipse to draw a ellipse on the screen	
	pOut->DrawElli(Center, P, FigGfxInfo, Selected);
}

bool CEllipse::InFig(int x, int y)  //Determine the position of the point
{
	if (pow(x - Center.x, 2) / pow(P.x, 2) + pow(y - Center.y, 2) / pow(P.y, 2) <= 1)
	{
		return true;
	}
	return false;
}

void CEllipse::Select(CFigure *tmp)
{
	CEllipse *elli = dynamic_cast<CEllipse *> (tmp);
	elli->SetSelected(1);
	elli->Draw(pOut);
}

void CEllipse::Save(ofstream &OutFile)      //Write yourself on the file
{
	OutFile << "Ellipse\t" << ID << "\t" << this->Center.x << "\t" << this->Center.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\t" ;
	if (this->FigGfxInfo.isFilled)
		OutFile << this->getColor(this->FigGfxInfo.FillClr) << "\t";
	else
		OutFile << "NON-FILLED\t";
	//OutFile << this->FigGfxInfo.Resize_Factor << "\n";
	OutFile << this->P.x << "\t" << this->P.y << "\n";
}

void CEllipse::Load(ifstream &Infile)      //Laod yourself from the file
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

void CEllipse::SetID(int ind)   //set the id of the figure
{
	ID = ind;
}

void CEllipse::Resize(float size)
{
	P.x *= size;
	P.y *= size;
}

string CEllipse::PrintInfo(Output* pOut)
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