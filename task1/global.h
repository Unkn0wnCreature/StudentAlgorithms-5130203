#include <iostream>
#include "product.h"
#include "product.cpp"
#include "warehouse.h"
#include "warehouse.cpp"
#include <cmath>

double calculate_dist(Warehouse w, double longitude, double lattitude);
void insert_new_product(Warehouse list[3]);
void search_product(Warehouse list[3]);
void delete_product(Warehouse list[3]);
void print_list(Warehouse list[3]);
void menu(int &opt);