/* 
Cree una clase Orden para manipular elementos en un array y que estos esten siempre ordenados. La clase debe
tener metodos print, find, add, delete. Use templates para pasarle dos functores y que estos permitan
ordenar en orden ascendente o descendente y que la clase Orden pueda ordenar cualquiero tipo de dato

Dificultad: 2/3
*/

#include <iostream>
#include <string>

using namespace std;

template<class T>
struct asc
{
    bool operator()(T pos, T val)
    {
        return pos < val;
    }
};

template<class T>
struct des
{
    bool operator()(T pos, T val)
    {
        return pos > val;
    }
};

template<class T, class U, int N = 100>
class orden
{
    T A[N];
    int n = 0;
    int max = N;
    U comp;
public:

    void print()
    {
        for (T* i = A; i < A + n; i++)
            cout << *i << " - ";
        cout << endl;
    }

    bool find(T val, T*& pos)
    {
        pos = NULL;

        if (n == 0)
            return false;
        pos = A;
        for (; pos < A + n && comp(*pos, val); pos++);
        if (pos == A + n)
            return false;
        if (*pos == val)
            return true;
        else
            return false;

    }

    bool add(T val)
    {
        T* p;

        if (n == max) return false;

        if (!find(val, p))
        {
            if (!p)
            {
                *A = val;
                n++;
            }
            else
            {
                for (T* tmp = A + n; tmp > p; tmp--)
                    *tmp = *(tmp - 1);
                *p = val;
                n++;
            }
        }

        return true;
    }

    bool pop(T val){

        T* p;
        if(n == 0) return false;

        if(find(val, p)){
            for(; p < A + n; p++){
                *p = *(p + 1);
            }
            n--;
        }

        return true;
    }

};

int main()
{
    orden<int, asc<int>, 10> obj;

    obj.print();
    obj.add(5);
    obj.print();
    obj.add(1);
    obj.print();
    obj.add(8);
    obj.print();
    obj.add(3);
    obj.print();
    obj.add(6);
    obj.print();
    obj.add(6);
    obj.print();
    obj.pop(5);
    obj.print();
    obj.pop(1);
    obj.print();
    obj.pop(2);
    obj.print();
}