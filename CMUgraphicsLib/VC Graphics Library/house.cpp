#include <iostream.h>
#include <math.h>
#include "CMUgraphics.h"

// global constants
const int HOUSE_WIDTH = 400;
const int HOUSE_HEIGHT = 200;
const int DOOR_WIDTH = 30;
const int DOOR_HEIGHT = 50;
const int WINDOW_WIDTH = 50;
const int WINDOW_HEIGHT = 70;

// declarations
void DrawHouse();
void DrawFrame(int x, int y);
void DrawDoor(int x, int y);
void DrawWindows();
void DrawWindow();

// global window object, 700x400 at (5,5)
window myWindow(700, 400, 5, 5);


int main()
{
	cout << "Hit <enter> once you've resized and moved the Console";
	cout << " window out of the way...\n";
	cin.ignore();
	
	DrawHouse();
	 	
 	return 0;
}


void DrawHouse()
{int x, y;

	cout << "You will be asked for the coordinates of the top left corner of the house.\n";
	cout << "100,150 is a good choice.\n\n";
	cout << "Enter x coordinate of house (top left): ";
	cin >> x;
	cout << "Enter y coordinate of house (top left): ";
	cin >> y;
	
	DrawFrame(x,y);
	DrawDoor(x,y);
	DrawWindows();
}


void DrawFrame(int x, int y)
{
	myWindow.SetPen(BROWN);
	myWindow.SetBrush(BROWN);
	myWindow.DrawRectangle(x, y, x + HOUSE_WIDTH, y + HOUSE_HEIGHT, FILLED);
	myWindow.SetPen(BLACK);
	myWindow.DrawLine(x, y, x + HOUSE_WIDTH/2, y - HOUSE_HEIGHT/2);
	myWindow.DrawLine(x + HOUSE_WIDTH, y, x + HOUSE_WIDTH/2, y - HOUSE_HEIGHT/2);
}


void DrawDoor(int x, int y)
{
	myWindow.SetPen(BLACK);
	myWindow.SetBrush(BLACK);
	myWindow.DrawRectangle(x + HOUSE_WIDTH/2 - DOOR_WIDTH/2, y +
HOUSE_HEIGHT - DOOR_HEIGHT, x + HOUSE_WIDTH/2 + DOOR_WIDTH/2, y +
HOUSE_HEIGHT, FILLED);
}


void DrawWindows()
{int i, n;

	cout << "How many windows? ";
	cin >> n;
	
	for (i = 0; i < n; i++)
		DrawWindow();
}


void DrawWindow()
{int x, y;

	cout << "Click top left corner of window location." << endl;
	myWindow.WaitMouseClick(x, y);
	myWindow.SetPen(BLACK);
	myWindow.SetBrush(WHITE);
	myWindow.DrawRectangle(x, y, x + WINDOW_WIDTH, y + WINDOW_HEIGHT, FILLED);
	myWindow.SetPen(BLACK);
	myWindow.DrawLine(x, y + WINDOW_HEIGHT/2, x + WINDOW_WIDTH, y +
WINDOW_HEIGHT / 2);
	myWindow.DrawLine(x + WINDOW_WIDTH/2, y, x + WINDOW_WIDTH/2, y +
WINDOW_HEIGHT);
}
