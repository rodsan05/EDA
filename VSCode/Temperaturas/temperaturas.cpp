// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int>& datos, int k) {
    
    vector<int> picos(2, 0);

    for(int i = 1; i < (int)datos.size() - 1; i++)
    {
        if(datos[i] > datos[i + 1] && datos [i] > datos[i - 1]){
            picos[0]++;
        }

        else if(datos[i] < datos[i + 1] && datos [i] < datos[i - 1]){
            picos[1]++;
        }
    }

    return picos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    vector<int> sol = resolver(v, k);
    // escribir 
    int e;
    for(int e : sol) cout << e << " ";
    cout << endl;
    
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