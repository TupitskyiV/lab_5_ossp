// ===== Matrix.h =====
#ifndef __MATRIX_H
#define __MATRIX_H

#include "SMatrix.h"

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

DLL_EXPORT SVector VectorCreate(unsigned long int);
DLL_EXPORT void VectorDisplay(SVector);
DLL_EXPORT SVector VectorAdd(SVector, SVector);
DLL_EXPORT SVector VectorDiff(SVector, SVector);
DLL_EXPORT double VectorScalar(SVector, SVector);
DLL_EXPORT SVector VectorMultConst(SVector, double);
DLL_EXPORT SVector VectorCopy(SVector);
DLL_EXPORT void VectorDelete(SVector*);

DLL_EXPORT SMatrix MatrixCreate(unsigned long int, unsigned long int);
DLL_EXPORT void MatrixDisplay(SMatrix);
DLL_EXPORT void MatrixMakeE(SMatrix*);
DLL_EXPORT SMatrix MatrixMMMult(SMatrix, SMatrix);
DLL_EXPORT SMatrix MatrixMMAdd(SMatrix, SMatrix);
DLL_EXPORT SMatrix MatrixMVMult(SMatrix, SVector);
DLL_EXPORT SMatrix MatrixCopy(SMatrix);
DLL_EXPORT void MatrixDelete(SMatrix*);

#endif
