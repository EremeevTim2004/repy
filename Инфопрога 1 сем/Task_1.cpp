#include <iostream>
#include <cmath>
using namespace std;

void Task_1(double x, double y){ // Задание 1
    double v;
    v=0.5*((sqrt(exp(x*x+y*y))-y*x)/(x*x+y*y))+log((sqrt(x*x*x*x)/(sqrt(y*y*y*y)))); // Решение уравнения
    cout<<v<<endl;
}

void Task_2(double x, double y){ // Задание 2
    double v;
    v=0,2*x*y+sqrt((exp(x-1)+exp(y-1))/(cos(abs(x+2*y))*cos(abs(x+2*y)))); // Решение уравнения
    cout<<v;
}

void Task_3(double x, double y){ // Задание 3
    double v;
    v=2%3*sin(sqrt((x*x-y*y)/(exp(x+y))+x*x*y*y))+((cos(x)+sin(y))/2); // Решение уравнения
    cout<<" "<<v<<endl; // Вывод
}

void Task_4(double x, double y){ // Задание 4
    double v;
    v=1%3*sqrt((exp(x*x+y*y)+5*x)/cos((x+y)*(x+y)))+x/y; // Решение уравнения
    cout<<" "<<v<<endl; // Вывод
}

void Task_5(double x, double y){ // Задание 5
    double v;
    v=0,4*((exp(sqrt(x*y)+sqrt(x+y))+sin(y*x))/(sqrt(cos(x)*cos(x)+sin(x)*sin(x)))); // Решение уравнения
    cout<<" "<<v<<endl; // Вывод
}

void Task_6(double x, double y){ // Задание 6
    double v;
    v=sqrt(exp(sqrt(cos((x+y)/(x-y)))+sin(log(x*y*y)*log(x*y*y)))); // Решение уравнения
    cout<<" "<<v<<endl; // Вывод
}

void Task_7(double x, double y){ // Задание 7
    double v;
    v=exp(sqrt(log((x*x+y*y)/(cos(x)*cos(x)*2)))); // Решение уравнения
    cout<<" "<<v<<endl; // Вывод
}

void Task_8(double x, double y){ // Задание 8
    double v;
    v=sqrt((sqrt(cos(x)+sin(y))+exp(x+y))/(sqrt(x+y+log(x)*log(x)))); // Решение уравнения
    cout<<"Ответ "<<v<<endl; // Вывод
}

void Task_9(double x, double y){ // Задание 9
    double v;
    v=sqrt(log((cos(x+y)*cos(x+y))/(sin((x+y)*(x+y))))*log((cos(x+y)*cos(x+y))/(sin((x+y)*(x+y))))+exp(x*x*y)); // Решение уравнения
    cout<<"Ответ "<<v<<endl; // Вывод
}

void Task_10(double x, double y){ // Задание 10
    double v;
    v=sqrt(cos((exp(sqrt(y+x)))/sin(sqrt(x*x-y*y))*sin(x*x-y*y))); // Решение уравнения
    cout<<"Ответ "<<v<<endl; // Вывод
}

void Task_11(int x){ // Задание 11
    int sum, pro, y;
    sum=x/100+x/10%10+x%10; // Решение при первом варианте условия
    pro=x/100*x/10%10*x%10; // Решение при втором варианте условия
    y=x%10*100+x/10%10*10+x/100;
    cout<<y<<' '<<sum<<' '<<pro<<endl;
}

