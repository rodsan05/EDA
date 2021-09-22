#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, e;
    cin >> n;
    vector<int> v(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v[i] = e;
    }
    //ambos bucles son equivalentes (superior e inferior)
    for(int& e : v) cin >> e; 
    
    for(int e : v) cout << e << " ";
}

//pasamos el parámetro de salida por referencia (&)
void fact(int n, int& out){
    //codigo
}

//pasamos el vector por referencia (&) para no copiarlo, pero como const para que no se pueda modificar
bool buscar(const vector<int>& v, int e){
    //codigo
}
