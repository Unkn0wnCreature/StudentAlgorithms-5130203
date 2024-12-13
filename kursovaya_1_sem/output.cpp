#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

#include "client.h"

void write_file(char file_name[30], struct Client c)
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "a");

    if (file)
    {   
        fprintf(file, "%d %s %2d %.2f\n", c.code, c.name, c.age, c.salary);
    }
    else {cout<< "Error to open file\n" << endl;}

    fclose(file);
};

void clean_file(char file_name[30])
{
    FILE *file;
    char file_path[100];

    strcpy(file_path, "data/");
    strcat(file_path, file_name);

    file = fopen(file_path, "w");
    fclose(file);
};