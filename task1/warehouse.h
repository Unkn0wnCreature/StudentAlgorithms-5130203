#pragma once
#include "product.h"

class Warehouse
{
    public:
        char code[4];
        enum CATEGORY{CENTER, WEST, EAST};
        double logitude, lattitude;
        int capacity, amount, size;
        Product* list;

    public:
        Warehouse(char* code, CATEGORY category, double longitude = 0, double lattitude = 0, int capacity = 0, int amount = 0);
        Warehouse(const Warehouse &w);
        ~Warehouse();
        void set_size(int n);
        int get_size();
        Product get_product(int pos);
        void menu(int &opt);
        void insert_product();
        void print_list();
        void search_product();
        void delete_product();
};