// ===== Matrix.h =====
// Захисна конструкція від подвійного включення
#ifndef __MATRIX_H
#define __MATRIX_H

#include "SMatrix.h"

// Директива для експорту функцій з DLL на Windows
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

// === ОПЕРАЦІЇ НАД ВЕКТОРАМИ ===

// Створення нового вектора розміру n
DLL_EXPORT SVector VectorCreate(unsigned long int n);

// Виведення вектора на екран
DLL_EXPORT void VectorDisplay(SVector v);

// Додавання двох векторів (a + b)
DLL_EXPORT SVector VectorAdd(SVector a, SVector b);

// Різниця двох векторів (a - b)
DLL_EXPORT SVector VectorDiff(SVector a, SVector b);

// Скалярний добуток векторів
DLL_EXPORT double VectorScalar(SVector a, SVector b);

// Множення вектора на константу
DLL_EXPORT SVector VectorMultConst(SVector v, double k);

// Копіювання вектора
DLL_EXPORT SVector VectorCopy(SVector v);

// Видалення (звільнення памʼяті) вектора
DLL_EXPORT void VectorDelete(SVector *v); // передача за вказівником для зміни

// === ОПЕРАЦІЇ НАД МАТРИЦЯМИ ===

// Створення матриці розміру (рядки, стовпці)
DLL_EXPORT SMatrix MatrixCreate(unsigned long int rows, unsigned long int cols);

// Виведення матриці на екран
DLL_EXPORT void MatrixDisplay(SMatrix m);

// Перетворення матриці на одиничну
DLL_EXPORT void MatrixMakeE(SMatrix *m); // передача за вказівником — матриця змінюється

// Множення двох матриць
DLL_EXPORT SMatrix MatrixMMMult(SMatrix a, SMatrix b);

// Додавання двох матриць
DLL_EXPORT SMatrix MatrixMMAdd(SMatrix a, SMatrix b);

// Множення матриці на вектор
DLL_EXPORT SMatrix MatrixMVMult(SMatrix m, SVector v);

// Копіювання матриці
DLL_EXPORT SMatrix MatrixCopy(SMatrix m);

// Видалення матриці (звільнення памʼяті)
DLL_EXPORT void MatrixDelete(SMatrix *m); // передача за вказівником

#endif // __MATRIX_H
