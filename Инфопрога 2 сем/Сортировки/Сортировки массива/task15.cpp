#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void insertion_sort(int* a, int size)
{
    int isxodP = 0, position = 0, temp;
    string temp1;
    for (int i = 0; i < size; ++i)
    {
        if(a[i] < a[i + 1]) ++isxodP;
        else break;
    }
    if(isxodP != size){
        for (int i = isxodP; i < size; ++i){
            position = 0;
            temp = 0;
            for (int j = 0; j < isxodP; ++j)
            { 
                if(a[j] <= a[isxodP]) ++position;
                else break;
            }

            if(position - 1 == isxodP) ++isxodP;
            else{
                temp = a[isxodP];
                for (int j = isxodP; j > position; --j)
                {
                    a[j] = a[j-1];
                }

                a[position] = temp;
            }

            ++isxodP;
        }
    }
}

int main()
{
    int size = 0;
    string temp;
    vector<int>nach;
    ifstream fin("Data.txt");
    string inp;
    while(getline(fin, inp)){ // СЃС‡РёС‚С‹РІР°РЅРёРµ СЌР»РµРјРµРЅС‚РѕРІ РёР· С„Р°Р№Р»Р°
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
    

    int** a = new int*[size]; // РёСЃС…РѕРґРЅС‹Р№ РјР°СЃСЃРёРІ
    int** b = new int*[size*2]; // РјР°СЃСЃРёРІ РёР· РґРёР°РіРѕРЅР°Р»РµР№, РїР°СЂР°Р»Р»РµР»СЊРЅС‹С… РіР»Р°РІРЅРѕР№ РґРёР°РіРѕРЅР°Р»Рё
    for (int i = 0; i <= size; ++i){
        a[i] = new int[size];
        b[i] = new int[i + 1];
        if (i != size - 1){
            b[size * 2 - i - 1] = new int[i + 1];
        }
    }    

    int add = 0;
    for (int i = 0; i < size; ++i){ // Р·Р°РїРѕР»РЅРµРЅРёРµ РјР°СЃСЃРёРІР° a
        for (int j = 0; j < size; ++j){
            a[i][j] = nach[add];
            ++add;
        }
        
    }

    int t = 0;
    for (int k = size - 1, m = size - 1; t < size; --m){ // Р·Р°РїРѕР»РЅРµРЅРёРµ РјР°СЃСЃРёРІР° b
        int j = k, t1 = 0;
        for (int i = size - m - 1; i >= 0 && j >= 0 && t1 < size - m; --i){
            b[t][t1] = a[j][i];
            ++t1;
            --j;
        }
        ++t;
    }
    for (int k = 0, m = 1; m < size, t < size * 2 - 1; ++m){ // Р·Р°РїРѕР»РЅРµРЅРёРµ РјР°СЃСЃРёРІР° b
        int j = k, t1 = 0;
        for (int i = m; i < size; ++i){
            b[t][t1] = a[j][i];
            ++t1;
            ++j;
        }
        ++t;
    }
    for (int i = 0; i < size; ++i){ // СЃРѕСЂС‚РёСЂРѕРІРєР° РјР°СЃСЃРёРІР° b
        insertion_sort(b[i], i + 1);
    }
    for (int i = 5; i < size*2; ++i){ // СЃРѕСЂС‚РёСЂРѕРІРєР° РјР°СЃСЃРёРІР° b
        insertion_sort(b[i], size*2 - i - 1);
    }

    t = 0;
    for (int k = size - 1, m = size - 1; t < size; --m){ // СЃРѕСЂС‚РёСЂРѕРІРєР° РёСЃС…РѕРґРЅРѕРіРѕ РјР°СЃСЃРёРІР° a
        int j = k, t1 = 0;
        for (int i = size - m - 1; i >= 0 && j >= 0 && t1 < size - m; --i){
            a[j][i] = b[t][t1];
            ++t1;
            --j;
        }
        ++t;
    }
    for (int k = 0, m = 1; m < size, t < size * 2 - 1; ++m){
        int j = k, t1 = 0;
        for (int i = m; i < size; ++i){
            a[j][i] = b[t][t1];
            ++t1;
            ++j;
        }
        ++t;
    }
    
    ofstream fout("output_3.txt");
    for (int i = 0; i < size; ++i){ // РІС‹РІРѕРґ РѕС‚СЃРѕСЂС‚РёСЂРѕРІР°РЅРЅРѕРіРѕ РјР°СЃСЃРёРІР° РІ С„Р°Р№Р»
        for (int j = 0; j < size; ++j){
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
    
    return 0;
}    