#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;


int main () {
    int input_num;
    cin >> input_num;

    vector<int> num_vector;


    for (int i=0; i<input_num; i++) {
        int input_number;
        cin >> input_number;
        num_vector.push_back(input_number);
    }

    sort(num_vector.begin(), num_vector.end());

    for (int i = 0; i < num_vector.size(); i++){
        cout << num_vector[i] << endl;
    }
    

    return 0;
}