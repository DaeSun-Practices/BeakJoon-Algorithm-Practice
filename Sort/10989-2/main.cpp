#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;


int main () {
    int input_num;
    cin >> input_num;

    set<int> duplication_detector;
    map<int, int> input_map;

    for (int i=0; i<input_num; i++) {
        int input_number;
        cin >> input_number;

        if (duplication_detector.insert(input_number).second){
            input_map[input_number] = 1;
        }
        else {
            input_map[input_number]++;
        }
    }

    vector<pair<int, int>> optimized_vector;

    map<int, int>::iterator current_element;
    for (current_element = input_map.begin(); current_element != input_map.end(); current_element++){
        int printing_number = current_element->first;
        int printing_count = current_element->second;

        optimized_vector.push_back(pair<int, int>(printing_number, printing_count));
    }

    sort(optimized_vector.begin(), optimized_vector.end());
    

    for (int i = 0; i < optimized_vector.size(); i++){
        int printing_number = optimized_vector[i].first;
        int printing_count = optimized_vector[i].second;

        for (int j=0; j < printing_count; j++){
            cout << printing_number << endl;
        }

    }
        


    return 0;
}