#pragma once
#include <fstream>
#include <iostream>

using namespace std;

struct Graph{
    int vertexCount;
    int** adjacencyMatrix;
};
Graph loadGraph(int n);
