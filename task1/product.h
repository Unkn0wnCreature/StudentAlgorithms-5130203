#pragma once

class Product
{
    public:
        int code;
        char description[50];
        double cost;
        int amount;
        double longitude;
        double lattitude;
    
    public:
        Product();
        Product(int code, char description[50], double cost, int amount, double longitude, double lattitude);
        Product(const Product &p);
        ~Product();
        //void get(int &code, char &description, double &cost, int &amount, double &longitude, double &lattitude);
        void set(char description[50], double cost, int amount, double longitude, double lattitude);
        double validate_component(double comp, double min, double max);
        void print();
};