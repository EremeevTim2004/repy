#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Выввод вектора
void printVector(vector<int> &vec) {
    cout << '{';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << " ";
        }
    }
    cout << '}' << endl;
}

// КОнвертация вектора в строку
string getVector(vector<int> &vec) {
    string s = "{";
    
    for (int i = 0; i < vec.size(); i++) {
        if (i < vec.size() - 1) {
            s += to_string(vec[i]) + ",";
        } else {
            s += to_string(vec[i]) + "}";
        }
    }
    return s;
}

// Вывод матрицы
void printMatrix(vector<vector<int>> &m) {
    /* Print every vector inside a matrix */
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size()) {
            printVector(m[i]);
        }
    }
}

// Вывод матрицы
void printMatrix(vector<vector<int>> &m, string &path) {
    /* Initialize file */
    ofstream file(path);
    string line;
    /* Print every vector inside a matrix */
    for (int i = 0; i < m.size(); i++) {
        if (i < m.size()) {
            file << getVector(m[i]) + "\n";
        }
    }
}

const int count(string &path) {
    fstream file;
    string line;
    int c = 0;
    while(getline(file, line)) {
        c++;
    }
    return c;
}

// Чтение матрциы из файла
vector<vector<int>> initMatrixFromFile(char* &path) {
    
    vector<vector<int>> matrix;
    
    fstream file;
    string line;
    
    file.open(path);
    
    while (!file.eof()) {
    
        vector<int> temp;
    
        getline(file, line);
    
        stringstream ss(line);
    
        while (ss.good()) {
    
            string num;
    
            getline(ss, num, ',');
    
            if (num != "\0") {
                temp.push_back(stoi(num));
            }
        }
    
        if (temp.size() > 0) {
            matrix.push_back(temp);
            temp.clear();
        }
    }
    
    return matrix;
}

/* Сложение двух матриц a и b и запись результата в c */
vector<vector<int>> addMatrices(vector<vector<int>> &a, vector<vector<int>> &b, size_t  mSize) {
    
    vector<int> ss(a.size(), 0);
    vector<vector<int>> s(ss.size(), ss);
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            s[i][j] = a[i][j] + b[i][j];
        }
    }
    
    return s;

}

/* Вычитание двух матриц a и b и запись результат в c */
vector<vector<int>> subMatrices(vector<vector<int>> &a, vector<vector<int>> &b, size_t  mSize) {

    vector<int> ss(a.size(), 0);
    vector<vector<int>> s(ss.size(), ss);
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            s[i][j] = a[i][j] - b[i][j];
        }
    }

    return s;

}

/* Перемножение двух матриц */
void multiply(vector<vector<int>> &a, vector<vector<int>> &b, vector<vector<int>> &s, size_t n) {

    if (n <= 1) {

        s[0][0] = a[0][0] * b[0][0];

    } else {

        /* ПОловина от текущего размера */
        size_t half = n / 2;

        vector<int> inner(half, 0);

        /* Создание новой матрицы */
        vector<vector<int>> A11(half, inner),
                            A12(half, inner),
                            A21(half, inner),
                            A22(half, inner),
                            B11(half, inner),
                            B12(half, inner),
                            B21(half, inner),
                            B22(half, inner),
                            P1(half, inner),
                            P2(half, inner),
                            P3(half, inner),
                            P4(half, inner),
                            P5(half, inner),
                            P6(half, inner),
                            P7(half, inner),
                            tempA(half, inner),
                            tempB(half, inner);
      
        /* Разделение матриц */
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                
                /* Для матрциы A */
                A11[i][j] = a[i][j];
                A12[i][j] = a[i][j + half];
                A21[i][j] = a[i + half][j];
                A22[i][j] = a[i + half][j + half];  
                
                /* Для матрциы B */
                B11[i][j] = b[i][j];
                B12[i][j] = b[i][j + half];
                B21[i][j] = b[i + half][j];
                B22[i][j] = b[i + half][j + half];
            
            }
        
        }
        /* Выполнение субопераций */
        vector<vector<int>> P1_1 = subMatrices(B12, B22, half);
        multiply(A11, P1_1, P1, half);
        vector<vector<int>> P2_1 = addMatrices(A11, A12, half);
        multiply(P2_1, B22, P2, half);
        vector<vector<int>> P3_1 = addMatrices(A21, A22, half);
        multiply(P3_1, B11, P3, half);
        vector<vector<int>> P4_1 = subMatrices(B21, B11, half);
        multiply(A22, P4_1, P4, half);
        vector<vector<int>> P5_1 = addMatrices(A11, A22, half);
        vector<vector<int>> P5_2 = addMatrices(B11, B22, half);
        multiply(P5_1, P5_2, P5, half);
        vector<vector<int>> P6_1 = subMatrices(A12, A22, half);
        vector<vector<int>> P6_2 = addMatrices(B21, B22, half);
        multiply(P6_1, P6_2, P6, half);
        vector<vector<int>> P7_1 = subMatrices(A11, A21, half);
        vector<vector<int>> P7_2 = addMatrices(B11, B12, half);
        multiply(P7_1, P7_2, P7, half);

        vector<vector<int>> C11_1 = addMatrices(P5, P4, half);
        vector<vector<int>> C11_2 = subMatrices(C11_1, P2, half);
        vector<vector<int>> C11 = addMatrices(C11_2, P6, half);
        vector<vector<int>> C12 = addMatrices(P1, P2, half);
        vector<vector<int>> C21 = addMatrices(P3, P4, half);
        vector<vector<int>> C22_1 = addMatrices(P1, P5, half);
        vector<vector<int>> C22_2 = subMatrices(C22_1, P3, half);
        vector<vector<int>> C22 = subMatrices(C22_2, P7, half);
        
        /* Группировка матриц*/
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                s[i][j] = C11[i][j];
                s[i][j + half] = C12[i][j];
                s[i + half][j] = C21[i][j];
                s[i + half][j + half] = C22[i][j];
            }
        }
    }
}

int main(int argc, char** argv) {

    /* ------------ Чтение данных с файла ------------ */
    
    /* Read file and initialize matrices */
    vector<vector<int>> matA1 = initMatrixFromFile(argv[1]);
    vector<vector<int>> matB1 = initMatrixFromFile(argv[2]);
    
    size_t curSize = matA1.size();
    vector<int> init(curSize, 0);
    vector<vector<int>> matS1(curSize, init);
    
    /* ------------ Перемножение матриц ------------ */
    
    multiply(matA1, matB1, matS1, curSize);
    
    /* Вывод результата */
    printMatrix(matS1);
    
    /* Запись результата в файла */
    string solPath = "solution.txt";
    printMatrix(matS1, solPath);

}