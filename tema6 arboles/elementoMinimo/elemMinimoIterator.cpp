// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>

using namespace std;
#include "bintree_eda.h"

template <class T>
// función que resuelve el problema
T resolver(bintree<T> datos) {
    T min;

    bintree<T>::const_iterator it=datos.begin();

    while (it != datos.end()){

        if (it->elem < min) min = it->elem;
        it++;
    }
    return min;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char t;
    cin >> t;
    if (! std::cin)
        return false;
    
    if (t == 'N') {
        bintree<int> tree = leerArbol(-1);
        int sol = resolver(tree);
        cout << sol << endl;
    }
    else if (t == 'P') {
        string s = "#";
        bintree<string> tree = leerArbol(s);
        string sol = resolver(tree);
        cout << sol << endl;
    }
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}