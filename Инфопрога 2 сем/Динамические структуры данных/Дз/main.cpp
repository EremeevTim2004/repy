#include <iostream>

/*Вывести элементы списка в обратном порядке.*/
void Task_1()
{

}

/*Найти последний четный элемент.*/
void Task_2()
{

}

/*Удалить первый минимальный элемент.*/
void Task_3()
{

}

/*Вставить 0 после последнего максимального.*/
void Task_4()
{

}

int main() //
{
    int Task;

    std::cout << "" << std::endl << ">>";
    std::cin >> Task;

    switch(Task)
    {
        case 1:
        {
            Task_1();

            break;
        }

        case 2:
        {
            Task_2();

            break;
        }

        case 3:
        {
            Task_3();

            break;
        }

        case 4:
        {
            Task_4();

            break;
        }

        default:
        {
            std::cout << "" << std::endl;
            
            break;
        }
    }
}