#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>

#include <string>
#include <unordered_map>
#include <map>

using namespace std;

using Votos = int;
using Estado = string;
using Partido = string;
class ConteoVotos {

private:

    using Partidos = unordered_map<Partido, Votos>; 

    struct Ganador {

        int votos;
        Partido partido;
    };
    struct InfoEstado {

        int compromisarios;
        Partidos partidos;
        Ganador ganador;
    };
    
    unordered_map<Partido, int> resultadosPartidosAux;

    unordered_map<Estado, InfoEstado> estados;
    

public:

    //Buscar en un hash map tiene coste constante. 
    //Insertar en un hash map tiene coste constante.
    //Por lo tanto el coste es O(1), constante
    void nuevo_estado(const Estado &nombre, int num_compromisarios) {

        unordered_map<Estado, InfoEstado>::iterator it = estados.find(nombre);

        if (it == estados.end()) {

            InfoEstado info;
            info.compromisarios = num_compromisarios;
            info.ganador.votos = 0;
            info.ganador.partido = "";

            estados.insert({nombre, info});
        }

        else throw domain_error("Estado ya existente");
    }  
    
    //Buscar en un hash map tiene coste constante. 
    //En el peor caso (no existe el partido) lo crea en el hash map, que tiene coste constante.
    //Además, comparamos si el número de votos del partido es mayor que el actual ganador para sustituirlo, lo cual es constante
    //Finalmente, si el ganador ha cambiado, actualizamos el hash map de resultados auxiliar, lo cual es constante
    //Por lo tanto el coste es O(1), constante
    void sumar_votos(const Estado &estado, const Partido &partido, int num_votos) {

        unordered_map<Estado, InfoEstado>::iterator it = estados.find(estado);

        if (it != estados.end()) {

            it->second.partidos[partido] += num_votos;

            if (it->second.partidos[partido] > it->second.ganador.votos) {
                
                unordered_map<Partido, int>::iterator itAux = resultadosPartidosAux.find(it->second.ganador.partido);

                it->second.ganador.partido = partido;
                it->second.ganador.votos = it->second.partidos[partido];

                //le suma los compromisarios al nuevo ganador
                resultadosPartidosAux[partido] += it->second.compromisarios;

                //si habia un antiguo ganador le resta los compromisarios
                if (itAux != resultadosPartidosAux.end()) itAux->second -= it->second.compromisarios; 
            }
        }

        else throw domain_error("Estado no encontrado");
    }

    //Buscar en un hash map tiene coste constante
    //Debido a que nos hemos guardado el ganador en un struct simplemente devolvemos el nombre del partido
    //Por lo tanto el coste es O(1), constante
    Partido ganador_en(const Estado &estado) const {
        
        unordered_map<Estado, InfoEstado>::const_iterator it = estados.find(estado);

        if (it != estados.end()) {

            return it->second.ganador.partido;
        }

        else throw domain_error("Estado no encontrado");
    }

    //Parte 1:
    //Creamos un map aux ordenado para guardar en orden los partidos y recorremos el hash map de resultados auxiliares para insertar los compromisarios de los ganadores, lo que tiene coste linear en el numero de partidos (p)
    //Insertar en un map ordenado tiene coste logarítmico en su tamaño, p
    //Por lo tanto el coste de recorrer el map aux es p*log(p), siendo p el número de partidos
    //Parte 2:
    //Recorremos el map aux para ir insertando los resultados al vector resultados, lo que tiene coste lineal en el numero de partidos
    //El coste total es el máximo de la parte 1 y 2, por lo tanto es: p*log(p), siendo p el número de partidos
    vector<pair<Partido,int>> resultados() const {

        map<Partido, int> aux;

        unordered_map<Partido, int>::const_iterator it = resultadosPartidosAux.begin();
        while (it != resultadosPartidosAux.end()) {
            
            if(it->second > 0) aux[it->first] = it->second;
            it++;
        }

        map<Partido, int>::iterator itAux = aux.begin();

        vector<pair<Partido, int>> resultados;

        while (itAux != aux.end()) {

            resultados.push_back({itAux->first, itAux->second});
            itAux++;
        }

        return resultados;
    }

}; 


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            } else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            } else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador  = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            } else if (comando == "resultados") {
                for (const auto &par : elecciones.resultados()) {
                    cout << par.first << " " << par.second << "\n";
                }
            }
        } catch (std::exception &e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
