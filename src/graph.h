#pragma once
#include <fstream>
#include <iostream>
#include <cstdint>

using namespace std;

struct Graph{
    int vertexCount;
    int** adjacencyMatrix;
};
Graph loadGraph(int n);
