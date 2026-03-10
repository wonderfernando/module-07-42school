#pragma once
#include <iostream>
#include <exception>
template <typename T>
class Array {
private:
    T* arrays;
    unsigned int length;

public:
    // Default constructor
    Array();
    
    // Parametrized constructor
    Array(unsigned int n);
    
    // Copy constructor (Orthodox Canonical Form)
    Array(const Array& other);
    
    // Copy assignment operator (Orthodox Canonical Form)
    Array& operator=(const Array& other);
    
    // Destructor (Orthodox Canonical Form)
    ~Array();
    
    // Member functions
    unsigned int size() const;
    
    // Subscript operators
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
};

// Default constructor
template <typename T>
Array<T>::Array() : arrays(NULL), length(0) {
    std::cout << "Array default constructor called" << std::endl;
}

// Parametrized constructor
template <typename T>
Array<T>::Array(unsigned int n) : arrays(new T[n]()), length(n) {
    std::cout << "Array parametrized constructor called with length " << n << std::endl;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : arrays(NULL), length(other.length) {
    std::cout << "Array copy constructor called" << std::endl;
    if (other.length > 0) {
        arrays = new T[other.length];
        for (unsigned int i = 0; i < length; i++) {
            arrays[i] = other.arrays[i];
        }
    }
}

// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &other) {
        if (arrays != NULL) {
            delete[] arrays;
        }
        length = other.length;
        if (other.length > 0) {
            arrays = new T[other.length];
            for (unsigned int i = 0; i < length; i++) {
                arrays[i] = other.arrays[i];
            }
        } else {
            arrays = NULL;
        }
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    if (arrays != NULL) {
        delete[] arrays;
    }
}

// length function
template <typename T>
unsigned int Array<T>::size() const {
    return length;
}

// Subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= length) {
        throw std::exception();
    }
    return arrays[index];
}

// Const subscript operator
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= length) {
        throw std::exception();
    }
    return arrays[index];
}