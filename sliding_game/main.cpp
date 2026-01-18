/*
Implemente un sliding game usando solo punteros

Dificultad: 3/3
*/

#include <iostream>
#include <random>

using namespace std;

class Slidegame {
private:
    int** table;
    int* space_position;
    int** current_row;
    int size_table;
public:
    Slidegame() {
        cout << "Ingrese el tamanho del tablero: ";
        cin >> size_table;

        table = new int*[size_table];
        for (int** t = table; t < table + size_table; t++) {
            *t = new int[size_table];
        }

        int numbers = 1;
        for (int** i = table; i < table + size_table; i++) {
            for (int* j = *i; j < *i + size_table; j++) {
                *j = numbers;
                if(*j == size_table * size_table){*j = 0;}

                numbers++;
            }
        }

        space_position = *(table + size_table - 1) + size_table - 1;
        current_row = table + size_table - 1;
    }

    void start_game() {
        shuffle();
        print_table();
        bool finished = false;
        while (!finished) {
            get_movement(finished);
            print_table();
        }
        cout << "Ganaste!!!" << endl;
    }

    void get_movement(bool& fin) {
        char mov;
        cout << "Ingrese el movimiento: ";
        cin >> mov;

        switch (mov) {
            case 'a':
                mov_A();
                break;
            case 'w':
                mov_W();
                break;
            case 's':
                mov_S();
                break;
            case 'd':
                mov_D();
                break;
            case 'f':
                fin = checkwin();
                break;
            default:
                fin = true;
        }
    }

    bool checkwin(){
        int counter = 1;
        for(int** p = table; p < table + size_table; p++){
            for(int* q = *p; q < *p + size_table; q++){
                if(*q != counter && *q != 0){
                    return false;
                }
                counter++;
            }
        }

        return true;
    }

    bool mov_A() {
        if (*current_row + size_table - 1 == space_position) {
            return false;
        }
        int tmp = *space_position;
        *space_position = *(space_position + 1);
        *(space_position + 1) = tmp;

        space_position++;
        return true;
    }

    bool mov_D() {
        if (*current_row == space_position) {
            return false;
        }
        int tmp = *space_position;
        *space_position = *(space_position - 1);
        *(space_position - 1) = tmp;

        space_position--;
        return true;
    }

    bool mov_W() {
        if (current_row == table + size_table - 1) {
            return false;
        }

        int distance = space_position - *current_row;
        int tmp = *space_position;
        *space_position = *(*(current_row + 1) + distance);
        *(*(current_row + 1) + distance) = tmp;

        current_row++;
        space_position = *(current_row) + distance;
        return true;
    }

    bool mov_S() {
        if (current_row == table) {
            return false;
        }

        int distance = space_position - *current_row;
        int tmp = *space_position;
        *space_position = *(*(current_row - 1) + distance);
        *(*(current_row - 1) + distance) = tmp;

        current_row--;
        space_position = *(current_row) + distance;
        return true;
    }

    void print_table() {
        for (int** i = table; i < table + size_table; i++) {
            for (int* j = *i; j < *i + size_table; j++) {
                cout << *j << "\t";
            }
            cout << endl;
        }
    }

    void shuffle() {
        for(long long int i = 0; i < 1000; i++){
            int m = generate_number(4);

            switch (m) {
            case 1:
                mov_A();
                break;
            case 2:
                mov_W();
                break;
            case 3:
                mov_S();
                break;
            case 4:
                mov_D();
                break;
            default:
                cout << "error";
            }
        }

        for (int** i = table; i < table + size_table; i++) {
            for (int* j = *i; j < *i + size_table; j++) {
                if(*j == 0){
                    swap(*j, *(*(table + size_table - 1) + size_table - 1));
                    space_position = *(table + size_table - 1) + size_table - 1;
                    current_row = table + size_table - 1;
                }
            }
        }
    }

    int generate_number(int n){
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> dis(1,n);

        return dis(gen);
    }

    ~Slidegame() {}
};

int main() {
    Slidegame game;
    game.start_game();

    return 0;
}