/*
Mira la imagen

Dificultad: Si
*/

#include<iostream>

int suma(int a, int b) {return a + b;}
int resta(int a, int b) {return a - b;}
int multi(int a, int b) {return a * b;}
int divi(int a, int b) {return a / b;}

void Verificar3D(int*** arr, int x1, int y1, int z1, int(*operacion)(int a, int b), double res){
    for(int** p = *arr; p < *arr + y1; p++){
        for(int* q = *p; q < *p + x1; q++){
            int resultado = *q;
            std::cout << *q << std::endl; 
            for(int*** r = arr + 1; r < arr + z1;r++){
                int a = q - **arr;
                resultado = operacion(resultado, *(**r + a));
            }
            if(resultado == res){
                std::cout << "CUMPLE" << std::endl;
            }  
        }
    }
}

int main(){

    int*** a = new int**[3];
    for(int i = 0; i < 3; i++){
        a[i] = new int*[3];
        for(int j = 0; j < 3; j++){
            a[i][j] = new int[3];
        }
    }

    a[0][0][0] = 9; a[0][0][1] = 7; a[0][0][2] = 1;
    a[0][1][0] = 2; a[0][1][1] = 4; a[0][1][2] = 8;
    a[0][2][0] = 5; a[0][2][1] = 3; a[0][2][2] = 6;

    a[1][0][0] = 2; a[1][0][1] = 2; a[1][0][2] = 5;
    a[1][1][0] = 4; a[1][1][1] = 3; a[1][1][2] = 2;
    a[1][2][0] = 1; a[1][2][1] = 1; a[1][2][2] = 7;

    a[2][0][0] = 6; a[2][0][1] = 0; a[2][0][2] = 0;
    a[2][1][0] = 1; a[2][1][1] = 3; a[2][1][2] = 1;
    a[2][2][0] = 2; a[2][2][1] = 5; a[2][2][2] = 2;

    Verificar3D(a, 3, 3, 3, resta, 5);

    return 0;
}
