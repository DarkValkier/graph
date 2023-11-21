#include "Graph.h"

Graph::Graph() {}

Graph::Graph(unsigned int _order) : order(_order)
{
	values = new int[_order];
	adjacency = new int*[_order];
	for (unsigned int i = 0; i < _order; i++)
	{
		adjacency[i] = new int[_order];
	}
}

Graph::Graph(Graph& _source) : order(_source.order)
{
	
	values = new int[order];
	adjacency = new int* [order];
	for (unsigned int i = 0; i < order; i++)
	{
		adjacency[i] = new int[order];
	}

	for (unsigned int i = 0; i < order; i++) {
		values[i] = _source.values[i];
		for (unsigned int j = 0; j < order; j++)
			adjacency[i][j] = _source.adjacency[i][j];
	}
}

Graph::~Graph()
{
	delete []values;
	for (unsigned int i = 0; i < order; i++)
		delete []adjacency[i];
	delete[]adjacency;
}

unsigned int Graph::get_order()
{
	return order;
}

int Graph::get_vertex(unsigned int _index)
{
	return values[_index];
}

void Graph::set_vertex(unsigned int _index, int _value)
{
	values[_index] = _value;
}

int Graph::get_adjacency(unsigned int _vertex1, unsigned int _vertex2)
{
	return adjacency[_vertex1][_vertex2];
}

void Graph::set_adjacency(unsigned int _vertex1, unsigned int _vertex2, int _value)
{
	adjacency[_vertex1][_vertex2] = _value;
}

int Graph::sum() {
	int result = 0;

	unsigned int start_vertex = 0;
	bool* visited = new bool[order];
	unsigned int* vertexes = new unsigned int[order];
	unsigned int vertexes_count = 0;

	for (unsigned int i = 0; i < order; i++)
	{
		visited[i] = false;
	}

	vertexes[0] = start_vertex;
	vertexes_count++;

	while (vertexes_count > 0)
	{
		unsigned int current_vertex = vertexes[vertexes_count - 1];
		vertexes[vertexes_count - 1] = -1;
		vertexes_count--;
		visited[current_vertex] = true;
		cout << "Входим в вершину " << current_vertex << endl;

		result += values[current_vertex];
		cout << "Значение вершины: " << values[current_vertex] << " | ";
		cout << "Текущая сумма: " << result << endl;

		for (unsigned int i = 0; i < order; i++) {
			if (visited[i])
				continue;
			if (adjacency[current_vertex][i] > 0) {
				vertexes[vertexes_count] = i;
				vertexes_count++;
				visited[i] = true;
			}
		}

		cout << "vertexes: ";
		for (unsigned int i = 0; i < vertexes_count; i++)
			cout << vertexes[i] << "  ";
		cout << endl;
	}
	return result;
}

Graph& Graph::operator=(Graph& _source) {
	order = _source.order;

	values = new int[order];
	adjacency = new int* [order];
	for (unsigned int i = 0; i < order; i++)
	{
		adjacency[i] = new int[order];
	}

	for (unsigned int i = 0; i < order; i++) {
		values[i] = _source.values[i];
		for (unsigned int j = 0; j < order; j++)
			adjacency[i][j] = _source.adjacency[i][j];
	}

	return *this;
}