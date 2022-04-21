#include <iostream>
#include <fstream>
#include <string>

struct Train //
{
    int train_number; // номер поезда

    // время отправления
    int hours_arrive;
    int minutes_arrive;

    // время в пути
    int hours_way;
    int minutes_way;
};

struct Point //
{
    double x;
    double y;

    Point(){};
};

struct Time //
{
    int hours; // часы, минуты, секунды
    int minutes;
    int seconds;
};

bool check_time(Train t){ //
    if(t.hours_arrive > 23 || t.hours_way > 23 || t.minutes_arrive > 59 || t.minutes_way > 59){ // проверка корректности
        return false;
    }

    return true;
}

bool check_time_2(Time a){ //
    if(a.hours > 23 || a.minutes > 59 || a.seconds > 59){ // проверка корректности
        return false;
    }

    return true;
}

bool in_square(Point a, double x_min, double y_min, double x_max, double y_max){ //
    if(x_min <= a.x && x_max >= a.x && y_min <= a.y && y_max >= a.y){ // условие нахождения внутри прямоугольника
        return true;
    }

    return false;
}

std::string time_arrive(Train t){ //
    int m_arr = t.minutes_arrive + t.minutes_way; // вычисление времени прибытия
    int h_arr = t.hours_arrive + t.hours_way + m_arr / 60;

    h_arr %= 24;
    m_arr %= 60;

    return std::to_string(h_arr) + ':' + std::to_string(m_arr);
}

std::string time_dif(Time a, Time b){ // вычисление разницы времени с учетом возможного перехода на новый день
    int s_a = a.hours * 60 * 60 + a.minutes * 60 + a.seconds;
    int s_b = b.hours * 60 * 60 + b.minutes * 60 + b.seconds;

    int s_dif = (24 * 60 * 60 + s_b - s_a) % (24 * 60 * 60);

    int m_dif = s_dif / 60;
    int h_dif = m_dif / 60;

    s_dif %= 60;
    m_dif %= 60;

    return std::to_string(h_dif) + ':' + std::to_string(m_dif) + ':' + std::to_string(s_dif);
}

std::string n_sec(Time a, int n){ //
    int s_a = a.hours * 60 * 60 + a.minutes * 60 + a.seconds; // вычисление нового времени с учетом возможного перехода на новый день

    s_a += n;

    int s_new = s_a % (24 * 60 * 60);
    int m_new = s_new / 60;
    int h_new = m_new / 60;

    s_new %= 60;
    m_new %= 60;

    return std::to_string(h_new) + ':' + std::to_string(m_new) + ':' + std::to_string(s_new);
}

/*Создать структуру Train, содержащую данные о номере поезда, времени отправления, 
*времени в пути. Определить для каждого поезда время прибытия на конечную станцию. 
*Необходима проверка на корректность ввода времени.*/
void Task_1(int train_col)
{
    Train* a = new Train [train_col];

    for(int i=0; i<train_col; i++){
        std::cout << "number of "<< i+1 << " train is" << std::endl << ">>";
        std::cin >> a[i].train_number; // ввод номера поезда

        std::string s;

        std::cout << "input " << i+1 << " train departure time" << std::endl << ">>";
        std::cin >> s; // ввод времени отправления

        a[i].hours_arrive = int(s[0]-'0')*10 + int(s[1]-'0');
        a[i].minutes_arrive = int(s[3]-'0')*10 + int(s[4]-'0');

        std::cout << "Input " << i+1 << " train arrive time" << std::endl << ">>";
        std::cin >> s; // ввод времени прибытия

        a[i].hours_way = int(s[0]-'0')*10 + int(s[1]-'0');
        a[i].minutes_way = int(s[3]-'0')*10 + int(s[4]-'0');
    }

   // Вывод данны
    std::cout << "Результат:" << std::endl;
    for(int i=0; i < train_col; i++)
    {
        if(check_time(a[i])) // проверка корректности времени и вывод
        {
            std::cout << a[i].train_number << " прибытие в " << time_arrive(a[i]) << std::endl;
        }
        
        else
        {
            std::cout << a[i].train_number << " некорректное время" << std::endl;
        }
    }
}

