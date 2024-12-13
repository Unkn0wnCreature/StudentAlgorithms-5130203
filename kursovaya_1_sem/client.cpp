#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include "client.h"
#include "output.h"
using namespace std;

static int num_clients = 0;
static int index = 0;

void menu_clients(int *opt, struct Client *list_clients)
{
   int pos;
   struct Client c;
   
   do
   {
        cout<<left;
        cout<< setw(20) << "\n--- MANAGMENT OF CLIENTS ---" <<endl;
        cout<< "[1]. Insert client" <<endl;
        cout<< "[2]. Read list of clients" <<endl;
        cout<< "[3]. Update client" <<endl;
        cout<< "[4]. Delete client" <<endl;
        cout<< "[5]. Exit" <<endl;
        cout<< "----------------------------------------------" <<endl;
        cout<< "Enter option: ";
        cin>>*opt;

        switch (*opt)
        {
            case 1: //insert
                insert_client(&list_clients[get_num_clients()]);
                print_clients_file(list_clients);
                break;
            case 2: //read
                //code
                break;
            case 3:
                //code
                break;
            case 4:
                //code
                break;
            case 5:
                cout<< "Exiting to main menu..." <<endl;
                break;
            default:
                cout<< "\nInvalid option" <<endl;
                break;
        }

    } while (*opt != 5);
}

void insert_client(struct Client *c)
{
    cout<< "\n*** INSERT CLIENT ***" << endl;
    index++;

    c -> code = index;

    cout<< "Name: ";
    cin>>c -> name;

    do
    {
        cout<< "Age: ";
        cin>>c -> age;
    } while (c -> age <= 0);
    
    do
    {
        cout<< "Salary: ";
        cin>>c -> salary;
    } while (c -> salary < 20000 || c -> salary > 500000);

    num_clients++;
};

int get_num_clients()
{
    return num_clients;
};

void print_clients_file(struct Client *list_clients)
{
    clean_file("client.txt");
    //print_head_client("client.txt");
    
    for (int i = 0; i < get_num_clients(); i++)
    {
        print_file_client("client.txt", list_clients[i]);
    };
};