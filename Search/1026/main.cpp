#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sort_desc(int a, int b){
    return a>b;
}

int main () {
    int number;
    cin >> number; 

    vector<int> a_vector;
    vector<int> b_vector;

    for (int i=0; i<number; i++){
        int input_number;
        cin >> input_number;
        a_vector.push_back(input_number);
    }

    for (int i=0; i<number; i++){
        int input_number;
        cin >> input_number;
        b_vector.push_back(input_number);
    }

    sort(a_vector.begin(), a_vector.end());
    sort(b_vector.begin(), b_vector.end(), sort_desc);

    int total = 0;
    for (int i=0; i<number; i++){
        total += a_vector[i] * b_vector[i];
    } 

    cout << total;

    return 0;
}