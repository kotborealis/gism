#include "graph.h"

Graph loadGraph(int n){
    Graph graph;

    graph.vertexCount=n;
    graph.adjacencyMatrix=new int*[graph.vertexCount];

    int buf,row_counter=0,col_counter=0,c=0;
    graph.adjacencyMatrix[row_counter]=new int[graph.vertexCount];
    cout<<"Start\n";
    while(c++<n*n && cin>>buf){
        cout<<buf<<" ";
        if(col_counter==graph.vertexCount){
            col_counter=0;
            row_counter++;
            graph.adjacencyMatrix[row_counter]=new int[graph.vertexCount];
            cout<<"\n";
        }
        graph.adjacencyMatrix[row_counter][col_counter++]=buf;
    }
    cout<<"End\n";
    return graph;
};
