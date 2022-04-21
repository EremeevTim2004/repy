#include "Functions.h"

void task_1(int n, int m) { // Задание 1
    int **arr = new int*[n * 2]; // Инициализация двумерного массива

    // Заполнение двумерного массива
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];

        std::cout << "arr[" << i << "] =";
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Initial matrix:" << std::endl;
    print_matrix(arr, n, m); //
    std::cout << std::endl;

    int *ref_arr = new int[m]; // Инициализация строки X

    // Заполнение строки X
    std::cout << "Input X." << std::endl << ">>";
    for (int i = 0; i < m; i++) {
        std::cin >> ref_arr[i];
    }
    std::cout << std::endl;

    std::cout << "Sting X:" << std::endl;
    print_array(ref_arr, m); //
    std::cout << std::endl;

    //
    for (int i = 0; i < n; i++) {
        if (!is_negative_exists(arr[i], m)) {
            insert_to_matrix(arr, n, i + 1, ref_arr);
            i++;
        }
    }

    std::cout << "Result:" << std::endl;
    print_matrix(arr, n, m); //
}

void task_6(int n, int m) { //
    int **arr = new int*[n * 2]; // Инициализация двумерного массива

    // Заполнение двумерного массива
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];

        std::cout << "arr[" << i << "] = ";
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "Initial matrix:" << std::endl;
    print_matrix(arr, n, m); //
    std::cout << std::endl;

    int *ref_arr = new int[m]; // Инициализация столбца X

    // Заполнение строки X
    std::cout << "Input X." << std::endl << ">>";
    for (int i = 0; i < m; i++) {
        std::cin >> ref_arr[i];
    }
    std::cout << std::endl;

    std::cout << "String X:" << std::endl;
    print_array(ref_arr, m); //
    std::cout << std::endl;

    //
    for (int i = 0; i < m; i++) {
        if (is_only_odd(arr, n, i)) {
            insert_column(arr, n, m, i, ref_arr);
            i += 1;
        }
    }

    std::cout << "Result:" << std::endl;
    print_matrix(arr, n, m); //
}

void task_11(int n, int m) { //
    int **arr = new int*[n * 2]; // Инициализация двумерного массива

    // Заполнение двумерного массива
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];

        std::cout << "arr[" << i << "] =";
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Initial matrix:" << std::endl;
    print_matrix(arr, n, m); //
    std::cout << std::endl;

    int min_elem = min_finder(arr, n, m); //

    //
    for (int i = 0; i < n; i++) {
        if (is_exists(arr[i], m, min_elem)) {
            remover(arr, n, i);
            i--;
        }
    }

    std::cout << "Result:" << std::endl;
    print_matrix(arr, n, m); //
}

void task_16(int n, int m) { //
    int **arr = new int*[n * 2]; // Инициализация двумерного массива

    for (int i = 0; i < n; i++) { // Заполнение двумерного массива
        arr[i] = new int[m];

        std::cout << "arr[" << i << "] =";
        for (int j = 0; j < m; j++) {
            std::cin >> arr[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Initial matrix:" << std::endl;
    print_matrix(arr, n, m); //
    std::cout << std::endl;

    int max_elem = max_finder(arr, n, m); //

    //
    for (int i = 0; i < m; i++) {
        if (is_exists_in_column(arr, m, i, max_elem)) {
            remove_column(arr, n, m, i);
            i--;
        }
    }

    std::cout << "Result:" << std::endl;
    print_matrix(arr, n, m); //
}