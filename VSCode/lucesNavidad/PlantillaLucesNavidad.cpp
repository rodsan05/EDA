
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int> &sol, vector<int> &usadas, int k, int n, int consumoAct, int consumoMax)
{

    bool valida = true;

    if (k >= 2 && sol[k] == sol[k - 1] && sol[k] == sol[k - 2])
        valida = false;

    int sumaRestoLuces = k + 1 - usadas[sol[k]];
    if (usadas[sol[k]] - sumaRestoLuces > 1) valida = false; 

    if (consumoAct > consumoMax)
        valida = false;

    return valida;
}

void resolver(vector<int> &sol, int k, int longitud, int numLuces, int consumoMax, const vector<int> &consumoPorColor, int consumoAct, vector<int> &usadas, int &nSols)
{

    for (int i = 0; i < numLuces; i++)
    {
        sol[k] = i;
        consumoAct += consumoPorColor[i];
        usadas[i]++;

        if (esValida(sol, usadas, k, longitud, consumoAct, consumoMax))
        {

            if (k == longitud - 1)
            {
                nSols++;
            }

            else
            {
                resolver(sol, k + 1, longitud, numLuces, consumoMax, consumoPorColor, consumoAct, usadas, nSols);
            }
        }

        consumoAct -= consumoPorColor[i];
        usadas[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{

    // leer los datos de la entrada
    int n, m, consumoMax;
    cin >> n;
    if (n == 0)
        return false;
    cin >> m >> consumoMax;
    vector<int> consumosPorColor(m);
    for (int &e : consumosPorColor)
        cin >> e;
    vector<int> soluc(n);
    vector<int> totalesPorColor(m, 0);

    vector<int> usadas(m, 0);
    int nSols = 0;
    resolver(soluc, 0, n, m, consumoMax, consumosPorColor, 0, usadas, nSols);
    // Salida
    cout << nSols << endl;

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
    //system("PAUSE");
#endif

    return 0;
}