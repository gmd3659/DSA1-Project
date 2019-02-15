// Testing.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

int xStart;
int yStart;
int xEnd;
int yEnd;

void SetStart(int xPos, int yPos)
{
	xStart = xPos;
	yStart = yPos;
}

void GetStart(int& xPos, int& yPos)
{
	if (xStart > 0 && yStart > 0)
	{
		xPos = xStart;
		yPos = yStart;
	}
	else
	{
		xPos = -1;
		yPos = -1;
	}
}

void SetEnd(int xPos, int yPos)
{
	xEnd = xPos;
	yEnd = yPos;
}

void GetEnd(int& xPos, int& yPos)
{
	if (xEnd > 0 && yEnd > 0)
	{
		xPos = xEnd;
		yPos = yEnd;
	}
	else
	{
		xPos = -1;
		yPos = -1;
	}
}

