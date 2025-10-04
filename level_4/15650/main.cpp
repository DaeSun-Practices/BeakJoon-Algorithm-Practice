#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vector<int> numbers_n;
    for (int i=1; i<=N; i++){
        numbers_n.push_back(i);
    }

    vector<int> mask_vector;
    
    

    for (int i=0; i<M; i++){
        mask_vector.push_back(1);
    }

    for (int i=0; i<N-M; i++){
        mask_vector.push_back(0);
    }

    do {
        for (int i=0; i < N; i++){
            if (mask_vector[i]){
                cout << numbers_n[i] << " ";
            }
        }
        cout << '\n';
    } while (next_permutation(mask_vector.begin(), mask_vector.end(), greater()));
    
    return 0;
}