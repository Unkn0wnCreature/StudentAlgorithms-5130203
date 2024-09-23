/*
Программа для произведения расчётов налога на имущество за земельный участок.

Наименование и значение переменных:
material - статус выбранного материала
floors - количество этажей в здании
services - статус подключения базовых услуг
square_with_roof - площадь участка с крышей
square_without_roof - площадь участка без крыши
square_garden - площадь участка с садом
taxe - сумма налога
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int material, floors, services, square_with_roof, square_without_roof, square_garden;
    float taxe;

    // запрос данных
    cout<<"Введите площадь с крышей (в кв.м): ";
    cin>>square_with_roof;
    
    cout<<"Введите площадь без крыши (в кв.м): ";
    cin>>square_without_roof;

    cout<<"Введите площадь сада (в кв.м): ";
    cin>>square_garden;

    taxe = 5 * square_with_roof + 3 * square_without_roof + square_garden;

    cout<<"Из какого материала изготовлено здание? (1 - качественный материал, 2 - саман, 3 - другой материал) ";
    cin>>material;

    // проверка
    if (material <= 0 || material >= 4) {cout<<"Нельзя ввести данные значенияю."<<endl;}
    else 
    {
        // изменение суммы налогов
        if (material == 1) {taxe = 1.15 * taxe;}
        else if (material == 2) {taxe = 1.1 * taxe;}
        else {taxe = 1.05 * taxe;};

    };
    
    // проверка на наличие базовых услуг
    cout<<"Есть ли базовые услуги? (1 - есть, 0 - нет) ";
    cin>>services;

    // проверка и изменение суммы налога
    if (services < 0 || services > 1) {cout<<"Нельзя ввести данное значение параметра."<<endl;}
    else {taxe = taxe + services * 2.5;};

    // указание этажности здания
    cout<<"Количество этажей в доме: ";
    cin>>floors;

    // проверка
    if (floors <= 0) {cout<<"Количество этажей в здании не может быть отрицательным."<<endl;}
    else
    {
        // изменение суммы налога в зависимости от этажности здания
        if (floors == 2) {taxe = 1.1 * taxe;}
        else if (floors == 3 || floors == 4) {taxe = 1.15 * taxe;}
        else {taxe = 1.2 * taxe;};
    };

    // выходные данные
    cout<<"Налог на имущество за земельный участок составит - "<< taxe <<" тыс. рублей."<<endl;
    
    return 0;
}