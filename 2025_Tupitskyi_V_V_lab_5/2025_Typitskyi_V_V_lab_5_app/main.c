#include <windows.h>
#include <stdio.h>
#include "Matrix.h"

int main() {
    printf("Attempting to load DLL...\n");
    HMODULE lib = LoadLibrary("2025_Tupitskyi_V_V_lab_5_dll.dll");
    if (!lib) {
        printf("Error: Could not load DLL!\n");
        return 1;
    }
    printf("DLL loaded successfully!\n");

    // Макрос для завантаження функцій
    #define LOAD(name) name = (void*)GetProcAddress(lib, #name); \
        if (!name) { printf("Error loading function: %s\n", #name); return 1; }

    // Вказівники на функції
    SVector (*VectorCreate)(unsigned long); LOAD(VectorCreate);
    void (*VectorDisplay)(SVector); LOAD(VectorDisplay);
    SVector (*VectorAdd)(SVector, SVector); LOAD(VectorAdd);
    SVector (*VectorDiff)(SVector, SVector); LOAD(VectorDiff);
    double (*VectorScalar)(SVector, SVector); LOAD(VectorScalar);
    SVector (*VectorMultConst)(SVector, double); LOAD(VectorMultConst);
    SVector (*VectorCopy)(SVector); LOAD(VectorCopy);
    void (*VectorDelete)(SVector*); LOAD(VectorDelete);

    SMatrix (*MatrixCreate)(unsigned long, unsigned long); LOAD(MatrixCreate);
    void (*MatrixDisplay)(SMatrix); LOAD(MatrixDisplay);
    void (*MatrixMakeE)(SMatrix*); LOAD(MatrixMakeE);
    SMatrix (*MatrixMMMult)(SMatrix, SMatrix); LOAD(MatrixMMMult);
    SMatrix (*MatrixMMAdd)(SMatrix, SMatrix); LOAD(MatrixMMAdd);
    SMatrix (*MatrixMVMult)(SMatrix, SVector); LOAD(MatrixMVMult);
    SMatrix (*MatrixCopy)(SMatrix); LOAD(MatrixCopy);
    void (*MatrixDelete)(SMatrix*); LOAD(MatrixDelete);

    printf("\nStart!\n");

    // === ВЕКТОРИ ===
    printf("\n--- VECTOR OPERATIONS ---\n");

    SVector v1 = VectorCreate(3);
    SVector v2 = VectorCreate(3);
    v1.Data[0]=1; v1.Data[1]=2; v1.Data[2]=3;
    v2.Data[0]=4; v2.Data[1]=5; v2.Data[2]=6;

    printf("\nVector 1:\n");
    VectorDisplay(v1);

    printf("Vector 2:\n");
    VectorDisplay(v2);

    printf("Vector Add:\n");
    SVector vAdd = VectorAdd(v1, v2);
    VectorDisplay(vAdd);

    printf("Vector Diff:\n");
    SVector vDiff = VectorDiff(v1, v2);
    VectorDisplay(vDiff);

    printf("Scalar Product: %.0f\n", VectorScalar(v1, v2));

    printf("Vector v1 * 2:\n");
    SVector vMul = VectorMultConst(v1, 2.0);
    VectorDisplay(vMul);

    printf("Copy of v2:\n");
    SVector vCopy = VectorCopy(v2);
    VectorDisplay(vCopy);

    // Очистка векторів
    VectorDelete(&v1); VectorDelete(&v2);
    VectorDelete(&vAdd); VectorDelete(&vDiff);
    VectorDelete(&vMul); VectorDelete(&vCopy);

    // === МАТРИЦІ ===
    printf("\n--- MATRIX OPERATIONS ---\n");

    SMatrix m1 = MatrixCreate(2,2);
    SMatrix m2 = MatrixCreate(2,2);
    m1.Data[0][0]=1; m1.Data[0][1]=2;
    m1.Data[1][0]=3; m1.Data[1][1]=4;
    m2.Data[0][0]=5; m2.Data[0][1]=6;
    m2.Data[1][0]=7; m2.Data[1][1]=8;

    printf("\nMatrix 1:\n");
    MatrixDisplay(m1);

    printf("Matrix 2:\n");
    MatrixDisplay(m2);

    printf("Matrix Add:\n");
    SMatrix mAdd = MatrixMMAdd(m1, m2);
    MatrixDisplay(mAdd);

    printf("Matrix Multiply:\n");
    SMatrix mMult = MatrixMMMult(m1, m2);
    MatrixDisplay(mMult);

    printf("Matrix 1 -> Identity:\n");
    MatrixMakeE(&m1);
    MatrixDisplay(m1);

    printf("Matrix * Vector:\n");
    SVector v3 = VectorCreate(2);
    v3.Data[0] = 1;
    v3.Data[1] = 2;
    SMatrix mVec = MatrixMVMult(m2, v3);
    MatrixDisplay(mVec);

    // Очистка
    MatrixDelete(&m1); MatrixDelete(&m2);
    MatrixDelete(&mAdd); MatrixDelete(&mMult);
    MatrixDelete(&mVec); VectorDelete(&v3);

    printf("\nStopped!\n");

    FreeLibrary(lib);
    return 0;
}
