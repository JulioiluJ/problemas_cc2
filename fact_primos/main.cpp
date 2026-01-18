/* 
Imprimir los factores primos de un array usando 3 threads.
Dificultad: 1/3
*/

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex candado;

void printFacPrim(int number){
    candado.lock();
    int temp = number;
    for(int i = 2; i <= number; i++){
        if(temp % i == 0){
            cout << i << " ";
            while(temp % i == 0){temp /= i;}
        }
    }
    cout << endl;
    candado.unlock();
}

void printFacPrimArray(int* ini, int* fin){
    for(int* p = ini; p < fin; p++){
        printFacPrim(*p);
    }
}

int main(){
    int a[] = {15, 23, 2, 6, 5, 72, 100, 35, 8, 11};

    thread t1(printFacPrimArray, a, a + 3);
    thread t2(printFacPrimArray, a + 4, a + 6);
    thread t3(printFacPrimArray, a + 7, a + 9);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}