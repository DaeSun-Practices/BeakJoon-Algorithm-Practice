#include <iostream>


using namespace std;


int main () {
    int input_num;
    cin >> input_num;

    int number_array[10001] = { 0 };

    for (int i=0; i<input_num; i++) {
        int input_number;
        cin >> input_number;
        number_array[input_number]++;
    }

    for (int i = 1; i < 10001; i++){
        if (number_array[i] !=0) {
            for (int j=0; j<number_array[i]; j++){
                cout << i << endl;
            }  
        }
        
    }
    

    return 0;
}