#include <iostream>
#include <cmath>
using namespace std;

void Task_1(int a, int x, int y){ //функция для задания 1, принимает на вход число a x и y
    int first, second, third, sum; // объявляем рабочие переменные
    if (a >= 100 && a < 1000){ // если а трехзначное число
        first = a / 100; // получаем первую цифру
        second = (a % 100) / 10; // получаем вторую цифру
        third = a % 10; //получаем третью цифру
        sum = first + second + third; // получаем сумму цифр
        if ((sum % x == 0) && (sum % y == 0)){ // если сумма кратна и х и у
            first = abs(first - 5);
            second = abs(second - 5); //то вычитаем от всех цифр 5 (по модулю)
            third = abs(third - 5);
        }
        if ((sum % x == 0) && (sum % y != 0)){ // если сумма кратна х и не кратна у
            first = (first * 2) % 10;
            second = (second * 2) % 10; // то увеличиваем все цифры в два раза и получаем остаток от деления на 10 в случае если цифра > 9
            third = (third * 2) % 10;
        }
        if ((sum % x != 0) && (sum % y == 0)){ // если сумма не кратна х но кратна у
            first = (first + 1) % 10;
            second = (second + 1) % 10; // прибавляем ко всем цифрам числа 1 и получаем остаток от деления от 10 в случае если цифра > 9
            third = (third + 1) % 10;
        }
        if ((sum % x != 0) && (sum % y != 0)){ // если сумма ни кратна ни х ни у
            first = abs(first - 1);
            second = abs(second - 1); // то вычитаем из всех цифр 1 по модулю
            third = abs(third - 1);
        }
        a = first * 100 + second * 10 + third; // собираем число обратно с новыми цифрами
        cout<<a; // на выходе получаем новое число
    }
    else{ // если введено не трехзначное число то вывести ошибку
        cout << "Ошибка ввода, введите трёхзначное число." << endl;
    }
}

void Task_7(int x){// функция для 7 ого задания
    int k_ch, logarifm, k_zn; // инициализируем рабочие переменные
    double result; // инициализируем результат
    k_ch=x+5;
    logarifm=8-2*x;
    k_zn=x*x+2*x+1;
    if (k_ch<0||k_zn<0){ // если подкоренное выражение < 0 то вывести ошибку
        cout<<""<<endl; // и завершить функцию
    }else if (k_zn == 0) { // если знаменатель равен 0, то вывести ошибку
            cout << "Деление на 0" << endl;
            return; // и завершить функцию
    }else if (logarifm < 0) { // если выражние из которого мы собираемся вывести логарифм < 0 - то вывести ошибку
            cout << "" << endl;
        }
    result=(sqrt(k_ch) + log(logarifm))/(sqrt(k_zn)); // собираем выражение в результа
    cout<<""<<result<<endl; // выводим на экран
}

