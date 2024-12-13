#include <iostream>
#include <cstring>
#include <iomanip>
#include "master.cpp"
using namespace std;

#define MAX_CLIENTS 100
#define MAX_PRODUCTS 100
#define MAX_ORDERS 100

void menu_master(int *opt);

int main()
{
    int opt;
    char cont;
    struct Client *list_clients;

    list_clients = new struct Client[MAX_CLIENTS];

    do
    {
        menu_master(&opt);

        switch (opt)
        {
            case 1:     // clients
                menu_clients(&opt, list_clients);
                break;
            case 2:     // products
                //code
                break;
            case 3:     // orders
                //code
                break;
            default:
                cout<<"\nInvalid option"<<endl;
                break;
        };

        // Request to user continue or not
        cout << "\nDo you want continue [Y|N]? "<< endl;
        cin>> cont;
    } while(cont == 'y' || cont == 'Y');

    cout << "The program is over!"<< endl;

    // cleaning of memory
    delete[] list_clients;

    return 0;
}

void menu_master(int *opt){
    cout << "-----------------------------------------------"<<endl;
    cout<<"*** SYSTEM OF PRODUCT SALES ***"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "\nSelect an option from [1-3] according to the menu:" << endl;
    cout << "[1]. Managment of Clients"<<endl;
    cout << "[2]. Managment of Products"<<endl;
    cout << "[3]. Managment of Orders"<<endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "Enter option: ";
    cin>> *opt;
    cout <<endl;
};