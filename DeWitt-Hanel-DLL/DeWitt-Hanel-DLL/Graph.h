#pragma once
#include <string>
#include <vector>
#include "Vertex.h"


class Graph
{
public:
	Graph();
	~Graph();

	std::vector<Vertex> openList = {};
	std::vector<Vertex> closedList = {};
	int** adjacencyMatrix;

	int** data;
	int width;
	int height;

	std::vector<int> yvals;
	std::vector<int> xvals;
};

