#include "ArbolAVL.h"
#include <algorithm> 
#include <vector>

int ArbolAVL::altura(NodoAVL* n) {
    if (n==nullptr) return 0;
    return n->altura;
}

int ArbolAVL::factorBalance(NodoAVL* n) {
    if (n==nullptr) return 0;
    return altura(n->izquierda) - altura(n->derecha);
}

void ArbolAVL::actualizarAltura(NodoAVL* n) {
    if (n==nullptr) {
       return;
    }
    int alturaIzquierda = altura(n->izquierda); 
    int alturaDerecha = altura(n->derecha);
    n->altura = 1 + std::max(alturaIzquierda, alturaDerecha);
}

NodoAVL* ArbolAVL::rotarIzquierda(NodoAVL* a){
    NodoAVL* b = a->derecha;
    NodoAVL* d = b->izquierda;
    b->izquierda = a;
    a->derecha = d;
    actualizarAltura(a);
    actualizarAltura(b);
    return b;
}

NodoAVL* ArbolAVL::rotarDerecha(NodoAVL* a){
    NodoAVL* b = a->izquierda;
    NodoAVL* d = b->derecha;
    b->derecha = a;
    a->izquierda = d;
    actualizarAltura(a);
    actualizarAltura(b);

    return b;

}

NodoAVL* ArbolAVL::rebalancear(NodoAVL* n) {
    if (n == nullptr) return n;
    actualizarAltura(n);
    int fb = factorBalance(n);

    if (fb > 1) { 
        if (factorBalance(n->izquierda) >= 0) {
            return rotarDerecha(n);
        } else {
            n->izquierda = rotarIzquierda(n->izquierda);
            return rotarDerecha(n);
        }
    } else if (fb < -1) {
        if (factorBalance(n->derecha) <= 0) {
            return rotarIzquierda(n);
        } else {
            n->derecha = rotarDerecha(n->derecha);
            return rotarIzquierda(n);
        }
    }
    return n;
}

NodoAVL* ArbolAVL::insertar(NodoAVL* n, int valor){
    if(n == nullptr){ 
        return new NodoAVL(valor);
    }
    if(n->dato < valor){ 
        n->derecha = insertar(n->derecha, valor);
    } else if (n->dato > valor){
        n->izquierda = insertar(n->izquierda, valor);
    } else {
        return n;
    }
    return rebalancear(n);
}

NodoAVL* ArbolAVL::eliminar(NodoAVL* n, int valor) {
    if (n == nullptr) return n;
    if (valor < n->dato) {
        n->izquierda = eliminar(n->izquierda, valor);
    } else if (valor > n->dato) {
        n->derecha = eliminar(n->derecha, valor);
    } else {
        if (n->izquierda == nullptr) {
            return n->derecha;
        } else if (n->derecha == nullptr){
            return n->izquierda;
        }  else {
            NodoAVL* temp = findMin(n->derecha);
            n->dato = temp->dato;
            n->derecha = eliminar(n->derecha, temp->dato);
        }
    }
    return rebalancear(n);
}

NodoAVL* ArbolAVL::findMin(NodoAVL* n) {
    NodoAVL* actual = n;
    while (actual->izquierda != nullptr) {
        actual = actual->izquierda;
    }
    return actual;
}

void ArbolAVL::inorden(NodoAVL* n, std::vector<int> &arreglo, int& indice){
    if (n == nullptr) return;
    inorden(n->izquierda, arreglo, indice);
    arreglo.push_back(n->dato);
    inorden(n->derecha, arreglo, indice);
}

int ArbolAVL::contarNodos(NodoAVL* n) {
    if (n == nullptr) return 0;
    return 1 + contarNodos(n->izquierda) + contarNodos(n->derecha);
}

void ArbolAVL::destruir(NodoAVL* n) {
    if (n == nullptr) return;
    destruir(n->izquierda);
    destruir(n->derecha);
    delete n;
}
 void ArbolAVL::insertar(int dato){
    raiz = insertar(raiz, dato);
 }
void ArbolAVL::eliminar(int dato){
    raiz = eliminar(raiz, dato);
}
ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}

double ArbolAVL::calcularMediana() {
        int totalNodos = contarNodos(raiz);
    if (totalNodos == 0) {
        return -1;
    }
    std::vector<int> arreglo;
    int indice = 0;
    inorden(raiz, arreglo, indice);

    double mediana;
    if (totalNodos % 2 == 1) {
        mediana = arreglo[totalNodos / 2];
    } else {
        mediana = (arreglo[totalNodos / 2 - 1] + arreglo[totalNodos / 2]) / 2.0;
    }
    return mediana;
}
