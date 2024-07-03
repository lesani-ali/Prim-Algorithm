# Prim's Algorithm for Minimum Spanning Tree

This repository contains an implementation of Prim's Algorithm to find the Minimum Spanning Tree (MST) of a given graph. The implementation is written in C++ and is structured into three files: `Main.cpp`, `Graph.h`, and `Graph.cpp`.

## Files

- **Main.cpp**: Contains the `main` function which initializes the graph, adds edges, and invokes functions to find and print the MST.
- **Graph.h**: Header file declaring the `Graph` class and its member functions and variables.
- **Graph.cpp**: Implementation of the `Graph` class functions including adding edges, finding the MST using Prim's Algorithm, and printing the MST.

## Usage

1. **Initialize the Graph**: Create an instance of the `Graph` class by specifying the number of nodes.
2. **Add Edges**: Use the `addEdge` function to add edges between nodes with specified weights.
3. **Find MST**: Call the `findMinimumSpanningTree` function to compute the MST using Prim's Algorithm.
4. **Print MST**: Use the `printMinimumSpanningTree` function to output the edges and total weight of the MST.

## Example

```cpp
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
```
