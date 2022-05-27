#include <iostream>

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

void testSet(){
    char op;
    int n;
    Set<int> set;
    cout << set << endl;
    do{
        cout << "Choose option ((a)dd, (r)emove, (c)ontains, (e)xit)" << endl;
        cin >> op;
        if (op == 'a'){
            cin >> n;
            set.add(n);
        } else if (op == 'r'){
            cin >> n;
            set.remove(n);
        } else if (op == 'c'){
            cin >> n;
            cout << set.contains(n) << endl;
        }
        cout << set << endl;
    } while (op != 'e');
    cout << "Program finished" << endl;
}

int main(){
    testSet();
}


