#include <bits/stdc++.h>

using namespace std;

void make_combi_recurr(
    vector<vector<int>> &combination_list,
    vector<int> &current_combi,
    vector<int> &number_n,
    int max_dept
){
    int current_depth = current_combi.size();
    if (current_depth == 0) {
        for (int i = 0; i < number_n.size(); i++){
            vector<int> new_combi = {i};

            make_combi_recurr(
                combination_list,
                new_combi,
                number_n,
                max_dept
            );
        }
    }
    else if (current_depth == max_dept){

    }
    else {
        cout << max_dept;
    }
}

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

    sort(n_numbers.begin(), n_numbers.end());

    vector<vector<int>> combination_list;
    vector<int> new_combi;
    make_combi_recurr(
        combination_list,
        new_combi,
        n_numbers,
        M
    );


 

    return 0;
}