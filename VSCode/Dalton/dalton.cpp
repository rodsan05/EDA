// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int> &vineta) {
    
    bool sonDalton = true;
    bool creciente = vineta[0] < vineta[1];
    int punt = vineta[0];
    int i = 1 ;
    while(i < (int)vineta.size() && sonDalton)
    {
        if(creciente) sonDalton = punt < vineta[i];
        else sonDalton = punt > vineta[i];
        punt = vineta[i];

        i++;
    }

    return sonDalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    bool sol = resolver(v);
    
    // escribir sol
    if(sol) cout << "DALTON" << endl;
    else cout << "DESCONOCIDOS" << endl;

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso());

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
