// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<char>& sol, int n, int m, int k, vector<bool> usadas) {
    
    for(char c = 'a'; c < 'a' + m; c++){

        sol[k] = c;
    
        if(k == n-1){

            for(char& s : sol) cout << s;
            cout << endl;
        }

        else{

            usadas[c - 'a'] = true;
            resolver(sol, n, m, k+1, usadas);
            usadas[c - 'a'] = false; 
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m;
    cin >> m;

    if (! std::cin)
        return false;
    
    int n;
    cin >> n;
    vector<char> sol(n);
    vector<bool> usadas(m);

    resolver(sol, n, m, 0, usadas);
    cout << endl;
    // escribir sol
    
    
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