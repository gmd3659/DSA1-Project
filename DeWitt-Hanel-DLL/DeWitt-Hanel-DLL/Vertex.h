#pragma once


class Vertex
{
public:
	Vertex(int p_xpos, int p_ypos, int xEnd, int yEnd);
	~Vertex();
	int getX();
	int getY();
	int getHeur();

	int xPos;
	int yPos;
	int heuristic;
	int lowestCost;
	bool visited;
};

