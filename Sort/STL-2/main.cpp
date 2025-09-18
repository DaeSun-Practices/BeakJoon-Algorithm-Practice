#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


int main () {
    vector<pair<int, string >> v;

    v.push_back(pair<int, string> (10, "김철수"));
    v.push_back(pair<int, string> (1, "이철수"));
    v.push_back(pair<int, string> (5, "박철수"));
    v.push_back(pair<int, string> (3, "정철수"));
    v.push_back(pair<int, string> (8, "최철수"));
    
    sort(v.begin(), v.end());

    for (int i=0; i<5; i++){
        cout << v[i].second << " " << v[i].first << endl;
    }

    cout << endl;

    return 0;
}