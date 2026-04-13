#include "ArbolRN.h"

void ArbolRN::insertar(int valor) {
    arbol.insert(valor);
}

void ArbolRN::eliminar(int valor) {
    arbol.erase(valor);
}

bool ArbolRN::buscar(int valor) {
    return arbol.find(valor) != arbol.end();
}

double ArbolRN::mediana() {
    if(arbol.size() == 0)return -1;
    int n = arbol.size();
    double r = -1;
    std::set<int>::iterator it = arbol.begin();
    if(n%2 == 0){
        // el set no maneja iteradores comunes, generalmente es mejor practica usar advance
        std::advance(it, (n/2)-1);
        r = *it;
        std::advance(it, 1);
        r+= *it;
        r/=2;
    }else{
        std::advance(it, (n/2));
        r = *it;
    }
    return r;
}