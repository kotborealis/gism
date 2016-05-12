#pragma once

bool equalMatrixUnroll1(int** a, int**b, int n);
bool equalMatrixUnroll2(int** a, int**b, int n);
bool equalMatrixUnroll3(int** a, int**b, int n);
bool equalMatrixUnroll4(int** a, int**b, int n);
bool equalMatrixUnroll5(int** a, int**b, int n);
bool equalMatrixUnroll6(int** a, int**b, int n);
bool equalMatrixUnroll7(int** a, int**b, int n);
bool equalMatrixUnroll8(int** a, int**b, int n);
bool equalMatrixUnroll9(int** a, int**b, int n);
bool equalMatrixUnroll10(int** a, int**b, int n);
bool equalMatrixUnroll11(int** a, int**b, int n);
bool equalMatrixUnroll12(int** a, int**b, int n);
bool equalMatrixUnroll13(int** a, int**b, int n);
bool equalMatrixUnrollN(int** a, int**b, int n);

typedef bool (*equalMatrixUnrollType) (int** a, int** b, int n);
extern equalMatrixUnrollType equalMatrixUnroll[];