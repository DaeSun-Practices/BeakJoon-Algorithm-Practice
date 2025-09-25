#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int max_weight;
    int max_num;

    cin >> max_num >> max_weight;

    vector<pair<int, int>> object_vector;

    for (int i=0; i < max_num; i++){
        int weight, value;
        cin >> weight >> value;
        object_vector.push_back(pair<int, int>(value, weight));
    }


    


    return 0;
}