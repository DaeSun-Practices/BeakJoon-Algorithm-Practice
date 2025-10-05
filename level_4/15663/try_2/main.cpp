#include <bits/stdc++.h>

using namespace std;


void make_combi_recurr(
    vector<vector<int>> combination_list,
    vector<int> current_combi,
    vector<int> number_n,
    int max_dept
)
{
    int current_dept = 0;
    current_dept = current_combi.size();

    if (current_dept == 0){
        for (int i=0; i < number_n.size(); i++){
            vector<int> new_combi = {i};
            make_combi_recurr(
                combination_list,
                new_combi,
                number_n,
                max_dept
            );
        }
    }

    else if (current_dept == max_dept){
        vector<int> real_combi;
        for (int index : current_combi){
            real_combi.push_back(number_n[index]);
        }

        if (find(combination_list.begin(), combination_list.end(), real_combi) == combination_list.end()){
            combination_list.push_back(real_combi);
            
            for (int x : real_combi) {
                cout << x << ' ';
            }
            cout << '\n';
            
        }
            
    }

    else {
        for (int index=0; index < number_n.size(); index++) {
            vector<int> new_combi = current_combi;
            if (find(current_combi.begin(), current_combi.end(), index) == current_combi.end()) {
                new_combi.push_back(index);

                make_combi_recurr(
                    combination_list,
                    new_combi,
                    number_n,
                    max_dept
                );
            }
        }
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> number_n;

    
    for (int i=0; i<N; i++){
        int x;
        cin >> x;

        number_n.push_back(x);
    }

    sort(number_n.begin(), number_n.end());

    vector<vector<int>> combination_list;
    set<vector<int>> tester;
    vector<int> new_combi;

    make_combi_recurr(
        combination_list,
        new_combi,
        number_n,
        M
    );

    for (int i=0; i < combination_list.size(); i++){
        for (int j=0; j < M; j++){
            cout << combination_list[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}