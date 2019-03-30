#include "stdafx.h"
#include "Graph.h"



Graph::Graph()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (data[i][j] == 0)
			{
				openList.push_back(Vertex(i, j));
				xvals.push_back(i);
				yvals.push_back(j);
			}
		}
	}
}




Graph::~Graph()
{
}


