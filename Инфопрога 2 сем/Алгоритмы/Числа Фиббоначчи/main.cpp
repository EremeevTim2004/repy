#include <iostream>

using namespace std;

// Рекурентные соотношения
/*void RecurentSerch(int nNum)
{
	//...
}*/

// Золотое сечение
void GoldSerch(int nNum)
{
	int counter = 3;

	int a = 1, b = 1, tmp;

	while (counter < nNum)
	{
		tmp = a;
		a = b + a;
		b = tmp;

		counter + = 1;
	}

	return a;
}

// Через матрицы
/*void MatrixSerch(int nNum)
{
	//...
}

// 
void Revizor(int res_1, int res_2, int res_3)
{
	if (res_1 < res_2 & res_1 < res_3)
	{
		std::cout << "RecurentSerch is won!" << std::endl;
	}
	else if (res_2 < res_1 & res_2 < res_3)
	{
		std::cout << "GoldSerch is won!" << std::endl;
	}
	else
	{
		std::cout << "MatrixSerch is won!" << std::endl;
	}
}*/

int main()
{
	int nNum;

	std::cout << "" << std::endl << ">>";
	std::cin >> nNum;

	//RecurentSerch(nNum);
	GoldSerch(nNum);
	//MatrixSerch(nNum);

	//Revizor();

	return 0;
}