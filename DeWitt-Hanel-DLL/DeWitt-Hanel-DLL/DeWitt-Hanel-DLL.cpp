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


void test()
{

}

char* GetTeam()
{
	char team[] = "Group 10 -- Gavin Dewitt and Brad Hanel";
	return team;
}

void SetMaze(const int** p_data, int p_width, int p_height)
{
	for (int i = 0; sizeof p_data / sizeof p_data[0]; i++)
	{
		for (int j = 0; sizeof p_data[0] / sizeof(int); j++)
		{
			*data[i, j] = *p_data[i, j];
		}
	}
}

int** GetMaze(int& width, int& height)
{

}

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