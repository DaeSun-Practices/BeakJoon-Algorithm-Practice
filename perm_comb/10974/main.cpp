#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> perm_array;
    for (int i=1;i<=N;i++){
        perm_array.push_back(i);
    }

    do {
        for (int i=0;i<N;i++){
            cout << perm_array[i] << " ";
        }
        cout << '\n';
    } while (next_permutation(perm_array.begin(), perm_array.end()));

    return 0;
}