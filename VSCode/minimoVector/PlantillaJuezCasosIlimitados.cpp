// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// coste log(n), siendo n la longitud del vector
int resolver(vector<int>& v, int ini, int fin) {
    
    int medio = (ini+fin)/2;
    int n = fin - ini;

    if(n == 0 || n == 1){

        if(v[ini] < v[fin]) return v[ini];
        else return v[fin];
    }

    if(v[medio] > v[ini]) return resolver(v, ini, medio);
    else return resolver(v, medio, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (! std::cin)
        return false;
    
    vector<int> v(n);
    for(int& e : v) cin >> e;

    int sol = resolver(v, 0, n-1);
    
    // escribir sol
    cout << sol << endl;
    
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