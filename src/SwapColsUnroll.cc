#include "SwapColsUnroll.h"

void SwapColsUnroll1(bool** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;}
void SwapColsUnroll2(bool** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;}
void SwapColsUnroll3(bool** m, int n, int a, int b){
    int swap=m[0][a];
    m[0][a]=m[0][b];
    m[0][b]=swap;
    swap=m[1][a];
    m[1][a]=m[1][b];
    m[1][b]=swap;
    swap=m[2][a];
    m[2][a]=m[2][b];
    m[2][b]=swap;}
void SwapColsUnroll4(bool** m, int n, int a, int b){
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
    m[3][b]=swap;}
void SwapColsUnroll5(bool** m, int n, int a, int b){
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
    m[4][b]=swap;}
void SwapColsUnroll6(bool** m, int n, int a, int b){
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
    m[5][b]=swap;}
void SwapColsUnroll7(bool** m, int n, int a, int b){
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
    m[6][b]=swap;}
void SwapColsUnroll8(bool** m, int n, int a, int b){
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
    m[7][b]=swap;}
void SwapColsUnroll9(bool** m, int n, int a, int b){
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
    m[8][b]=swap;}
void SwapColsUnroll10(bool** m, int n, int a, int b){
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
    m[9][b]=swap;}
void SwapColsUnroll11(bool** m, int n, int a, int b){
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
    m[10][b]=swap;}
void SwapColsUnroll12(bool** m, int n, int a, int b){
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
    m[11][b]=swap;}
void SwapColsUnroll13(bool** m, int n, int a, int b){
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
    m[12][b]=swap;}
void SwapColsUnrollN(bool** m, int n, int a, int b){
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