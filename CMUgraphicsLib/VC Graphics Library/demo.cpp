
#include <iostream>
#include <sstream>
#include <cmath>

#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found

// Function to wait for a mouse click and clear the screen
void WaitNClear(window &inputWindow);

int main()
{
 int iX, iY;
    
    // Create a new window 600 by 440 in size
    window testWindow(600, 440, 5, 5);

    // Change the window title to something different
    testWindow.ChangeTitle("CMU Graphics Package Demo");
    
    
    // -- LINE DEMO --

    // Draw some different lines for example purposes
    
    // Draws a green vertical line with a pen thickness of 5 pixels
    testWindow.SetPen(0.0, 1.0, 0.0, 5);    
    testWindow.DrawLine(5, 10, 5, 420);
    
    // Draws a black vertical line with a pen thickness of 1 pixel
    testWindow.SetPen(0.0, 0.0, 0.0, 1);
    testWindow.DrawLine(15, 10, 15, 420);
    
    // Draws a red diagonal line with a pen thickness of 10 pixels
    testWindow.SetPen(1.0, 0.0, 0.0, 10);
    testWindow.DrawLine(25, 10, 570, 420);
    
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- RECTANGLE DEMO --
    
    // Draw a FRAME rectangle in black with a 5 pixel border
    testWindow.SetPen(BLACK, 5);    
    testWindow.DrawRectangle(10, 10, 100, 100, FRAME);
    
    // Draw a FILLED rectangle in red without a border
    testWindow.SetPen(RED, 0);    
    testWindow.SetBrush(RED);
    testWindow.DrawRectangle(30, 30, 200, 200, FILLED);
    
    // Draw a FILLED rectangle in blue with a green 5 pixel border
    testWindow.SetPen(GREEN, 5);    
    testWindow.SetBrush(BLUE);
    testWindow.DrawRectangle(50, 50, 300, 300, FILLED);
    
    // Draw a FILLED rounded rectangle in cyan with a yellow 5 pixel border
    testWindow.SetPen(1.0, 1.0, 0.0, 5);    
    testWindow.SetBrush(0.0, 1.0, 1.0);
    testWindow.DrawRectangle(70, 70, 400, 400, FILLED, 20, 20);
    
    // Draw an INVERTED rectangle
    testWindow.DrawRectangle(200, 200, 500, 300, INVERTED);
    
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    

    // -- TRIANGLE DEMO -- 
    
    // Draw a FRAME triangle in blue with a 5 pixel border
    testWindow.SetPen(BLUE, 5);    
    testWindow.DrawTriangle(10, 10, 10, 50, 300, 300, FRAME);
    
    // Draw a FILLED triangle in magenta without a border
    testWindow.SetPen(0.9, 0.2, 0.9, 0);    
    testWindow.SetBrush(0.9, 0.2, 0.9);
    testWindow.DrawTriangle(570, 430, 400, 400, 150, 200, FILLED);
    
    // Draw a FILLED triangle in green with a red 5 pixel border
    testWindow.SetPen(RED, 5);    
    testWindow.SetBrush(GREEN);
    testWindow.DrawTriangle(580, 10, 590, 200, 300, 300, FILLED);

    // Draw an INVERTED triangle
    testWindow.DrawTriangle(100, 100, 10, 420, 300, 250, INVERTED);
        
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- POLYGON DEMO -- 
    
    // Draw a FRAME polygon with a red 5 pixel border
    testWindow.SetPen(RED, 5);    
    int XPoints1[] = {10, 250, 300, 100};
    int YPoints1[] = {10, 50, 300, 150};
    testWindow.DrawPolygon(XPoints1, YPoints1, 4, FRAME);
    
    // Draw a FILLED polygon in aquamarine without a border
    testWindow.SetPen(AQUAMARINE, 0);    
    testWindow.SetBrush(AQUAMARINE);
    int XPoints2[] = {590, 420, 300, 100, 50, 20};
    int YPoints2[] = {420, 400, 150, 200, 45, 80};
    testWindow.DrawPolygon(XPoints2, YPoints2, 6, FILLED);
    
    // Draw a FILLED polygon in mistyrose with a grey 5 pixel border
    testWindow.SetPen(GREY, 5);    
    testWindow.SetBrush(MISTYROSE);
    int XPoints3[] = {400, 320, 400, 100, 120};
    int YPoints3[] = {40, 150, 250, 200, 380};
    testWindow.DrawPolygon(XPoints3, YPoints3, 5, FILLED);

    // Draw an INVERTED polygon
    int XPoints4[] = {300, 500, 580, 200};
    int YPoints4[] = {100, 100, 400, 400};
    testWindow.DrawPolygon(XPoints4, YPoints4, 4, INVERTED);

    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- CIRCLE DEMO -- 
    
    // Draw a FRAME circle in orange with a 5 pixel border
    testWindow.SetPen(ORANGE, 5);    
    testWindow.DrawCircle(100, 100, 70, FRAME);
    
    // Draw a FILLED circle in purple without a border
    testWindow.SetPen(0.5, 0.1, 0.9, 0);    
    testWindow.SetBrush(0.5, 0.1, 0.9);
    testWindow.DrawCircle(300, 200, 100, FILLED);
    
    // Draw a FILLED circle in grey with a yellow 7 pixel border
    testWindow.SetPen(YELLOW, 7);    
    testWindow.SetBrush(GREY);
    testWindow.DrawCircle(400, 400, 30, FILLED);

    // Draw an INVERTED circle
    testWindow.DrawCircle(500, 50, 120, INVERTED);
        
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- ELLIPSE DEMO -- 
    
    // Draw a FRAME ellipse in khaki with a 4 pixel border
    testWindow.SetPen(KHAKI, 4);    
    testWindow.DrawEllipse(50, 100, 70, 300, FRAME);
    
    // Draw a FILLED ellipse in green without a border
    testWindow.SetPen(0.0, 1.0, 0.0, 0);    
    testWindow.SetBrush(0.0, 1.0, 0.0);
    testWindow.DrawEllipse(300, 200, 150, 400, FILLED);
    
    // Draw a FILLED ellipse in salmon with a tomato 3 pixel border
    testWindow.SetPen(TOMATO, 3);    
    testWindow.SetBrush(SALMON);
    testWindow.DrawEllipse(350, 100, 560, 150, FILLED);

    // Draw an INVERTED ellipse
    testWindow.DrawEllipse(100, 300, 200, 400, INVERTED);
        
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- ARC DEMO -- 
    
    // Draw a FRAME arc from 30 to 120 degrees in orchid with a 4 pixel border 
    testWindow.SetPen(ORCHID, 4);    
    testWindow.DrawArc(20, 150, 90, 300, 30.0, 120.0, FRAME);
    
    // Draw a FILLED arc from 0.2 to 2.1 radians in cyan without a border
    testWindow.SetPen(0.0, 1.0, 0.5, 0);    
    testWindow.SetBrush(0.0, 1.0, 0.5);
    testWindow.DrawArc(200, 100, 350, 400, 0.2, 2.1, FILLED, RADIANS);
    
    // Draw a FILLED arc from 90 to 270 degrees in thistle with a plum 6 pixel border
    testWindow.SetPen(PLUM, 6);    
    testWindow.SetBrush(THISTLE);
    testWindow.DrawArc(350, 100, 560, 150, 90, 270, FILLED);

    // Draw an INVERTED arc from 1.0 to 3.141 radians
    testWindow.DrawArc(100, 300, 200, 400, 1.0, 3.141, INVERTED, RADIANS);
        
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- BEZIER CURVE DEMO --
    
    // Draw a maroon curve with a pen thickness of 5 pixels
    testWindow.SetPen(MAROON, 5);    
    testWindow.DrawBezier(5, 10, 5, 470, 10, 5, 470, 5);
    
    // Draw a black curve with a pen thickness of 1 pixel
    testWindow.SetPen(0.0, 0.0, 0.0, 1);
    testWindow.DrawBezier(15, 24, 200, 470, 300, 100, 560, 400);
    
    // Draw a coral curve with a pen thickness of 10 pixels
    testWindow.SetPen(CORAL, 10);
    testWindow.DrawBezier(500, 10, 630, 470, 300, 300, 10, 10);
    
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- TEXT DEMO --
    
    // Draw black text in italicized arial.
    testWindow.SetPen(BLACK); 
    testWindow.SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");   
    testWindow.DrawString(0, 0, "The moving cursor writes, and having written, blinks on.");

    // Draw "42" in hotpink bold modern text
    testWindow.SetPen(HOTPINK);
    testWindow.SetFont(72, BOLD, MODERN);
    
    // Use GetIntegerSize to find out where to draw a box around the number
    testWindow.GetIntegerSize(iX, iY, 42);
    testWindow.DrawRectangle(100,100, 100 + iX, 100 + iY, FILLED);
    testWindow.DrawInteger(100,100,42);
    
    // Draws a dark grey colored approximation of pi
    testWindow.SetPen(DARKGREY);
    testWindow.SetFont(36, UNDERLINED, SWISS);
    testWindow.DrawDouble(500, 340, 3.1415926);
    
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- IMAGE DEMO --

    image testImage("scs.jpg", JPEG);
    double dScale;

    // Draw the image once
    testWindow.DrawImage(testImage, 10, 10);
    
    // Turn on double buffering
    testWindow.SetBuffering(true);

    for(dScale = 1.0; dScale < 2.0; dScale += 0.01)
    {
        // Paint the background white
        testWindow.SetPen(WHITE, 0);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

        // Scale and draw the image
        testWindow.DrawImage(testImage, 10, 10, (int)(testImage.GetWidth() * dScale), (int)(testImage.GetHeight() * dScale));

        // Update the screen buffer
        testWindow.UpdateBuffer();
        
        // Pause for a few milliseconds so it doesn't animate too quickly
        Pause(20);
    }
    
    // Store the screen in our image variable
    testWindow.StoreImage(testImage, 0, 0, (unsigned short)(testWindow.GetWidth() - 1), (unsigned short)(testWindow.GetHeight() - 1));
    
    for(dScale = 1.0; dScale > 0.0; dScale -= 0.01)
    {
        // Paint the background white
        testWindow.SetPen(WHITE, 0);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

        // Scale and draw the image
        testWindow.DrawImage(testImage, 0, 0, (int)(testImage.GetWidth() * dScale), (int)(testImage.GetHeight() * dScale));

        // Update the screen buffer
        testWindow.UpdateBuffer();
        
        // Pause for a few milliseconds so it doesn't animate too quickly
        Pause(20);
    }    
        
    // Turn double buffering off
    testWindow.SetBuffering(false);

    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- KEYBOARD AND MOUSE INPUT DEMO --

    testWindow.SetBuffering(true);
    
    bool bQuit = false;
    keytype ktInput;
    clicktype ctInput;
    char cKeyData;
    
    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  

    do
    {
      // Paint the background white
      testWindow.SetPen(WHITE, 0);    
      testWindow.SetBrush(WHITE);
      testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());
    
      // Draws instructions
      testWindow.SetPen(BLACK); 
  
      testWindow.DrawString(5, 5, "Keyboard and Mouse Input Demo. Press \"Escape\" to quit");

      ktInput = testWindow.GetKeyPress(cKeyData);
      ctInput = testWindow.GetMouseClick(iX, iY);
  
      // Figure out what key was pressed
      if(ktInput == ESCAPE) {
          bQuit = true;
      } else if(ktInput == ASCII) {
          ostringstream output;
          output << "The ASCII key '" << cKeyData << "' was pressed.";
          testWindow.DrawString(5, 30, output.str());
      } else if(ktInput == FUNCTION) {
          ostringstream output;
          output << "The Function key F" << int(cKeyData) << " was pressed.";
          testWindow.DrawString(5, 30, output.str());      
      } else if(ktInput == ARROW) {
          switch(cKeyData)
          {
            case 1:
              testWindow.DrawString(5, 30, "The End key was pressed.");
              break;
            case 2:
              testWindow.DrawString(5, 30, "The Down Arrow key was pressed.");
              break;
            case 3:
              testWindow.DrawString(5, 30, "The Page Down key was pressed.");
              break;
            case 4:
              testWindow.DrawString(5, 30, "The Left Arrow key was pressed.");
              break;
            case 5:
              testWindow.DrawString(5, 30, "The Center Keypad key was pressed.");
              break;
            case 6:
              testWindow.DrawString(5, 30, "The Right Arrow key was pressed.");
              break;
            case 7:
              testWindow.DrawString(5, 30, "The Home key was pressed.");
              break;
            case 8:
              testWindow.DrawString(5, 30, "The Up Arrow key was pressed.");
              break;
            case 9:
              testWindow.DrawString(5, 30, "The Page Up key was pressed.");
          }
      
      }

      if(ctInput == LEFT_CLICK) {
          ostringstream output;
          output << "The mouse was left-clicked at (" << iX << ", " << iY << ").";
          testWindow.DrawString(5, 60, output.str()); 
          
      } else if(ctInput == RIGHT_CLICK) {
          ostringstream output;
          output << "The mouse was right-clicked at (" << iX << ", " << iY << ").";
          testWindow.DrawString(5, 60, output.str()); 
      }

      // Update the screen buffer
      testWindow.UpdateBuffer();

      // Pause for half a second
      Pause(500);

    } while(bQuit != true);

    testWindow.SetBuffering(false);
    
    // Wait for a mouse click and clear the window
    WaitNClear(testWindow);
    
    
    // -- GETCOLOR DEMO --
    
    testWindow.SetBuffering(true);    

    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    testImage.Open("scs.jpg", JPEG); 

    // Clear the screen
    testWindow.SetPen(WHITE);    
    testWindow.SetBrush(WHITE);
    testWindow.DrawRectangle(0, 0, testWindow.GetWidth(), testWindow.GetHeight());

    iX = iY = 0;

    testWindow.DrawImage(testImage, 10, 10);
 
    // Loop until there is a mouse click
    while(testWindow.GetMouseClick(iX, iY) == NO_CLICK)
    {
       testWindow.SetPen(WHITE);    
       testWindow.SetBrush(WHITE);
       testWindow.DrawRectangle(4, 370, 630, 430);
    
       testWindow.SetPen(BLACK);    
       testWindow.SetBrush(WHITE);
   
       double dRed, dGreen, dBlue;
       
       // Get the color currently under the mouse...
       testWindow.GetMouseCoord(iX, iY);
       testWindow.GetColor(iX, iY, dRed, dGreen, dBlue);
       
       // Draw the color info near the bottom of the window
       ostringstream output;
       output << "Red: " << dRed << "  Green: " << dGreen << "  Blue: " << dBlue;
       testWindow.DrawString(5, 380, output.str());
       testWindow.DrawString(testWindow.GetWidth()/2 - 100, testWindow.GetHeight() - 25, "Click mouse to continue...");
	
        // Update the screen buffer
        testWindow.UpdateBuffer();
    }
    
    testWindow.SetBuffering(false);
    
    
    // -- MOUSESTATE DEMO --

    // Flush out the input queues before beginning
    testWindow.FlushMouseQueue();
    testWindow.FlushKeyQueue();

    testWindow.SetFont(20, BOLD, BY_NAME, "Arial");  

    testWindow.SetBuffering(true);   
    
    int RectULX = 100; 
    int RectULY = 100;
    int RectWidth = 20;
    
    bool bDragging = false;

    iX = iY = 0;

    int iXOld = 0;
    int iYOld = 0;

    // Loop until there escape is pressed
    while(testWindow.GetKeyPress(cKeyData) != ESCAPE)
    {
        testWindow.SetPen(WHITE);    
        testWindow.SetBrush(WHITE);
        testWindow.DrawRectangle(0, 0, testWindow.GetWidth() - 1, testWindow.GetHeight() - 1);          
      

       // Dragging voodoo
        if(bDragging == false) {
            if(testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN) {
                if(((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
                   bDragging = true; 
                   iXOld = iX; iYOld = iY;
                }
            }
        } else {
            if(testWindow.GetButtonState(LEFT_BUTTON, iX, iY) == BUTTON_UP) {
                bDragging = false; 
            } else {
                if(iX != iXOld) {
                    RectULX = RectULX + (iX - iXOld);
                    iXOld = iX;
                }
                if(iY != iYOld) {
                    RectULY = RectULY + (iY - iYOld);
                    iYOld = iY;
                }
            }
        
        }
       
        // Draw rectangle
      
        testWindow.SetPen(ORANGE);    
        testWindow.SetBrush(ORANGE);
        testWindow.DrawRectangle(RectULX, RectULY, RectULX + RectWidth, RectULY + RectWidth);
       
        // Draw some info 
        testWindow.SetPen(BLACK); 
        testWindow.DrawString(5, 5, "MouseState Demo. Drag the orange box around. Press \"Escape\" to quit");   
     
        // Update the screen buffer
        testWindow.UpdateBuffer();
 
    }
    
	testWindow.SetBuffering(false);
     
	return 0;
}


void WaitNClear(window &inputWindow)
{
 int iX, iY;
 
 	inputWindow.SetPen(BLACK);
	inputWindow.SetFont(16, BOLD, SWISS);
    inputWindow.DrawString(inputWindow.GetWidth()/2 - 100, inputWindow.GetHeight() - 25, "Click mouse to continue...");

    // Flush the mouse queue
    inputWindow.FlushMouseQueue();

    // Ignore return value since we don't care what type of click it was
    inputWindow.WaitMouseClick(iX, iY);

    // Set the brush and pen white so we can clear the background
    inputWindow.SetPen(WHITE, 0);    
    inputWindow.SetBrush(WHITE);
    
    // Draw a rectangle that covers the entire window
    inputWindow.DrawRectangle(0, 0, inputWindow.GetWidth(), inputWindow.GetHeight());
}
