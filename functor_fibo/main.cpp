/* 
Imprimir n-simos numeros de fibonacci usando functores
Dificultad: 2/3
*/

#include<iostream>

using namespace std;

template<typename T>
class funct{
    int x;
    public:
    funct(T _x) : x(_x) {};
    T operator()(T a){
        return x + a;
    }

};

template<typename T, typename O>
class fibo{
    int A[2] = {1, 1};
    int i;
    public:
    fibo(int _i) : i(_i) {};
    void init(){
        for(int j = 0; j < i; j++){
            cout << *A << endl;
            O opera(*A);
            *A = *(A + 1);
            *(A + 1) = opera(*(A + 1));
        }
    }
};

int main(){
    fibo<int,funct<int>> fib(10);
    fib.init();

    return 0;
}