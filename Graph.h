#ifndef Graph_H
#define Graph_H

#include <vector>
#include <iostream>
#include "string.h"

using namespace std;

class Graph
{
public:
    // Constructor to initialize the graph with the given number of nodes
    Graph(int numberOfNodes);
    
    // Destructor to clean up the allocated memory
    ~Graph();

    // Function to add an edge between two nodes with a specified weight
    void addEdge(int firstNode, int secondNode, int weight);
    
    // Function to find the Minimum Spanning Tree using the specified algorithm (default is Prim's)
    void findMinimumSpanningTree(string algorithm = "prim");
    
    // Function to print the Minimum Spanning Tree
    void printMinimumSpanningTree();

private:
    int theNumberOfNodes; // Number of nodes in the graph
    vector<pair<int, int>>* theAdjMatrix; // Adjacency list representation of the graph
    int* theParent; // Array to store the parent of each node in the MST
    int* theKeys; // Array to store the key values used to pick minimum weight edge
    bool* theMSTSet; // Array to represent the set of vertices included in MST
    int theMinimumCost; // Minimum cost of the spanning tree
};

#endif // Graph_H
