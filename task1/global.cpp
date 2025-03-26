#include <iostream>
#include "product.h"
#include "product.cpp"
#include "warehouse.h"
#include "warehouse.cpp"
#include <cmath>

using namespace std;

double calculate_dist(Warehouse w, double longitude, double lattitude){
    return abs(w.logitude - longitude) + abs(w.lattitude - lattitude);
}

void insert_new_product(Warehouse list[3]){
    char description[50];
    int amount;
    double cost, longitude, lattitude;
    cout<< "Insert new product" <<endl;

    cout<< "Description: "; cin>> description;

    do{
        cout<< "Cost: "; cin>> cost;
    } while (cost < 0);

    do{
        cout<< "Amount: "; cin>> amount;
    } while (amount <= 0);

    do{
        cout<< "Longitude: "; cin>> longitude;
    } while (longitude < 19 || longitude > 169);

    do{
        cout<< "Lattitude: "; cin>> lattitude;
    } while (lattitude < 41 || lattitude > 82);

    if (calculate_dist(list[0], longitude, lattitude) < calculate_dist(list[1], longitude, lattitude) 
    && calculate_dist(list[0], longitude, lattitude) < calculate_dist(list[2], longitude, lattitude)){
        list[0].insert_product(description, cost, amount, longitude, lattitude);
    }

    if (calculate_dist(list[1], longitude, lattitude) < calculate_dist(list[0], longitude, lattitude) 
    && calculate_dist(list[1], longitude, lattitude) < calculate_dist(list[2], longitude, lattitude)){
        list[1].insert_product(description, cost, amount, longitude, lattitude);
    }

    if (calculate_dist(list[2], longitude, lattitude) < calculate_dist(list[0], longitude, lattitude) 
    && calculate_dist(list[2], longitude, lattitude) < calculate_dist(list[1], longitude, lattitude)){
        list[2].insert_product(description, cost, amount, longitude, lattitude);
    }
}

void search_product(Warehouse list[3]){
    char search_criteria[50];
    cout<< "Search criteria: "; cin>> search_criteria;

    for (int i = 0; i < 3; i++){
        if (list[i].search_product(search_criteria) != -1){
            cout<< "---------------" << list[i].code_letter << list[i].index << "---------------" <<endl;
            list[i].get_product(list[i].search_product(search_criteria)).print();
        }
    }
}

void delete_product(Warehouse list[3]){
    int opt;
    char search_criteria[50];
    do{
        cout << "Choose warehouse: "; cin>> opt;
    } while (opt < 1 && opt > 3);

    cout<< "Search criteria: "; cin>> search_criteria;

    switch (opt)
    {
    case 1:
        list[0].delete_product(search_criteria);
        break;
    case 2:
        list[1].delete_product(search_criteria);
        break;
    case 3:
        list[2].delete_product(search_criteria);
        break;
    }
}

void print_list(Warehouse list[3]){
    int opt;
    do{
        cout << "Choose warehouse: "; cin>> opt;
    } while (opt < 1 && opt > 3);

    switch (opt)
    {
    case 1:
        list[0].print_list();
        break;
    case 2:
        list[1].print_list();
        break;
    case 3:
        list[2].print_list();
        break;
    }  
}

void menu(int &opt)
{
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF WAREHOUSES"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by description"<<endl;
    cout<<"[4]. Delete product"<<endl;
    cout<<"[5]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opt;  
}