#include "iter.hpp"
#include <string>

 
int main(void)
{
    std::cout << "=== Test 1: Array não-const com função const ref (print) ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = 5;
    iter(intArray, intSize, print<int>);
    
    std::cout << "\n=== Test 2: Array não-const com função non-const ref (increment) ===" << std::endl;
    iter(intArray, intSize, increment<int>);
    std::cout << "Depois do increment:" << std::endl;
    iter(intArray, intSize, print<int>);
    
    std::cout << "\n=== Test 3: Array const com função const ref (print) ===" << std::endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    size_t constSize = 5;
    iter(constArray, constSize, print<int>);
    
    // Nota: iter(constArray, constSize, increment<int>); 
    // NÃO COMPILARIA porque increment recebe non-const ref
    
    std::cout << "\n=== Test 4: Array de doubles não-const ===" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleSize = 5;
    iter(doubleArray, doubleSize, printA<double>);
    std::cout << "Depois do increment:" << std::endl;
    iter(doubleArray, doubleSize, increment<double>);
    iter(doubleArray, doubleSize, printA<double>);
   
    return 0;
}