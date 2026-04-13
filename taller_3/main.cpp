#include <iostream>
#include <fstream>
#include <ctime>
#include "ArbolRN.h"
#include "ArbolAVL.h"
#include <vector>

int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cout << "Uso: " << argv[0] << " <nombre_archivo>" << std::endl;
        return 1;
    }
    
    std::ifstream archivo(argv[1]);
    if(!archivo.is_open()){
        std::cerr << "No se pudo abrir el archivo: " << argv[1] << std::endl;
        return 1;
    }
    std::string linea;
    std::vector<std::pair<char, int>> operaciones;
    while(std::getline(archivo, linea)){
        char operacion = linea[0];
        int valor = std::stoi(linea.substr(2)); 
        operaciones.push_back(std::make_pair(operacion, valor));
    }  
    archivo.close();
    
    // Arbol RN 
    ArbolRN arbol;
    std::clock_t start = std::clock();

    for(std::pair<char,int> p: operaciones){
        char op = p.first;
        int valor = p.second;
        if(op == 'A')arbol.insertar(valor);
        else if(op == 'E')arbol.eliminar(valor);
    }
    
    double mediana = arbol.mediana();
    
    std::clock_t end = std::clock();
    double tiempo = double(end - start) / CLOCKS_PER_SEC; 
    
    std::cout<<"Arbol RN:"<<std::endl;
    std::cout<<"La mediana del arbol es: ";
    if(mediana == -1)std::cout<<"No hay mediana"<<std::endl;
    else std::cout<<mediana<<std::endl;
    std::cout << "Tiempo de ejecución: " << tiempo << " segundos" << std::endl;

    // arbol avl
    ArbolAVL arbol_avl;
    start = std::clock();
    
    for(std::pair<char,int> p: operaciones){
        if(p.first == 'A')arbol_avl.insertar(p.second);
        else arbol_avl.eliminar(p.second);
    }
   
    mediana = arbol_avl.calcularMediana();

    end = std::clock();
    tiempo = double(end - start) / CLOCKS_PER_SEC; 

    std::cout<<"Arbol AVL:"<<std::endl;
    std::cout<<"La mediana del arbol es: ";
    if(mediana == -1)std::cout<<"No hay mediana"<<std::endl;
    else std::cout<<mediana<<std::endl;
    std::cout << "Tiempo de ejecución: " << tiempo << " segundos" << std::endl;

    arbol_avl.destruir(arbol_avl.raiz);
}