#pragma once


class Vertex
{
public:
	Vertex(int p_xpos, int p_ypos);
	~Vertex();

	int xPos;
	int yPos;
	int heuristic;
	int lowestCost;
	bool visited;
};

