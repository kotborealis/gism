#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdint>
#include <queue>
#include <vector>
#include <algorithm>
#include "graph.h"

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
void SwapColsUnroll1(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
}
void SwapColsUnroll2(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
}
void SwapColsUnroll3(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
}
void SwapColsUnroll4(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
}
void SwapColsUnroll5(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
}
void SwapColsUnroll6(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
}
void SwapColsUnroll7(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
}
void SwapColsUnroll8(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
}
void SwapColsUnroll9(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
}
void SwapColsUnroll10(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
    swap=m[9][a];
    m[9][a]=m[9][b];
    m[9][b]=swap;
}
void SwapColsUnroll11(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
    swap=m[9][a];
    m[9][a]=m[9][b];
    m[9][b]=swap;
    swap=m[10][a];
    m[10][a]=m[10][b];
    m[10][b]=swap;
}
void SwapColsUnroll12(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
    swap=m[9][a];
    m[9][a]=m[9][b];
    m[9][b]=swap;
    swap=m[10][a];
    m[10][a]=m[10][b];
    m[10][b]=swap;
    swap=m[11][a];
    m[11][a]=m[11][b];
    m[11][b]=swap;
}
void SwapColsUnroll13(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
    swap=m[9][a];
    m[9][a]=m[9][b];
    m[9][b]=swap;
    swap=m[10][a];
    m[10][a]=m[10][b];
    m[10][b]=swap;
    swap=m[11][a];
    m[11][a]=m[11][b];
    m[11][b]=swap;
    swap=m[12][a];
    m[12][a]=m[12][b];
    m[12][b]=swap;
}
void SwapColsUnrollN(int** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;
    swap=m[3][a];
    m[3][a]=m[3][b];
    m[3][b]=swap;
    swap=m[4][a];
    m[4][a]=m[4][b];
    m[4][b]=swap;
    swap=m[5][a];
    m[5][a]=m[5][b];
    m[5][b]=swap;
    swap=m[6][a];
    m[6][a]=m[6][b];
    m[6][b]=swap;
    swap=m[7][a];
    m[7][a]=m[7][b];
    m[7][b]=swap;
    swap=m[8][a];
    m[8][a]=m[8][b];
    m[8][b]=swap;
    swap=m[9][a];
    m[9][a]=m[9][b];
    m[9][b]=swap;
    swap=m[10][a];
    m[10][a]=m[10][b];
    m[10][b]=swap;
    swap=m[11][a];
    m[11][a]=m[11][b];
    m[11][b]=swap;
    swap=m[12][a];
    m[12][a]=m[12][b];
    m[12][b]=swap;

    for(int i=13;i<n;i++){
        swap=m[i][a];
        m[i][a]=m[i][b];
        m[i][b]=swap;
    }
}

typedef void (*SwapColsUnrollType) (int** m, int n, int a, int b);
SwapColsUnrollType SwapColsUnroll[]={
    SwapColsUnroll1,
    SwapColsUnroll2,
    SwapColsUnroll3,
    SwapColsUnroll4,
    SwapColsUnroll5,
    SwapColsUnroll6,
    SwapColsUnroll7,
    SwapColsUnroll8,
    SwapColsUnroll9,
    SwapColsUnroll10,
    SwapColsUnroll11,
    SwapColsUnroll12,
    SwapColsUnroll13,
    SwapColsUnrollN
};

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
    }

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
            /*for(int j=0; j<n; j++){
                swap=graph_a.adjacencyMatrix[j][a];
                graph_a.adjacencyMatrix[j][a]=graph_a.adjacencyMatrix[j][b];
                graph_a.adjacencyMatrix[j][b]=swap;
            }*/
            SwapColsUnroll[_n_call](graph_a.adjacencyMatrix,n,a,b);
            /**
             * Compare adjacency matrix of graph a and graph b
             */
            bool equal = true;
            for(int k=0;k<n && equal;k++)
                for(int j=0;j<n && equal;j++)
                        equal=graph_a.adjacencyMatrix[k][j]==graph_b.adjacencyMatrix[k][j];
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

