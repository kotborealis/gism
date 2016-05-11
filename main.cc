#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdint>
#include "graph.h"

using namespace std;

int main(int argc, char** argv){
    clock_t tStart = clock();//measure program execution time
    double tEnd;//measure program execution time
    /*if(argc<3){
        cout<<"Expected 2 args, got only "<<argc<<"\n";
        return 1;
    }*/
    int n;
    cin>>n;
    Graph graph_a = loadGraph(n);
    Graph graph_b = loadGraph(n);
    
    /**
     * TODO: Invariants
     */

    /**
     * Enumerate permutations and permutate matrices
     */
    int* idx = new int[n];
    int swap,_ = 0;
    int* swap_ptr = NULL;
    for(int i = 0; i<n; i++)
        idx[i]=0;
    for(int i=0; i<n;) {
        if (idx[i] < i) {
            swap = i % 2 * idx[i];
            int a = swap;
            int b = i;
            idx[i]++;
            i = 1;

            /**
             * Permutate matrix a
             */
            /**
             * Swap rows
             */
            swap_ptr = graph_a.adjacencyMatrix[a];
            graph_a.adjacencyMatrix[a] = graph_a.adjacencyMatrix[b];
            graph_a.adjacencyMatrix[b] = swap_ptr;
            /**
             * Swap collumns
             */
            for(int j=0; j<n; j++){
                if(graph_a.adjacencyMatrix[j][a] ^ graph_a.adjacencyMatrix[j][b]){
                    swap=graph_a.adjacencyMatrix[j][a];
                    graph_a.adjacencyMatrix[j][a]=graph_a.adjacencyMatrix[j][b];
                    graph_a.adjacencyMatrix[j][b]=swap;
                }
            }
            /**
             * Compare adjacency matrix of graph a and graph b
             */
            bool equal = true;
            for(int k=0;k<n && equal;k++)
                for(int j=0;j<n && equal;j++)
                    if(graph_a.adjacencyMatrix[k][j] ^ graph_b.adjacencyMatrix[k][j])//then not equal
                        equal=false;
            /**
             * If equal===true then graph a and graph b isomorphic
             */
            if(equal){
                tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
                cout<<"Found isomorphism in "<<tEnd<<"ms\n";
                return 1;
            }
        }
        else
            idx[i++] = 0;
    }
    tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<<"isomorphism not found in "<<tEnd<<"ms\n";
    return 0;
}
