#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    // Define the number of nodes in the graph
    int numberOfNodes = 5;
    
    // Create a Graph object with the specified number of nodes
    Graph* graphObject = new Graph(numberOfNodes);

    // Add edges to the graph
    graphObject->addEdge(0, 1, 2);
    graphObject->addEdge(0, 3, 6);
    graphObject->addEdge(1, 3, 8);
    graphObject->addEdge(1, 4, 5);
    graphObject->addEdge(1, 2, 3);
    graphObject->addEdge(2, 4, 7);

    // Find and print the Minimum Spanning Tree using Prim's Algorithm
    graphObject->findMinimumSpanningTree();
    graphObject->printMinimumSpanningTree();

    // Wait for user input before terminating the program
    cin.get();
    
    // Deallocate memory for the graph object
    delete graphObject;

    return 0;
}
