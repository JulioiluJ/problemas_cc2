/* 
Construir dos iteradores de 'Vector' (Clase creada), uno debe iterar de inicio a fin y el otro de
fin a inicio 
Dificultad: 3/3
*/

#include <iostream>

using namespace std;

template<class T>
class Iterator {
private:
    T* it;
public:
    void operator=(T* valor) {
        it = valor;
    }
    void operator=(T valor) {
        *it = valor;
    }
    T* operator++(int) {
        it++;
        return it;
    }
    T operator*() {
        return *it;
    }
    bool operator<=(T* otro) {
        return it <= otro;
    }
    friend istream& operator>>(istream &input, Iterator D) {
        input>>(*D.it);
        return input;
    }
};

template<class T>
class Iterator2 {
private:
    T* it;
public:
    void operator=(T* valor) {
        it = valor;
    }
    void operator=(T valor) {
        *it = valor;
    }
    T* operator++(int) {
        it--;
        return it;
    }

    T operator*() {
        return *it;
    }
    bool operator>=(T* otro) {
        return it >= otro;
    }
    friend istream& operator>>(istream &input, Iterator2 D) {
        input>>(*D.it);
        return input;
    }
};

template<class T, class I>
class Vector {
private:
    T a[10];
public:
    typedef I it_vector;

    T* begin() {
        return &a[0];
    }
    T* end() {
        return &a[9];
    }

};

int main() {
    Vector<int, Iterator<int>> Ent;
    Vector<int, Iterator<int>>::it_vector It;

    int x = 100;

    for (It = Ent.begin(); It <= Ent.end(); It++) {
        It = x;
        x+= 100;
    }
    for (It = Ent.begin(); It <= Ent.end(); It++) {
        cout << *It << endl;
    }

    cout << "--------------------------------" << endl;
    for (It = Ent.begin(); It <= Ent.end(); It++) {
        cout << "Ingrese un entero: ";
        cin >> It;
    }
    for (It = Ent.begin(); It <= Ent.end(); It++) {
        cout << *It << endl;
    }

    cout << "=================================" << endl;

    Vector<int, Iterator2<int>> Ent2;
    Vector<int, Iterator2<int>>::it_vector It2;

    for (It2 = Ent2.end(); It2 >= Ent2.begin(); It2++) {
        It2 = x;
        x+= 100;
    }

    for (It = Ent2.begin(); It <= Ent2.end(); It++) {
        cout << *It << endl;
    }

    cout << "--------------------------------" << endl;

    for (It = Ent2.begin(); It <= Ent2.end(); It++) {
        cout << "Ingrese un numero:";
        cin >> It;
    }

    for (It2 = Ent2.end(); It2 >= Ent2.begin(); It2++) {
        cout << *It2 << endl;
    }

    return 0;
}
