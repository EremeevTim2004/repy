void print_matrix(int **arr, int rows, int cols) { // Вывод двумерного массива

    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_array(int *arr, int size) { // Вывод одномерного массива

    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void insert_to_matrix(int **arr, int& rows, int index, int *elem) { // Вставка строки в матрицу

    for (int i = rows; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = elem;
    rows++;
}

void insert(int* arr, int& size, int index, int elem) { // Вставка элемента в массив
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = elem;
}

void insert_column(int **arr, int col_size, int& row_size, int column, int *ref_arr) { // Вставка столбца
    row_size++;
    for (int i = 0; i < col_size; i++) {
        insert(arr[i], row_size, column, ref_arr[i]);
    }
}

bool is_only_odd(int **arr, int rows, int column) { // Проверка содержания столбца (только нечётные элементы)
    for (int i = 0; i < rows; i++) {
        if (arr[i][column] % 2 == 0) {
            return false;
        }
    }

    return true;
}

bool is_negative_exists(int *arr, int size) { // Проверка содержания столбца (есть ли отрицательный элемент)
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            return true;
        }
    }

    return false;
}

int min_finder(int **arr, int rows, int cols) { // Поиск минимального элемента в матрице
    int min_ = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < min_) {
                min_ = arr[i][j];
            }
        }
    }

    return min_;
}

bool is_exists(int *arr, int size, int elem) { // Проверка содержания массива (поиск элемента в массиве)
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            return true;
        }
    }

    return false;
}

int max_finder(int **arr, int rows, int cols) { // Поиск минимального элемента в матрице
    int max_ = INT_MIN;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max_) {
                max_ = arr[i][j];
            }
        }
    }

    return max_;
}

bool is_exists_in_column(int **arr, int size, int column, int elem) { // Проверка содержания столбца (поиск элемента)
    for (int i = 0; i < size; i++) {
        if (arr[i][column] == elem) {
            return true;
        }
    }

    return false;
}

void remover(int **arr, int& size, int index) { // Удаление элемента из массива
    if (size <= index) return;

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

void remove(int *arr, int& size, int index) { // Удаление элемента из массива
    if (size <= index) {
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void remove_column(int **arr, int rows, int& cols, int column) { // Удаление столбца
    for (int i = 0; i < rows; i++) {
        remove(arr[i], cols, column);
    }
    cols--;
}