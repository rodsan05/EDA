//Rodrigo Sánchez Torres

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<vector<bool>>& consentimientos, const vector<int>& sol, int k){

    if(k == 0) return true; 

    return consentimientos[sol[k]][sol[k-1]];
}

// La tupla solución: [0, 1, ..., Ai] siendo Ai el artista que toca en la posición i
// Las marcas realizadas están un vector de booleanos, en el que se marca si el artista i ya ha sido colocado

void resolver(const vector<vector<int>>& beneficios, const vector<vector<bool>>& consentimientos, const vector<int>& sumaMaxima, vector<int>& sol, vector<bool>& marcas, int n, int& vSol, int& mejorSol, int k){

    for(int i = 0; i < n; i++ ){

        if(!marcas[i]){
            sol[k] = i;

            if(esValida(consentimientos, sol, k)){

                vSol += beneficios[i][k];

                if(k == n - 1){

                    if(vSol > mejorSol) mejorSol = vSol;
                }

                else if(vSol + sumaMaxima[k+1] > mejorSol){

                    marcas[i] = true;
                    resolver(beneficios, consentimientos, sumaMaxima,sol, marcas, n, vSol, mejorSol, k + 1);
                    marcas[i] = false;
                }

                vSol -= beneficios[i][k];
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
    vector<vector<int>> beneficios(n,vector<int>(n));
    vector<vector<bool>> consentimientos(n,vector<bool>(n));
    vector<int> maximos(n, 0);
    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < n; ++j){
            
            cin >> beneficios[i][j];
            if(beneficios[i][j] > maximos[j]) maximos[j] = beneficios[i][j];
        }
    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            consentimientos[i][j] = b;
        }

    vector<int> sol(n);
    vector<bool> marcas(n);

    int mejorSol = 0;
    int vSol = 0;

    vector<int> sumaMaxima = maximos;
    for(int i = n - 2; i > -1; i--){

        sumaMaxima[i] += sumaMaxima[i + 1];
    }

    resolver(beneficios, consentimientos, sumaMaxima, sol, marcas, n, vSol, mejorSol, 0);
    // salida

    if(mejorSol == 0) cout << "NEGOCIA CON LOS ARTISTAS" << endl;

    else cout << mejorSol << endl;
}

//#define DOMJUDGE
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("input3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
