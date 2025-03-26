#include <iostream>
#include "product.cpp"

int main()
{
    Product p;
    p = Product("Milk", 50, 4, 70, 50);
    p.print();

    return 0;
}