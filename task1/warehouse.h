#pragma once
#include "product.h"

enum CATEGORY{CENTER, WEST, EAST};

class Warehouse
{
    public:
        char code_letter = 'W';
        unsigned int index;
        CATEGORY category;
        double logitude, lattitude;
        int capacity, amount, size;
        Product* list;

    public:
        Warehouse();
        Warehouse(unsigned int index, CATEGORY category, double longitude, double lattitude, int capacity, int n);
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

void input_max_products(int &n);