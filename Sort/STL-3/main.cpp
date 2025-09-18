#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool sort_2 (pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){

    if (a.second.first < b.second.first) {
        return true;
    }
    else if (a.second.first == b.second.first) {
        if  (a.second.second < b.second.second) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main () {
    vector<pair<string, pair<int, int>>> v;

    v.push_back(pair<string, pair<int, int>> ("김철수", make_pair(29, 2015)));
    v.push_back(pair<string, pair<int, int>> ("이철수", make_pair(32, 2018)));
    v.push_back(pair<string, pair<int, int>> ("박철수", make_pair(14, 2017)));
    v.push_back(pair<string, pair<int, int>> ("정철수", make_pair(29, 2016)));
    v.push_back(pair<string, pair<int, int>> ("최철수", make_pair(32, 2025)));
    
    sort(v.begin(), v.end(), sort_2);

    for (int i = 0 ; i < 5 ; i++){
        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
    }


    return 0;
}