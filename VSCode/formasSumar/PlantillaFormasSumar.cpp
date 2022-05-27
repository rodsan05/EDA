
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

void resolver(vector<int> &sol, const vector<int> &acum, const vector<int> &nums, const vector<int> &menorDesde, int n, int valor, int sumaAct, int k, int &nSols)
{
    if (sumaAct + acum[k] >= valor) {
        sumaAct += nums[k];

        if (sumaAct <= valor)
        {

            if (sumaAct == valor)
            {
                nSols++;
            }

            else if (k < n - 1 && sumaAct + menorDesde[k + 1] <= valor)
                resolver(sol, acum, nums, menorDesde, n, valor, sumaAct, k + 1, nSols);
        }
        sumaAct -= nums[k];

        if (sumaAct <= valor)
        {

            if (sumaAct == valor)
            {
                nSols++;
            }

            else if (k < n - 1 && sumaAct + menorDesde[k + 1] <= valor)
                resolver(sol, acum, nums, menorDesde, n, valor, sumaAct, k + 1, nSols);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, valor;
    cin >> n;
    if (!cin)
        return false;
    cin >> valor;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> sol(n);
    int nSols = 0;

    vector<int> menorDesde(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (nums[j] < menorDesde[i])
                menorDesde[i] = nums[j];
    }

    vector<int> ac(n);
    ac[n-1] = nums[n-1];
    for (int i = n-2; i > -1; i--) {

        ac[i] = nums[i] + ac[i+1];
    }

    resolver(sol, ac, nums, menorDesde, n, valor, 0, 0, nSols);
    // Salida
    cout << nSols << endl;

    return true;
}

//#define DOMJUDGE
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
