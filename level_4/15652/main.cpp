#include <bits/stdc++.h>

using namespace std;

void recur_backtracking(vector<int> previous_vector, int max_num, int max_dept){
    int current_dept = previous_vector.size();
    if (current_dept == max_dept) {
        for (int i=0; i < max_dept; i++){
            cout << previous_vector[i] << " ";
        }
        cout << '\n';

        return ;
    }
    else if (current_dept == 0){
        for (int i=1; i <= max_num; i++){
            vector<int> new_vector = {i};
            recur_backtracking(new_vector, max_num, max_dept);
        }

        return;
    }
    else {
        int last_number = previous_vector.back();
        for (int i=last_number; i <= max_num; i++){
            vector<int> new_vector = previous_vector;
            new_vector.push_back(i);
            recur_backtracking(new_vector, max_num, max_dept);
        }
        return;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> previous_vector;
    recur_backtracking(previous_vector, N, M);


    return 0;
}