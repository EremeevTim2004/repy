#include <iostream>
#include <cstdint>
#include "Tasks.h"

int main() { // Главная функция
    int Task;
    std::cout << "Input task number (2, 9, 13 or 19)." << std::endl << ">>";
    std::cin >> Task;
    switch(Task) { // Выбор задания через свитч-кэйс
        case 2: { //
            // n
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            task_2(n);
            break;
        }
        case 9: { //
            // m
            uint64_t m;
            std::cout << "Input m." << std::endl << ">>";
            std::cin >> m;

            // n
            uint64_t n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            task_9(m, n);
            break;
        }
        case 13: { //
            // x
            uint64_t x;
            std::cout << "Input x." << std::endl << ">>";
            std::cin >> x;

            task_13(x);
            break;
        }
        case 19: { //
            // n
            uint64_t n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            task_19(n);
            break;
        }
        default: { //
            std::cout << "Error!" << std::endl;
            break;
        }
    }
    return 0;
}
