#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdint>
#include <queue>
#include <vector>
#include <algorithm>
#include "graph.h"
#include "SwapColsUnroll.h"
#include "equalMatrixUnroll.h"

#define _TIME_DISABLED false
#define _TIME if(!_TIME_DISABLED){cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<"ms\n";}
#define _FOUND cout<<"YES\n";return 0;
#define _NFOUND cout<<"NO\n";return 0;

#define _MAX_NODES 16

using namespace std;

int ConnectedComponents(Graph g, int n){
    vector<int> used(n,false);
    int c_node;
    int cc=1;
    for(int i=0;i<n;i++){
        if(used[i])
            continue;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            c_node = q.front();q.pop();

            if(used[c_node])continue;
            used[c_node]=true;

            for(int j=0;j<n;j++)
                if(g.adjacencyMatrix[c_node][j])
                    q.push(j);
        }
        for(int j=0;j<n;j++)
            if(!used[j]){
                cc++;
                break;
            }
    }
    return cc;
}

int idx[_MAX_NODES];

int main(int argc, char** argv){
    clock_t tStart = clock();
    int n,_n_call;
    cin>>n;
    _n_call=n-1>13?13:n-1;
    Graph graph_a = loadGraph(n);
    Graph graph_b = loadGraph(n);

    if(n>10){
        /**
         * TODO: Invariants
         */

        /** Edges and passport **/
        int a_edges=0,b_edges=0;
        vector<int> a_passport(n);
        vector<int> b_passport(n);
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++){
                    a_edges+=graph_a.adjacencyMatrix[x][y];
                    b_edges+=graph_b.adjacencyMatrix[x][y];

                    a_passport[x]+=graph_a.adjacencyMatrix[x][y];
                    b_passport[x]+=graph_b.adjacencyMatrix[x][y];
            }
        if(a_edges!=b_edges){
            _TIME;
            _NFOUND;
        }
        sort(a_passport.begin(),a_passport.end());
        sort(b_passport.begin(),b_passport.end());
        for(int i=0;i<n;i++)
            if(a_passport[i]!=b_passport[i]){
                _TIME;
                _NFOUND;
            }

        /** Connected components **/
        int a_cc = ConnectedComponents(graph_a,n);
        int b_cc = ConnectedComponents(graph_b,n);
        if(a_cc!=b_cc){
            _TIME;
            _NFOUND;
        }
    }

    /**
     * Enumerate permutations and permutate matrices
     */
    int* swap_ptr = NULL;
    int a,b;
    for(int i = 0; i<_MAX_NODES; i++)
        idx[i]=0;
    for(int i=0; i<n;) {
        if (idx[i] < i) {
            a = i % 2 * idx[i];
            idx[i]++;
            /**
             * Permutate matrix a
             */
            /**
             * Swap rows
             */
            swap_ptr = graph_a.adjacencyMatrix[a];
            graph_a.adjacencyMatrix[a] = graph_a.adjacencyMatrix[i];
            graph_a.adjacencyMatrix[i] = swap_ptr;
            /**
             * Swap collumns
             */
            SwapColsUnroll[_n_call](graph_a.adjacencyMatrix,n,a,i);
            /**
             * Compare adjacency matrix of graph a and graph b
             */
            bool equal = equalMatrixUnroll[_n_call](graph_a.adjacencyMatrix,graph_b.adjacencyMatrix,n);
            /**
             * If equal===true then graph a and graph b isomorphic
             */
            if(equal){
                _TIME;
                _FOUND;
            }
            i = 1;
        }
        else
            idx[i++] = 0;
    }
    _TIME;
    _NFOUND;
    return 0;
}

