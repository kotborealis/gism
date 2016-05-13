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

vector<int> PathsToAllNodes(Graph g, int n){
    vector<int> paths(n*n,-1);
    for(int i=0;i<n;i++){
        vector<int> used(n,false);
        vector<int> m(n,0);
        queue<int> q;
        int c_node;
        q.push(i);
        while(!q.empty()){
            c_node = q.front();q.pop();
            used[c_node]=true;
            paths[i*n+c_node]=m[c_node];

            for(int j=0;j<n;j++){
                if(used[j] || !g.adjacencyMatrix[c_node][j])
                    continue;
                q.push(j);
                m[j]=m[c_node]+1;
            }
        }
    }
    sort(paths.begin(),paths.end());
    return paths;
}

int main(int argc, char** argv){
    clock_t tStart = clock();
    int n,_n_call;
    cin>>n;
    _n_call=n-1>13?13:n-1;
    Graph graph_a = loadGraph(n);
    Graph graph_b = loadGraph(n);

    //if(n>10){
        /**
         * TODO: Invariants
         */

        /** Edges and passport **/
        int a_edges=0,b_edges=0;
        vector<int> a_passport(n);
        vector<int> b_passport(n);
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++){
                    /** Edges count **/
                    a_edges+=graph_a.adjacencyMatrix[x][y];
                    b_edges+=graph_b.adjacencyMatrix[x][y];

                    /** Passport **/
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

        vector<int> a_p = PathsToAllNodes(graph_a, n);
        vector<int> b_p = PathsToAllNodes(graph_b, n);
        for(int i=0;i<n;i++)
            if(a_p[i]!=b_p[i]){
                cout<<"PATHS\n";
                _TIME;
                _NFOUND;
            }
    //}

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
            SwapColsUnroll[_n_call](graph_a.adjacencyMatrix,n,a,b);
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
                return 1;
            }
        }
        else
            idx[i++] = 0;
    }
    _TIME;
    _NFOUND;
    return 0;
}

