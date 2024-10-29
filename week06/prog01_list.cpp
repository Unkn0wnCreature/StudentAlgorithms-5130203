#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// объявление функций
void num_of_elements(int *n);
int *allocation_of_memory(int n);
void input_vector(int n, int *x, char r);
void print_vector(int n, int *x, char r);
double average_num(int n, int *x);
double sum_of_multiplication(int n, int *x, int *y);
double sum_of_elements_in_power(int n, int power, int *x);
double calculation_of_regression(int n, int *x, int *y);
double calculation_of_ind_regression(int n, int *x, int *y);
void coef_y_and_error(int n, int *x, int *y);

// головвная функция
int main()
{
    int n, *x, *y, m = 2;
    double beta1, beta0;

    // ввод количества элементов в векторах *x и *y
    num_of_elements(&n);

    // динамическое выделение памяти
    x = allocation_of_memory(n);
    y = allocation_of_memory(n);

    // ввод значений векторов
    input_vector(n, x, 'x');
    input_vector(n, y, 'y');

    // печать векторов
    print_vector(n, x, 'x');
    print_vector(n, y, 'y');

    // вычисление регрессии B1
    beta1 = calculation_of_regression(n, x, y);
    cout<< "\nBeta(1) = " << beta1 <<endl;

    // вычисление регрессии B0
    beta0 = calculation_of_ind_regression(n, x, y);
    cout<< "\nBeta(0) = " << beta0 <<endl;

    // вывод ожидаемого значения Y и ощибки
    coef_y_and_error(n, x, y);

    return 0;
}

// ввод количества элементов вектора
void num_of_elements(int *n)
{
    do
    {
        cout<< "Введите n: ";
        cin>>*n;
    } while (*n <= 0);
    
}

// динамическое выделение памяти
int *allocation_of_memory(int n)
{
    return (int *) malloc(n * sizeof(int));
}

// ввод вектора
void input_vector(int n, int *x, char r)
{

    for (int i = 0; i < n; i++)
    {
        cout<< "\nВведите " << r << ": ";
        cin>>x[i];
    }
}

// вывод вектора
void print_vector(int n, int *x, char r)
{
    cout<< r << ": ";

    for (int i = 0; i < n; i++)
    {
        cout<< x[i] << " ";
    };

    cout<<endl;
}

// расчёт среднего значения
double average_num(int n, int *x)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    };

    return sum / n;
}

// вычисление суммы произведений элементов x[i] и y[i]
double sum_of_multiplication(int n, int *x, int *y)
{
    double result = 0; // начальное значение

    for (int i = 0; i < n; i++)
    {
        result += x[i] * y[i]; // накопление результата
    };

    return result;
}

// вычисление суммы элементов массива *x в степени (int power)
double sum_of_elements_in_power(int n, int power, int *x)
{
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        result += pow(x[i], power);
    };

    return result;
}

// вычисление регрессии B1
double calculation_of_regression(int n, int *x, int *y)
{
    double average_x, average_y, sum_square_x, sum_x, sum_of_mult;

    sum_of_mult = sum_of_multiplication(n, x, y);
    sum_square_x = sum_of_elements_in_power(n, 2, x);
    sum_x = sum_of_elements_in_power(n, 1, x);
    average_x = average_num(n, x);
    average_y = average_num(n, x);

    return (sum_of_mult - n * average_x * average_y) / (sum_square_x - (sum_x / n));
}   

// вычисление регрессии B0
double calculation_of_ind_regression(int n, int *x, int *y)
{
    double average_x, average_y, beta1;

    average_x = average_num(n, x);
    average_y = average_num(n, x);
    beta1 = calculation_of_regression(n, x, y);

    return (average_y - beta1 * average_x);
}

// вычисление ожидаемого значения Y и ошибки
void coef_y_and_error(int n, int *x, int *y)
{
    double beta0, beta1;

    beta1 = calculation_of_regression(n, x, y);
    beta0 = calculation_of_ind_regression(n, x, y);

    cout<< "\nX\tCoef_Y\tError" <<endl;
    cout<< "-----------------------------------" <<endl;

    for (int i = 0; i < n; i++)
    {   
        double c_y = beta0 + beta1 * x[i], error = abs(y[i] - c_y);
        cout<< x[i] << "\t" << c_y << "\t" << error <<endl;
    };
}