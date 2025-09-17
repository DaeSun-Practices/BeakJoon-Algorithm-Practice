#include <iostream>

using namespace std;

int main () {
    int my_array[] = {1,2,3,4,5,4,3,2,1};

    for (int i = 1; i < sizeof(my_array) / sizeof(int); i++) {
        int previous = my_array[i - 1];
        int current = my_array[i];

        if (previous > current) {
            cout << previous << endl;
            break;
        }

        cout << previous << endl;

    }


    char my_string[] = "Hello\0 World!";
    for (int i = 0; i < sizeof(my_string) / sizeof(char); i++) {
        char current = my_string[i];

        if (current == '\0') {
            cout << endl;
            break;
        }

        cout << current;

    }


    int i = 0;
    while (true) {
        if (i > 9) {
            cout << endl;
            break;
        }


        cout << i ;

        i++;
    }


    int index = 0;
    while (true) {
        char current = my_string[index];

        if (current == '\0') {
            break;
        }

        cout << current;



        index++;
    }

    return 0;
}