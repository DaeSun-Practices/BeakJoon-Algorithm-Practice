#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,S;
    cin >> N >> S;

    vector<int> v;

    for (int _=0;_<N;_++){
        int x;
        cin >> x;

        v.push_back(x);
    }

    int awnser = 0;
    
    for (int mask=1; mask < (1<<N); mask++){
        int current = 0;

        for (int i=0; i< N; i++){
            if (mask & 1<<i){
                current += v[i];
            }
        }

        if (current == S){
            awnser++;
        }
    }

    cout << awnser;

}