#include <bits/stdc++.h>

using namespace std;

void recurr_backtracking (vector<int> number_n, vector<int> previous_vec, int max_dept){
    int current_dept = previous_vec.size();
    if (current_dept == 0){
        for (int x: number_n){
            vector<int> new_vec = { x };
            recurr_backtracking(number_n, new_vec, max_dept);
        }
        return;
    }
    else if (current_dept == max_dept){
        for (int x: previous_vec){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    else {
        for (int x: number_n){
            auto it = find(previous_vec.begin(), previous_vec.end(),x);
            if (it == previous_vec.end()){
                vector<int> new_vec = previous_vec;
                new_vec.push_back(x);
                recurr_backtracking(number_n, new_vec, max_dept);
            }
        }
        return;
    }
}

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


    vector<int> current_vector;
    recurr_backtracking(number_n, current_vector, M);

    return 0;
}