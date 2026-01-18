/*
Dado un array 2D de chars, implemente una funcion que busque una palabra cualquiera en las cuatro
direccions: izquierda, derecha, arriba y abajo. Usar 4 threads. Use la funcion main como punto de
partida

Dificultad: 3/3
*/

#include <iostream>
#include <thread>

using namespace std;

int contarde(char(*mat)[10], char* palabra)
{
    char* ini = *mat;
    char* fin = *(mat + 9) + 9;
    int contador = 0;

    for(char* p = ini; p < fin; p++){
        char* r = p;
        char* q = palabra;
        for(; *q; q++){
            if((r - *mat) % 10 == 0 && p < r){break;}
            if(r > fin){break;}
            if(*q != *r){break;}
            r++;
        }
        if(*q == '\0'){
            contador++;
        }
    }

    return contador;
}

int contariz(char(*mat)[10], char* palabra)
{
    char* ini = *mat;
    char* fin = *(mat + 9) + 9;
    int contador = 0;

    for(char* p = fin; p > ini; p--){
        char* r = p;
        char* q = palabra;
        for(; *q; q++){
            if((r - *mat) % 10 == 9 && p > r){break;}
            if(r < ini){break;}
            if(*q != *r){break;}
            r--;
        }
        if(*q == '\0'){
            contador++;
        }
    }

    return contador;
}

int contarab(char(*mat)[10], char* palabra)
{
    char* ini = *mat;
    char* fin = *(mat + 9) + 9;
    int contador = 0;

    for(char* p = ini; p < fin; p++){
        char* r = p;
        char* q = palabra;
        for(; *q; q++){
            if(r > fin){break;}
            if(*q != *r){break;}
            r+=10;
        }
        if(*q == '\0'){
            contador++;
        }
    }

    return contador;
}

int contarar(char(*mat)[10], char* palabra)
{
    char* ini = *mat;
    char* fin = *(mat + 9) + 9;
    int contador = 0;

    for(char* p = ini; p < fin; p++){
        char* r = p;
        char* q = palabra;
        for(; *q; q++){
            if(r > fin){break;}
            if(*q != *r){break;}
            r-=10;
        }
        if(*q == '\0'){
            contador++;
        }
    }

    return contador;
}

int contar(char(*mat)[10], char* palabra){
    int resultado = 0;

    thread t1([&resultado, mat, palabra]{
        resultado += contarde(mat, palabra);
    });
    thread t2([&resultado, mat, palabra]{
        resultado += contariz(mat, palabra);
    });
    thread t3([&resultado, mat, palabra]{
        resultado += contarar(mat, palabra);
    });
    thread t4([&resultado, mat, palabra]{
        resultado += contarab(mat, palabra);
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return resultado;
}

int main()
{
    char mat[10][10] = {
        {'C','A','S','A','D','O','R','A','D','O'},
        {'D','C','A','S','A','D','O','A','S','A'},
        {'D','O','R','A','D','O','C','A','S','A'},
        {'A','S','A','D','O','R','A','D','O','S'},
        {'C','A','S','A','D','O','C','A','S','A'},
        {'A','D','O','A','S','A','D','O','S','O'},
        {'A','S','A','C','C','A','S','A','D','O'},
        {'A','S','A','A','S','A','C','A','S','A'},
        {'C','A','S','A','D','O','A','S','A','D'},
        {'D','O','R','A','D','O','A','S','A','C'},
    };

    char palabras[][10] = { "CASADO", "ASADO","DORADO","CASA","ASA" };

    cout << "CONTADOR DE PALABRAS" << endl;
    for (char(*p)[10] = palabras; p < palabras + 5; p++)
        cout << "La palabra " << *p << " aparece " << contar(mat,*p) << " veces" << endl;
}
