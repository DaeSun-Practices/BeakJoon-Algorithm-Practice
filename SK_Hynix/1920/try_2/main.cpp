#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N ;


    set<long long> n_set;
    long long x;
    for (int _=0;_<N;_++){
        cin >> x;
        n_set.insert(x);
    }


    int M;
    cin >> M;

    for (int _=0;_<M;_++){
        cin >> x;

        if (n_set.find(x) == n_set.end()){
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }

    return 0;
}
