#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> n_numbers;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;

        n_numbers.push_back(x);
    }

    sort(n_numbers.begin(), n_numbers.end(), greater());

    vector<int> mask_vector;
    for (int i=0; i<N-M; i++) {
        mask_vector.push_back(0);
    }
    for (int i=1; i<=M; i++) {
        mask_vector.push_back(i);
    }

    vector<vector<int>> combi_table;

    do {
        for (int order_index = 1; order_index <= M; order_index++){
            for (int i=0; i<N; i++){
                if (mask_vector[i] == order_index) {
                    cout << n_numbers[i] << ' ';
                    break;
                }
            }
            
        }

        cout << '\n';
    } while (next_permutation(mask_vector.begin(), mask_vector.end(), less()));

    return 0;
}