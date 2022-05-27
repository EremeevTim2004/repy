#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <vector <int>> A(4);
	vector <vector <int>> B(4);
	
	// Заполнение матрицы А
	std::cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];

	// Заполнение матрицы В
	std::cin >> B[0][0] >> B[0][1] >> B[1][0] >> B[1][1];

	// Вывод исходных матриц
	std::cout << "Matrix A:" << std::endl;
	std::cout << A[0][0] << " "; std::cout << A[0][1] << " " << std::endl;
	std::cout << A[1][0] << " "; std::cout << A[1][1] << " " << std::endl;

	std::cout << "Matrix B:" << std::endl;
	std::cout << B[0][0] << " "; std::cout << B[0][1] << " " << std::endl;
	std::cout << B[1][0] << " "; std::cout << B[1][1] << " " << std::endl;

	// Strassen's idea
	vector<vector <int>> C;

	int P1, P2, P3, P4, P5, P6, P7;

	P1 = A[0][0]*(B[0][1] - B[1][1]); 
	P2 = (A[0][0] + A[0][1]) * B[1][1];
	P3 = (A[1][0] + A[1][1]) * B[0][0];
	P4 = A[1][1] * (B[1][0] - B[0][0]);
	P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
	P6 = (A[0][1] - A[1][1]) * (B[0][1] + B[1][1]); 
	P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

	C[1][1] = P5 + P4 - P2 + P6;
	C[2][1] = P1 + P2;
	C[1][2] = P3 + P4;
	C[2][2] = P5 + P1 - P3 - P7;

	// Вывод результата
	std::cout << "Matrix C:" << std::endl;
	std::cout << C[0][0] << " "; std::cout << C[0][1] << " " << std::endl;
	std::cout << C[1][0] << " "; std::cout << C[1][1] << " " << std::endl;
}