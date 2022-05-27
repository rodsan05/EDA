//Nombre: Rodrigo Sánchez Torres
//Usuario Juez: VJ56

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
using namespace std;


template <class T>
class queue_plus : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    //el coste en el peor caso es n, siendo n el numero de elementos de la cola 
    void cuela(const T& a, const T& b){
        // Ojo que para acceder a prim o ult hay que escribir this->prim o this->ult
        Nodo* nodoA = this->prim;
        Nodo* nodoAntB = nullptr;
        while(nodoA != nullptr && nodoA->elem != a) nodoA = nodoA->sig;

        nodoAntB = nodoA;
        if(nodoA != nullptr){
            while(nodoAntB->sig != nullptr && nodoAntB->sig->elem != b) nodoAntB = nodoAntB->sig;

            if(nodoAntB->sig != nullptr && nodoA != nodoAntB){

                Nodo* nodoB = nodoAntB->sig;
                Nodo* nodoSigA = nodoA->sig;

                nodoAntB->sig = nodoB->sig;
                if(nodoAntB->sig == nullptr) this->ult = nodoAntB;
                nodoA->sig = nodoB;
                nodoB->sig = nodoSigA;
            }
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a, b;
    queue_plus<int> q;
    cin >> n;
    if (n == -1) return false;
    while (n != -1){
        q.push(n);
        cin >> n;
    }
    cin >> a >> b;

    // llamada a metodo
    q.cuela(a,b);

    // escribir sol (pero antes dar una vuelta para comprobar que la cola está bien formada)
    for (int i = 0; i < q.size(); ++i){
        n = q.front();
        q.pop();
        q.push(n);
    }
    // Ahora imprimimos la cola y de paso la dejamos vacía
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return true;
}

//#define DOMJUDGE
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
    //system("PAUSE");
#endif

    return 0;
}
