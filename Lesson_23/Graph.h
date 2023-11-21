#pragma once
#include <iostream>

using namespace std;

class Graph
{
	int* values = nullptr;
	int** adjacency = nullptr;
	unsigned int order = 0;
public:
	Graph();
	Graph(unsigned int);
	Graph(Graph&);
	~Graph();

	unsigned int get_order();
	int get_vertex(unsigned int);
	void set_vertex(unsigned int, int);
	int get_adjacency(unsigned int, unsigned int);
	void set_adjacency(unsigned int, unsigned int, int);

	Graph& operator=(Graph&);

	int sum();
};

