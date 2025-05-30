#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

SVector VectorCreate(unsigned long int size) {
    SVector v;
    v.VectorSize = size;
    v.Data = (double*)calloc(size, sizeof(double));
    return v;
}

void VectorDisplay(SVector v) {
    printf("Vector: ");
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        printf("%.2lf ", v.Data[i]);
    }
    printf("\n");
}

SVector VectorMultConst(SVector v, double k) {
    SVector result = VectorCreate(v.VectorSize);
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        result.Data[i] = v.Data[i] * k;
    }
    return result;
}

void VectorDelete(SVector* v) {
    free(v->Data);
    v->Data = NULL;
    v->VectorSize = 0;
}

SMatrix MatrixCreate(unsigned long int row, unsigned long int col) {
    SMatrix m;
    m.Row = row;
    m.Col = col;
    m.Data = malloc(row * sizeof(double*));
    for (unsigned long i = 0; i < row; i++) {
        m.Data[i] = calloc(col, sizeof(double));
    }
    return m;
}

void MatrixDisplay(SMatrix m) {
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            printf("%.2lf ", m.Data[i][j]);
        }
        printf("\n");
    }
}

void MatrixDelete(SMatrix* m) {
    for (unsigned long i = 0; i < m->Row; i++) {
        free(m->Data[i]);
    }
    free(m->Data);
    m->Data = NULL;
    m->Row = 0;
    m->Col = 0;
}
