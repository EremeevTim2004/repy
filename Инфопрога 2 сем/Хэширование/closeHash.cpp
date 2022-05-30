#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<cmath>

float A = (sqrt(5) - 1) / 2;

using namespace std;

struct worker
{
    string surname;
    string post;
    int dayB;
    int monthB;
    int yearB;
    int pay;
    int countYears;
    bool full;

    void getData()
    {
        cin >> surname;
        cin >> post;
        cin >> dayB;
        cin >> monthB;
        cin >> yearB;
        cin >> countYears;
        cin >> pay;
    }

    void ShowDataset()
    {
        cout << surname << '\t' << post
            << '\t' << dayB << " " << monthB << " " << yearB << '\t' << countYears <<'\t'
            << pay << endl;
    }
};

void correctDate(string date, int& day, int& month, int& year)
{
    int length = date.size();
    int counter = 0;

    string temp = "";
    
    for (int i = 0; i < length; i++)
    {
        if (date[i] != '.')
        {
            temp += date[i];
        }
        else if (date[i] == '.' || i == (length - 1))
        {
            if (counter == 0)
            {
                day = stoi(temp);
                temp = "";
                counter++;
            }
            else if (counter == 1)
            {
                month = stoi(temp);
                temp = "";
                counter++;
            }
            else if (counter == 2)
            {
                year = stoi(temp);
                temp = "";
                counter++;
            }
        }
    }
    if (counter == 2)
    {
        year = stoi(temp);
        temp = "";
        counter++;
    }
};

int Hash(int n, int Year)
{
    float temp = fmod(Year, A);

    return (n * temp);
}

void find(vector<worker>& hashTable, int year, string surname, int n)
{
    int pos = Hash(n, year);
    bool flag = false;
    for (int i = pos; i < n; i++)
    {
        if (hashTable[i].yearB == year && hashTable[i].surname == surname)
        {
            cout << "элемент найден, в ячейке " << i << endl;

            hashTable[i].ShowDataset();
            
            flag = true;
            
            return;
        }
    }
    if (!flag)
    {
        for (int i = 0; i < pos; i++)
        {
            if (hashTable[i].yearB == year && hashTable[i].surname == surname)
            {
                cout << "элемент найден, в ячейке " << i << endl;

                hashTable[i].ShowDataset();
                
                flag = true;
                
                return;
            }
        }

        cout << "такого элемента нет\n";
        
        return;
    }
}



int main()
{
    string line;

    ifstream fin;
    fin.open("D:\\input.txt");
    
    int n;
    cout << "введите размер таблицы\n";
    cin >> n;

    vector <worker> HashTable(n);

    for (int i = 0; i < n; i++)
    {
        HashTable[i].full == false;
    }

    worker workers;

    int counter = 0;

    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            int flag = 0;
            int length;

            string temp;
            
            length = line.size();
            
            string surname, pos, date, pay, cYears = "";

            int day, month, year;

            for (int i = 0; i < length; i++)
            {
                if (line[i] != ' ' && i != (length - 1))
                {
                    temp += line[i];
                }
                else
                {
                    if (flag == 0)
                    {
                        surname = temp;
                        temp = "";
                        flag++;
                    }
                    else if (flag == 1)
                    {
                        pos = temp;
                        temp = "";
                        flag++;
                    }
                    else if (flag == 2)
                    {
                        date = temp;
                        temp = "";
                        flag++;
                    }
                    else if (flag == 3)
                    {
                        cYears = temp;
                        temp = "";
                        flag++;
                    }
                    
                    else if (flag == 4)
                    {
                        pay = temp;
                        temp = "";
                        flag++;
                    }
                }
            }

            workers.surname = surname;
            workers.post = pos;
            correctDate(date, day, month, year);
            workers.dayB = day;
            workers.monthB = month;
            workers.yearB = year;
            workers.pay = stoi(pay);
            workers.countYears = stoi(cYears);
            counter++;
            int posArr = Hash(n, workers.yearB);
            bool flag1 = false;

            for (int i = posArr; i < n; i++)
            {
                if (!HashTable[i].full)
                {
                    HashTable[i] = workers;

                    flag1 = true;

                    break;
                }
            }

            if (!flag1)
            {
                for (int i = 0; i < posArr; i++)
                {
                    if (!HashTable[i].full)
                    {
                        HashTable[i] = workers;

                        flag1 = true;
                        
                        break;
                    }
                }
            }
        }

        cout << endl;
        
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";

            HashTable[i].ShowDataset();
        }
    }
    else
    {
        cout << "файл не открыт";
    }

    fin.close();

    while (true)
    {
        cout << "введите\n 1 - найти элемент\n 0 - выход\n";
        int var;
        cin >> var;
        if (var == 1)
        {
            int Years;
            string surname;

            cout << "введите год\n";
            cin >> Years;

            cout << "введите фамилию\n";
            cin >> surname;
            
            find(HashTable, Years, surname, n);
        }
        else if (var == 0)
        {
            break;
        }
    }

    return 0;
}