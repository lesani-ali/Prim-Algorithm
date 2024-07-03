#include "Graph.h"

#define INF 9999999 // Define an infinite value

// Constructor to initialize the graph with the given number of nodes
Graph::Graph(int numberOfNodes) : theNumberOfNodes{ numberOfNodes }
{
    theAdjMatrix = new vector<pair<int, int>>[numberOfNodes];
    theParent = new int[numberOfNodes];
    theKeys = new int[numberOfNodes];
    theMSTSet = new bool[numberOfNodes];
    theMinimumCost = 0;
}

// Destructor to clean up the allocated memory
Graph::~Graph() 
{
    delete[] theAdjMatrix;
    delete[] theParent;
    delete[] theKeys;
    delete[] theMSTSet;
}

// Function to add an edge between two nodes with a specified weight
void Graph::addEdge(int firstNode, int secondNode, int weight)
{
    theAdjMatrix[firstNode].push_back(make_pair(secondNode, weight));
    theAdjMatrix[secondNode].push_back(make_pair(firstNode, weight));
}

// Function to find the Minimum Spanning Tree using Prim's Algorithm
void Graph::findMinimumSpanningTree(string algorithm)
{
    // Initialize keys as infinite and MST set as false
    for (int i = 0; i < theNumberOfNodes; i++) {
        theKeys[i] = INF;
        theMSTSet[i] = false;
        theParent[i] = -1;
    }

    // Key value of the first node is set to 0
    theKeys[0] = 0;

    int index;
    int mini;
    // Loop to find the minimum key value
    for (int i = 0; i < theNumberOfNodes - 1; i++) {
        mini = INF;
        for (int v = 0; v < theNumberOfNodes; v++) {
            if (!theMSTSet[v] && theKeys[v] < mini) {
                mini = theKeys[v];
                index = v;
            }
        }

        theMSTSet[index] = true;

        // Update the key values of the adjacent nodes
        for (auto it : theAdjMatrix[index]) {
            int vertix = it.first;
            int weight = it.second;
            if (!theMSTSet[vertix] && weight < theKeys[vertix]) {
                theParent[vertix] = index;
                theKeys[vertix] = weight;
            }
        }
    }
}

// Function to print the Minimum Spanning Tree
void Graph::printMinimumSpanningTree()
{
    for (int i = 1; i < theNumberOfNodes; i++) {
        cout << theParent[i] << " - " << i << endl;
        theMinimumCost += theKeys[i];
    }

    cout << "\nThe sum of weights of minimum spanning tree: " << theMinimumCost;
}