/*Ваш выбор: Дано множество точек на плоскости. 
*Найти все точки, находящиеся внутри прямоугольника с координатами вершин {Xmin, Ymin}, {Xmax, Ymax}*/
void Task_2(int point_col)
{
    std::cout << "Введите координаты точек" << std::endl;

    Point* a = new Point [point_col];

    // ввод координат
    for(int i = 0; i < point_col; i ++)
    {
        // Ввод x координаты
        std::cout << "point " << i+1 << " x = ";
        std::cin >> a[i].x; 

        // Ввод y координаты
        std::cout << "point " << i+1 << " y = ";
        std::cin >> a[i].y;
    }

    // ввод координат прямоугольника
    int x_min, y_min, x_max, y_max;
    std::cout << "Введите координаты прямоугольника(x_min)" << std::endl << ">>";
    std::cin >> x_min;
    std::cout << "Введите координаты прямоугольника(y_min)" << std::endl << ">>";
    std::cin >> y_min;
    std::cout << "Введите координаты прямоугольника(x_max)" << std::endl << ">>";
    std::cin >> x_max;
    std::cout << "Введите координаты прямоугольника(y_max)" << std::endl << ">>";
    std::cin >> y_max;

    puts("Результат:");
    for(int i = 0; i < point_col; i ++)
    {
        if(in_square(a[i], x_min, y_min, x_max, y_max)){ // проверка на нахождение внутри
            std::cout << a[i].x << ' ' << a[i].y << std::endl;
        }
    }
}

/*Реализовать функции для работы с временем: 
*определение количества прошедших секунд, минут, часов,
*определение времени через N секунд, корректность времени.*/
void Task_3(int quastions_col)
{
    for (int i = 0; i < quastions_col; i ++)
    {
        std::string s;

        puts("Введите запрос(dif, nsec):"); // dif - разница времени, nsec - время через n секунд
        std::cin >> s;

        if(s == "dif")
        {            
            Time a;

            puts("Введите первое время(часы, минуты, секунды через пробел):");
            std::cin >> a.hours >> a.minutes >> a.seconds;
            

            Time b;

            puts("Введите второе время(часы, минуты, секунды через пробел):");
            std::cin >> b.hours >> b.minutes >> b.seconds;

            puts("Результат:");
            if(check_time_2(a) && check_time_2(b)) // проверка корректности времени и вывод
            {
                std::cout << time_dif(a, b) << std::endl;
            }

            else
            {
                std::cout << "Некорректное время" << std::endl;
            }
        }

        else
        {
            Time a;
            std::cout << "Введите начальное время(часы, минуты, секунды через пробел)" << std::endl << ">>"; 
            std::cin >> a.hours >> a.minutes >> a.seconds;

            int n;

            puts("Введите n:");
            std::cin >> n;

            puts("Результат:");
            if(check_time_2(a)) // проверка корректности времени и вывод
            {
                std::cout << n_sec(a, n) << std::endl;
            }

            else
            {
                std::cout << "Некорректное время" << std::endl;
            }
        }
    }
}

int main() // Главная функция
{
    int Task; // Инициализация переменной

    //
    std::cout << "Введите номер задания" << std::endl << ">>";
    std::cin >> Task;

    switch(Task) // Выбор раздела заданий через свитч-кэйс
    {
        case 1: //
        {
            int train_col;//

            //
            std::cout << "Введиет ко-во поездов" << std::endl << ">>";
            std::cin >> train_col;

            Task_1(train_col); //

            break;
        }

        case 2: //
        {
            int point_col; //

            //
            std::cout << "Введиет ко-во точек" << std::endl << ">>";
            std::cin >> point_col;

            Task_2(point_col); //

            break;
        }
        
        case 3: //
        {
            int quastions_col;

            std::cout << "Введите кол-во вопросов" << std::endl << ">>";
            std::cin >> quastions_col;

            Task_3(quastions_col); //

            break;
        }

        default: //
        {
            std::cout << "" << std::endl;
            break;
        }
    }

    return 0;
}
