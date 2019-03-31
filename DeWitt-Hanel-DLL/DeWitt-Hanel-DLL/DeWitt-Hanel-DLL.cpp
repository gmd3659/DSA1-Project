// DeWitt-Hanel-DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Graph.h"
#include "Vertex.h"
#include <vector>
#include <stack>




Graph g = Graph();


size_t gnpCall = 0;

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
	
	g.width = p_width;
	g.height = p_height;
	g.data = new int*[g.width];
	for (int i = 0; i < g.width; i++)
	{
		g.data[i] = new int[g.height];
	}

	for (int i = 0; i < g.height; i++)
	{
		for (int j = 0; j < g.width; j++) 
		{
			g.data[i][j] = p_data[i][j];
		}
	}

	for (int i = 0; i < g.height; i++)
	{
		for (int j = 0; j < g.width; j++)
		{
			if (g.data[i][j] == 0)
			{
				g.openList.push_back(Vertex(i, j, g.xEnd, g.yEnd));
			}
		}
	}

	if(g.width <= 0 || g.height <= 0)
	{
		return false;
	}
	return true;

}

//gets the maze data from the DLL. Return the maze data that was passed in using the SetMaze function, and the width/ height using the references to the arguments. If the maze data is not set, then return nullptr.
int** GetMaze(int& p_width, int& p_height)
{
	p_width = g.width;
	p_height = g.height;
	return const_cast<int**>(g.data);

	if (g.data == NULL)
	{
		return nullptr;
	}
}



//returns the next x/y postion to move to.
bool GetNextPosition(int& xpos, int& ypos) 
{
	//Set current/starting vector
	std::vector<Vertex> tempVector = {Vertex(xpos, ypos, g.xEnd, g.yEnd)};
	
	//Set visisted to true and add current vertex to stack
	for (size_t i = 0; i < g.openList.size(); i++)
	{
		if (g.openList[i].getX() == xpos && g.openList[i].getY() == ypos)
		{
			g.openList[i].visited = true;

			//Check for it being the start
			if (g.previousPath.size() == 0)
			{
				g.previousPath.push(g.openList[i]);

			}
			//Check to make sure were not pushing the same vertex twice
			else if (g.previousPath.top().getX() != xpos || g.previousPath.top().getY() != ypos)
			{
				g.previousPath.push(g.openList[i]);
			}

		}
	}

	//Check which of the 4 adjacent spaces can be moved to
	for(size_t i = 0; i < g.openList.size(); i++)
	{
		if (g.openList[i].getX() == xpos + 1 && g.openList[i].getY() == ypos && g.openList[i].visited == false) 
		{
			tempVector.push_back(g.openList[i]);
		}
		if (g.openList[i].getX() == xpos && g.openList[i].getY() == ypos + 1 && g.openList[i].visited == false)
		{
			tempVector.push_back(g.openList[i]);
		}
		if (g.openList[i].getX() == xpos - 1 && g.openList[i].getY() == ypos && g.openList[i].visited == false)
		{
			tempVector.push_back(g.openList[i]);
		}
		if (g.openList[i].getX() == xpos && g.openList[i].getY() == ypos - 1 && g.openList[i].visited == false)
		{
			tempVector.push_back(g.openList[i]);
		}
	}

	
	//Check for more than 0 valid adjacent spaces
	if (tempVector.size() == 1)
	{
		//If less than 0 valid spaces

		//Pop the current vertex off the stack
		g.previousPath.pop();

		//Set lastVert equal to the previous vertex to step backwards
		Vertex lastVert = g.previousPath.top();
		
		//Set the previously vertex's visited to false
		for (size_t i = 0; i < g.openList.size(); i++)
		{
			if (g.openList[i].getX() == lastVert.getX() && g.openList[i].getY() == lastVert.getY())
			{
				g.openList[i].visited = false;
			}
		}
	}
	else 
	{
		//If more than 0 valid spaces
		Vertex lowest = tempVector[1];

		for (size_t i = 1; i < tempVector.size(); i++)
		{
			if (tempVector[i].getHeur() < lowest.getHeur())
			{
				lowest = tempVector[i];
			}
			xpos = lowest.getX();
			ypos = lowest.getY();
		}
	}

	return true;
}

//sets the starting location for the player.  Save the x and y values for the starting location. Return true if the data being saved is valid and was saved, else return false.
bool SetStart(int xPos, int yPos)
{

	//return whether x and y are valid
	if (xPos >= 0 && yPos >= 0)
	{
		//Set start variables
		g.xStart = xPos;
		g.yStart = yPos;
		return true;
	}
	return false;
}

//gets the starting location for the player.  Return the saved x and y starting locations. Return true if the data for the starting location was saved and is valid, else return false. If you are returning false, then you do not need to send the x and y values back.
bool GetStart(int& xPos, int& yPos)
{
	if (g.xStart >= 0 && g.yStart >= 0)
	{
		//Return values and true
		xPos = g.xStart;
		yPos = g.yStart;
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
		g.xEnd = xPos;
		g.yEnd = yPos;
		return true;
	}
	return false;
}

//gets the ending location for the player.  Return the saved x and y end locations.  Return true if the data for the ending location was saved and is valid, else return false. If you are returning false, then you do not need to send the x and y values back.
bool GetEnd(int& xPos, int& yPos)
{
	if (g.xEnd >= 0 && g.yEnd >= 0)
	{
		//Return values and true
		xPos = g.xEnd;
		yPos = g.yEnd;
		return true;
	}
	else
	{
		return false;
	}
}

//this function will make the player start back at their start location and step through each part of the path to the end again.
bool Restart()
{
	return false;
}