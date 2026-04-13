#ifndef ARBOLRN_H
#define ARBOLRN_H

#include <set>
class ArbolRN{
    private:
        std::set<int> arbol;
    public:
        void insertar(int valor);
        void eliminar(int valor);
        bool buscar(int valor);
        double mediana();
};

#endif