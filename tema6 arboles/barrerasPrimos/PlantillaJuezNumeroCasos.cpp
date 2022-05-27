// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "bintree_eda.h"

bool esPrimo(int n){

    if (n == 0 || n == 1) return false;

    for (int i = 2; i < n/2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// función que resuelve el problema
int resolver(bintree<int> const& datos, int prof, int& sol, int& profMin) {
    
    // if (datos.empty()) return prof;
    // if (datos.root() % 7 == 0){
    //     sol = datos.root();
    //     return prof;
    // }

    // int izq, der;
    // if (!datos.left().empty() && !esPrimo(datos.left().root())) izq = resolver(datos.left(), prof + 1, sol);
    // if (!datos.right().empty() && !esPrimo(datos.right().root())) der = resolver(datos.right(), prof + 1, sol); 

    if (datos.empty()) return 1;

    int izq = 1, der = 1;
    if (!datos.left().empty() && !esPrimo(datos.left().root())) izq = resolver(datos.left(), prof + 1, sol, profMin);
    if (!datos.right().empty() && !esPrimo(datos.right().root())) der = resolver(datos.right(), prof + 1, sol, profMin);
    
    if (izq % 7 == 0) {
        if (prof < profMin) {
            profMin = prof;
            return izq;
        }
    }
    if (der % 7 == 0) {
        if (prof < profMin) {
            profMin = prof;
            return der;
        }
    }
    else return 1; 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> tree = leerArbol(-1);
    cin;
    int prof = 1;
    int sol = 0;
    int profMin = INT_MAX;
    prof = resolver(tree, prof, sol, profMin);

    // escribir sol
    if (sol == 0) cout << "NO HAY" << endl;
    else cout << sol << " " << prof << endl;
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
     system("PAUSE");
     #endif
    
    return 0;
}