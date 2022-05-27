
#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

bool esHoja(bintree<char> const& tree){

    return tree.left().empty() && tree.right().empty();
}

//el coste es n, siendo n el numero de elementos del arbol
bool esZurdo(bintree<char> const& tree, int& descend){

    if (tree.empty()) {
        descend = 0;
        return true;
    }
    if (esHoja(tree)) { 
        descend = 1;
        return true;
    }
    int descenIzq, descenDer;
    bool izqZurdo = esZurdo(tree.left(), descenIzq);
    bool derZurdo = esZurdo(tree.right(), descenDer);

    descend = descenIzq + descenDer + 1;

    bool masEnIzq = descenIzq > descenDer;
    
    return izqZurdo && derZurdo && masEnIzq;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> tree;
    tree = leerArbol('.');
    
    int descend = 0;
    if (esZurdo(tree, descend)) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
