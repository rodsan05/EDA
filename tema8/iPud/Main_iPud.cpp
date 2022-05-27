
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <list>
#include <unordered_map>
using namespace std;

using cancion = std::string;
using artista = std::string;

class iPud {

private:

    struct datosCancion {

        string artista;
        int duracion;
        bool enPlaylist;

        list<cancion>::iterator posPlaylist;
        list<cancion>::iterator posReproducidas;
    };

    int timePlaylist = 0;

    unordered_map<cancion, datosCancion> canciones;

    list<cancion> playlist;

    list<cancion> reproducidas;

public:

    //constante
    void addSong(cancion S, artista A, int D) {

        datosCancion datos;

        datos.artista = A;
        datos.duracion = D;
        datos.enPlaylist = false;
        datos.posPlaylist = playlist.end();
        datos.posReproducidas = reproducidas.end();

        canciones.insert({S, datos});
    }

    //constante
    void addToPlaylist(cancion S) {

        unordered_map<cancion, datosCancion>::iterator it = canciones.find(S);

        if (it == canciones.end()) throw invalid_argument("addToPlaylist");

        else if (!it->second.enPlaylist) {

            playlist.push_back(S);

            it->second.enPlaylist = true;
            it->second.posPlaylist = playlist.end()--;

            timePlaylist += it->second.duracion;
        }
    }

    //constante
    cancion current() {

        if (playlist.empty()) throw invalid_argument("current");

        else return playlist.front();
    }

    //constante
    void play() {

        if (!playlist.empty()) {

            unordered_map<cancion, datosCancion>::iterator it = canciones.find(playlist.front());

            if (it != canciones.end()) {

                if (it->second.posReproducidas != reproducidas.end()) reproducidas.erase(it->second.posReproducidas);
            
                reproducidas.push_front(playlist.front());

                it->second.posReproducidas = reproducidas.begin();

                it->second.enPlaylist = false;

                timePlaylist -= it->second.duracion;
            }

            playlist.pop_front();
        }
    }

    //constante
    int totalTime() {

        return timePlaylist;
    }

    //lineal en N
    list<cancion> recent(int N) {

        list<cancion>::iterator it = reproducidas.begin();

        list<cancion> recientes;

        int i = 0;
        while (i < N && it != reproducidas.end()) {

            recientes.push_back(*it);

            it++;
            i++;
        }

        return recientes;
    }

    //constante
    void deleteSong(cancion S) {

        unordered_map<cancion, datosCancion>::iterator it = canciones.find(S);

        if (it != canciones.end()) {

            if (it->second.posPlaylist != playlist.end()) playlist.erase(it->second.posPlaylist);
            
            if (it->second.posReproducidas != reproducidas.end()) reproducidas.erase(it->second.posReproducidas);

            canciones.erase(it);            
        }
    }

};

bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    cancion tit; artista aut; int dur;
    iPud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            } else if (operacion == "addToPlaylist") {
                cin >> tit;
                ipud.addToPlaylist(tit);
            } else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            } else if (operacion == "play") {
                try {
                    string tocando = ipud.current(); // para saber si la lista es vacía
                    ipud.play();
                    cout << "Sonando " << tocando << '\n';
                } catch (invalid_argument e) {
                    cout << "No hay canciones en la lista\n";
                }
            } else if (operacion == "totalTime") {
                cout << "Tiempo total " << ipud.totalTime() << '\n';
            } else if (operacion == "recent") {
                int N;
                cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& s : lista)
                        cout << "    " << s << '\n';
                }
            } else if (operacion == "deleteSong") {
                cin >> tit;
                ipud.deleteSong(tit);
            } else { // operacion desconocida
                assert(false);
            }
        } catch (invalid_argument e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
    }
    cout << "---\n";
    return true;
}

int main(){
    while (resuelve());
    return 0;
}
