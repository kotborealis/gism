#pragma once

bool equalMatrixUnroll1(bool** a, bool** b, int n);
bool equalMatrixUnroll2(bool** a, bool** b, int n);
bool equalMatrixUnroll3(bool** a, bool** b, int n);
bool equalMatrixUnroll4(bool** a, bool** b, int n);
bool equalMatrixUnroll5(bool** a, bool** b, int n);
bool equalMatrixUnroll6(bool** a, bool** b, int n);
bool equalMatrixUnroll7(bool** a, bool** b, int n);
bool equalMatrixUnroll8(bool** a, bool** b, int n);
bool equalMatrixUnroll9(bool** a, bool** b, int n);
bool equalMatrixUnroll10(bool** a, bool** b, int n);
bool equalMatrixUnroll11(bool** a, bool** b, int n);
bool equalMatrixUnroll12(bool** a, bool** b, int n);
bool equalMatrixUnroll13(bool** a, bool** b, int n);
bool equalMatrixUnrollN(bool** a, bool** b, int n);

typedef bool (*equalMatrixUnrollType) (bool** a, bool** b, int n);
extern equalMatrixUnrollType equalMatrixUnroll[];