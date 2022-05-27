// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#include "Set.h"

template <class T>
ostream& operator<<(ostream& out, Set<T> const& set) {
    out << "{";
    const T* elems = set.toArray();
    for (int i = 0; i < set.size()-1; i++)
        out << elems[i] << ",";
    if (set.size() > 0) out << elems[set.size()-1];
    out << "}";
    return out;
}

// el coste es n, siendo n la longitud del vector de entrada
void resolver(vector<int>& v, int k, Set<int>& set) {
    
    for(int i = 0; i < k; i++) set.add(v[i]);


    for (int j = k; j < v.size(); j++){

        if(v[j] < set.getMax() && !set.contains(v[j])) {
            
            set.removeMax();
            set.add(v[j]);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;
    cin >> k;

    if (k == 0)
        return false;

    vector<int> v;
    int n;
    cin >> n;
    while(n != -1){

        v.push_back(n);
        cin >> n;
    }

    Set<int> set;
    resolver(v, k, set);
    
    // escribir sol
    cout << set << endl;

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
