#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

//El algoritmo tiene complejidad N*log2(N), siendo N la longitud del string. Esto es porque la función sort es la de mayor complejidad en el algoritmo.
bool anagramas(const string& cad1, const string& cad2) {
    bool esAnagrama = false;

    if(cad1.length() == cad2.length()) 
    {
        string v1 = cad1;
        string v2 = cad2;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if (v1 == v2) esAnagrama = true;
    }

    return esAnagrama;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string word1, word2;
    cin >> word1 >> word2;
    cout << (anagramas(word1,word2) ? "SI" : "NO") << endl;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}