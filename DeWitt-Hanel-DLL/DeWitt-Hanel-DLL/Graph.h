#pragma once
#include <string>
#include <vector>
#include "Vertex.h"
#include <stack>

class Graph
{
public:
	Graph();
	~Graph();

	//list of all 0's in data that are unvisited
	std::vector<Vertex> openList = {};
	std::stack<Vertex> previousPath = {};
	int** adjacencyMatrix;

	//sent in by exe
	int** data;
	int width;
	int height;

	//start and end positions, sent in by exe
	int xStart;
	int yStart;
	int xEnd;
	int yEnd;
};

