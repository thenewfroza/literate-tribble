#pragma once
#include <iostream>

const int maxRows = 10;
const int maxCols = 10;

typedef int matrix[maxCols][maxCols];

void PrintMatrix(matrix matr, int rows, int cols);

//1
int CountZeroInRows(matrix matr, int rows, int cols);

//2
void TMatrix(matrix matr, int size);

//3
bool IsSymmetric(matrix matr, int rows, int cols);

//4
void DelRow(matrix matr, int& rows, int cols, int num);

//5
void AddRow(matrix matr, int* arr, int& rows, int cols, int num);

//6
void DelColRow(matrix matr, int& rows, int& cols, int n, int m);

//7
int DetSquareMatrix(matrix matr, int size);
