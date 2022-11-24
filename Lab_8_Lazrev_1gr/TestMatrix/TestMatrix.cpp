#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_8_Lazrev_1gr\Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMatrix
{
	TEST_CLASS(TestCountZeroRowsInMatrix)
	{
	public:
		TEST_METHOD(TestWithOutZero)
		{
			int rows = 3, cols = 3;
			int matr[maxRows][maxCols] = { {1,-2,3},{5,-6,7},{-9,10,11} };
			Assert::AreEqual(CountZeroInRows(matr, rows, cols), 0);
			int matr1[maxRows][maxCols] = { {122,-2,13},{3,4,5},{34,-204,23} };
			Assert::AreEqual(CountZeroInRows(matr1, rows, cols), 0);
		}
		TEST_METHOD(TestZero)
		{
			int rows = 4, cols = 3;
			int matr[maxRows][maxCols] = { {0,0,0},{5,-6,7},{-9,10,11},{1,1,1} };
			Assert::AreEqual(CountZeroInRows(matr, rows, cols), 1);
			int matr1[maxRows][maxCols] = { {122,-2,13},{0,0,0},{34,-204,23},{0,0,0} };
			Assert::AreEqual(CountZeroInRows(matr1, rows, cols), 2);
		}
	};
	TEST_CLASS(TestTransposeMatrix)
	{
	public:
		TEST_METHOD(Test1)
		{
			int matr[maxRows][maxCols] = { {1,2,3},{4,5,6},{7,8,9} };
			TMatrix(matr, 3);
			int transMatr[maxRows][maxCols] = { {1,4,7}, {2,5,8}, {3,6,9} };
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					Assert::AreEqual(matr[i][j], transMatr[i][j]);
		}
		TEST_METHOD(Test2)
		{
			int matr1[maxRows][maxCols] = { {2,3,-9,0},{-6,-7,-8,8},{5,6,-2,5},{-8,9,-9,3} };
			TMatrix(matr1, 4);
			int transMatr1[maxRows][maxCols] = { {2,-6,5,-8}, {3,-7,6,9}, {-9,-8,-2,-9}, {0,8,5,3}};
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					Assert::AreEqual(matr1[i][j], transMatr1[i][j]);
		}
	};
	TEST_CLASS(TestIsSymmetric)
	{
	public:
		TEST_METHOD(TestTrue)
		{
			int matr[maxRows][maxCols] = { {1,0,0},{0,2,0},{0,0,3} };
			Assert::IsTrue(IsSymmetric(matr, 3, 3));
		}
		TEST_METHOD(TestFalse)
		{
			int matr[maxRows][maxCols] = { {1,1,0},{0,2,0},{0,0,3} };
			Assert::IsFalse(IsSymmetric(matr, 3, 3));
		}
	};
	TEST_CLASS(TestDelRow)
	{
	public:
		int matr[maxRows][maxCols] = { { 1,2,3 }, { 4,-5,6 }, { 7,0,9 } };
		int newMatr[maxRows][maxCols] = {{ 1,2,3 }, { 4,-5,6 }};
		int rows = 3, cols = 3, num;
		TEST_METHOD(TestTrue)
		{
			num = 3;
			try {
				DelRow(matr, rows, cols, num);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(TestFalse)
		{
			num = 5;
			try {
				DelRow(matr, rows, cols, num);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
				Assert::IsTrue(false);
			}
			catch (int) {
				Assert::IsFalse(false);
			}
		}
	};
	TEST_CLASS(TestAddRow)
	{
	public:
		int* arr;
		int matr[maxRows][maxCols] = { { 1,2,3 }, { 4,-5,6 }, { 7,0,9 } };
		int newMatr[maxRows][maxCols] = { { 1,2,3 }, { 4,-5,6 }, { 6,6,6}, { 7,0,9 } };
		int rows = 3, cols = 3, num;
		TEST_METHOD(TestTrue)
		{
			arr = new int[cols] { 6, 6, 6 };
			num = 3;
			try {
				AddRow(matr, arr, rows, cols, num);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
			delete[] arr;
			arr = nullptr;
		}
		TEST_METHOD(TestFalse)
		{
			arr = new int[cols] { 6, 6, 6 };
			num = 4;
			try {
				AddRow(matr, arr, rows, cols, num);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
				Assert::IsTrue(false);
			}
			catch (int) {
				Assert::IsFalse(false);
			}
			delete[] arr;
			arr = nullptr;
		}
	};
	TEST_CLASS(TestDelColRow)
	{
	public:
		int matr[maxRows][maxCols] = { { 1,2,3 }, { 4,-5,6 }, { 7,0,9 } };
		int newMatr[maxRows][maxCols] = { { 1,2 }, { 4,-5 } };
		int rows = 3, cols = 3, n, m;
		TEST_METHOD(TestTrue)
		{
			n = 3, m = 3;
			try {
				DelColRow(matr, rows, cols, n, m);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(TestFalse)
		{
			n = 5, m = 3;
			try {
				DelColRow(matr, rows, cols, n, m);
				for (int i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						Assert::AreEqual(matr[i][j], newMatr[i][j]);
				Assert::IsTrue(false);
			}
			catch (int) {
				Assert::IsFalse(false);
			}
		}
	};
	TEST_CLASS(TestDeterminantOfSquareMatrix)
	{
	public:
		TEST_METHOD(TestFalse)
		{
			try {
				int size = 0, matr[maxRows][maxCols] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
				Assert::AreEqual(DetSquareMatrix(matr, size), 12);
				Assert::IsTrue(false);
			}
			catch(int) {
				Assert::IsFalse(false);
			}
		}
		TEST_METHOD(TestN1)
		{
			try {
				int size = 1, matr[maxRows][maxCols] = { {12} };
				Assert::AreEqual(DetSquareMatrix(matr, size), 12);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(TestN2)
		{
			try {
				int size = 2, matr[maxRows][maxCols] = { {5,-4}, {7,1} };
				Assert::AreEqual(DetSquareMatrix(matr, size), 33);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(TestNmore3)
		{
			try {
				int size = 4, matr[maxRows][maxCols] = { {1,-2,3,4},{5,6,-7,-8},{9,-10,11,12},{13,14,15,-16} };
				Assert::AreEqual(DetSquareMatrix(matr, size), 4800);
			}
			catch (int) {
				Assert::IsTrue(false);
			}
		}
	};
}
