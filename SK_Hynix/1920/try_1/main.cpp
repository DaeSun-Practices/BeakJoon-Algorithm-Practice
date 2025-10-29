#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N ;


    vector<long long> n_list;
    long long x;
    for (int _=0;_<N;_++){
        cin >> x;
        n_list.push_back(x);
    }

    sort(n_list.begin(), n_list.end());


    int M;
    cin >> M;

    for (int _=0;_<M;_++){
        cin >> x;

        if (find(n_list.begin(), n_list.end(), x) ==  n_list.end()){
            cout << '0\n';
        }
        else {
            cout << '1\n';
        }
    }

    return 0;
}
