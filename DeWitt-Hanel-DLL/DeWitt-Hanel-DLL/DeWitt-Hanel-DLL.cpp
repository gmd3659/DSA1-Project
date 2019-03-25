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
__declspec(dllexport) void SetMaze(const int** p_data, int p_width, int p_height);
__declspec(dllexport) int** GetMaze(int& p_width, int& p_height);
__declspec(dllexport) void GetNextPosition(int& xpos, int& ypos);
__declspec(dllexport) bool SetStart(int xPos, int yPos);
__declspec(dllexport) bool GetStart(int& xPos, int& yPos);
__declspec(dllexport) bool SetEnd(int xPos, int yPos);
__declspec(dllexport) bool GetEnd(int& xPos, int& yPos);


void test()
{

}

// Returns a string that has both team members name.  Have the C string value return both team member names.  There is no defined format for this.
char* GetTeam()
{
	return team;
}

void SetMaze(const int** p_data, int p_width, int p_height)
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

}

int** GetMaze(int& p_width, int& p_height)
{
	p_width = width;
	p_height = height;
	return const_cast<int**>(data); 
}

void GetNextPosition(int& xpos, int& ypos) 
{
		xpos = xvals[gnpCall];
		ypos = yvals[gnpCall];
		gnpCall++;

}

bool SetStart(int xPos, int yPos)
{
	//Set start variables
	xStart = xPos;
	yStart = yPos;

	//return whether x and y are valid
	if (xPos >= 0 && yPos >= 0)
	{
		return true;
	}
	return false;
}

bool GetStart(int& xPos, int& yPos)
{
	if (xStart >= 0 && yStart >= 0)
	{
		//Return values and true
		xPos = xStart;
		yPos = yStart;
		return true;
	}
	else
	{
		//Don't return points unless valid
		//xPos = -1;
		//yPos = -1;
		return false;
	}
}

bool SetEnd(int xPos, int yPos)
{
	xEnd = xPos;
	yEnd = yPos;

	//return whether x and y are valid
	if (xEnd >= 0 && yEnd >= 0)
	{
		return true;
	}
	return false;
}

bool GetEnd(int& xPos, int& yPos)
{
	if (xEnd >= 0 && yEnd >= 0)
	{
		//Return values and true
		xPos = xEnd;
		yPos = yEnd;
		return true;
	}
	else
	{
		//Don't return points unless valid
		//xPos = -1;
		//yPos = -1;
		return false;
	}
}

bool Restart()
{

}