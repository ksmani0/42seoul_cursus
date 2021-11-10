#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* arr, size_t len, void (*func)(T&))
{
    for (int i = 0; i < len; ++i)
    {
        func(*arr);
        ++arr;
    }
}

template <typename T>
void PrintArr(T& arr)
{
    std::cout << arr << "\n";
}

template <class T>
void AddFiveNPrint(T& arr)
{
    arr += 5;
    std::cout << arr << "\n";
}

#endif