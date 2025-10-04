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
    for (int bitmask=0; bitmask<2^N; bitmask++){
        int current = 0;

        for (int mask=1; mask<N+1; mask++){
            if (bitmask % 2^mask) {
                current += v[mask-1];
            }
        }

        if (S == current){
            
        }
    }

}