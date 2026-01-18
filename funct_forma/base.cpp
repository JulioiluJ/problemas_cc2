/* 
Codifo refenciado en main.cpp
*/

#include <iostream>

using namespace std;

float rectangulo(float base, float altura) {
    cout << "El area del rectangulo es: " << base * altura << endl;
    return base * altura;
}

float circulo(float radio, float zero) {
    float pi = 3.1416;
    cout << "El area del circulo es: " << pi * (radio * radio) << endl;
    return pi * (radio * radio);
}

float triangulo(float base, float altura) {
    cout << "El area del triangulo es: " << (base * altura) / 2 << endl;
    return (base * altura) / 2;
}

float cuadrado(float lado, float zero) {
    cout << "El area del cuadrado es: " << lado * lado << endl;
    return lado * lado;
}

typedef float (*PF)(float, float);

int main() {

    PF PuntFun[4] = {rectangulo,circulo,triangulo,cuadrado};
    PF* ppff = PuntFun;

    float figuras[4][2]={{2,0},{3,5},{10,0},{5,3}};//figuras
    int op[4]= {3,2,1,0};//configuracion de figuras

    int* pop = op;
    float area;
    float (*pfiguras)[2] = figuras;

    for(int i =0; i <4; i++){
        (*(ppff+*pop))((*pfiguras)[0],(*pfiguras)[1]);
        pop++;
        pfiguras++;
    }
}