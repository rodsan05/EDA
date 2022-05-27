// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
using namespace std;

bool esValida(const vector<int> &marcas, const vector<int> &sol, const vector<int> &piezas, int k)
{

    bool valida = true;

    if (marcas[0] < marcas[2])
        valida = false;
    if ((sol[k] == 3) && (sol[k - 1] == sol[k]))
        valida = false;
    if (marcas[sol[k]] > piezas[sol[k]]) 
        valida = false;

    return valida;
}

bool esSolucion(const vector<int> &marcas, const vector<int> &sol, int n, int k) {

    return (k == n - 1) && (marcas[1] > (marcas[0] + marcas[2]));
}

// función que resuelve el problema
void resolver(vector<int> &marcas, vector<int> &sol, const vector<int> &piezas, int n, int k, bool& haySolucion)
{
    for (int i = 0; i < 3; i++)
    {
        sol[k] = i;

        marcas[i]++;
        if (esValida(marcas, sol, piezas, k))
        {
            if (esSolucion(marcas, sol, n, k))
            {
                for (int j = 0; j < n; j++)
                {

                    switch (sol[j])
                    {
                    case 0:
                        cout << "azul ";
                        break;
                    case 1:
                        cout << "rojo ";
                        break;
                    case 2:
                        cout << "verde ";
                        break;

                    default:
                        break;
                    }
                }
                cout << endl;

                if (!haySolucion) haySolucion = true;
            }

            else if (k < n - 1)
            {
                resolver(marcas, sol, piezas, n, k + 1, haySolucion);
            }
        }
        marcas[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n, a, v, r;

    cin >> n;
    cin >> a;
    cin >> r;
    cin >> v;

    if (n == 0)
        return false;

    vector<int> soluc(n);
    soluc[0] = 1;
    vector<int> piezas = {a, r, v};
    vector<int> marcas = {0, 1, 0};

    bool haySolucion = false;
    resolver(marcas, soluc, piezas, n, 1, haySolucion);

    if (!haySolucion) cout << "SIN SOLUCION" << endl;
    cout << endl;

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
