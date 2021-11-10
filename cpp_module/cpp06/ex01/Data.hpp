#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <exception>

struct Data
{
    char name[32];
    unsigned short age;
    unsigned short height;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
