#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<int> number_n;
    for (int _=0;_<N;_++){
        int x;
        cin >> x;
        number_n.push_back(x);
    }

    sort(number_n.begin(), number_n.end());

    
    vector<int> mask_vector;
    for (int i=1;i<=M;i++){
        mask_vector.push_back(i);
    }
    for (int _=0;_<N-M;_++){
        mask_vector.push_back(0);
    }

    sort(mask_vector.begin(), mask_vector.end(), greater());

    do {
        for (int mask_idx=M; mask_idx>=1; mask_idx--){
            for (int i=0; i<N; i++){
                if (mask_idx == mask_vector[i]){
                    cout << number_n[i] << " ";
                }
            }
        }
        cout << '\n';
    } while(next_permutation(mask_vector.begin(), mask_vector.end(), greater()));

    return 0;
}