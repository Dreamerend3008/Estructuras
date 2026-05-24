#include "Grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <cmath>

int main(int argc, char* argv[]) {
    if(argc < 3){
        std::cout << "Uso: " << argv[0] << " <nombre_archivo> <nombre_archivo_salida>" << std::endl;
        return 1;
    }
    
    std::ifstream archivo(argv[1]);
    std::ofstream archivo_e(argv[2]);
    if(!archivo.is_open() || !archivo_e.is_open()){
        std::cerr << "No se pudo abrir uno o ambos archivos." << std::endl;
        return 1;
    }
    std::string linea;
    std::getline(archivo, linea);
    int n = std::stoi(linea);
    archivo_e << n << "\n";
    std::cout<<"Hay "<<n<<" circuitos \n";
    for(int i=0;i<n;i++){
        std::getline(archivo, linea);
        int m = std::stoi(linea);
        archivo_e << m << "\n";
        std::cout<<"El circuito "<<i+1<<" tiene "<<m<<" agujeros \n";
        std::vector<std::pair<double,double>> agujeros;
        for(int j=0;j<m;j++){
            std::getline(archivo, linea);
            double x, y;
            std::stringstream ss(linea);
            ss >> x >> y;
            agujeros.push_back({x, y});
        }
        if (m == 0) {
            std::cout << "Distancia total recorrida por el circuito " << i+1 << ": 0\n" << "\n";
            continue;
        }
        std::vector<std::pair<int, Nodo>> aristas;
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                double x1 = agujeros[j].first;
                double y1 = agujeros[j].second;
                double x2 = agujeros[k].first;
                double y2 = agujeros[k].second;
                double w = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
                aristas.push_back({j, {k, w}});
                aristas.push_back({k, {j, w}});
            }
        }
        int inicial = 0;
        double mn = __DBL_MAX__;
        for(int j=0;j<m;j++){
            double x = agujeros[j].first;
            double y = agujeros[j].second;
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            if(dist < mn){
                mn = dist;
                inicial = j;
            }
        }
        Grafo g(m, aristas);
        std::vector<int> orden = g.ordenar_nodos(inicial);
        
        double x1=0, y1=0;
        double distancia_total = 0.0;
        for(int nodo : orden){
            archivo_e << agujeros[nodo].first << " " << agujeros[nodo].second << "\n";
            
            double dist = sqrt(pow(agujeros[nodo].first - x1, 2) + pow(agujeros[nodo].second - y1, 2));
            distancia_total += dist;
            x1 = agujeros[nodo].first;
            y1 = agujeros[nodo].second;
        }
        std::cout << "Distancia total recorrida por el circuito " << i+1 << ": " << distancia_total << "\n" << "\n";
    }
    archivo.close();
    archivo_e.close();
}