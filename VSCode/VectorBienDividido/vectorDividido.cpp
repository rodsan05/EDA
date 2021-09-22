// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& datos, int p) {
    
    if(p == (int)datos.size() - 1) return true;
    
    //max de la primera mitad y min de la segunda mitad
    int min2 = datos[p+1], max1 = datos[0];
    //busca el max de la primera mitad
    for(int i = 1; i < p + 1; i++){
        if(datos[i] > max1) max1 = datos[i]; 
    }
    //busca el min de la segunda mitad
    for(int j = p + 2; j < (int)datos.size(); j++){
        if(datos[j] < min2) min2 = datos[j]; 
    }

    //comprueba que el max de la primera mitad sea mayor que el min de la segunda mitad
    return max1 < min2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    int p;
    cin >> p;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    bool sol = resolver(v, p);
    // escribir 
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