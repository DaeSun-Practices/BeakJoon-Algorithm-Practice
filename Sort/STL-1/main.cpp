#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool desc_sort (int a, int b){

    if (a>b) 
        return true;
    else
        return false;
}

int main () {
    int numers[] = {10, 3, 2, 5, 1, 6, 4, 7, 9, 8};

    sort(numers, numers + 10);

    for (int i=0; i<10; i++){
        cout << numers[i] << " ";
    }

    cout << endl;
    

    sort(numers, numers + 10, desc_sort);


    for (int i=0; i<10; i++){
        cout << numers[i] << " ";
    }

    cout << endl;

    return 0;
}