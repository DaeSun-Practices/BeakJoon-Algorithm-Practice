#include <bits/stdc++.h>
using namespace std;

void make_combi_recurr(
    vector<vector<int>> &combination_list,
    vector<int> &current_combi,
    vector<int> &number_n,
    int max_dept,
    int start
) {
    if ((int)current_combi.size() == max_dept) {
        if (find(combination_list.begin(), combination_list.end(), current_combi) == combination_list.end()){
            combination_list.push_back(current_combi);
        }
        return;
    }

    for (int i = 0; i < number_n.size(); i++) {
        current_combi.push_back(number_n[i]);
        make_combi_recurr(combination_list, current_combi, number_n, max_dept, i + 1);
        current_combi.pop_back();
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> number_n(N);
    for (int i = 0; i < N; i++) {
        cin >> number_n[i];
    }

    sort(number_n.begin(), number_n.end());

    vector<vector<int>> combination_list;
    vector<int> current_combi;

    make_combi_recurr(combination_list, current_combi, number_n, M, 0);

    for (auto &comb : combination_list) {
        for (int x : comb) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
