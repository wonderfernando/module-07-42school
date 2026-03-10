#pragma once
#include <iostream>
#include <exception>
template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

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
Array<T>::Array() : _array(NULL), _size(0) {
    std::cout << "Array default constructor called" << std::endl;
}

// Parametrized constructor
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
    std::cout << "Array parametrized constructor called with size " << n << std::endl;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(other._size) {
    std::cout << "Array copy constructor called" << std::endl;
    if (other._size > 0) {
        _array = new T[other._size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
}

// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &other) {
        if (_array != NULL) {
            delete[] _array;
        }
        _size = other._size;
        if (other._size > 0) {
            _array = new T[other._size];
            for (unsigned int i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
        } else {
            _array = NULL;
        }
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called" << std::endl;
    if (_array != NULL) {
        delete[] _array;
    }
}

// Size function
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

// Subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::exception();
    }
    return _array[index];
}

// Const subscript operator
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::exception();
    }
    return _array[index];
}