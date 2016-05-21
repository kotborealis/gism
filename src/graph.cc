#include "graph.h"

Graph loadGraph(int n){
    Graph graph;

    graph.vertexCount=n;
    graph.adjacencyMatrix=new bool*[graph.vertexCount];

    bool buf;
    int row_counter=0,col_counter=0,c=0;
    graph.adjacencyMatrix[row_counter]=new bool[graph.vertexCount];
    while(c++<n*n && cin>>buf){
        if(col_counter==graph.vertexCount){
            col_counter=0;
            row_counter++;
            graph.adjacencyMatrix[row_counter]=new bool[graph.vertexCount];
        }
        graph.adjacencyMatrix[row_counter][col_counter++]=buf;
    }
    return graph;
};
