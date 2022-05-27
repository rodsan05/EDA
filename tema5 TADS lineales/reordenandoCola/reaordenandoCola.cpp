// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;


// función que resuelve el problema
void resolver(queue<int>& q) {
    
    queue<int> auxQ;
    stack<int> auxS;
 
    while(!q.empty())
    {
        if(q.front() < 0) {

            auxS.push(q.front());
            q.pop();
        }
        else {

            auxQ.push(q.front());
            q.pop();
        }
    }

    while(!auxS.empty())
    {
        q.push(auxS.top());
        auxS.pop();
    }
    while(!auxQ.empty())
    {
        q.push(auxQ.front());
        auxQ.pop();
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
    
    queue<int> datos;
    int k;
    for (int i = 0; i < n; i++) {
        
        cin >> k;
        datos.push(k);
    }

    resolver(datos);
    // escribir sol
    
    while (!datos.empty())
    {
        cout << datos.front() << " ";
        datos.pop();
    }
    cout << endl;
    
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
