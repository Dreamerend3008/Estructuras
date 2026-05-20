#include "Grafo.h"
#include "nodo.h"
#include <vector>
#include <queue>
#include <algorithm>
Grafo::Grafo(int n, std::vector<std::pair<int, Nodo>> aristas){
    this->n = n;
    adj.resize(n);
    visitados.resize(n, false);
    for(const std::pair<int,Nodo> p : aristas){ // truco de competitiva para recorrer un vector de pairs
       adj[p.first].push_back(p.second); 
    }
}

void Grafo::dfs(std::queue<int> &orden, int u){
    if(visitados[u])return;
    visitados[u] = true;
    orden.push(u);
    double mn = __DBL_MAX__;
    int v = -1;
    for(Nodo no: adj[u]){
        if(mn > no.w && visitados[no.u] == false){
            mn = no.w;
            v = no.u;
        }
    }
    if(v == -1)return;
    dfs(orden, v);
}

std::vector<int> Grafo::ordenar_nodos(int inicial){
    // entregar desde el input el nodo 0 va a ser el mas cercano a (0,0)
    std::queue<int> q;
    dfs(q, inicial);
    std::vector<int> orden;
    while(!q.empty()){
        orden.push_back(q.front());
        q.pop();
    }
    return orden;
}
