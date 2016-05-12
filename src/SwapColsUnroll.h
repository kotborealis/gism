#pragma once
#include <cstdint>

void SwapColsUnroll1(int** m, int n, int a, int b);
void SwapColsUnroll2(int** m, int n, int a, int b);
void SwapColsUnroll3(int** m, int n, int a, int b);
void SwapColsUnroll4(int** m, int n, int a, int b);
void SwapColsUnroll5(int** m, int n, int a, int b);
void SwapColsUnroll6(int** m, int n, int a, int b);
void SwapColsUnroll7(int** m, int n, int a, int b);
void SwapColsUnroll8(int** m, int n, int a, int b);
void SwapColsUnroll9(int** m, int n, int a, int b);
void SwapColsUnroll10(int** m, int n, int a, int b);
void SwapColsUnroll11(int** m, int n, int a, int b);
void SwapColsUnroll12(int** m, int n, int a, int b);
void SwapColsUnroll13(int** m, int n, int a, int b);
void SwapColsUnrollN(int** m, int n, int a, int b);

typedef void (*SwapColsUnrollType) (int** m, int n, int a, int b);
extern SwapColsUnrollType SwapColsUnroll[];