#pragma once
#include <cstdint>

void SwapColsUnroll1(bool** m, int n, int a, int b);
void SwapColsUnroll2(bool** m, int n, int a, int b);
void SwapColsUnroll3(bool** m, int n, int a, int b);
void SwapColsUnroll4(bool** m, int n, int a, int b);
void SwapColsUnroll5(bool** m, int n, int a, int b);
void SwapColsUnroll6(bool** m, int n, int a, int b);
void SwapColsUnroll7(bool** m, int n, int a, int b);
void SwapColsUnroll8(bool** m, int n, int a, int b);
void SwapColsUnroll9(bool** m, int n, int a, int b);
void SwapColsUnroll10(bool** m, int n, int a, int b);
void SwapColsUnroll11(bool** m, int n, int a, int b);
void SwapColsUnroll12(bool** m, int n, int a, int b);
void SwapColsUnroll13(bool** m, int n, int a, int b);
void SwapColsUnrollN(bool** m, int n, int a, int b);

typedef void (*SwapColsUnrollType) (bool** m, int n, int a, int b);
extern SwapColsUnrollType SwapColsUnroll[];