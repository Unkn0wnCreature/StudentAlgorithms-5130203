#include <iostream>
#include "product.h"
#include <cstring>

using namespace std;

Product::Product(char code[13], char description[50], double cost, int amount, double longitude, double lattitude)
{
    this->code = code;
    strcpy(this->description, description);
    this->cost = cost;
    this->amount = amount;
    this->longitude = validate_component(longitude, 19, 169);
    this->lattitude = validate_component(lattitude, 41, 82);
}

Product::Product(const Product &p)
{
    this->code = p.code;
    strcpy(this->description, p.description);
    this->cost = p.cost;
    this->amount = p.amount;
    this->longitude = p.longitude;
    this->lattitude = p.lattitude;
}

Product::~Product(){}

void Product::set(char description[50], double cost, int amount, double longitude, double lattitude)
{
    strcpy(this->description, description);
    this->cost = cost;
    this->amount = amount;
    this->longitude = validate_component(longitude, 19, 169);
    this->lattitude = validate_component(lattitude, 41, 82);
}

void Product::get(char* &code, char* &description, double &cost, int &amount, double &longitude, double &lattitude)
{
    code = this->code;
    strcpy(description, this->description);
    cost = this->cost;
    amount = this->amount;
    longitude = this->longitude;
    lattitude = this->lattitude;
}

void Product::print()
{
    cout<< "Code: " << code << "\n"
    << "Description: " << description << "\n"
    << "Cost: " << cost << "\n"
    << "Amount: " << amount << "\n"
    << "Longitude: " << longitude << "\n"
    << "Lattitude: " << lattitude <<endl;
}

double Product::validate_component(double comp, double min, double max)
{
    if (comp <= min) {return min;}
    else if (comp >= max) {return max;}
    else {return comp;}
}