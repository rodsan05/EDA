#include <iostream>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

bool esHoja(bintree<int> const& tree){

    return tree.left().empty() && tree.right().empty();
}

//coste n, siendo n el número de elementos del árbol
int caudalesNav(bintree<int> const& tree, int& nCaudales){

    if(tree.empty()) return 0;
    if(esHoja(tree)) return 1; //si es hoja significa que es un manantial

    int valorCaudal = caudalesNav(tree.left(), nCaudales) + caudalesNav(tree.right(), nCaudales) - tree.root();
    if(valorCaudal >= 3) nCaudales++;

    if(valorCaudal < 0) valorCaudal = 0;
    return valorCaudal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(){
	bintree<int> arb;
	arb = leerArbol(-1); // -1 es la repr. de arbol vacio
	
    int sol = 0;
    int temp = caudalesNav(arb, sol);

    //al final cabe la posibilidad de que se haya sumado el caudal de la raíz, que no existe, asi que se descuenta si ha pasado
    if(temp >= 3 && sol > 0) sol--;
 
    cout << sol << endl;
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

