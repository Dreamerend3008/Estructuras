#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>

struct NodoAVL {
    int dato;
    int altura;
    NodoAVL* izquierda;
    NodoAVL* derecha;

    NodoAVL(int valor){
        dato = valor;
        altura = 1; // Altura inicial del nodo
        izquierda = nullptr;
        derecha = nullptr;
    }
};
#endif
