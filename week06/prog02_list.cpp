#include <iostream>
using namespace std;

// объявление функций
void num_of_elements(int *n);
char *allocation_of_memory(int n);
void input_vector(int n, char *x);
void print_vector(int n, char *x);
void unify(int n_1, int n_2, char *x, char *y, char *z);

// головная функция
int main()
{
    int n1, n2, n3;
    char *a, *b, *z;

    // ввод количества элементов в векторах
    num_of_elements(&n1);
    num_of_elements(&n2);

    // длина объединённого вектора
    n3 = n1 + n2;

    // динамическое выделение памяти
    a = allocation_of_memory(n1);
    b = allocation_of_memory(n2);
    z = allocation_of_memory(n3);
    
    // ввод значений векторов
    input_vector(n1, a);
    input_vector(n2, b);

    // печать векторов
    print_vector(n1, a);
    print_vector(n2, b);

    // объединение в единый вектор с чередующимися элементами
    unify(n1, n2, a, b, z);

    // печать объединённого вектора
    print_vector(n3, z);
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
char *allocation_of_memory(int n)
{
    return (char *) malloc(n * sizeof(char));
}

// ввод вектора
void input_vector(int n, char *x)
{
    cout<< "\nВведите слова из " << n << " символов: ";
    cin>>x;
}

// вывод вектора
void print_vector(int n, char *x)
{
    cout<< "\nVECTOR" <<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< x[i] << " ";
    };
}

// объединение в единый вектор с чередующимися элементами
void unify(int n_1, int n_2, char *x, char *y, char *z)
{
    int n_3 = n_1 + n_2; // длина объединённого вектора

    if (n_1 > n_2)
    {
        for (int i = 0; i < n_3; i++)
        {
            if (i < n_2 * 2)
            {
                if (i % 2 == 0) {z[i] = x[i / 2];}
                else {z[i] = y[i / 2];};
            }
            else {z[i] = x[i - abs(n_1 - n_3)];}; // печатаем оставшиеся значения большего вектора
        };
    }
    else
    {
        for (int i = 0; i < n_3; i++)
        {
            if (i < n_1 * 2)
            {
                if (i % 2 == 0) {z[i] = x[i / 2];}
                else {z[i] = y[i / 2];};
            }
            else {z[i] = y[i - abs(n_2 - n_3)];}; // печатаем оставшиеся значения большего вектора
        };
    };
}