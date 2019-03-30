#include "stdafx.h"
#include "Vertex.h"
#include <cstdlib>



Vertex::Vertex(int p_xpos, int p_ypos)
{
	xPos = p_xpos;
	yPos = p_ypos;
	//heuristic = abs(xPos - xEnd) + abs(yPos - yEnd);
}


Vertex::~Vertex()
{
}
