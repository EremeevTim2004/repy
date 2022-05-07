#include <iostream>
#include <fstream>
#include <string>

#include "funcs.h"

using namespace std;

// func to make matrix
void MatrixMakingHand(int row, int col)
{
	//...
}

void MatrixMakingFile(int row, int col; string file_name)
{
	//...
}

// filling matrix by hand
void MatrixFillingByHand(int matrix[row][col], int row, int col)
{
	//...
}

// filling matrix from file
void MatrixFillingFromFile(int matrix[row][col], int row, int col, string file_name)
{
	//...
}

// func to output matrix
void MatrixOutputConsole(int matrix[row][col], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "\n\n";
}

void MatrixOutputFile(int matrix[row][col], int row, int col, string file_name)
{
	//...
}

// Function to implement the Strassen algorithm
void ShtrassenAlgorithm(int matrix_A[row_A][col_A], int matirx_B[row_B][col_B], int row_A, int col_A, int row_B, int col_B)
{
	//...
}

void VinogradAlgorithm(int matrix_A[row_A][col_A], int matirx_B[row_B][col_B], int row_A, int col_A, int row_B, int col_B)
{
	//...
}