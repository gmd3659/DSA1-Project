// DeWitt-Hanel-DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Graph.h"
#include "Vertex.h"

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
__declspec(dllexport) bool SetStart(int xPos, int yPos);
__declspec(dllexport) bool GetStart(int& xPos, int& yPos);
__declspec(dllexport) bool SetEnd(int xPos, int yPos);
__declspec(dllexport) bool GetEnd(int& xPos, int& yPos);
__declspec(dllexport) bool Restart();


// Returns a string that has both team members name.  Have the C string value return both team member names.  There is no defined format for this.
char* GetTeam()
{
	return team;
}

//sets the maze data from the main program into the DLL.  Save the data into a variable in the DLL. 
bool SetMaze(const int** p_data, int p_width, int p_height)
{
	width = p_width;
	height = p_height;
	data = new int*[width];
	for (int i = 0; i < width; i++)
	{
		data[i] = new int[height];
	}

	if(width <= 0 || height <= 0)
	{
		return false;
	}
	return true;

}

//gets the maze data from the DLL. Return the maze data that was passed in using the SetMaze function, and the width/ height using the references to the arguments. If the maze data is not set, then return nullptr.
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

//returns the next x/y postion to move to.
bool GetNextPosition(int& xpos, int& ypos) 
{
	if(gnpCall >= (sizeof(xvals) / sizeof(*xvals)) || gnpCall >= (sizeof(yvals) / sizeof(*yvals)))
	{
		return false;
	}
	xpos = xvals[gnpCall];
	ypos = yvals[gnpCall];
	gnpCall++;
	return true;
}

//sets the starting location for the player.  Save the x and y values for the starting location. Return true if the data being saved is valid and was saved, else return false.
bool SetStart(int xPos, int yPos)
{

	//return whether x and y are valid
	if (xPos >= 0 && yPos >= 0)
	{
		//Set start variables
		xStart = xPos;
		yStart = yPos;
		return true;
	}
	return false;
}

//gets the starting location for the player.  Return the saved x and y starting locations. Return true if the data for the starting location was saved and is valid, else return false. If you are returning false, then you do not need to send the x and y values back.
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

//sets the ending location for the player.  Save the x and y values for the ending location. Return true if the data being saved is valid and was saved, else return false.
bool SetEnd(int xPos, int yPos)
{

	//return whether x and y are valid
	if (xPos >= 0 && yPos >= 0)
	{
		xEnd = xPos;
		yEnd = yPos;
		return true;
	}
	return false;
}

//gets the ending location for the player.  Return the saved x and y end locations.  Return true if the data for the ending location was saved and is valid, else return false. If you are returning false, then you do not need to send the x and y values back.
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

//this function will make the player start back at their start location and step through each part of the path to the end again.
bool Restart()
{
	return false;
}