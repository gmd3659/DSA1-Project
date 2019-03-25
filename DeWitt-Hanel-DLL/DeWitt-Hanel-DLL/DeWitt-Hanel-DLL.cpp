// DeWitt-Hanel-DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

int** data;
int width;
int height;

int xStart;
int yStart;
int xEnd;
int yEnd;

int gnpCall = 0;

int yvals[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int xvals[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

char team[40] = "Group 10 -- Gavin Dewitt and Brad Hanel";

__declspec(dllexport) char* GetTeam();
__declspec(dllexport) bool SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllexport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllexport) bool GetNextPosition(int& xpos, int& ypos);
__declspec(dllexport) void SetStart(int xPos, int yPos);
__declspec(dllexport) void GetStart(int& xPos, int& yPos);
__declspec(dllexport) void SetEnd(int xPos, int yPos);
__declspec(dllexport) void GetEnd(int& xPos, int& yPos);


void test()
{

}

// Returns a string that has both team members name.  Have the C string value return both team member names.  There is no defined format for this.
char* GetTeam()
{
	return team;
}

bool SetMaze(const int** p_data, int p_width, int p_height)
{
	width = p_width;
	height = p_height;
	for (int i = 0; i < p_width; i++)
	{
		for (int j = 0; j < p_height; j++)
		{
			*data[i, j] = *p_data[i, j];
		}
	}

	if(width <= 0 || height <= 0)
	{
		return false;
	}
	return true;

}

int** GetMaze(int& p_width, int& p_height)
{
	p_width = width;
	p_height = height;
	return const_cast<int**>(data); 

	if (data == NULL) 
	{
		return nullptr;
	}
}

bool GetNextPosition(int& xpos, int& ypos) 
{
	if(gnpCall >= sizeof(xvals) / sizeof(*xvals) || sizeof(yvals) / sizeof(*yvals))
	{
		return false;
	}
	xpos = xvals[gnpCall];
	ypos = yvals[gnpCall];
	gnpCall++;
	return true;
}

void SetStart(int xPos, int yPos)
{
	xStart = xPos;
	yStart = yPos;
}

void GetStart(int& xPos, int& yPos)
{
	if (xStart >= 0 && yStart >= 0)
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
	if (xEnd >= 0 && yEnd >= 0)
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