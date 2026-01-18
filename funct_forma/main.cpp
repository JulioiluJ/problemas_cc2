/* 
Usando el codigo base.cpp de punto de partida, modifique el codigo para usar funcores en lugar de
punteros a funcion (RECOMENDACION: Usar polimorfimos para almacenar los functores en el array)
Dificultad: 2/3
*/

#include <iostream>
using namespace std;

class Forma{
    public:
    virtual float operator()(float a, float b) = 0;
    virtual ~Forma(){};
};

class Rectangulo : public Forma {
    public:
    float operator()(float base, float altura) override{
        cout << "El area del rectangulo es: " << base * altura << endl;
        return base * altura;
    }
};

class Circulo : public Forma {
    public:
    float operator()(float radio, float zero) override{
        float pi = 3.1416;
        cout << "El area del circulo es: " << pi * (radio * radio) << endl;
        return pi * (radio * radio);
    }
};

class Triangulo : public Forma {
    public:
    float operator()(float base, float altura) override{
        cout << "El area del triangulo es: " << (base * altura) / 2 << endl;
        return (base * altura) / 2;
    }
};

class Cuadrado : public Forma {
    public:
    float operator()(float lado, float zero) override{
        cout << "El area del cuadrado es: " << lado * lado << endl;
        return lado * lado;
    }
};

int main() {
Rectangulo rec;
Circulo cir;
Triangulo tri;
Cuadrado cua;

Forma* PuntFun[4] = {&rec, &cir, &tri, &cua};

Forma** ppff = PuntFun;

float figuras[4][2]={{2,0},{3,5},{10,0},{5,3}};

int op[4]= {3,2,1,0};

int* pop = op;
float area;
float (*pfiguras)[2] = figuras;
for(int i =0; i < 4; i++)
{
    (**(ppff+*pop))((*pfiguras)[0],(*pfiguras)[1]);
    pop++;
    pfiguras++;
}
}