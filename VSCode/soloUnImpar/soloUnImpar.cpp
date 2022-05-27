// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// la complejidad es log(n), siendo n el tamaño del vector
int resolver(vector<int>& datos, int ini, int fin) {

    int mitad = (ini+fin)/2;
    //Num de elementos hasta el final desde el central
    int dif = fin - mitad;

    //Casos base
    if (ini == fin-1 || ini == fin)
    {
        if(datos[ini]%2 != 0) return datos[ini];
        else return datos[fin];
    }

    //Comprueba si el final es igual al central + 2 * num de elementos hasta el final
    if(datos[fin] == datos[mitad] + (2 * dif)){

        return resolver(datos, ini, mitad);
    }
    else return resolver(datos, mitad, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
    
    vector<int> v(n);
    for (int& e : v) cin >> e; 

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
