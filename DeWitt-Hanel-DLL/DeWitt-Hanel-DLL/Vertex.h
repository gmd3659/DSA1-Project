#pragma once
class Vertex
{
public:
	Vertex();
	~Vertex();

	int xPos;
	int yPos;
	int heuristic;
	int lowestCost;
	bool visited;
};

