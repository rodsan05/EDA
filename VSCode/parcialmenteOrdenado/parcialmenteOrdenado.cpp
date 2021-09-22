// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& v, int ini, int fin) {
    
    if(ini == fin-1) return true; //Si solo hay un elemento devuelve true

    int minI = v[ini], minD = v[(ini+fin)/2], maxI = v[ini], maxD = v[(ini+fin)/2];
    int i = ini + 1, j = fin/2 + 1; 
    //Recorre las 2 mitades del vector buscando el min y max de cada lado
    while(i < fin/2)
    {
        if (v[i] < minI) minI = v[i];
        if (v[i] > maxI) maxI = v[i];
        if (v[j] < minD) minD = v[j];
        if (v[j] > maxD) maxD = v[j];

        i++;
        j++;
    }
    //Si el se cumplen las condiciones ejecuta el algoritmo con las mitades
    if(minI <= minD && maxI <= maxD) return resolver(v, ini, (ini+fin)/2) && resolver(v, (ini+fin)/2, fin);
    
    else return false;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> vect;
    int n;
    cin >> n;
    vect.push_back(n);
    while(n != 0)
    {
        cin >> n;
        vect.push_back(n);
    }

    if (vect[0] == 0)
        return false;
    
    bool sol = resolver(vect, 0, (int)vect.size() - 1);
    
    // escribir sol
    if(sol) cout << "SI" << endl;
    else cout << "NO" << endl;

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
