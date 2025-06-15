// ===== Matrix.c =====
#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"

// === Створення вектора ===
SVector VectorCreate(unsigned long int n) {
    SVector v = {NULL, 0}; // Ініціалізація
    if (n == 0) return v;  // Захист від нульового розміру
    v.Data = (double*)calloc(n, sizeof(double));
    if (!v.Data) return v; // Перевірка на успішне виділення памʼяті
    v.VectorSize = n;
    return v;
}

// === Виведення вектора ===
void VectorDisplay(SVector v) {
    if (!v.Data) return; // Перевірка вказівника
    printf("Vector: ");
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        printf("%.2lf ", v.Data[i]);
    }
    printf("\n");
}

// === Додавання векторів ===
SVector VectorAdd(SVector a, SVector b) {
    if (!a.Data || !b.Data || a.VectorSize != b.VectorSize) return VectorCreate(0);
    SVector r = VectorCreate(a.VectorSize);
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        r.Data[i] = a.Data[i] + b.Data[i];
    }
    return r;
}

// === Різниця векторів ===
SVector VectorDiff(SVector a, SVector b) {
    if (!a.Data || !b.Data || a.VectorSize != b.VectorSize) return VectorCreate(0);
    SVector r = VectorCreate(a.VectorSize);
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        r.Data[i] = a.Data[i] - b.Data[i];
    }
    return r;
}

// === Скалярний добуток векторів ===
double VectorScalar(SVector a, SVector b) {
    if (!a.Data || !b.Data || a.VectorSize != b.VectorSize) return 0;
    double s = 0;
    for (unsigned long i = 0; i < a.VectorSize; i++) {
        s += a.Data[i] * b.Data[i];
    }
    return s;
}

// === Множення вектора на константу ===
SVector VectorMultConst(SVector v, double k) {
    if (!v.Data) return VectorCreate(0);
    SVector r = VectorCreate(v.VectorSize);
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        r.Data[i] = v.Data[i] * k;
    }
    return r;
}

// === Копіювання вектора ===
SVector VectorCopy(SVector v) {
    if (!v.Data) return VectorCreate(0);
    SVector c = VectorCreate(v.VectorSize);
    for (unsigned long i = 0; i < v.VectorSize; i++) {
        c.Data[i] = v.Data[i];
    }
    return c;
}

// === Видалення вектора ===
void VectorDelete(SVector *v) {
    if (!v || !v->Data) return;
    free(v->Data);
    v->Data = NULL;
    v->VectorSize = 0;
}

// === Створення матриці ===
SMatrix MatrixCreate(unsigned long r, unsigned long c) {
    SMatrix m = {NULL, 0, 0};
    if (r == 0 || c == 0) return m;
    m.Data = (double**)malloc(r * sizeof(double*));
    if (!m.Data) return m;
    m.Row = r;
    m.Col = c;

    for (unsigned long i = 0; i < r; i++) {
        m.Data[i] = (double*)calloc(c, sizeof(double));
        if (!m.Data[i]) {
            // Якщо не вдалось виділити пам’ять — чистимо
            for (unsigned long j = 0; j < i; j++) {
                free(m.Data[j]);
            }
            free(m.Data);
            m.Data = NULL;
            m.Row = m.Col = 0;
            break;
        }
    }
    return m;
}

// === Виведення матриці ===
void MatrixDisplay(SMatrix m) {
    if (!m.Data) return;
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            printf("%.2lf ", m.Data[i][j]);
        }
        printf("\n");
    }
}

// === Одинична матриця ===
void MatrixMakeE(SMatrix *m) {
    if (!m || !m->Data) return;
    for (unsigned long i = 0; i < m->Row; i++) {
        for (unsigned long j = 0; j < m->Col; j++) {
            m->Data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
}

// === Множення матриць ===
SMatrix MatrixMMMult(SMatrix a, SMatrix b) {
    if (!a.Data || !b.Data || a.Col != b.Row) return MatrixCreate(0, 0);
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

// === Додавання матриць ===
SMatrix MatrixMMAdd(SMatrix a, SMatrix b) {
    if (!a.Data || !b.Data || a.Row != b.Row || a.Col != b.Col) return MatrixCreate(0, 0);
    SMatrix r = MatrixCreate(a.Row, a.Col);
    for (unsigned long i = 0; i < a.Row; i++) {
        for (unsigned long j = 0; j < a.Col; j++) {
            r.Data[i][j] = a.Data[i][j] + b.Data[i][j];
        }
    }
    return r;
}

// === Множення матриці на вектор ===
SMatrix MatrixMVMult(SMatrix m, SVector v) {
    if (!m.Data || !v.Data || m.Col != v.VectorSize) return MatrixCreate(0, 0);
    SMatrix r = MatrixCreate(m.Row, 1);
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            r.Data[i][0] += m.Data[i][j] * v.Data[j];
        }
    }
    return r;
}

// === Копіювання матриці ===
SMatrix MatrixCopy(SMatrix m) {
    if (!m.Data) return MatrixCreate(0, 0);
    SMatrix c = MatrixCreate(m.Row, m.Col);
    for (unsigned long i = 0; i < m.Row; i++) {
        for (unsigned long j = 0; j < m.Col; j++) {
            c.Data[i][j] = m.Data[i][j];
        }
    }
    return c;
}

// === Видалення матриці ===
void MatrixDelete(SMatrix *m) {
    if (!m || !m->Data) return;
    for (unsigned long i = 0; i < m->Row; i++) {
        free(m->Data[i]);
    }
    free(m->Data);
    m->Data = NULL;
    m->Row = m->Col = 0;
}
