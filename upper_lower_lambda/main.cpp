/*
Implemente una funcion lambda que pase un char de minuscula a mayuscula y otra que haga lo contrario
Luego una funcion que reciba un array de char y la funcion lambda, combierta cada elemento del array
a la condicion de la funcion lambda

Dificultad: 1/3
*/

#include<iostream>

using namespace std;

void funcCad(char* cad, char(*op)(char a)){
    for(char* p = cad; *p; p++){
        *p = op(*p);
    }
}

void print(char* ini){
    cout << ini << endl;
}

int main(){
    char arr1[] = "holaaskdfjhHskdfjklasjdfh";
    char arr2[] = "HOLAadsfjhaksfhULkjHkKJHkKJHjhkJHJkHkjH";
    char arr3[] = "$%^adkfsh*&)(&*gjlkjgh7tu7*TuyigYghgyur5r7tFu7Yg*7YH8&yuh*7TG86tgtyyuhG8yGgyuuygUyFg*Y^Ugs5DE^FRTG&YUHIJO8y67fr&%TGYUH&*";

    print(arr3);

    auto lower = [](char a){
        if (a > 64 && a < 91){
            return static_cast<char>(a + 32);
        }
        return a;
    };

    auto upper = [](char a){
        if (a > 96 && a < 123){
            return static_cast<char>(a - 32);
        }
        return a;
    };

    funcCad(arr3, upper);
    print(arr3);

    return 0;
}