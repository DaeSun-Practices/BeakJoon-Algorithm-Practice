#include <iostream>

using namespace std;

int main () {
    int size_num = 9;
    int radius = size_num / 2;

    for (int i = 0; i <= radius; i++ ){

        for (int j=0 ; j <= radius - 1 - i; j++) {
            cout << ' ';
        }

        for (int j=1 ; j <= i * 2 + 1; j++) {
            cout << '*';
        }

        for (int j=0 ; j <= radius - 1 - i; j++) {
            cout << ' ';
        }

        cout << endl;
    }

    for (int i = 0; i < radius; i++ ){

        for (int j=1 ; j <= i+1; j++) {
            cout << ' ';
        }

        for (int j=1 ; j <= (radius - i - 1) * 2 + 1; j++) {
            cout << '*';
        }


        for (int j=1 ; j <= i+1; j++) {
            cout << ' ';
        }


        cout << endl;
    }

    return 0;
}