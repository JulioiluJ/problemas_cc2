/*
Implemente dos funciones lambda, una identifica si un numero es par y la otra si es multiplo de 3,
luego cree una funcion que reciba un array y la funcion lambda como parametro. La funcion debe enviar
los numeros que cumplan la condicion de la funcion lambda al principio del array, todo esto de manera
ordenada, el array iniciar debe estar ya ordenado

Dificultad: 1/3
*/

#include<iostream>

using namespace std;

void split(int* ini, int* fin, int(*op)(int a)){
    int* initmp = ini;
    for(int* p = fin; p >= initmp; p--){
        if(!op(*p)){
            for(int* q = p; q > ini; q--){
                swap(*q, *(q - 1));
            }
            initmp++;
            p++;
        }
    }
}

void print(int* ini, int* fin){
    for (; ini<=fin; ini++){
        cout << *ini << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {74, 23, 91, 45, 8, 56, 33, 67, 12, 89};
    int n = 9;

    print(arr, arr + n);

    auto par = [](int a){
        return a % 2;
    };

    auto tri = [](int a){
        return a % 3;
    };
    
    split(arr, arr + n, par);
    print(arr, arr + n);

    return 0;
}
