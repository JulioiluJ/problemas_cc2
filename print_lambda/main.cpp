/*
Crees 2 funciones lambda, para saber si un numero es par y otra para saber si es multiplo de 3,
luego una funcion imprimir que tenga como parametros el array y un puntero a funcion con la lambda,
la funcion imprimir debera imprimir solo los numeros que cumplan la condicion de la funcion lambda,
luego en el main cree dos threads que impriman los numeros pares y multiplos de 3 de un array

Dificultad: 1/3
*/

#include <iostream>
#include <thread>

using namespace std;

void imprimir(int* ini, int* fin, int(*op)(int n)){
    for(;ini <= fin; ini++){
        if(op(*ini) == 0){
            cout << *ini << " ";
        }
    }
    cout << endl;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto par([](int n){
        return n % 2;
    });

    auto tri([](int n){
        return n % 3;
    });

    thread t1(imprimir, a, a + 9, par);
    thread t2(imprimir, a, a + 9, tri);

    t1.join();
    t2.join();

    return 0;
}