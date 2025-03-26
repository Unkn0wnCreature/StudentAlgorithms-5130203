#include "warehouse.h"
#include <iostream>
#include <iomanip>
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
    this->amount = capacity;
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


void Warehouse::set_size(int n){
    this->size = n;
}

int Warehouse::get_size(){
    return this->size;
}


void Warehouse::insert_product(char description[50], double cost, int amount, double longitude, double lattitude){
    this->list[this->size].code = (1 + rand() % 2) * 1000000000 + (1 + rand() % 999999);

    this->list[this->size].description = description;

    this->list[this->size].cost = cost;

    this->list[this->size].amount = amount;

    if (this->list[this->size].amount > this->amount){
        this->list[this->size].amount = this->amount;
        this->amount = 0;
    } else {this->amount = this->capacity - this->list[this->size].amount;}

    this->list[this->size].longitude = longitude;
    
    this->list[this->size].lattitude = lattitude;
    
    this->size++;
    this->set_size(this->size);
}


Product Warehouse::get_product(int pos){
    return this->list[pos];
}

void Warehouse::print_list(){
    cout<< setw(15) << "Code" <<
    setw(10) << "Description" <<
    setw(10) << "Cost" <<
    setw(10) << "Amount" <<
    setw(10) << "Longitude" <<
    setw(10) << "Lattitude" <<endl;

    for (int i = 0; i < this->size; i++){
        this->list[i].print();
    }
}

int Warehouse::search_product(char search_criteria[50]){
    for (int i = 0; i < this->get_size(); i++){
        if (strcmp(this->list[i].description, search_criteria) == 0) {return i;}
        else {return -1;}
    }
}

void Warehouse::delete_product(char search_criteria[50]){
    int pos = this->search_product(search_criteria);

    if (pos != -1){
        for (int i = 0; i < this->get_size(); i++){
            this->list[i] = this->list[i+1];
            this->size--;
            this->set_size(this->size);
            cout<< "Product deleted" <<endl;
        }
    } else {cout<< "Product not found!" <<endl;}
}
