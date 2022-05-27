

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


struct Cancion{
    int duracion;
    int puntos;
};

void resolver(vector<int> &sol, const vector<Cancion> &canciones, const vector<int> &mayorValorDesde, int n, int duracion, int k, int durA, int durB, int valorAct, int &mejorValor) {

    //cogemos cancion en cara A
    sol[k] = 1;
    durA += canciones[k].duracion;
    valorAct += canciones[k].puntos;

    if (durA <= duracion) {

        if (k == n - 1) {

            if (valorAct > mejorValor) mejorValor = valorAct;
        }

        else if (valorAct + mayorValorDesde[k+1] > mejorValor) resolver(sol, canciones, mayorValorDesde, n, duracion, k + 1, durA, durB, valorAct, mejorValor);
    }
    durA -= canciones[k].duracion;
    valorAct -= canciones[k].puntos;

    //cogemos cancion en cara B
    sol[k] = 2;
    durB += canciones[k].duracion;
    valorAct += canciones[k].puntos;

    if (durB <= duracion) {

        if (k == n - 1) {

            if (valorAct > mejorValor) mejorValor = valorAct;
        }

        else if (valorAct + mayorValorDesde[k+1] > mejorValor) resolver(sol, canciones, mayorValorDesde, n, duracion, k + 1, durA, durB, valorAct, mejorValor);
    }
    durB -= canciones[k].duracion;
    valorAct -= canciones[k].puntos;

    //no cogemos la cancion
    sol[k] = 0;
    
    if (k == n - 1) {

        if (valorAct > mejorValor) mejorValor = valorAct;
    }

    else if (valorAct + mayorValorDesde[k+1] > mejorValor) resolver(sol, canciones, mayorValorDesde, n, duracion, k + 1, durA, durB, valorAct, mejorValor);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, duracion;
    cin >> n;
    if (n == 0) return false;
    cin >> duracion;
    vector<int> soluc(n);
    vector<Cancion> canciones(n);
    for (int i = 0; i < n; ++i)
        cin >> canciones[i].duracion >> canciones[i].puntos;

    int mejorValor = INT_MIN;

    vector<int> mayorValorDesde(n);

    mayorValorDesde[n-1] = canciones[n-1].puntos;
    for (int i = n-2; i > -1; i--) {

        mayorValorDesde[i] = canciones[i].puntos + mayorValorDesde[i+1];
    }

    resolver(soluc, canciones, mayorValorDesde, n, duracion, 0, 0, 0, 0, mejorValor);
    // Salida
    cout << mejorValor << endl;
    return true;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
