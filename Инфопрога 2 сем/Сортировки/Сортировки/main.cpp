#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

ifstream in("Data.txt");
ofstream out("SortedData.txt");

struct date //дата
{
    int dd, mm, yy;
};

struct people //данные о человеке
{
    string Surname; //фамилия
    date DateOfBirth; //дата рождения
    string Post;
    int Exp;
    int Salary; //зарплата
};

date Str_to_Date(string str) //из строки в дату
{
    date x;
    string temp;

    temp = str.substr(0, 2);//день
    x.dd = atoi(temp.c_str());

    temp = str.substr(3, 2);//месяц
    x.mm = atoi(temp.c_str());

    temp = str.substr(6, 4);//год
    x.yy = atoi(temp.c_str());

    return x;
}

vector<people> inFile() //ввод из файла
{
    vector<people> x;
    people temp;

    while (in.peek() != EOF)
    {
        in >> temp.Surname;//фамилия
        in >> temp.Post;
        
        string tmp;//дата рождения
        in >> tmp;
        
        temp.DateOfBirth = Str_to_Date(tmp);

        in >> temp.Exp;
        in >> temp.Salary;//зарплата
        
        x.push_back(temp);
    }

    return x;
}

void print(people x) //вывод в файл
{
    out << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
    out << left << setw(24) << x.Post;//на должность 24 позиции

    if (x.DateOfBirth.dd < 10)
    {
        out << left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
    }

    else
    {
        out << left << x.DateOfBirth.dd << '.';
    }

    if (x.DateOfBirth.mm < 10)
    {
        out << '0' << x.DateOfBirth.mm << '.';
    }

    else 
    {
        out << x.DateOfBirth.mm << '.';
    }

    out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
    out << left << setw(10) << x.Exp;//Стаж
    out << left << setw(10) << x.Salary << endl;//запрлата
}

bool operator<(people a, people b) //переопределяем оператор < в соотвествии с условием
{
    if (a.Salary < b.Salary)
    {
        return true;
    }

    if (a.Salary == b.Salary && a.DateOfBirth.yy < b.DateOfBirth.yy)
    {
        return true;
    }

    if (a.Salary == b.Salary && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Exp < b.Exp)
    {
        return true;
    }

    return false;
}

bool operator>(people a, people b) //переопределяем оператор < в соотвествии с условием
{
    if (a.Salary > b.Salary) 
    {
        return true;
    }

    if (a.Salary == b.Salary && a.DateOfBirth.yy > b.DateOfBirth.yy) 
    {
        return true;
    }
    
    if (a.Salary == b.Salary && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Exp > b.Exp)
    {
        return true;
    }

    return false;
}

void quicksort(vector<people> &mas, int first, int last) 
{
    people mid, tmp;
    int f = first, l = last;

    mid = mas[(f + l) / 2]; //вычисление опорного элемента

    do 
    {
        while (mas[f] < mid) 
        {
            f++; //оставляем слева от опорного всё что меньше его
        }

        while (mas[l] > mid) 
        {
            l--; //оставляем справа что больше
        }

        //перестановка элементов
        if (f <= l)  
        {
            tmp = mas[f];
            mas[f] = mas[l];
            mas[l] = tmp;

            f++;
            l--;
        }
    }
    
    while (f < l);

    if (first < l) //рекурсивно вызываем сортировку для левого отрезка
    {
        quicksort(mas, first, l);
    }

    if (f < last) //для правого
    {
        quicksort(mas, f, last);
    }
}

void Merge(vector<people> &mas, int first, int last) //функция для слияния двух массивов
{
    int middle, l1, l2, j;
    vector<people> buf(100); //вектор с промежуточными данными

    middle = (first + last) / 2; //вычисление среднего элемента
    l1 = first; //начало левой части
    l2 = middle + 1; //начало правой части
    
    //выполнять от начала до конца
    for (j = first; j <= last; j++) 
        if ((l1 <= middle) && ((l2 > last) || (mas[l1] < mas[l2])))
        {
            buf[j] = mas[l1];
            
            l1++;
        } 
        
        else 
        {
            buf[j] = mas[l2];

            l2++;
        }

    //возвращение результата в вектор
    for (j = first; j <= last; j++) 
    {
        mas[j] = buf[j]; 
    }
}

void MergeSort(vector<people> &mas, int first, int last) 
{
    if (first < last)
    {
        MergeSort(mas, first, (first + last) / 2); //сортировка левой части
        MergeSort(mas, (first + last) / 2 + 1, last); //сортировка правой части
        Merge(mas, first, last); //слияние двух частей
    }
}

void choice_sort(vector<people> &mas) // 
{
    for (int i = 0; i < mas.size(); ++i) 
    {
        people tmp = mas[i];

        int min_index = i; //индекс минимального элемента

        //ищем минимальный элемент среди [i, n-1]
        for (int j = i+1; j < mas.size(); ++j) 
        {
            if (mas[j] < mas[min_index])
            {
                min_index = j;
            }
        }

        //меняем i-ый с минимальным
        mas[i] = mas[min_index];
        mas[min_index] = tmp;
    }
}

int main() // 
{
    int n;

    cout << "Input task number (1-3)" << endl << ">>";
    cin >> n;

    vector<people> x;

    x = inFile();

    switch (n) 
    {
        case 1: 
        {
            quicksort(x, 0, x.size() - 1);

            break;
        }

        case 2: 
        {
            MergeSort(x,0,x.size()-1);

            break;
        }

        case 3: 
        {
            choice_sort(x);

            break;
        }

        default: 
        {
            cout << "No such sort" << endl;

            break;
        }
    }

    for (int i = 0; i < x.size(); i++)
    {
        print(x[i]);
    }

    return 0;
}
