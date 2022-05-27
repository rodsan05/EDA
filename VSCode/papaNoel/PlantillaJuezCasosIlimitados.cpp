// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>

#include <vector>
using namespace std;

// función que resuelve el problema
void resolver(vector<int> &sol, int n, int m, int k, int satisfActual, const vector<vector<int>> &satisfaccion, int &mejorSol, vector<bool> &marcas, const vector<int> &mejorPosible)
{

    for (int i = 0; i < m; i++)
    {

        if (!marcas[i])
        {
            sol[k] = i;
            satisfActual += satisfaccion[k][i];

            if (k == n - 1)
            {

                if (satisfActual > mejorSol)
                    mejorSol = satisfActual;
            }

            else if (satisfActual + mejorPosible[k] > mejorSol)
            {
                marcas[i] = true;
                resolver(sol, n, m, k + 1, satisfActual, satisfaccion, mejorSol, marcas, mejorPosible);
                marcas[i] = false;
            }

            satisfActual -= satisfaccion[k][i];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int m;
    cin >> m;

    if (!std::cin)
        return false;

    int n;
    cin >> n;

    vector<int> sol(n);

    int e;
    vector<vector<int>> satisfaccion;

    for (int i = 0; i < n; i++)
    {

        vector<int> fila;

        for (int j = 0; j < m; j++)
        {

            cin >> e;
            fila.push_back(e);
        }

        satisfaccion.push_back(fila);
    }

    vector<bool> marcas(m);
    int mejorSol = INT_MIN;

    vector<int> maxFilas(n, INT_MIN);
    for (int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++)
        if (maxFilas[i] < satisfaccion[i][j]) maxFilas[i] = satisfaccion[i][j];
    }

    vector<int> mejorPosible(n, 0);

    mejorPosible[n-1] = maxFilas[n-1];
    for (int i = n - 2; i > -1; i--) {

        mejorPosible[i] = maxFilas[i] + mejorPosible[i+1];
    }

    resolver(sol, n, m, 0, 0, satisfaccion, mejorSol, marcas, mejorPosible);

    // escribir sol
    cout << mejorSol << endl;

    return true;
}

int main()
{
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