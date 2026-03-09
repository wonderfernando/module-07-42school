#pragma once
#include <iostream>

template <typename T, typename F>
void iter(T *array,const size_t size,F func){
    for (size_t i = 0; i < size; i++)
        func(array[i]);
}

template <typename T>
void print(const T& x) {
    std::cout << x << std::endl;
}


template <typename A>
void printA(const A& x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T& x) {
    x++;
}
