#pragma once
#include <string>
#include <vector>
#include "Vertex.h"


class Graph
{
public:
	Graph();
	~Graph();

	std::vector<Vertex> vertices;
	int adjacencyMatrix[];
};

