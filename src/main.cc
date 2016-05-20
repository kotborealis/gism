#include <iostream>
#include <time.h>
#include <queue>
#include <algorithm>
#include "graph.h"
#include "SwapColsUnroll.h"
#include "equalMatrixUnroll.h"

#define _TIME_DISABLED false
#define _ENABLE_INVARIANTS_ON 0
#define _TIME if(!_TIME_DISABLED){cout<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<"ms\n";}
#define _FOUND cout<<"YES\n";return 0;
#define _NFOUND cout<<"NO\n";return 0;

#define _MAX_NODES 16

using namespace std;

int ConnectedComponents(Graph g, int n){
    bool* used = new bool[n];
    int c_node;
    int cc=1;
    for(int i=0;i<n;i++)
      used[i]=false;
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

    if(n>=_ENABLE_INVARIANTS_ON){
        /** Edges and passport **/
        int a_edges=0,b_edges=0;
        int* a_passport = new int[n];
        int* b_passport = new int[n];
        for(int x=0;x<n;x++){
            a_passport[x]=0;
            b_passport[x]=0;
            for(int y=0;y<n;y++){
                    a_edges+=graph_a.adjacencyMatrix[x][y];
                    b_edges+=graph_b.adjacencyMatrix[x][y];

                    a_passport[x]+=graph_a.adjacencyMatrix[x][y];
                    b_passport[x]+=graph_b.adjacencyMatrix[x][y];
            }
        }
        /** If graphs have diffrent number of edges **/
        if(a_edges!=b_edges){
            _TIME;
            _NFOUND;
        }
        sort(a_passport,a_passport+n);
        sort(b_passport,b_passport+n);
        /** If their passports are not equal **/
        for(int i=0;i<n;i++)
            if(a_passport[i]!=b_passport[i]){
                _TIME;
                _NFOUND;
            }
        /**/

        /** Paths and cycles **/
        int* m_a = new int[n];
        int* m_b = new int[n];
        bool* u_a = new bool[n];
        bool* u_b = new bool[n];
        int d_a=0,d_b=0;
        queue<int> q;
        int c_node;
        bool cycles_a, cycles_b;
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++){
                m_a[i]=0;
                m_b[i]=0;
                u_a[i]=false;
                u_b[i]=false;
            }
            q.push(i);
            u_a[i]=true;
            while(!q.empty()){
                c_node = q.front();q.pop();
                if(m_a[c_node]>d_a)d_a=m_a[c_node];
                for(int j=0;j<n;j++){
                    if(!u_a[j] && graph_a.adjacencyMatrix[c_node][j]){
                        u_a[j]=true;
                        q.push(j);
                        m_a[j]=m_a[c_node]+1;
                    }
                    cycles_a=m_a[j]>=m_a[c_node];
                }
            }
            q.push(i);
            u_b[i]=true;
            while(!q.empty()){
                c_node = q.front();q.pop();
                if(m_b[c_node]>d_b)d_b=m_b[c_node];
                for(int j=0;j<n;j++){
                    if(!u_b[j] && graph_b.adjacencyMatrix[c_node][j]){
                        u_b[j]=true;
                        q.push(j);
                        m_b[j]=m_b[c_node]+1;
                    }
                    cycles_b=m_b[j]>=m_b[c_node];
                }
            }
        }
        /** if one have cycle and other dont **/
        if(cycles_b!=cycles_a){
          _TIME;
          _NFOUND;
        }
        if(d_a!=d_b){
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
        /**/
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
