/*
Программа №2 из Списка 02

Задача: разложение числа на цифра и работа с ними

Определение переменных:
n1 - вводимое число
sum_dig - сумма цифр числа n1
dig - количество разрядов числа n1
opt - определяет опцию из списка
r_odd_dig - призмедение нечётных чисел числа n1
n - переменная-клон переменной n1
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n1, sum_dig, dig, opt, r_odd_dig;
    char cont;
    do
    {
        int n = n1; // копируем число n1 в переменную n, чтобы не изменять введённое значение
        // print the menu of options

        cout << "\nSelect an option from [1-8] according to the menu:" <<endl;
        cout << "[1]. Enter a number in the range between 1000 and 999999"<<endl;
        cout << "[2]. Print the digits of the number"<<endl;
        cout << "[3]. Count how many digits the number has"<<endl;
        cout << "[4]. Return the lowest and highest digits of the number"<<endl;
        cout << "[5]. Return the sum of the digits of the number"<<endl;
        cout << "[6]. Return the product of the odd digits"<<endl;
        cout << "[7]. Calculate the inverted version of the number"<<endl;
        cout << "---------------------------------------------------"<<endl;
        cout << "Enter option: ";
        cin>>opt;
        switch (opt)
        {
            case 1: // OPTION 01: Enter the number
            {
                do
                {  
                    cout<< "Введите число от 1000 и 999999: ";
                    cin>>n1;

                }
                while (n1 < 1000 || n1 > 999999);
                
                break;
            };

            case 2: // OPTION 02: Check if the number has repeated digits
            {
                cout<< "Цифры введённого числа: ";
                while (n != 0)
                {
                    cout<< (n % 10) << " ";
                    n /= 10;
                };

                break;
            };

            case 3: // OPTION 03: Count how many digits the number has
            {
                dig = 0;
                while (n != 0)
                {
                    dig++;
                    n /= 10;
                };

                cout<< "Количество цифр в введённом числе: " << dig << endl;

                break;
            };

            case 4: // OPTION 04: Return the lowest and highest digits of the number
            {
                int mx_dig = -1, mn_dig = 10;
                while (n != 0)
                {
                    if ((n % 10) >= mx_dig) {mx_dig = n % 10;};
                    if ((n % 10) <= mn_dig) {mn_dig = n % 10;};
                    n /= 10;
                };

                cout<< "Максимальная цифра числа: " << mx_dig << endl;
                cout << "Минимальная цифра числа: " << mn_dig << endl;

                break;
            };

            case 5: // OPTION 05: Return the sum of the digits of the number
            {
                sum_dig = 0;
                while (n != 0)
                {
                    sum_dig += (n % 10);
                    n /= 10;
                };

                cout<< "Сумма цифр числа: " << sum_dig << endl;

                break;
            };

            case 6: // OPTION 06: Return the product of the odd digits
            {
                r_odd_dig = 1;
                while (n != 0)
                {
                    if ((n % 10) % 2 != 0) {r_odd_dig *= (n % 10);};
                    n /= 10;
                };

                cout<< "Произведение нечётных цифр числа: " << r_odd_dig << endl;
                
                break;
            };
            
            case 7: // OPTION 07: Calculate the inverted version of the number
            {
                cout<< "Перевёрнутое число: ";
                while (n != 0)
                {
                    cout<< (n % 10);
                    n /= 10;
                };

                break;
            };
        };

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;

        cin>> cont;
    }
    while(cont == 'y' || cont == 'Y');

    cout << "\n The program is over!"<< endl;

    return 0;
}