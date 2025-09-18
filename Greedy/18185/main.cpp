#include <iostream>
#include <algorithm>

using namespace std;

int test_three(int array[], int index){
    int max_buy = min(min(array[index], array[index+1]), array[index+2]);
    int price = max_buy * 7;

    array[index] -= max_buy;
    array[index+1] -= max_buy;
    array[index+2] -= max_buy;

    return price;
}

int test_two(int array[], int index){
    int max_buy = min(array[index], array[index+1]);
    int price = max_buy * 5;

    array[index] -= max_buy;
    array[index+1] -= max_buy;
    
    return price;
}


int main () {
    int total_price = 0;
    int number_input;
    cin >> number_input;
    int array[number_input];

    for (int i=0; i<number_input; i++){
        cin >> array[i];
    }

    int i=0;
    for (i=0; i< number_input - 2; i++){
        

        if (array[i+1] > array[i+2]) {
            int pre_buy_count = min(array[i], array[i+1] - array[i+2]);

            array[i] -= pre_buy_count;
            array[i+1] -= pre_buy_count;
            
            total_price += pre_buy_count * 5;
        }

        total_price += test_three(array, i);


        total_price += test_two(array, i);
        if (array[i] > 0) {
            total_price += array[i] * 3;
            array[i] = 0;
        }
    }

    total_price += test_two(array, i);
    if (array[i] > 0) {
        total_price += array[i] * 3;
        array[i] = 0;
    }

    if (array[number_input-1] > 0) {
        total_price += array[number_input-1] * 3;
        array[number_input-1] = 0;
    }



    cout << total_price;




    return 0;
}