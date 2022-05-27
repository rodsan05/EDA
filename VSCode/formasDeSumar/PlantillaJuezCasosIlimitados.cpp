// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int>& sol, int k, int s, int& suma){

    for (int j = 0; j < k; j++) suma += sol[j];

    return suma <= s;
}

// función que resuelve el problema
void resolver(vector<int>& v, vector<int>& sol, vector<bool>& marcas, int n, int s, int k, int& cont, int antI) {
    
    for(int i = antI; i < n; i++){
        
        if(!marcas[i]){

            sol[k] = v[i];
            int suma = 0;
            if(esValida(sol, k, s, suma)){

                if(suma == s) cont++;

                else{
                    marcas[i] = true;
                    resolver(v, sol, marcas, n, s, k+1, cont, i);
                    marcas[i] = false;
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (! std::cin)
        return false;
    
    int s;
    cin >> s;
    vector<int> v(n);

    for(int& e : v) cin >> e;
    vector<int> sol(n);
    int cont = 0;
    vector<bool> marcas(n);
    resolver(v, sol, marcas, n, s, 0, cont, 0);
    
    // escribir sol
    cout << cont << endl;
    
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