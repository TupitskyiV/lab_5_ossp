// ===== SMatrix.h =====
#ifndef __SMATRIX_H
#define __SMATRIX_H

// === Структура для зберігання вектора ===
typedef struct Vector {
    double *Data;                 // Вказівник на масив елементів вектора
    unsigned long int VectorSize; // Розмір вектора
} SVector;

// === Структура для зберігання матриці ===
typedef struct Matrix {
    double **Data;               // Вказівник на масив вказівників (двовимірна матриця)
    unsigned long int Row;       // Кількість рядків
    unsigned long int Col;       // Кількість стовпців
} SMatrix;

#endif // __SMATRIX_H
