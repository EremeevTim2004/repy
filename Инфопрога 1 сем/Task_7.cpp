#include <iostream>
#include <vector>

std::vector <int> V_builder(int n) { // Вспомогательная функция для создания массива
    std::vector<int> V(n);
    std::cout << "Input array`s elements" << std::endl;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        V[i] = tmp;
    }
    return V;
}

void V_outer(std::vector <int> V) { // Вспомогательная функция для вывода массива
    for (int i: V) {
        std::cout << i << " ";
    }
}

/*** Дан многочлен P(x) степени n. Получить его производную P'(x). */
void task_1(int n) { // Задание 1
    std::vector <int> V = V_builder(n+1);//создаем массив длиной n+1
    std::vector <int> Pro(n); //будущий массив с производной
    for (int i = 0; i < n; ++i) {
        Pro[i] = V[i + 1] * (i + 1); //формируем производную по правилу (x^n)` = nx^n-1
    }
    V_outer(Pro);
}

/* Дан многочлен P(x) степени n и действительное число A.
 * Получить многочлен (x^2 + 2Ax + A^2)P(x) */
void task_6(int n, int A) { // Задание 6
    std::vector <int> V = V_builder(n+1);
    std::vector <int> Pr(n + 3);
    for (int i = 0; i < n + 3; ++i) { // Перемножаем элементы
        if (i == 0 || i == 1) {
            Pr[i] = V[i] * (-A);
        } else if (i < n+1) {
            Pr[i] = V[i] * (-A) + V[i - 2];
        } else {
            Pr[i] = V[i - 2];
        }
    }
    V_outer(Pr);
}

int factorial(int n) { // Вспомогательная рекурсивная функция для поиска факториала
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

/* Вывести коэффициенты многочлена по схеме триугольника паскаля. */
void task_11(int n) { // Задание 11
    std::vector<int> V(n + 1);
    for (int i = 0; i <= n; ++i) {
        V[i] = factorial(n) / (factorial(n-i) * factorial(i));//по правилу бинома Ньютона формируем коэффициенты
    }
    V_outer(V);
}

int main() { // Главная функция
    int Task;
    std::cout << "Choose task (1, 6 or 11)" << std::endl << ">>"; // реализуем выбор задачи
    std::cin >> Task; //выбираем задачу с ввода
    switch (Task) { // смотрим какую задачу выбрали
        case 1: { // Вывод 1 задания
            int n;
            std::cout << "Input n" << std::endl << ">>";
            std::cin >> n; //Вводим два значения
            task_1(n); //выполняем задачу
            break;
        }
        case 6: { // Вывод 6 задания
            int n;
            std::cout << "Input n" << std::endl << ">>";
            std::cin >> n; //Вводим два значения
            std::cout << "Input A" << std::endl << ">>";
            int A;
            std::cin >> A; //Вводим два значения
            task_6(n, A);
            break;
        }
        case 11: { // Вывод 11 задания
            int n;
            std::cout << "Input n" << std::endl << ">>";
            std::cin >> n;
            task_11(n);
            break;
        }
        default: { // Ошибка ввода
            std::cout << "Error!";
            break;
        }
    }
    return 0;
}
