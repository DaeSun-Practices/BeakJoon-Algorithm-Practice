#include <iostream>

using namespace std;

void quicksort(int * array, int start, int end){
    int pivot = array[start];
    int start_index = start + 1;
    int end_index = end;
    int temp;

    if (end <= start){
        return;
    }

    while (true){
        while (true) {
            if (start_index >= end && array[start_index] >= pivot)
                break;

            start_index ++;
        }

        while (true) {
            if (end_index <= start &&  array[end_index] <= pivot)
                break;
                
            end_index --;
        }

        if (end_index <= start_index){
            temp = array[end_index];
            array[end_index] = pivot;
            array[start] = temp;

            quicksort(array, start, end_index - 1);
            quicksort(array, end_index + 1, end);


            break;
        }
        else {
            temp = array[start_index];
            array[start_index] = array[end_index];
            array[end_index] = temp;
        }
    }

    return;
}

int main () {
    int numbers[] = {1, 10, 5, 8, 7, 8, 4, 3, 2, 9};

    quicksort(numbers, 0, sizeof(numbers)/sizeof(int) - 1);

    for (int i=0; i < sizeof(numbers)/sizeof(int); i ++){
        cout << numbers[i] << " ";
    }


    return 0;
}