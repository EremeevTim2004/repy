#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void sortPiramid(int** a, int Size){ // пирамидальная сортировка для строк
    int size, i = 0;
    while(true){ // поиск индекса самого молодого предка
        if (pow(2, i) > Size){
            size =  pow(2, i - 1)-2;
            break;
        }
        ++i;
    }
    for (int k = 0; k < Size; ++k){
        int add = 1;
        while(add != 0){ // сравнение потомков с предком, если потомок старше предка, то меняем их местами
            add = 0;
            for(i = size; i >= 0; --i){
                if(i * 2 + 1 < Size){
                    if (a[i][k] < a[i * 2 + 1][k]){ 
                        swap(a[i][k], a[i * 2 + 1][k]);
                        ++add;
                    }   
                }
                if(i * 2 + 2 < Size){
                    if (a[i][k] < a[i * 2 + 2][k]){
                        swap(a[i][k], a[i * 2 + 2][k]);
                        ++add;
                    }  
                }     
            }
        } 
    }     
}

int main()
{
    int size = 0;
 
    string temp;
    string inp;
    vector<int>nach;

    ifstream fin("Data.txt");
    
    while(getline(fin, inp)) // считывание из файла
    {
        ++size;

        temp = "";
        
        for (int i = 0; i < inp.length(); ++i)
        {
            if(inp[i] != ' ')
            {
                temp += inp[i];
            }
            else 
            {
                nach.push_back(stoi(temp));
                temp = "";
            }   
        }

        nach.push_back(stoi(temp)); 
    }

    fin.close();

    // блок с созданием исходного массива
    int** a = new int*[size]; 
    for (int i = 0; i <= size; ++i) a[i] = new int[size];

    int add = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            a[i][j] = nach[add];
            ++add;
        }
    }

    // вызов сортировки
    sortPiramid(a, size); 

    // вывод в файл отсортированного массива
    fstream fout("output_1.txt"); 
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            fout << a[i][j] << " ";
        }

        fout << endl;
    } 

    return 0;
}    