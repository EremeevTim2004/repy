#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct data
{
    string Name;
    string post;
    int date_of_birth;
    int experience;
    int salary;
};


struct date_of_birth
{
    int d;
    int m;
    int y;
};

/*
* Метод деления по месяцу рождения
*/
void task_1()
{

}

/*
* Основная - линейное хэширование
* Вспомогательная - метод умножения по году
*/
void task_2()
{

} 

// Функция исправляющая кализию
// хз как она должна работать
void ColishionFixer()
{

}

int OpenHashMaker(string array[], int arraySize, int hashSize)
{
    int hashArray[hashSize];

    for (int i = 0; i < arraySize; i ++)
    {
        hashArray[i] = (int)(data.date_of_birth.d + data.date_of_birt.m + data.date_of_birth.y) / hashSize;
    }
}

int main()
{
    int task;

    std::cout << "" << std::endl << ">>";
    std::cin >> task;

    switch (task)
    {
        // открытое хэширование
        case 1:
        {
            break;
        }

        // закрытое хэширование
        case 2:
        {
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