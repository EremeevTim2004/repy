#include <iostream>
#include "Tasks.h"

int main() { // Главная функция
    int Task;
    std::cout << "Input task number (1, 6, 11 or 16)." << std::endl << ">>";
    std::cin >> Task;
    switch(Task) { //
        case 1: { //
            // n
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            // m
            int m;
            std::cout << "Input m." << std::endl << ">>";
            std::cin >> m;

            task_1(n, m);
            break;
        }
        case 6: { //
            // n
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            // m
            int m;
            std::cout << "Input m." << std::endl << ">>";
            std::cin >> m;

            task_6(n, m);
            break;
        }
        case 11: { //
            // n
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            // m
            int m;
            std::cout << "Input m." << std::endl << ">>";
            std::cin >> m;

            task_11(n, m);
            break;
        }
        case 16: { //
            // n
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            // m
            int m;
            std::cout << "Input m." << std::endl << ">>";
            std::cin >> m;

            task_16(n, m);
            break;
        }
        default: { //
            std::cout << "Error!" << std::endl;
            break;
        }
    }
    return 0;
}
