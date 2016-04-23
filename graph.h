#pragma once
#include <fstream>
#include <iostream>

using namespace std;

struct Graph{
    int vertexCount;
    int** adjacencyMatrix;
};
/**
 * Load graph from file
 * @param  filename
 * @return {int} Number of vertex
 */
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
}

void printGraph(Graph graph){
    int row_counter=0,col_counter=0;
    for(size_t i = 0; i<graph.vertexCount*graph.vertexCount; i++){
        cout<<graph.adjacencyMatrix[row_counter][col_counter++]<<" ";
        if(col_counter==graph.vertexCount){
            col_counter=0;
            row_counter++;
            cout<<"\n";
        }
    }
    cout<<"\n";
}
