#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <cstdint>

#define _INT int

using namespace std;

void printMatrix(_INT** a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            std::cout<<(int)a[i][j]<<" ";
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void printPermutation(_INT *p, int n){
    std::cout<<"permutation\n";
    for(int i=0;i<n;i++)
        std::cout<<(int)p[i]<<" ";
    std::cout<<"\n\n";
}

int main(int argc, char** argv){
    clock_t tStart = clock();
    int n = atoi(argv[1]);
    _INT* permutation = new _INT[n];
    int* idx = new int[n];
    _INT _;
    _INT* _ptr;
    int row_counter_a=0;
    int col_counter_a=0;
    int row_counter_b=0;
    int col_counter_b=0;

    _INT** a = (_INT**)malloc(sizeof(_INT*)*n);
    _INT** a_ = (_INT**)malloc(sizeof(_INT*)*n);
    _INT** a_temp = (_INT**)malloc(sizeof(_INT*)*n);
    _INT** perm_m = (_INT**)malloc(sizeof(_INT*)*n);
    _INT** b = (_INT**)malloc(sizeof(_INT*)*n);
    for(int i=0;i<n;i++){
        a[i]=(_INT*)malloc(sizeof(_INT)*n);
        a_[i]=(_INT*)malloc(sizeof(_INT)*n);
        a_temp[i]=(_INT*)malloc(sizeof(_INT)*n);
        perm_m[i]=(_INT*)malloc(sizeof(_INT)*n);
        b[i]=(_INT*)malloc(sizeof(_INT)*n);
    }

    //Read
    ifstream file_a ("a.txt");
    ifstream file_b ("b.txt");
    while(file_a>>_){
        a[row_counter_a][col_counter_a]=_;
        if(++col_counter_a==n){
            col_counter_a=0;
            row_counter_a++;
        }
    }
    while(file_b>>_){
        b[row_counter_b][col_counter_b]=_;
        if(++col_counter_b==n){
            col_counter_b=0;
            row_counter_b++;
        }
    }
    if(col_counter_b!=col_counter_a || row_counter_b!=row_counter_a){
        std::cout<<"Pizdec!\n";
        return 0;
    }
    std::cout<<"A\n";
    printMatrix(a,n);

    for(int i=0;i<n;i++){
        permutation[i]=i;
        idx[i]=0;
    }
    int counter=0;
    for (int i=1;i<n;counter++){
        if(idx[i]<i){
            int swap = i%2*idx[i];
            int tmp = permutation[swap];
            permutation[swap] = permutation[i];
            permutation[i] = tmp;
            idx[i]++;
            i = 1;
            printPermutation(permutation,n);
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                	a_[j][k]=0;
                	a_temp[j][k]=0;
                    perm_m[j][k]=0;
                    if(permutation[j]==k)
                    	perm_m[j][k]=1;
                }
            std::cout<<"Perm m\n";
            printMatrix(perm_m,n);
            
            /**
             * CODE GOES HERE
             */
             std::cout<<"A\n";
            printMatrix(a,n);
            //swap cols
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                	for(int l=0;l<n;l++)
                		if(a[j][l]&&perm_m[l][k]){
            				a_temp[j][k]=1;
            				break;
                		}
            std::cout<<"A_temp\n";
            printMatrix(a_temp,n);
            //swap rows
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                	for(int l=0;l<n;l++)
                		if(a_temp[l][k]&&perm_m[j][l]){
            				a_[j][k]=1;
            				break;
                		}
            std::cout<<"A_\n";
            printMatrix(a_,n);
    		return 0;
        }
        else
            idx[i++] = 0;
    }
    double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
    std::cout<<tEnd<<"s NOT FOUND\n";
    return 0;
};