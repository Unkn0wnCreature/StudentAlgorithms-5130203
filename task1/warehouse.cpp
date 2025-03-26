#include "warehouse.h"
#include <iostream>
#include <cstring>

using namespace std;

void input_max_products(int &n)
{
    do {cout<< "Max products: "; cin>>n;} 
    while (n <= 0);
}

Warehouse::Warehouse()
{
    this->index = 100;
    this->category = CENTER;
    this->logitude = 0.0;
    this->lattitude = 0.0;
    this->capacity = 0;
    this->amount = 0;
    this->size = 0;
    this->list = nullptr;
}

Warehouse::Warehouse(unsigned int index, CATEGORY category, double longitude, double lattitude, int capacity, int n)
{
    if (100 + index > 999) {cout<< "Unable to give such a code.";}
    else {this->index = 100 + index;}

    this->category = category;
    this->logitude = longitude;
    this->lattitude = lattitude;
    this->capacity = capacity;
    this->amount = 0;
    this->size = 0;
    this->list = new Product[n];
}

Warehouse::Warehouse(const Warehouse &w)
{
    this->index = w.index;
    this->category = w.category;
    this->logitude = w.logitude;
    this->lattitude = w.lattitude;
    this->capacity = w.capacity;
    this->amount = w.amount;
    this->size = w.size;
    this->list = new Product[w.size];

    for (int i = 0; i < w.size; i++) {this->list[i] = w.list[i];}
}

Warehouse::~Warehouse()
{
    delete[] this->list;
}

void Warehouse::menu(int &opt)
{
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF CLIENTS"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by description"<<endl;
    cout<<"[4]. Delete product"<<endl;
    cout<<"[5]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opt;  
}

void Warehouse::set_size(int n){
    this->size = n;
}

int Warehouse::get_size(){
    return this->size;
}

void Warehouse::insert_product(){
    cout<< "Insert new product" <<endl;
    this->list[this->size].code = (1 + rand() % 2) * 1000000000 + (1 + rand() % 999999);

    cout<< "Description: "; cin>> this->list[this->size].description;

    
}