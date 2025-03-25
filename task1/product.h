#pragma once

class Product
{
    public:
        char code[13];
        char description[50];
        double cost;
        int amount;
        double longitude;
        double lattitude;
    
    public:
        Product(char code[13], char description[50], double cost = 0, int amount = 0, double longitude = 0, double lattitude = 0);
        Product(const Product &p);
        ~Product();
        void get(char* &code, char* &description, double &cost, int &amount, double &longitude, double &lattitude);
        void set(char description[50], double cost, int amount, double longitude, double lattitude);
        double validate_component(double comp, double min, double max);
        void print();
};