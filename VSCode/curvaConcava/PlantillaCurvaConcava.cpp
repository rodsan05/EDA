#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// tiene coste log(n), siendo n la longitud del vector
int minimo(const vector<int>& v, int ini, int fin) {
    
    int medio = (ini+fin)/2;
    int n = fin - ini;

    if (n == 1 || n == 0) {

        if(v[ini] < v[fin]) return v[ini];
        else return v[fin];
    }

    if (v[medio] > v [medio+1]) return minimo(v, medio, fin);
    else if (v[medio] > v [medio-1]) return minimo(v, ini, medio);
    else return v[medio];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    cout << minimo(sec, 0, n-1) << endl;
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
    //system("PAUSE");
#endif

    return 0;
}