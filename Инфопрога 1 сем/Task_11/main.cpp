#include <iostream>
#include "Tasks.h"

template <typename T>
void printArray(T** arr, int rows, int cols) { // 
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
void function_for_5(T** arr, int rows, int cols) { // 
	T max = arr[0][0]; int indexRMax = 0;
	T min = arr[0][0]; int indexRMin = 0;
	for (int i = 0; i < rows; ++i) { // 
		for (int j = 0; j < cols; ++j) {
			if (max < arr[i][j]) {
				max = arr[i][j];
				indexRMax = i;
			}
			if (min > arr[i][j]) {
				min = arr[i][j];
				indexRMin = i;
			}
		}
	}
	T temp;
	if (indexRMax != indexRMin) { //
		for (int i = 0; i < cols; ++i) {
			temp = arr[indexRMax][i];
			arr[indexRMax][i] = arr[indexRMin][i];
			arr[indexRMin][i] = temp;
		}
	}
	cout << "answer : \n";
	printArray(arr, rows, cols);
}

template <typename T>
void function_for_14(T** arr, int rows, int cols) { // 
	if (rows % 2 == 0) { //
		T temp;
		for (int j = 0; j < cols; ++j) {
			temp = arr[rows / 2][j];
			arr[rows / 2][j] = arr[rows / 2 - 1][j];
			arr[rows / 2 - 1][j] = temp;
		}
		std::cout << "answer : \n";
		printArray(arr, rows, cols);
	}
	else { // 
		std::cout << "answer : \n";
		printArray(arr, rows, cols);
	}
}

template <typename T>
void fillArray_for_5(T** arr, int rows, int cols) { //
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cin >> arr[i][j];
		}
	}
	function_for_5(arr, rows, cols);
}

template <typename T>
void fillArray_for_14(T** arr, int rows, int cols) { //
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cin >> arr[i][j];
		}
	}
	function_for_14(arr, rows, cols);
}

void task_5(int rows, int cols, int typeArray) {
	int** arr1 = new int* [rows]; // 
	for (int i = 0; i < rows; ++i) {
		arr1[i] = new int[cols];
	}
	double** arr2 = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		arr2[i] = new double[cols];
	}
	char** arr3 = new char* [rows];
	for (int i = 0; i < rows; ++i) {
		arr3[i] = new char[cols];
	}

	switch (typeArray) { // 
	case 1:
		fillArray_for_5(arr1, rows, cols);
		break;
	case 2:
		fillArray_for_5(arr2, rows, cols);
		break;
	case 3:
		fillArray_for_5(arr3, rows, cols);
		break;
	default:
		std::cout << "net takogo tipa \n";
		break;
	}
}

void task_14(int rows, int cols, int typeArray) { //
	//
	int** arr1 = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		arr1[i] = new int[cols];
	}
	double** arr2 = new double* [rows];
	for (int i = 0; i < rows; ++i) {
		arr2[i] = new double[cols];
	}
	char** arr3 = new char* [rows];
	for (int i = 0; i < rows; ++i) {
		arr3[i] = new char[cols];
	}

	switch (typeArray) { // 
	case 1:
		fillArray_for_14(arr1, rows, cols);
		break;
	case 2:
		fillArray_for_14(arr2, rows, cols);
		break;
	case 3:
		fillArray_for_14(arr3, rows, cols);
		break;
	default:
		std::cout << "Error! No such type! \n";
		break;
	}
}

int main() {
    int Task;
    std::cout << "Input Task number (5 or 14)." << std::endl << ">>";
    std::cin >> Task;
    switch(Task) {
        case 5: {
            //
            int rows, cols, typeArray;
            std::cout << "enter the rows and cols" << std::endl << ">>";
            std::cin >> rows >> cols;
            std::cout << "vvedite 1 dlia int, 2 dlia double and 3 dlia char" << std::endl << ">>";
            std::cin >> typeArray;

            task_5(rows, cols, typeArray);
            break;
        }
        case 14: { //
            int rows, cols, typeArray;
            std::cout << "enter the rows and cols" << std::endl << ">>";
            std::cin >> rows >> cols;
            std::cout << "vvedite 1 dlia int, 2 dlia double and 3 dlia char" << std::endl << ">>";
            std::cin >> typeArray;

            task_14(rows, cols, typeArray);
            break;
        }
       
        default: {
            std::cout << "Error! No such task number!" << std::endl;
            break;
        }
    }
    return 0;
}