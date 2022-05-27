// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esValida(vector<int>& sol, int k){

    bool correcta = true;

    int i = 0;
    while(i < k && correcta){

        if((sol[i] == sol[k]) || (abs(sol[k] - sol[i]) == k - i)) correcta = false;

        else i++;
    }

    return correcta;
}

// función que resuelve el problema
void resolver(vector<bool>& columnas, vector<bool>& diagonales, vector<int>& sol, int n, int k, int& nSol) {
    
    for(int i = 0; i < n; i++){

        sol[k] = i;

        if(esValida(sol, k)){ 

            if(k == n-1){

                nSol++;
            }

            else{

                resolver(columnas, diagonales, sol, n, k + 1, nSol);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    
    vector<int> sol(n);
    int nSol = 0;

    vector<bool> columnas(n);
    if(n == 2) vector<bool> d(n);
    else vector<bool> d(n*2 + 2);
    
    vector<bool> diagonales = d;
    resolver(columnas, diagonales, sol, n, 0, nSol);
    // escribir sol
    cout << nSol << endl;
    
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