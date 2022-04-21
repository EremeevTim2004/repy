#include <iostream>

// Вставка элемента в массив
void insert(int* arr, int& size, int index, int elem) {
	for (int i = size; i > index; i--) {
		arr[i] = arr[i - 1];
	}

	arr[index] = elem;
	size++;
}

// Удаление элемента из массива
void remove(int* arr, int& size, int index) {
	if (size <= index) return;

	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}

	size--;
}

// Поиск максимального элемента в массиве
int max(int *arr, int size) {
    int max_e = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max_e) {
            max_e = arr[i];
        }
    }
    return max_e;
}

// Поиск элемента в массиве элемента, равного num
int find_e_1(int *arr, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == num) {
			return i;
		}
	}

	return -1;
}

// Поиск первого в массиве элемента, кратного числу num
int find_e_2(int *arr, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (arr[i] % num == 0) {
			return i;
		}
	}

	return -1;

}

void task_4(int n, int X) { // Задание 4
    //  Инициализация динамического массива
	int *arr = new int[n];

	// Заполнение массива
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

	// Удаление элементов массива
	int index = find_e_2(arr, n, X);
	while (index != -1) {
		remove(arr, n, index);

		index = find_e_2(arr, n, X);
	}


	// Вывод массива
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

void task_7(int n) { // Задание 7
    //  Инициализация динамического массива
	int *arr = new int[n];

	// Заполнение массива
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

	// Максимальный элемент массива
	int max_elem = max(arr, n);
	std::cout << std::endl;
	std::cout << "Max: " << max_elem << std::endl;

	// Удаление всех максимальных элементов
	int max_index = find_e_1(arr, n, max_elem);
	while (max_index != -1) {
		remove(arr, n, max_index);

		max_index = find_e_1(arr, n, max_elem);
	}

	// Вывод массива
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

void task_12(int n, int x, int y) { // Задание 12
	int *arr = new int[n*2]; // Инициализация динамического массива

	// Заполнение массива
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = ";
		std::cin >> arr[i];
	}

    for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			insert(arr, n, i + 1, y);
		}
	}

    // Вывод массива
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

void task_16(int n, int X) { // Задание 16
    int *arr = new int[n*2]; // Инициализация динамического массива

    // Заполнение массива
    for(int i = 0; i < n; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    // Максимальный элемент
    int max_e = max(arr, n);
    std::cout << "Max element of arr:" << max_e << std::endl;

    // Вставка элементов
	for (int i = 0; i < n; i++) {
		if (arr[i] == max_e) {
			insert(arr, n, i, X);
			i += 1;
		}
	}

    // Вывод массива
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
	}
}

int main() { // Главная функция
    int Task;
    std::cout << "Input task number (4, 7, 12 or 16)." << std::endl << ">>";
    std::cin >> Task;
    switch(Task) { // Выбор задания через свитч-кейс
        case 4: { // Вывод задания 4
        // Размер массива
        int n;
        std::cout << "Input n." << std::endl << ">>";
        std::cin >> n;

        // X
        int X;
        std::cout << std::endl;
        std::cout << "Input X." << std::endl << ">>";
        std::cin >> X;

        task_4(n, X);
        break;
        }
        case 7: { // Вывод задания 7
            // Размер массива
            int n;
            std::cout << "Input n." << std::endl << ">>";
            std::cin >> n;

            task_7(n);
            break;
        }
        case 12: { // Вывод задания 12
            // Размер массива
            int n;
            std::cout << "input n." << std::endl << ">>";
            std::cin >> n;

            // x
            int x;
            std::cout << "Input x." << std::endl << ">>";
            std::cin >> x;

            // y
            int y;
            std::cout << "Input y." << std::endl << ">>";
            std::cin >> y;

            task_12(n, x, y);
            break;
        }
        case 16: { // Вывод задания 16
            // Размер массива
            int n;
            std::cout << "input n." << std::endl << ">>";
            std::cin >> n;

            // X
            int X;
            std:: cout << "input X." << std::endl << ">>";
            std::cin >> X;

            task_16(n, X);
            break;
        }
        default: { // Ошибка ввода
            std::cout << "Error!" << std::endl;
            break;
        }
    }
    return  0;
}