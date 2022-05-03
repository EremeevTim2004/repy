#include <iostream>

using namespace std;

void move(char point1, char point2)
{
    std::cout << "Из стержня " << poin1 << " в стержнь " << point2 << std::endl;
}

void moveTower(int amount, char point1, char, point 2, char temp)
{
    if (amount == 0)
    {
        return;
    }

    moveTower(amount - 1, temp, point2);
    
    move(point1, point2);

    moveTower(amount - 1, temp, point2, point1);
}

int main()
{
    int disk_kol;

    std::cout << "Введите кол-во дисков" << std::endl << ">>";
    std::cin >> disk_kol;

    moveTower(disk_kol, 'A', 'B', 'C');
}
