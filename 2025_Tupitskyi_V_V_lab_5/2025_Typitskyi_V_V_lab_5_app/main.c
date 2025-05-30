#include <windows.h>
#include <stdio.h>
#include "Matrix.h"
#include "SMatrix.h"

// Вектори
typedef SVector (*PFN_VectorCreate)(unsigned long);
typedef void    (*PFN_VectorDisplay)(SVector);
typedef SVector (*PFN_VectorMultConst)(SVector, double);
typedef void    (*PFN_VectorDelete)(SVector*);

// Матриці
typedef SMatrix (*PFN_MatrixCreate)(unsigned long, unsigned long);
typedef void    (*PFN_MatrixDisplay)(SMatrix);
typedef void    (*PFN_MatrixDelete)(SMatrix*);

int main() {
    HMODULE lib = LoadLibrary("2025_Tupitskyi_V_V_lab_5_dll.dll");
    if (!lib) {
        printf("Не вдалося завантажити DLL\n");
        return 1;
    }

    // Векторні функції
    PFN_VectorCreate VectorCreate = (PFN_VectorCreate)GetProcAddress(lib, "VectorCreate");
    PFN_VectorDisplay VectorDisplay = (PFN_VectorDisplay)GetProcAddress(lib, "VectorDisplay");
    PFN_VectorMultConst VectorMultConst = (PFN_VectorMultConst)GetProcAddress(lib, "VectorMultConst");
    PFN_VectorDelete VectorDelete = (PFN_VectorDelete)GetProcAddress(lib, "VectorDelete");

    // Матричні функції
    PFN_MatrixCreate MatrixCreate = (PFN_MatrixCreate)GetProcAddress(lib, "MatrixCreate");
    PFN_MatrixDisplay MatrixDisplay = (PFN_MatrixDisplay)GetProcAddress(lib, "MatrixDisplay");
    PFN_MatrixDelete MatrixDelete = (PFN_MatrixDelete)GetProcAddress(lib, "MatrixDelete");

    if (!VectorCreate || !VectorDisplay || !VectorMultConst || !VectorDelete ||
        !MatrixCreate || !MatrixDisplay || !MatrixDelete) {
        printf("Не вдалося знайти функції\n");
        return 1;
    }

    // Вектори
    SVector v = VectorCreate(3);
    v.Data[0] = 1; v.Data[1] = 2; v.Data[2] = 3;
    VectorDisplay(v);

    SVector v2 = VectorMultConst(v, 3.5);
    VectorDisplay(v2);
    VectorDelete(&v);
    VectorDelete(&v2);

    // Матриці
    SMatrix m = MatrixCreate(2, 2);
    m.Data[0][0] = 1; m.Data[0][1] = 2;
    m.Data[1][0] = 3; m.Data[1][1] = 4;
    MatrixDisplay(m);
    MatrixDelete(&m);

    FreeLibrary(lib);
    return 0;
}
