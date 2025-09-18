#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

bool sort_strings (pair<int, string> a, pair<int, string> b) {
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else {
        return a.second < b.second;
    }
}

int main () {
    set<string> input_set;
    vector<pair<int, string>> input_vector;

    int string_num;
    cin >> string_num;

    for (int i=0; i < string_num; i++){
        string input_string;
        cin >> input_string;
        if (input_set.insert(input_string).second)
            input_vector.push_back(pair<int, string> (input_string.size(),input_string));
    }

    sort(input_vector.begin(), input_vector.end(), sort_strings);

    for (int i=0; i < input_vector.size(); i++){
        cout << input_vector[i].second << endl;
    }




    return 0;
}