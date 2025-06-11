// ===== Matrix.c =====
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

SVector VectorCreate(unsigned long int n) {
    SVector v;
    v.VectorSize = n;
    v.Data = calloc(n, sizeof(double));
    return v;
}

void VectorDisplay(SVector v) {
    printf("Vector: ");
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        printf("%.2lf ", v.Data[i]);
    }
    printf("\n");
}

SVector VectorAdd(SVector a, SVector b) {
    SVector r = VectorCreate(a.VectorSize);
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        r.Data[i] = a.Data[i] + b.Data[i];
    }
    return r;
}

SVector VectorDiff(SVector a, SVector b) {
    SVector r = VectorCreate(a.VectorSize);
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        r.Data[i] = a.Data[i] - b.Data[i];
    }
    return r;
}

double VectorScalar(SVector a, SVector b) {
    double s = 0;
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        s += a.Data[i] * b.Data[i];
    }
    return s;
}

SVector VectorMultConst(SVector v, double k) {
    SVector r = VectorCreate(v.VectorSize);
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        r.Data[i] = v.Data[i] * k;
    }
    return r;
}

SVector VectorCopy(SVector v) {
    SVector c = VectorCreate(v.VectorSize);
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        c.Data[i] = v.Data[i];
    }
    return c;
}

void VectorDelete(SVector *v) {
    free(v->Data);
    v->Data = NULL;
    v->VectorSize = 0;
}

SMatrix MatrixCreate(unsigned long r, unsigned long c) {
    SMatrix m;
    m.Row = r; m.Col = c;
    m.Data = malloc(r * sizeof(double*));
    for (unsigned long i = 0; i < r; i++) {
        m.Data[i] = calloc(c, sizeof(double));
    }
    return m;
}

void MatrixDisplay(SMatrix m) {
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            printf("%.0lf ", m.Data[i][j]);
        }
        printf("\n");
    }
}

void MatrixMakeE(SMatrix *m) {
    for (unsigned long i = 0; i < m->Row; i++) {
        for (unsigned long j = 0; j < m->Col; j++) {
            m->Data[i][j] = (i == j) ? 1 : 0;
        }
    }
}

SMatrix MatrixMMMult(SMatrix a, SMatrix b) {
    SMatrix r = MatrixCreate(a.Row, b.Col);
    for (unsigned long i = 0; i < a.Row; i++) {
        for (unsigned long j = 0; j < b.Col; j++) {
            for (unsigned long k = 0; k < a.Col; k++) {
                r.Data[i][j] += a.Data[i][k] * b.Data[k][j];
            }
        }
    }
    return r;
}

SMatrix MatrixMMAdd(SMatrix a, SMatrix b) {
    SMatrix r = MatrixCreate(a.Row, a.Col);
    for (unsigned long i = 0; i < a.Row; i++) {
        for (unsigned long j = 0; j < a.Col; j++) {
            r.Data[i][j] = a.Data[i][j] + b.Data[i][j];
        }
    }
    return r;
}

SMatrix MatrixMVMult(SMatrix m, SVector v) {
    SMatrix r = MatrixCreate(m.Row, 1);
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            r.Data[i][0] += m.Data[i][j] * v.Data[j];
        }
    }
    return r;
}

SMatrix MatrixCopy(SMatrix m) {
    SMatrix c = MatrixCreate(m.Row, m.Col);
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            c.Data[i][j] = m.Data[i][j];
        }
    }
    return c;
}

void MatrixDelete(SMatrix *m) {
    for (unsigned long i = 0; i < m->Row; i++) {
        free(m->Data[i]);
    }
    free(m->Data);
    m->Data = NULL;
    m->Row = m->Col = 0;
}
