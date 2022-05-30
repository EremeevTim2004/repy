#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
        cout << surname << '\t' << post << '\t' << dayB << " " << monthB << " " << yearB << '\t' << countYears << '\t' << pay << endl;
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
                counter ++;
            }
            else if (counter == 1)
            {
                month = stoi(temp);
                temp = "";
                counter ++;
            }
            else if (counter == 2)
            {
                year = stoi(temp);
                temp = "";
                counter ++;
            }
        }
    }

    if (counter == 2)
    {
        year = stoi(temp);
        temp = "";
        counter ++;
    }
};

struct list {
    worker container;
    list* next;
    list* prev;
    list* head;
    list* tail;
};

//вставка элемента в конец списка
void push(list*& h, list*& t, worker x)
{ 
    list* r = new list; //создаем новый элемент

    r->container = x;
    r->next = NULL; //всегда последний
    
    //если список пуст
    if (!h && !t)
    { 
        r->prev = NULL; //первый элемент
        h = r; //это голова
    }
    else
    {
        t->next = r; //r - следующий для хвоста
        r->prev = t; //хвост - предыдущий для r
    }

    t = r; //r теперь хвост
}


//вывод списка в консоль
void print(list* h, list* t)
{
    list* p = h;
    
    while (p)
    {
        worker temp = p->container;

        temp.ShowDataset();
        
        p = p->next;
        
        cout << endl;
    }

    cout << endl;
}

//печать элементов списка
list* find(list* h, list* t, int x, string surname) 
{ 
    list* p = h; //укзатель на голову
    while (p) { //пока не дошли до конца списка
        if (p->container.countYears == x && p->container.surname == surname) break; // если нашли, прекращаем цикл
        p = p->next; //переход к следующему элементу
    }
    return p; //возвращаем указатель
}

//удаляем после r
void del_node(list*& h, list*& t, list* r)
{ 
    if (r == h && r == t) //единственный элемент списка
    {
        h = t = NULL;
    }
    else if (r == h) //удаляем голову списка
    {
        h = h->next; //сдвигаем голову
        h->prev = NULL;
    }
    else if (r == t) //удаляем хвост списка
    {
        t = t->prev; //сдвигаем хвост
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev; //для следующего от r предыдущи становится r->prev
        r->prev->next = r->next; //для предыдущего от r следующим становится r->next
    }
    delete r; //удаляем r
}

int Hash(int n, int countYears) {
    return (countYears % n);
}

int main()
{
    std::string line;

    ifstream fin;
    fin.open("Data.txt");

    int n;
    std::cout << "введите размер таблицы\n";
    std::cin >> n;
    vector <list> hashTable(n);

    for (int i = 0; i < n; i++)
    {
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }

    worker workers; 

    int counter = 0;
    
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            int flag = 0;
            int length;

            length = line.size();
            
            string temp;
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

            push(hashTable[Hash(n, workers.countYears)].head, hashTable[Hash(n, workers.countYears)].tail, workers);
        }


        cout << endl;
        
        for (int i = 0; i < n; i++)
        {
            cout << i << ": \n";

            print(hashTable[i].head, hashTable[i].tail);
        }
    }
    else
    {
        cout << "файл не открыт";
    }


    fin.close();

    while (true)
    {
        int var;

        cout << "введите\n 1 - найти элемент\n 2 - удалить элемент\n 0 - выход\n";
        cin >> var;

        if (var == 1)
        {
            int cYears;

            string surname;
            cout << "введите стаж\n";
            cin >> cYears;
            cout << "введите фамилию\n";
            cin >> surname;
            list* rez = find(hashTable[Hash(n, cYears)].head, hashTable[Hash(n, cYears)].tail, cYears, surname);

            if (rez != NULL)
            {
                rez->container.ShowDataset();
            }
            else
            {
                cout << "такого элемента нет\n";
            }
        }
        else if (var == 2)
        {
            int cYears;
            string surname;

            cout << "введите стаж\n";
            cin >> cYears;

            cout << "введите фамилию\n";
            cin >> surname;

            list* rez = find(hashTable[Hash(n, cYears)].head, hashTable[Hash(n, cYears)].tail, cYears, surname);
            if (rez != NULL)
            {
                rez->container.ShowDataset();

                del_node(hashTable[Hash(n, cYears)].head, hashTable[Hash(n, cYears)].tail, rez);

                cout << "элемент удален\n";
            }
            else
            {
                cout << "такого элемента нет\n";
            }
        }
        else if (var == 0)
        {
            break;
        }
        
    }

    cout << "хэш таблица: \n";

    for (int i = 0; i < n; i++)
    {
        cout << i << ": \n";
        
        print(hashTable[i].head, hashTable[i].tail);
    }

    return 0;
}