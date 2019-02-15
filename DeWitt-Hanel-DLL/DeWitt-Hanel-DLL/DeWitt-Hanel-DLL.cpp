// DeWitt-Hanel-DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

int** data;
int width;
int height;


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

int** GetMaze()
{

}