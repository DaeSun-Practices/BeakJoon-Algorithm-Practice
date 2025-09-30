#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    string find_by_num[N];
    unordered_map<string, int> find_by_string;

    for (int i=0; i< N ; i ++){
        string name;
        cin >> name;

        find_by_num[i] = name;
        find_by_string.insert({name, i+1});
    }

    for (int i=0; i< M ; i ++){
        string query;
        cin >> query;

        if (isdigit(query[0])){
            cout << find_by_num[stoi(query)-1] << '\n';
        }
        else {
            cout << find_by_string[query] << '\n';
        }
    }


    return 0;
}