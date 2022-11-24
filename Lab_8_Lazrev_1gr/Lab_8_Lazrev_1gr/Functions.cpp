#include "Functions.h"

void PrintMatrix(matrix matr, int rows, int cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			printf("%5d", matr[i][j]);
		}
		std::cout << std::endl;
	}
}

//1
int CountZeroInRows(matrix matr, int rows, int cols) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			if (matr[i][j] == 0) {
				count++;
				break;
			}
	}
	return count;
}

//2
void TMatrix(matrix matr, int size) {
	for (int i = 0; i < size; i++) 
		for (int j = i + 1; j < size; j++)
			std::swap(matr[i][j], matr[j][i]);
}

//3
bool IsSymmetric(matrix matr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (matr[i][j] != matr[j][i]) return false;
	return true;
}
 
//4
void DelRow(matrix matr, int& rows, int cols, int num) {
	if (!((num > 0) && (num <= rows))) throw 1;
	for (int i = num; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matr[i - 1][j] = matr[i][j];
	rows--;
}

//5
void AddRow(matrix matr, int* arr, int& rows, int cols, int num) {
	if (!((num > 0) && (num <= rows))) throw 1;
	for (int i = rows; i > num - 1; i--)
		for (int j = 0; j < cols; j++)
			matr[i][j] = matr[i - 1][j];
	for (int j = 0; j < cols; j++)
		matr[num - 1][j] = arr[j];
	rows++;
}

/*
6 (сдвиг столбцов и строчки на одну позицию)
Реализовать функцию для вычеркивания из матрицы строки с индексом M и
столбца с индексом N (M, N - параметры функции)
*/
void DelColRow(matrix matr, int& rows, int& cols, int n, int m) {
	if (!(((n * m) > 0) && (n <= rows) && (m <= cols))) throw 1;
	for (int i = m; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matr[i - 1][j] = matr[i][j];
	rows--;
	for (int i = 0; i < rows; i++)
		for (int j = n; j < cols; j++)
			matr[i][j - 1] = matr[i][j];
	cols--;
}

//7 - Реализовать функцию вычисления определителя квадратной матрицы
int DetSquareMatrix(matrix matr, int size) {
	int det = 0, a, f = 1;
	if (size < 1) throw 1;
	if (size == 1) return matr[0][0];
	if (size == 2) return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
	// n >= 3
	int newMatr[maxRows][maxCols], newSize = size - 1;
	for (int i = 0; i < size; i++) {
		//Minor
		for (int n = 0; n < i; n++)
			for (int m = 0; m < size; m++)
				newMatr[n][m] = matr[n][m + 1];
		for (int n = i; n < size; n++)
			for (int m = 0; m < size; m++)
				newMatr[n][m] = matr[n + 1][m + 1];
		//Формула
		a = matr[i][0];
		/*std::cout << "-1^(j+1) = " << f << "; a("<< i <<",0) = " << a << std::endl
			<< "---------------- " << std::endl;;
		PrintMatrix(newMatr, newSize, newSize);
		std::cout << "---------------- " << std::endl;*/
		det += f * a * DetSquareMatrix(newMatr, newSize);
		f *= -1;
	}
	return det;
}