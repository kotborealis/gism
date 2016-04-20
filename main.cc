#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdint>
#include "graph.h"

#define _INT int

using namespace std;

int main(int argc, char** argv){
    if(argc<3){
        cout<<"Expected 2 args, got only "<<argc<<"\n";
        return 1;
    }
    Graph graph_a = loadGraph(argv[1]);
    Graph graph_b = loadGraph(argv[2]);

};
