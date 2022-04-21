#include <iostream>

/* Поменять местами строки по следующему правилу: первую с последней, вторую с предпоследней и т. д. */
void Task_1(int n, int m){ // Задание 1
    int arr[n][m];

    arr[0][0] = arr[0][1] = arr[0][2] = arr[0][3] = arr[0][4] = 1; // Предварительное заполнение
    arr[1][0] = arr[1][1] = arr[1][2] = arr[1][3] = arr[1][4] = 2;
    arr[2][0] = arr[2][1] = arr[2][2] = arr[2][3] = arr[2][4] = 3;
    arr[3][0] = arr[3][1] = arr[3][2] = arr[3][3] = arr[3][4] = 4;
    arr[4][0] = arr[4][1] = arr[4][2] = arr[4][3] = arr[4][4] = 5;

    std::cout << std::endl << "Matrix: " << std::endl;
    for (int i = 0; i < n; i++) { // Вывод первоначальной матрицы
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int tmp;
    for (int i = 0; i < n; i++) { // Меняем строки местами
        for (int j = 0; j < m; j++) {
            tmp = arr[i][j];
            arr[i][j] = arr[n - 1 - i][j];
            arr[n - 1 - i][j] = tmp;
        }
    }

    std::cout << std::endl << "Result: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* Найти первый минимальный и первый максимальный элементы массива. Поиск вести построчно.
 * Поменять местами строки, содержащие эти элементы. */
void Task_7(int n, int m){ // Задание 7
    int arr[n][m];

    arr[0][0] = 4; arr[0][1] = 5; arr[0][2] = 9; arr[0][3] = 2; arr[0][4] = 1;
    arr[0][0] = 2; arr[0][1] = 4; arr[0][2] = 1; arr[0][3] = 3; arr[0][4] = 2;
    arr[0][0] = 4; arr[0][1] = 3; arr[0][2] = 7; arr[0][3] = 2; arr[0][4] = 0;
    arr[0][0] = 9; arr[0][1] = 5; arr[0][2] = 2; arr[0][3] = 7; arr[0][4] = 4;
    arr[0][0] = 4; arr[0][1] = 6; arr[0][2] = 8; arr[0][3] = 1; arr[0][4] = 3;

    std::cout << std::endl << "Matrix: " << std::endl;
    for (int i = 0; i < n; ++i) { // Вывод первоначальной матрицы
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int min_e, min_j = -1, max_e, max_j = -1; // Инициализация доп переенных
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] < min_e) { // Нахождение минимального
                min_e = arr[i][j];
                min_j = j;
            }

            if (arr[i][j] > max_e) { // Нахождение максимального
                max_e = arr[i][j];
                max_j = j;
            }
        }
    }

    int tmp;
    for (int i = 0; i < n; ++i) { // Замена столбцов
        tmp = arr[i][min_j];
        arr[i][min_j] = arr[i][max_j];
        arr[i][max_j] = tmp;
    }

    for (int i =0; i < n; ++i) { // Вывод изменённой матрицы
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* Заменить первый максимальный элемент в заштрихованной области, включая границы,
 * на первый минимальный элемент из незаштрихованной области, не включая границы.
 * Поиск вести построчно. */
void Task_12(int n, int m){ // Задание 12
    int arr[n][m];

    arr[0][0] = 4; arr[0][1] = 5; arr[0][2] = 8; arr[0][3] = 2; arr[0][4] = 1;
    arr[0][0] = 2; arr[0][1] = 4; arr[0][2] = 1; arr[0][3] = 3; arr[0][4] = 2;
    arr[0][0] = 4; arr[0][1] = 3; arr[0][2] = 7; arr[0][3] = 2; arr[0][4] = 0;
    arr[0][0] = 9; arr[0][1] = 5; arr[0][2] = 2; arr[0][3] = 7; arr[0][4] = 4;
    arr[0][0] = 4; arr[0][1] = 6; arr[0][2] = 8; arr[0][3] = 1; arr[0][4] = 3;

    std::cout << std::endl << "Matrix: " << std::endl; // Вывод матрицы
    for (int i = 0; i < m; ++i) { //
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int min_e, min_i = -1, min_j =- 1, max_e, max_i=-1, max_j=-1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j <= n - i - 1) {
                if (arr[i][j] > max_e) { // Поиск максимального элемента в заштрихованной области, включая границы
                    max_e=arr[i][j];
                    max_i=i;
                    max_j=j;
                }
            }
            else {
                if (arr[i][j] < min_e) { // Поиск минимального элемента в не заштрихованной области, не включая границы
                    min_e=arr[i][j];
                    min_i=i;
                    min_j=j;
                }
            }
        }
    }

    int tmp = arr[max_i][max_j]; // Замена элементов
    arr[max_i][max_j] = arr[min_i][min_j];
    arr[min_i][min_j]=tmp;

    std::cout << std::endl << "Result: " << std::endl;
    for (int i = 0; i < n; ++i) { // Вывод изменённой матрицы
        for (int j = 0; j < m; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/* Заполнить массив n*n числами от 0 до n^2-1 в требуемом порядке. */
void Task_19(int n){ // Задание 19
    int clones = 0, stitches = 0;
    int arr[n][n];
    bool indicator = true;
    for (int i = 0; i < n * n; i++){
        arr[stitches][clones]=i;
        // std::cout << "(" << stitches << " " << clones << ") ->";
        if (indicator) {
            stitches += 1;
            if (stitches >= n) {
                clones += 1;
                stitches -= 1;
                indicator = false;
            }
        }
        else {
            stitches -= 1;
            if (stitches <0) {
                stitches += 1;
                clones += 1;
                indicator = true;
            }
        }
    }

    std::cout << std::endl << "Matrix: " << std::endl;
    for (int i = 0; i < n; i++) { //
        for (int j = 0; j < n; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() { // Главная функция
    int Task, n, m; // Инициализация доп переенныйх
    std::cout<<"Input task number (1, 7, 12, 19)."<<std::endl<<">>";
    std::cin>>Task;
    switch (Task) {
        case 1: { // Вывод задания 1
            std::cout << "Input n. " << std::endl << ">>";
            std::cin >> n;
            m = n;
            Task_1(n, m);
            break;
        }
        case 7: { // Вывод задания 7
            std::cout<<"input n."<<std::endl<<">>";
            std::cin >> n;
            m = n;
            Task_7(n, m);
            break;
        }
        case 12: { // Вывод задания 12
            std::cout<<"input n."<<std::endl<<">>";
            std::cin >> n;
            m = n;
            Task_12(n, m);
            break;
        }
        case 19: { // Вывод задания 19
            std::cout << "input n." << std::endl << ">>";
            std::cin>>n;
            Task_19(n);
            break;
        }
        default:{ // Ошибка ввода
            std::cout<<"Input error!";
            break;
        }
    }
    return 0;
}