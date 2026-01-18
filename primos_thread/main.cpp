/*
Dado un array a, copie los numeros primos de ese array a un puntero b usando threads

Dificultad: 1/3
*/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int index = 0;
mutex candado;

bool isP(int number){
    if(number == 1){return false;}
    for(int i = 2; i < number; i++){
        if (number % i == 0){
            return false;
        }
    }
    return true;
}

void printArr(int* ini, int* fin){
    for(;ini<fin;ini++){
        cout << *ini << " " << endl;
    }
    cout << endl;
}

void add(int* p, int number){
    candado.lock();
    *(p + index) = number;
    index++;
    candado.unlock();
}

void inicializar(int* b, int* ini, int* fin){
    
    for(int* p = ini; p <= fin; p++){
        if(isP(*p)){
            add(b, *p);
        }
    }
    
}

int main(){
    int* a = new int[99];
    for(int i = 0; i < 99; i++){
        *(a + i) = i + 2;
    }

    int* b = new int[100];

    thread t1(inicializar, b, a, a + 11);
    thread t2(inicializar, b, a + 12, a + 23);
    thread t3(inicializar, b, a + 24, a + 35);
    thread t4(inicializar, b, a + 36, a + 47);
    thread t5(inicializar, b, a + 48, a + 59);
    thread t6(inicializar, b, a + 60, a + 71);
    thread t7(inicializar, b, a + 72, a + 83);
    thread t8(inicializar, b, a + 84, a + 99);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    cout << index << endl;
    printArr(b, b + index - 1);

    return 0;
}