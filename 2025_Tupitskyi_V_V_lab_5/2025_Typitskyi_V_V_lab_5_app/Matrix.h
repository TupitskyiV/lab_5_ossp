#ifndef MATRIX_H
#define MATRIX_H

#include "SMatrix.h"

// �������
SVector VectorCreate(unsigned long int size);
void VectorDisplay(SVector v);
SVector VectorMultConst(SVector v, double k);
void VectorDelete(SVector* v);

// �������
SMatrix MatrixCreate(unsigned long int row, unsigned long int col);
void MatrixDisplay(SMatrix m);
void MatrixDelete(SMatrix* m);

#endif
