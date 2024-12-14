#pragma once

struct Client
{
    int code;
    char name[50];
    int age;
    double salary;
};

void menu_clients(int *opt, struct Client *list_clients);
void insert_client(struct Client *c);
int get_num_clients();