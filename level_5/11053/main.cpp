#include <bits/stdc++.h>

using namespace std;

int n;
int x;
int MIN_NUM = 0;
int MAX_NUM = 1001;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> original_vector;
    for (int _=0; _<n; _++){
        cin >> x;
        original_vector.push_back(x);
    }

    vector<int> permutation_length(n, 1);

    for (int i=1; i<n; i++){
        int criteria = original_vector[i];

        int before_max = 1;
        for (int j=0; j<i; j++){
            if (original_vector[j] < criteria) {
                before_max = max(before_max, permutation_length[j] + 1);
            }
        }

        permutation_length[i] = before_max;
    }

    int total_max = permutation_length[0];
    for (int i=1; i<n; i++){
        total_max = max(total_max, permutation_length[i]);    
    }

    cout << total_max;

    return 0;
}