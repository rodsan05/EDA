// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// coste log(n), siendo n la longitud del vector
int resolver(vector<int>& v, int ini, int fin) {
    
    int medio = (ini+fin)/2;
    int n = fin - ini;

    int dif = fin - medio;

    if(n == 0) return ini;

    if(v[medio] == v[medio + 1]){

        if((dif)%2 == 0) return resolver(v, medio, fin);
        else return resolver(v, ini, medio - 1);
    }

    else if(v[medio] == v[medio - 1]){

        if((dif)%2 == 0) return resolver(v, ini, medio);
        else return resolver(v, medio + 1, fin);
    }

    else return medio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> v(n);
    for(int& e : v) cin >> e;

    int sol = resolver(v, 0, n-1);
    // escribir sol
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
     system("PAUSE");
     #endif
    
    return 0;
}