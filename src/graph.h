#pragma once
#include <fstream>
#include <iostream>
#include <cstdint>
#include <sstream>

using namespace std;

using namespace std;

struct Graph{
    int vertexCount;
    bool** adjacencyMatrix;
};
Graph loadGraph(int n, istringstream& input);