void Task_12(int X){ // Задание 12
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y;
    first_digit_of_Y=25%(X/100);   // Нахождение первой цыфры
    second_digit_of_Y=25%(X/10%10); // Нахождение второй цыфры
    third_digit_of_Y=25%(X%10);    // Нахождение третей цыфры
    Y=first_digit_of_Y*100+second_digit_of_Y*10+third_digit_of_Y; // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_13(int X){ // Задание 13
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y, forth_digit_of_Y;
    first_digit_of_Y=31%(X/10); // Нахождение первой цыфры Y
    second_digit_of_Y=31%(X%10); // Нахождение второй цыфры Y
    third_digit_of_Y=48%(X/10); // Нахождение третьей цыфры Y
    forth_digit_of_Y=48%(X%10); // Нахождение четвёртой цыфры Y
    Y=first_digit_of_Y*1000+second_digit_of_Y*100+third_digit_of_Y*10+forth_digit_of_Y; // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_14(int X){ // задание 14
    int preY, Y, b, c;
    preY=(X/100)*(X/10%10)*(X%10)/(X/100)+(X/10%10)+(X%10); // Нахождение частного между произведение и суммой цыфр Х
    b=preY/10%10; // Нахождение второй цыфры preY
    c=preY%10;    // Нахождение третьей цыфры preY
    Y=preY/100*100+c*10+b; // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_15(int X){ // Задание 15
    int Y, sum_of_digit_X;
    sum_of_digit_X=X/100+X/10%10+X%10; // Нахождение суммы цыфр Х
    Y=sum_of_digit_X%(X/100)*100+sum_of_digit_X%(X/10%10)*10+sum_of_digit_X%(X%10); // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_16(int X){ // Задание 16
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y;
    first_digit_of_Y=((X/10)%10+X%10)%10; // Нахождение первой цыфры Y
    second_digit_of_Y=abs(X/100-X%10); // Нахождение второй цыфры Y
    third_digit_of_Y=(X/10%10)%(X/100); // Нахождение третьей цыфры Y
    Y=first_digit_of_Y*100+second_digit_of_Y*10+third_digit_of_Y; // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_17(int X){ // Задание 17
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y;
    first_digit_of_Y=((X/100)+(X/10%10)+(X%10))%10; // Нахождение первой цыфры Y
    second_digit_of_Y=((X/100)*(X/10%10)*(X%10))%100; // Нахождение второй цыфры Y
    third_digit_of_Y=((X/10%10)+(X%10))%(X/100); // Нахождение третьей цыфры Y
    Y=first_digit_of_Y*100+second_digit_of_Y*10+third_digit_of_Y; // Нахождение итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_18(int X){ // Задание 18
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y, forth_digit_of_Y;
    first_digit_of_Y=(X/1000+X/100%10)%10; // Нахождение первой цыфры Y
    second_digit_of_Y=(X/100%10+X/10%10)%(X/1000); // Нахождение второй цыфры Y
    third_digit_of_Y=(X/1000+X/100%10+X/10%10+X%10)%(X/1000); // Нахождение третьей цыфры Y
    forth_digit_of_Y=abs((X/100%10)-(X%10)); // Нахождение четвёртой цыфры Y
    Y=first_digit_of_Y*1000+second_digit_of_Y*100+third_digit_of_Y*10+forth_digit_of_Y; // Нахождение Итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_19(int X){ // Задание 19
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y, forth_digit_of_Y;
    first_digit_of_Y=(X/1000+X/100%10+X/10%10+X%10)%10;  // Нахождение первой цыфры Y
    second_digit_of_Y=((X/100%10)*(X/10%10))%(X/1000); // Нахождение второй цыфры Y
    third_digit_of_Y=(X/1000+X/100%10+X/10%10+X%10)%(X%10);  // Нахождение третьей цыфры Y
    forth_digit_of_Y=abs(X/100%10-X/10%10)%10;  // Нахождение четвёртой цыфры Y
    Y=first_digit_of_Y*1000+second_digit_of_Y*100+third_digit_of_Y*10+forth_digit_of_Y; // Нахождение Итогового числа
    cout<<Y<<endl; // Вывод
}

void Task_20(int X){ // Задание 20
    int Y, first_digit_of_Y, second_digit_of_Y, third_digit_of_Y, forth_digit_of_Y;
    first_digit_of_Y=(X/1000+X/100%10+X/10%10+X%10)%10;  // Нахождение первой цыфры Y
    second_digit_of_Y=(X/100%10)%(X/1000); // Нахождение второй цыфры Y
    third_digit_of_Y=(X/1000+X/100%10+X/10%10+X%10)%(X/100%10);  // Нахождение третьей цыфры Y
    forth_digit_of_Y=(X/1000)%(X/100%10); // Нахождение четвёртой цыфры Y
    Y=first_digit_of_Y*1000+second_digit_of_Y*100+third_digit_of_Y*10+forth_digit_of_Y; // Нахождение Итогового числа
    cout<<Y<<endl; // Вывод
}

int main() {
    int Task;
    double x, y;
    int X;
    cout<<"Input Task (1-20) or 0 to exit";
    cin>>Task;
    switch(Task) {
        case 1: {
            cout<<"Input x & y";
            cin>>x>>y;
            Task_1(x,y);
            break;
        }
        case 2: {
            cout<<"Input x & y";
            cin>>x>>y;
            Task_2(x,y);
            break;
        }
        case 3: {
            cout<<"Input x & y";
            cin>>x>>y;
            Task_3(x,y);
            break;
        }
        case 4: {
            cout<<"Input x & y";
            cin>>x>>y;
            Task_4(x,y);
            break;
        }
        case 5:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_5(x,y);
            break;
        }
        case 6:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_6(x,y);
            break;
        }
        case 7:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_7(x,y);
            break;
        }
        case 8:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_8(x,y);
            break;
        }
        case 9:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_9(x,y);
            break;
        }
        case 10:{
            cout<<"Input x & y";
            cin>>x>>y;
            Task_10(x,y);
            break;
        }
        case 11:{
            cout<<"Input X";
            cin>>X;
            Task_11(X);
            break;
        }
        case 12:{
            cout<<"Input X";
            cin>>X;
            Task_12(X);
            break;
        }
        case 13:{
            cout<<"Input X";
            cin>>X;
            Task_13(X);
            break;
        }
        case 14:{
            cout<<"Input X";
            cin>>X;
            Task_14(X);
            break;
        }
        case 15:{
            cout<<"Input X";
            cin>>X;
            Task_15(X);
            break;
        }
        case 16:{
            cout<<"Input X";
            cin>>X;
            Task_16(X);
            break;
        }
        case 17:{
            cout<<"Input X";
            cin>>X;
            Task_17(X);
            break;
        }
        case 18:{
            cout<<"Input X";
            cin>>X;
            Task_18(X);
            break;
        }
        case 19:{
            cout<<"Input X";
            cin>>X;
            Task_19(X);
            break;
        }
        case 20:{
            cout<<"Input X";
            cin>>X;
            Task_20(X);
            break;
        }
        case 0:{
            cout<<"Exit!";
            break;
        }
        default:{
            cout<<"Error";
            break;
        }
    }
    return 0;
}
