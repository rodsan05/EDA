// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// coste log(n), siendo n la longitud del vector
bool resolver(vector<int>& v, int ini, int fin) {
    
    int medio = (ini+fin)/2;
    int n = fin - ini;

    if(n == 1 || n == 0){
        return v[fin] == fin || v[ini] == ini;
    }

    if(v[medio] == medio) return true;
    else if(v[medio] < medio) return resolver(v, medio, fin);
    else return resolver(v, ini, medio);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long int n;
    cin >> n;
    bool sol = false;
    
    if(n != 0)
    {
    vector<int> v(n);
    for (int& e : v) cin >> e;
    
    sol = resolver(v, 0, n-1);
    }
    // escribir sol
    if(sol) cout << "SI" << endl;
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
     system("PAUSE");
     #endif
    
    return 0;
}