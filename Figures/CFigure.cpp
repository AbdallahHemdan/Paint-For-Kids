#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	setStored();
}
CFigure::CFigure(){}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{
	return Selected;
}
void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
string CFigure::getColor(color c) const
{
	if(c==BLACK) return "BLACK";
	else if(c==WHITE) return "WHITE";
	else if(c==BLUE) return "BLUE";
	else if(c==RED) return "RED";
	else if(c==YELLOW) return "YELLOW";
	else if(c==GREEN) return "GREEN";
	else if(c==LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	else if(c==MAGENTA) return "MAGENTA";
	else if(c==TURQUOISE) return "TURQUOISE";
	return "COLOR";
}
color CFigure::GetStrinColor(string s) const
{
	if(s == "BLACK")
		return BLACK;
	if(s == "BLUE")
		return BLUE;
	if(s == "WHITE")
		return WHITE;
	if(s == "RED")
		return RED;
	if(s == "YELLOW")
		return YELLOW;
	if(s == "GREEN")
		return GREEN;
	if(s == "LIGHTGOLDENRODYELLOW")
		return LIGHTGOLDENRODYELLOW;
	if(s == "MAGENTA")
		return MAGENTA;
	if(s == "TURQUOISE")
		return TURQUOISE;
	return BLACK;
}

void CFigure::setStored()
{
	storedFill = FigGfxInfo.FillClr;
	storedDraw = FigGfxInfo.DrawClr;
	IsFilled = FigGfxInfo.isFilled;
}

void CFigure::assignStored()
{
	FigGfxInfo.isFilled = IsFilled;
	FigGfxInfo.FillClr = storedFill;
	FigGfxInfo.DrawClr = storedDraw;
}

void CFigure::SetGfxInfo(GfxInfo &PickGfxInfo)
{
	PickGfxInfo.isFilled = IsFilled;
	PickGfxInfo.FillClr = storedFill;
	PickGfxInfo.DrawClr = storedDraw;
}

void CFigure::setSize(float size)
{
	FigGfxInfo.Resize_Factor = size;
}