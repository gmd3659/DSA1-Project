#include "stdafx.h"
#include "Vertex.h"
#include "Graph.h"
#include <cstdlib>



Vertex::Vertex(int p_xpos, int p_ypos, int xEnd, int yEnd)
{
	visited = false;
	xPos = p_xpos;
	yPos = p_ypos;
	heuristic = abs(xPos - xEnd) + abs(yPos - yEnd);
}

int Vertex::getX() 
{
	return xPos;
}

int Vertex::getY()
{
	return yPos;
}

int Vertex::getHeur()
{
	return heuristic;
}


Vertex::~Vertex()
{
}
