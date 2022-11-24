#include "Functions.h"

int main(){
	int rows = 3, cols = 3, num = 4;
	int matr[maxRows][maxCols] = { {1,-2,3},{5,-6,7},{-9,10,11} };
	PrintMatrix(matr, rows, cols);

	//1
	//std::cout << "Count = " << CountZeroInRows(matr, rows, cols) << std::endl;

	//2
	/*TMatrix(matr, rows);
	PrintMatrix(matr, rows, cols);*/ 

	//3
	//std::cout << "Symmetric = " << IsSymmetric(matr, rows, cols) << std::endl;

	//4
	/*std::cout << "---------------- " << std::endl;
	try{
		DelRow(matr, rows, cols, num);
		PrintMatrix(matr, rows, cols);
	}
	catch(int a){
		std::cout << "!((num > 0) && (num <= rows))" <<std::endl;
	}*/
	
	//5
	/*std::cout << "---------------- " << std::endl;
	int* arr = new int[cols]{ 6, 6, 6 };
	try{
		AddRow(matr, arr, rows, cols, num);
		PrintMatrix(matr, rows, cols);
	}
	catch(int a){
		std::cout << "!((num > 0) && (num <= rows))" <<std::endl;
	}
	delete[] arr;
	arr = nullptr;*/

	//6
	/*std::cout << "---------------- " << std::endl;
	try{
		DelColRow(matr, rows, cols, 3, 3);
		PrintMatrix(matr, rows, cols);
	}
	catch(int a){
		std::cout << "!((num > 0) && (num <= rows))" <<std::endl;
	}*/

	//7
	/*std::cout << "Determinant = " << DetSquareMatrix(matr, rows) << std::endl;
	int size1 = 4, matr1[maxRows][maxCols] = {{1,-2,3,4},{5,6,-7,-8},{9,-10,11,12},{13,14,15,-16}};
	PrintMatrix(matr1, size1, size1);
	std::cout << "Determinant = " << DetSquareMatrix(matr1, size1) << std::endl;*/

	return 0;
}