#include <iostream>
#include <fstream>
#include <string>

#include "funcs.h"

using namespace std;

//
int main()
{
	int voter_1; //

	std::cout << "Whitch method do u prefer? (1 - Shtrassen; 2 - Vinigrad)" << std::endl << ">>";
	std::cin >> voter_1;

	//
	switch(voter_1)
	{
		// Реализация через алгоритм Штрассена
		case 1:
		{
			int voter_2;

			std::cout << "" << std::endl << ">>";
			std::cin >> voter_2;

			switch(voter_2)
			{
				// by hand
				case 1:
				{
					int row_A, col_A;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_A >> col_A;

					MatrixMakingHand(row_A, col_A);

					int row_B, col_B;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_B >> col_B;
					
					MatrixMakingHand(row_B, col_B);

					ShtrassenAlgorithm(matrix_A, matirx_B, row_A, col_A, row_B, col_B);

					break;
				}

				// from file
				case 2:
				{
					std::string file_name;

					std::cout << "" << std::endl << ">>";
					std::cin >> file_name;

					// тут будет работа с файлами

					int row_A, col_A;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_A >> col_A;

					MatrixMakingFile(row_A, col_A);

					int row_B, col_B;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_B >> col_B;
					
					MatrixMakingFile(row_B, col_B);

					ShtrassenAlgorithm(matrix_A, matirx_B, row_A, col_A, row_B, col_B);

					break;
				}

				default:
				{
					std::cout << "" << std::endl;

					break;
				}
			}

			break;
		}

		// Реализация через алгоритм Винограда
		case 2:
		{
			int voter_2;

			std::cout << "" << std::endl << ">>";
			std::cin >> voter_2;

			switch(voter_2)
			{
				// by hand
				case 1:
				{
					int row_A, col_A;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_A >> col_A;

					MatrixMakingHand(row_A, col_A);

					int row_B, col_B;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_B >> col_B;
					
					MatrixMakingHand(row_B, col_B);

					VinogradAlgorithm(matrix_A, matirx_B, row_A, col_A, row_B, col_B);

					break;
				}

				// from file
				case 2:
				{
					std::string file_name;

					std::cout << "" << std::endl << ">>";
					std::cin >> file_name;

					// тут будет работа с файлами

					int row_A, col_A;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_A >> col_A;

					MatrixMakingFile(row_A, col_A);

					int row_B, col_B;

					std::cout << "" << std::endl << ">>";
					std::cin >> row_B >> col_B;
					
					MatrixMakingFile(row_B, col_B);

					VinogradAlgorithm(matrix_A, matirx_B, row_A, col_A, row_B, col_B);

					break;
				}

				default:
				{
					std::cout << "" << std::endl;

					break;
				}
			}		

			break;
		}

		default:
		{
			std::cout << "" << std::endl;

			break;
		}
	}

	return 0;
}