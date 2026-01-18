/* 
Construir un iterador de matriz, Tiene que empezar en al posicion (0, 0) y en cada iteracion debe
pasar a la siguiente fila y en la columna del menor numero entre los que se encuentren en la diagonal
izquiera, derecha o debajo del mismo. Colocar 0 en cada elemento iterado.

Ejemplo:
matriz = {
    {3, 1, 6, 7},
    {3, 1, 5, 2},
    {9, 7, 0, 1},
    {9, 8, 1, 2},
    {8, 3, 5, 9}
}
1.  Parte en matriz[0][0] = 3
2.  Busca el menor numero entre las diagonales y debajo de 3: min(3, 1) = 1
3.  Busca el menor numero entre las diagonales y debajo de 1: min(9, 7, 0) = 0
4.  Busca el menor numero entre las diagonales y debajo de 0: min(8, 1, 2) = 1
4.  Busca el menor numero entre las diagonales y debajo de 1: min(3, 5, 9) = 3
    Termina de iterar porque ya esta en la ultima fila

Matriz luego de iterar
matriz = {
    {0, 1, 6, 7},
    {3, 0, 5, 2},
    {9, 7, 0, 1},
    {9, 8, 0, 2},
    {8, 0, 5, 9}
}

Dificultad: 3/3
*/

#include<iostream>

using namespace std;

class Matrix{
    int (*arr)[4];
    int x;
    int y;
    public:
    Matrix(int (*_arr)[4], int _x, int _y) : arr(_arr), x(_x), y(_y) {};
    void imprimir(){
        for(int* p = *arr; p < *(arr + x - 1) + y; p++){
                cout << *p << " ";
        }
            cout << endl;
    }

};

int main(){
    int A[][4] = {
        {3, 1, 6, 7},
        {3, 1, 5, 2},
        {9, 7, 0, 1},
        {9, 8, 1, 2},
        {8, 3, 5, 9}
    };

    Matrix mx(A, 5, 4);

    mx.imprimir();

    //for(auto it = m.begin(); it <= m.end(); it++)
    //   *it = 0;

    return 0;
}