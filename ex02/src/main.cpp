#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "=== Teste 1: Construtor Padrão ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Tamanho do array vazio: " << emptyArray.size() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Teste 2: Construtor Parametrizado ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Tamanho: " << intArray.size() << std::endl;
    std::cout << "Valores inicializados por padrão:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Teste 3: Modificando Elementos ===" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }
    std::cout << "Após modificação:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Teste 4: Construtor de Cópia ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Array copiado, tamanho: " << copyArray.size() << std::endl;
    std::cout << "Modificando o array original..." << std::endl;
    intArray[0] = 999;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;
    std::cout << "copyArray[0] = " << copyArray[0] << " (não deve ter mudado!)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Teste 5: Operador de Atribuição ===" << std::endl;
    Array<int> assignArray;
    assignArray = copyArray;
    std::cout << "Array atribuído, tamanho: " << assignArray.size() << std::endl;
    copyArray[1] = 777;
    std::cout << "copyArray[1] = " << copyArray[1] << std::endl;
    std::cout << "assignArray[1] = " << assignArray[1] << " (não deve ter mudado!)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Teste 6 Acesso Fora dos Limites ===" << std::endl;
    try {
        std::cout << "Tentando acessar index 10 em array de tamanho 5..." << std::endl;
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Teste 7: Array Vazio - Acesso Inválido ===" << std::endl;
    try {
        std::cout << "Tentando acessar index 0 em array vazio..." << std::endl;
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exceção capturada: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Teste 8: Array de Floats ===" << std::endl;
    Array<float> floatArray(4);
    for (unsigned int i = 0; i < floatArray.size(); i++) {
        floatArray[i] = i * 3.14f;
        std::cout << "floatArray[" << i << "] = " << floatArray[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Todos os testes concluídos! ===" << std::endl;
    return 0;
}