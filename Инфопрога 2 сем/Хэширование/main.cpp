#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct data
{
    string Name;
    string post;
    struct date_of_birth;
    int experience;
    int salary;
};


struct date_of_birth
{
    int d;
    int m;
    int y;
};

// Функция исправляющая кализию
// хз как она должна работать
void ColishionFixer()
{

}

pair <int, int> OpenHashMaker(string Array[], int ArraySize, int HashTableSize)
{
    pair<int, int> HashTable[HashTableSize];

    int day_of_birth = ...;
    int month_of_birth = ...;
    int year_of_birth = ...;

    for (int i = 0; i < ArraySize; i ++)
    {
        HashTable[i].first = (day_of_birth + month_of_birth + year_of_birth) % HashTableSize;
        HashTable[i].second = day_of_birth + month_of_birth + year_of_birth;
    }

    // проверка наличия колизии
    if (...)
    {
        ColishionFixer();
    }

    for (int i = 0; i < HashTableSize; i ++)
    {
        return HashTable[i];
    }
}

void FReader(string IFileName)
{

}

void FWriter(string OFileName)
{
    
}

/*
* Метод деления по месяцу рождения
*/
void task_1(string Array[], int ArraySize)
{

}

/*
* Основная - линейное хэширование
* Вспомогательная - метод умножения по году
*/
void task_2()
{

} 

int main()
{
    ifstream fin("Data.txt");
    ofstream fout("HashTable.txt");


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