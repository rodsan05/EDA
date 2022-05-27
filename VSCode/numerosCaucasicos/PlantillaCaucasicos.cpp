
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

bool esPar(int n){

    return (n % 2) == 0;
}

//2 llamadas recursivas de la mitad de elementos
//coste log(n), siendo n el numero de elementos del vector
bool caucasico(vector<int>& v, int ini, int fin, int& pares){

    int n = fin - ini;
    int medio = (ini + fin)/2;

    if (n == 0) {

        if (esPar(v[ini])) pares++;
        return true;
    }

    int paresIzq = 0, paresDer = 0;
    bool soluc = caucasico(v, ini, medio, paresIzq) && caucasico(v, medio + 1, fin, paresDer);

    pares = paresIzq + paresDer;

    if (soluc && abs(paresIzq - paresDer) <= 2) return true;
    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0) return false;
    vector<int> sec(n);
    for (int& e : sec) cin >> e;
    int pares = 0;
    cout << (caucasico(sec, 0, n - 1, pares)? "SI" : "NO") << endl;
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