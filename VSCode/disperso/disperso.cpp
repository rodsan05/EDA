// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>   
using namespace std;


// función que resuelve el problema
bool resolver(vector<long>& datos, long ini, long fin, long k) {
    
    if(ini == fin-1) return true;
    else if(abs(datos[ini] - datos[fin - 1]) >= k)
    {
        return resolver(datos, ini, (ini+fin)/2, k) && resolver(datos, (ini+fin)/2, fin, k);
    }

    else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long n;
    cin >> n;
    vector<long> v(n);
    
    long k;
    cin >> k;

    for (long i = 0; i < n; i++) cin >> v[i];
    if (! std::cin)
        return false;
    
    bool sol = resolver(v, 0, n, k);
    
    // escribir sol
    if(sol) cout << "SI" << endl;
    else cout << "NO" << endl;
    
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