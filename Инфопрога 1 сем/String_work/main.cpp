#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Дана строка, содержащая латинские буквы. Все гласные буквы заменить пробелом.*/
std::string Task_3(std::string s)
{
    std::string s2 = "aeiou"; // гласные

    for(int i=0; i<s.size(); i++)
    {
        for(int j=0; j<s2.size(); j++)
        {
            if(s[i] == s2[j]) // если совпало с одной из гласных - заменяем пробелом
            {
                s.replace(i, 1, 1, ' ');

                break;
            }
        }
    }

    return s;
}

/*Дано предложение, содержащее знаки препинания. После всех слов, начинающихся с данной буквы, 
поставить двоеточие.*/
std::string Task_9(std::string s, char s2)
{
    std::string s3("`~!@#$%&^*()-_=+[]{};:,.?<>"); // знаки препинания

    int flag = 0; // флаг 1 - слово началось с нужной буквы, 0 - нет

    for(int i=0; i<s.size(); i++)
    {
        if((i == 0 || s[i-1] == ' ') && s[i] == s2) // проверка певой буквы слова на соответствие s2
        {
            flag = 1;
        }

        if((i == s.size() - 1 || s[i+1] == ' ') && flag == 1) // если слово началось с s2 и сейчас последний символ слова
        {
            int f = 0; // флаг 1- последний символ - знак препинания, 0 - нет
        
            for(int j=0; j<s3.size(); j++)
            {
                if(s[i] == s3[j]) // проверка совпадения последнего символа перед пробелом(или концом строки) с каким-то знаком препинания
                {
                    f = 1;
                    
                    s.replace(i, 1, 1, ':'); // замена знака
                    
                    break;
                }
            }

            if(f == 0) // если последний символ - не знак препинания
            {
                s.insert(i+1, 1, ':'); // вставка двоеточия после слова
            }

            flag = 0; // обнуление флага для нового слова
        }
    }

    return s;
}

/*Дано предложение, записанное латинскими буквами. Вывести только те слова, 
которые можно прочитать, используя русский алфавит. Например, "МАМА, ОВЕС"*/
void Task_13(std::string s)
{
    std::string s3("ETOPAHKXCBM"); // буквы кторые можно прочесть используя русский алфавит

    int flag = 0; // флаг 0 - все буквы слова подходят, 1 - нет

    std::string s2 = ""; // текущее слово

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {

            if(flag == 0 && s2 != ""){ // если слово соответствует условиям то выводим его
                std::cout << s2 << ' ';
            }

            s2 = ""; // переход к новому слову

            flag = 0;
        }

        else
        {
            int f = 0; // флаг - есть буква в s3 или нет, 0 - нет, 1 - да
            for(int j=0; j<s3.size(); j++)
            {
                if(s[i] == s3[j]) // проверка на вхождение в s3
                {
                    f = 1;

                    break;
                }
            }

            if(f == 0) // если нет, то слово не подходит и меняем флаг t
            {
                flag = 1;
            }

            s2+=s[i]; // запись слова из s в s2
        }
    }

    if(flag == 0) // вывод последнего слова, если оно подходит
    {
        std::cout << s2;
    }
}

/*Дан файл, содержащий расписание движения поездов в виде: Маршрут - время отправления - время в пути. 
Вывести в новый файл данные о поездах, которые прибываеют на конечную станцию в промежутке от 12 до 15 часов.*/
void Task_20(std::istream& in)
{
    while(!in.eof()) // пока не конец файла
    {
        std::string s;

        getline(in, s); // считывание очередной строки

        int t = 0; // номер части(0 - маршрут, 1 - отправление, 2 - время пути)
        int ind1, ind2; // индексы разделителей " - " с указанием индекса '-'

        for(int i=0; i<s.size(); i++)
        {
            if(i != 0 && i != s.size() - 1 && s[i] == '-' && s[i-1] == ' ' && s[i+1] == ' ') // проверка на разделитель
            {
                t++; // переход к след. части

                if(t == 1) // запоминание индексов разделителей
                {
                    ind1 = i;
                }

                else
                {
                    ind2 = i;
                }
            }
        }

        int h = int(s[ind1+2] - '0') * 10 + int(s[ind1+3] - '0'); // подсчет времени отправления
        int m = int(s[ind1+5] - '0') * 10 + int(s[ind1+6] - '0');

        int ph = int(s[ind2+2] - '0') * 10 + int(s[ind2+3] - '0'); // подсчет времени пути
        int pm = int(s[ind2+5] - '0') * 10 + int(s[ind2+6] - '0');

        // подсчет времени прибытия
        m += pm;
        m %= 60;

        h += ph + m/60;
        h %= 24;

        if(h >=12 && (h < 15 || (h == 15 && m == 0))) // проверка на нужный промежуток и вывод при необходимости
        {
            std::cout << s << std::endl;
        }
    }
}

int main() //
{
    int Task; //

    std::cout << "Введите номер задания (3, 9, 13, 20)" << std::endl << ">>";
    std::cin >> Task;

switch(Task) // Выбор задания через свитч-кэйс
    {
            case 3: //
            {
                std::string s; // Инициализация строки

                // Заполнение строки с клавиатуры
                std::cout << "Введите строку" << std::endl << ">>";
                getline(std::cin, s);
                getline(std::cin, s);

                s = Task_3(s); //

                //
                std::cout << "Результат:" << std::endl;
                std::cout << s << std::endl;

                break;
            }

            case 9: //
            {
                std::string s; //

                //
                std::cout << "Введите строку" << std::endl << ">>";
                getline(std::cin, s); // доп. getline т.к. из ввода task не дочиталось \n
                getline(std::cin, s);

                char s2; //

                //
                puts("Введите символ:");
                std::cin >> s2;

                s = Task_9(s, s2); //

                //
                std::cout << "Результат:" << std::endl;
                std::cout << s << std::endl;

                break;
            }

            case 13: //
            {
                std::string s; //

                //
                std::cout << "Введите строку" << std::endl << ">>";
                getline(std::cin, s);
                getline(std::cin, s);

                //
                std::cout << "Результат:" << std::endl;
                Task_13(s);

                break;
            }

            case 20: //
            {
                std::ifstream in; //

                std::string InputFileName; //

                //
                std::cout << "Введите название файла:" << std::endl << ">>";
                std::cin >> InputFileName;

                in.open(InputFileName); // открытие файла для чтения

                if(!in.is_open()) //
                {
                    std::cout << "Ошибка открытия файла";

                    return 0;
                }

                //
                puts("Результат:");

                Task_20(in);

                break;
            }

            default: //
            {
                std::cout << "Error! Wrong podtask number!" << std::endl;
                break;
            }
    }

    return 0;
}