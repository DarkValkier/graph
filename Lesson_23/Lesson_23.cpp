#include <iostream>
#include <Windows.h>
#include "Graph.h"

using namespace std;

void generate_graph(Graph& _graph) {
    Graph graph(6);
    graph.set_vertex(0, 6);
    graph.set_vertex(1, 6);
    graph.set_vertex(2, 1);
    graph.set_vertex(3, 3);
    graph.set_vertex(4, 8);
    graph.set_vertex(5, 10);

    graph.set_adjacency(0, 0, 0);
    graph.set_adjacency(0, 1, 1);
    graph.set_adjacency(0, 2, 0);
    graph.set_adjacency(0, 3, 1);
    graph.set_adjacency(0, 4, 0);
    graph.set_adjacency(0, 5, 0);
    graph.set_adjacency(1, 0, 1);
    graph.set_adjacency(1, 1, 0);
    graph.set_adjacency(1, 2, 1);
    graph.set_adjacency(1, 3, 0);
    graph.set_adjacency(1, 4, 0);
    graph.set_adjacency(1, 5, 0);
    graph.set_adjacency(2, 0, 0);
    graph.set_adjacency(2, 1, 1);
    graph.set_adjacency(2, 2, 0);
    graph.set_adjacency(2, 3, 0);
    graph.set_adjacency(2, 4, 0);
    graph.set_adjacency(2, 5, 0);
    graph.set_adjacency(3, 0, 1);
    graph.set_adjacency(3, 1, 0);
    graph.set_adjacency(3, 2, 0);
    graph.set_adjacency(3, 3, 0);
    graph.set_adjacency(3, 4, 1);
    graph.set_adjacency(3, 5, 1);
    graph.set_adjacency(3, 5, 1);
    graph.set_adjacency(4, 0, 0);
    graph.set_adjacency(4, 1, 0);
    graph.set_adjacency(4, 2, 0);
    graph.set_adjacency(4, 3, 1);
    graph.set_adjacency(4, 4, 0);
    graph.set_adjacency(4, 5, 1);
    graph.set_adjacency(5, 0, 0);
    graph.set_adjacency(5, 1, 0);
    graph.set_adjacency(5, 2, 0);
    graph.set_adjacency(5, 3, 1);
    graph.set_adjacency(5, 4, 1);
    graph.set_adjacency(5, 5, 0);
    _graph = graph;
}

Graph& enter_graph() {
    cout << "Введите количество вершин графа: ";
    unsigned int graph_order;
    cin >> graph_order;

    Graph graph1(graph_order);
    
    for (unsigned int i = 0; i < graph_order; i++)
    {
        cout << "Укажите значение для вершины " << i << ": ";
        int value;
        cin >> value;
        graph1.set_vertex(i, value);
        for (unsigned int j = i + 1; j < graph_order; j++)
        {
            if (i == j)
            {
                graph1.set_adjacency(i, j, 0);
            }
            else
            {
                cout << "Связаны ли вершины " << i << " и " << j << "? (y/n): ";
                char answer = 'n';
                cin >> answer;

                if (answer == 'y') {
                    graph1.set_adjacency(i, j, 1);
                    graph1.set_adjacency(j, i, 1);
                }
                else
                {
                    graph1.set_adjacency(i, j, 0);
                    graph1.set_adjacency(j, i, 0);
                }
            }
        }
    }
    return graph1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Graph graph1;
    generate_graph(graph1);
    

    int sum = graph1.sum();
    cout << "Сумма вершин графа: " << sum << "." << endl;
}
