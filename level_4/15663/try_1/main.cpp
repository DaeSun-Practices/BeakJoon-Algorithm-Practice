#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> number_n;
    vector<int> mask_vector;

    for (int i=0; i<M; i++){
        mask_vector.push_back(1);
    }
    for (int i=0; i<N-M; i++){
        mask_vector.push_back(0);
    }




    
    for (int i=0; i<N; i++){
        int x;
        cin >> x;

        number_n.push_back(x);
    }

    sort(number_n.begin(), number_n.end());

    
    vector<vector<int>> combi_list;
    do {
        vector<int> combi;
        for (int i=0; i < N; i++){
            if (mask_vector[i]){
                combi.push_back(number_n[i]);
            }
        }
        if (find(combi_list.begin(), combi_list.end(), combi) == combi_list.end())
            combi_list.push_back(combi);

    } while (next_permutation(mask_vector.begin(), mask_vector.end(), greater()));

    for (int i=0; i < combi_list.size(); i++){
        for (int j=0; j< M; j++){
            cout << combi_list[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}