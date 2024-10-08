/*
Программа №1 из Списка 01

Задача: вычислить значение x(T) для маятника

Определпние переменных:
k - отношение амплитуды к координате (вход)
w - частота маятника
pi - const;
A - амплитуда колебаний
T - период колебаний
w0 - начальная частота
x - координата маятника

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float k, w, A;
    double T, w0, x;
    const double pi = 2 * asin(1.0);

    // запрос переменных
    cout<<"k = ";
    cin>>k;

    cout<<"w = ";
    cin>>w;

    cout<<"A = ";
    cin>>A;

    // рассчёт начальной частоты
    w0 = asin(1 / k);

    if (w == 0) {cout<<"Знаменатель не может равняться нулю.";}
    else
    {
        if (k == 1) {T = 0;}
        else {T = ((pi / 2) - w0) / w;};

        //cout<<"T = "<< T <<endl;
        // рассчёт координаты
        x = A * sin(w * T + w0);

        // выходные данные
        cout<<"x(T) = "<< x <<endl;
    };

    return 0;
}