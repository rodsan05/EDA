// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;


// función que resuelve el problema
void resolver(vector<int> &sol, const vector<vector<int>> &precios, vector<int> &compradosPorSuper, const vector<int> &menorPrecioDesde,int nProd, int nSuper, int k, int precioAct, int& mejorPrecio) {
     
    for (int i = 0; i < nSuper; i++) {

        if (compradosPorSuper[i] < 3) {

            sol[k] = precios[i][k];
            precioAct += precios[i][k];

            if (k == nProd - 1) {

                if (precioAct < mejorPrecio) mejorPrecio = precioAct;
            }

            else {

                if(precioAct + menorPrecioDesde[k+1] < mejorPrecio) {

                    compradosPorSuper[i]++;
                    resolver(sol, precios, compradosPorSuper, menorPrecioDesde, nProd, nSuper, k + 1, precioAct, mejorPrecio);
                    compradosPorSuper[i]--;
                }
            }

            precioAct -= precios[i][k];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int supermercados, productos;

    cin >> supermercados;
    cin >> productos;

    vector<vector<int>> precios(supermercados, vector<int>(productos));

    for (int i = 0; i < supermercados; i++) {

        for (int j = 0; j < productos; j++) {

            cin >> precios[i][j];
        }
    }

    vector<int> sol(productos);
    vector<int> compradosPorSuper(supermercados, 0);

    vector<int> menorPrecio(productos, INT_MAX);

    for (int i = 0; i < productos; i++) {

        for (int j = 0; j < supermercados; j++) {

            if (menorPrecio[i] > precios[j][i]) menorPrecio[i] = precios[j][i];
        }
    }

    vector<int> menorPrecioDesde = menorPrecio;
    for (int i = productos - 2; i > -1; i--) {

        menorPrecioDesde[i] += menorPrecioDesde[i + 1];
    }
    
    int mejorPrecio = INT_MAX;
    resolver(sol, precios, compradosPorSuper, menorPrecioDesde, productos, supermercados, 0, 0, mejorPrecio);
    // escribir sol
    if (mejorPrecio != INT_MAX)
    cout << mejorPrecio << endl;

    else cout << "Sin solucion factible" << endl;
    
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