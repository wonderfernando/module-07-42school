#pragma once
#include <iostream>

template < typename T >
void swap(T& a, T& b){
    T aux;
    aux = a;
    a = b;
    b = aux;
}

template < typename U >
U min(U a, U b){
    return a < b ? a : b;
}

template < typename X >
X max(X a, X b){
    return a > b ? a : b;
}