void Task_11(int m, int n) { //функция для выполнения 11 задания.
    int day, month, year; //объявляем рабочие переменные.
    day = 1;
    month = 1; //ввели условные данные.
    year = 2000;
    if (n > 20) { //если количество введённых дней больше 20, то вывести ошибку и завершить функцию
        cout << "Неверное кол-во байт" << endl;
        return;
    }
    if (m < 0) { // если количество введённых месяцев меньше 0, то вывести ошибку и завершить функцию
        cout << "Неверное кол-во месяцев" << endl;
        return;
    }
    day += n; // к условным данным прибавляем введённые
    month += m;
    while (month > 12) { // пока количество месяцев больше 12, из количества месяцев вычесть 12 и прибавить 1 год
        month -= 12;
        year += 1;
    }
    cout << "Результат : "; // интерфейс
    cout << day; // выводим день
    switch (month) { //цифровое значение месяца переводим в буквенное с помощью оператора свитч - кейс.
        case 1: {
            cout << "  ";
            break;
        }
        case 2: {
        }
            cout << "  ";
            break;
        case 3: {
            cout << "  ";
            break;
        }
        case 4: {
            cout << "  ";
            break;
        }
        case 5: {
            cout << "  ";
            break;
        }
        case 6: {
            cout << "  ";
            break;
        }
        case 7: {
            cout << "  ";
            break;
        }
        case 8: {
            cout << "  ";
            break;
        }
        case 9: {
            cout << "  ";
            break;
        }
        case 10: {
            cout << "  ";
            break;
        }
        case 11: {
            cout << "  ";
            break;
        }
        case 12: {
            cout << "  ";
            break;
        }
        default: { // для отладки
            cout << "  (" << month << ") ";
        }
            cout << year << " " << endl; // выводим полученный год
    }

    void
    Task_16(double x1, double y1, double r1, double x2, double y2, double r2) { // функция для выполнения 16 задания
        double d, a, b; // объявляем рабочие переменные
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // расстояние между серединами окружностей
        a = (d * d + r1 * r1 - (r2 * r2)) / (2 * d); // часть от d
        b = (r2 * r2 + d * d - (r1 * r1)) / (2 * d); // часть от d
        if (x1 == x2 && y1 == y2 &&
            r1 == r2) { // если координаты середин окружностей и их радиусы совпадают, то сами это окружности савпадают
            cout << "Окружности совпадают." << endl;
        } else if ((r1 + r2) <
                   d) { // если сумма радиусов больше расстояния между серединами окружностей то окружности не пересекаются
            cout << "Окружности не пересекаються" << endl;
        } else if ((r1 - r2) >
                   d) { // если разность между радиусом 1 окружности и радиусом 2 окружности больше расстояния между центрами этих окружностей, то вторая окружность лежит в первой
            cout << "Окружности лежат одна в другой ( 2-nd in 1-st )." << endl;
        } else if ((r2 - r1) >
                   d) { // если разность между радиусом 2 окружности и радиусом 1 окружности больше расстояния между центрами этих окружностей, то первая окружность лежит во второй
            cout << "Окружности лежат одна в другой ( 1-st in 2-nd )." << endl;
        } else if ((r1 + r2) == d) { // если сумма радиусов равна расстоянию между центрами этих окружностей
            float p0x, p0y; // инициализируем координаты точки касания
            p0x = x1 + (a / d) * (abs(x2 - x1)); // вычисляем координату х
            p0y = y1 + (a / d) * (abs(y2 - y1)); // вычисляем координату у
            cout << "Окружности косаються в точке: " << endl << "P0 (" << p0x << "," << p0y << ")"
                 << endl; // выводим на экран
        } else if (r1 + r2 > d) { // если сумма радиусов больше расстояние между центрами этих окружности
            float p0x, p0y, h, p3x, p3y, p4x, p4y; //инициализируем переменные для координат точек треугольника
            p0x = x1 + (a / d) * ((x2 -
                                   x1)); // считаем где находится начало высоты треугольника на отрезке от центра 1 окружности до центр 2 окружности
            p0y = y1 + (a / d) * ((y2 - y1));
            h = sqrt((r1 * r1) - (a * a)); // находим длинну высоты треугольника
            p3x = p0x + ((abs(y2 - y1)) / d) * h; //находим координаты точки 1 пересечения
            p3y = p0y - ((abs(x2 - x1)) / d) * h;
            p4x = p0x - ((abs(y2 - y1)) / d) * h; //находим координаты точки 2 пересечения
            p4y = p0y + ((abs(x2 - x1)) / d) * h;
            cout << "Окружности пересекаеться в точках: " << endl << "P3 (" << p3x << "," << p3y << ")" << endl
                 << "P4 (" << p4x << "," << p4y << ")" << endl; //выводим полученные координаты на экран
        }
    }

    int main() { //
        int a, x, y, Task = 1; //объявления переменные для работы функции и интерфейса
        cout << "Выберете задание (1,7,11,16) или введите 0 чтобы выйти.)" << endl << ">> ";
        cin >> Task; //вводим номер задания
        switch (Task) {
            case 1: { // выполнение 1 задания
                cout << "Введите A и X." << endl << ">> ";
                cin >> a >> x >> y; // вводим данные
                Task_1(a, x, y); //получаем результат
                break;
            }
            case 7: { //выполнение 7 задания
                cout << "Введите X." << endl << ">> ";
                cin >> x; //вводим данные.
                Task_7(x); //передаём функции, полученное значение и получаем результат
                break;
            }
            case 11: { //выполняем задание 11
                cout << "Введите М и N." << endl << ">> ";
                cin >> M >> N; // вводим данные
                Task_11(M, N); //передаём функции полученные значения и получаем результат
                break;
            }
            case 16:
                cout << "Введиет x1,y1,R1,x2,y2,R2." << endl << ">> ";
                double a1, b, c, d, e, f; // инициализируем переменные для ввода их в функцию
                cin >> a1 >> b >> c >> d >> e >> f; // вводим данные
                Task_16(a1, b, c, d, e, f); //передаём функции полученные значения и получаем результат
                break;
            case 0: {
                cout << "Выход." << endl;
                break;
            }
            default: {
                cout << "" << endl; //при ошибке ввода номера задания писать об этом на экране.
                break;
            }
        }
        return 0;
    }