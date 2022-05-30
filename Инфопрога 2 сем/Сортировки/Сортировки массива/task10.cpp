#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

void sortDwarf(int** a, int size){ // сортировка гномом
    for (int k = 0; k < size; ++k){
        for(int i = 0; i < size - 1; ++i){
            if(a[k][i] < a[k][i + 1] && k % 2 == 0){
                swap(a[k][i], a[k][i + 1]);
                --i;
                if(i >= 0){
                    --i;
                }
            }
            if(a[k][i] > a[k][i + 1] && k % 2 != 0){
                swap(a[k][i], a[k][i + 1]);
                --i;
                if(i >= 0){
                    --i;
                }
            }
        }
    }    
}

int main(){

    int size = 0;
    string temp;
    vector<int>nach;
    ifstream fin("Data.txt");
    string inp;
    while(getline(fin, inp)){ // считывание элементов из файла
        ++size;
        temp = "";
        for (int i = 0; i < inp.length(); ++i){
            if(inp[i] != ' ') temp += inp[i];
            else {
                nach.push_back(stoi(temp));
                temp = "";
            }   
        }
        nach.push_back(stoi(temp)); 
    }
    fin.close();
    

    int** a = new int*[size]; // блок с заполнением исходного массива
    for (int i = 0; i <= size; ++i) a[i] = new int[size];

    int add = 0;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            a[i][j] = nach[add];
            ++add;
        }
        
    }

    sortDwarf(a, size); // вызов сортировки

    fstream fout("output_2.txt"); // вывод в файл отсортированного массива
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            fout << a[i][j] << " ";
        }
        fout << endl;
    } 
    fout.close();  

    return 0;
}    