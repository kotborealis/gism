#include "graph.h"

Graph loadGraph(char* filename){
    ifstream file (filename);
    Graph graph;

    file>>graph.vertexCount;

    graph.adjacencyMatrix=new int*[graph.vertexCount];

    int buf,row_counter=0,col_counter=0;
    graph.adjacencyMatrix[row_counter]=new int[graph.vertexCount];
    while(file>>buf){
        if(col_counter==graph.vertexCount){
            col_counter=0;
            row_counter++;
            graph.adjacencyMatrix[row_counter]=new int[graph.vertexCount];
        }
        graph.adjacencyMatrix[row_counter][col_counter++]=buf;
    }
    return graph;
};
