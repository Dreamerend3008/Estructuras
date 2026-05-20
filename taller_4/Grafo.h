#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
#include "nodo.h"
class Grafo{
    private:
        int n;
        std::vector<int> nodos;
        std::vector<std::vector<Nodo>> adj;
        std::vector<bool> visitados;
    public:
        Grafo(int n, std::vector<std::pair<int, Nodo>> aristas);        
        std::vector<int> ordenar_nodos(int inicial);
        void dfs(std::queue<int> &orden, int u);
};

#endif