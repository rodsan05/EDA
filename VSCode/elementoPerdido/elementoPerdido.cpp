// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// el coste es log(n), siendo n la longitud de v1. Esto es asi ya que se produce una llamada recursiva de n/2 y el coste de juntar es constante.
int resolver(vector<int>& v1, vector<int>& v2, int ini, int fin) {
    
    int medio = (ini+fin)/2;
    int n = fin - ini;

    if (n == 0) return v1[ini];
    if (n == 1) {

        if(v1[ini] == v2[ini]) return v1[fin]; 
        else return v1[ini];
    }
    if (v1[medio] < v2[medio]) {

        return resolver(v1, v2, ini, medio);
    }
    else return resolver(v1, v2, medio, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long long int numElementos;
    cin >> numElementos;
    vector<int> v1(numElementos);
    vector<int> v2(numElementos - 1);
    for (int& e : v1) cin >> e;
    for (int& e : v2) cin >> e;
    int sol = resolver(v1, v2, 0, v1.size()-1);
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