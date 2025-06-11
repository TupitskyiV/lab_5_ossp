// ===== SMatrix.h =====
#ifndef __SMATRIX_H
#define __SMATRIX_H

typedef struct Vector {
    double *Data;
    unsigned long int VectorSize;
} SVector;

typedef struct Matrix {
    double **Data;
    unsigned long int Row;
    unsigned long int Col;
} SMatrix;

#endif
