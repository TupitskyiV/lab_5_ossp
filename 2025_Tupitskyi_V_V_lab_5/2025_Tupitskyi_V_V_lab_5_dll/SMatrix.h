// ===== SMatrix.h =====
#ifndef __SMATRIX_H
#define __SMATRIX_H

// === ��������� ��� ��������� ������� ===
typedef struct Vector {
    double *Data;                 // �������� �� ����� �������� �������
    unsigned long int VectorSize; // ����� �������
} SVector;

// === ��������� ��� ��������� ������� ===
typedef struct Matrix {
    double **Data;               // �������� �� ����� ��������� (��������� �������)
    unsigned long int Row;       // ʳ������ �����
    unsigned long int Col;       // ʳ������ ��������
} SMatrix;

#endif // __SMATRIX_H
