// Nombre del alumno Rodrigo Sánchez Torres
// Usuario del Juez VJ56


#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h> 
using namespace std;

// función que resuelve el problema
void complementario(long num, long pot, long& sol) {
    
    //Saca el último dígito del número
    int c = num % 10;
    num /= 10; 

    //Complementa el dígito y lo pone en el acumulador en la posición que le corresponda
    sol += (9 - c) * pot;

    if(num > 0) complementario(num, pot*10, sol);
}
void inverso(long num, long pot, long& sol)
{
    //Saca el último digito del numero
    int c = num % 10;
    num /= 10;

    //Lo pone en la posición que corresponda en el inverso
    sol += c * pot;

    if(num > 0) inverso(num, pot/10, sol);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long n;
    cin >> n;

    long comp = 0;
    complementario(n, 1, comp);

    int ncifras = 0;
    while(n / 10 != 0)
    {
        n /= 10;
        ncifras++;
    }
    long pot = 1;
    for(int i = 0; i < ncifras; i++) pot *= 10;

    long inv = 0;
    inverso(comp, pot, inv);
    // escribir sol
    cout << comp << " " << inv << endl;
    
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