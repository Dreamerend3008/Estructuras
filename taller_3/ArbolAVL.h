#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.H"
#include <vector>


struct ArbolAVL {
private:
public:
    NodoAVL* raiz;

    // Utilidades internas
    int altura(NodoAVL* n);
    int factorBalance(NodoAVL* n);
    void actualizarAltura(NodoAVL* n);
   

    // Rotaciones
    NodoAVL* rotarDerecha(NodoAVL* y);
    NodoAVL* rotarIzquierda(NodoAVL* a);
    NodoAVL* rebalancear(NodoAVL* n);

    // Operaciones recursivas
    NodoAVL* insertar(NodoAVL* n, int dato);
    NodoAVL* eliminar(NodoAVL* n, int dato);
    NodoAVL* findMin(NodoAVL* n);

    // Recorrido inorden para mediana
    void inorden(NodoAVL* n, std::vector<int> &arreglo, int& indice);
    int contarNodos(NodoAVL* n);
    void destruir(NodoAVL* n);
    ArbolAVL();
    void insertar(int dato);
    void eliminar(int dato);

    // Retorna la mediana como double 
    double calcularMediana();
};

#endif