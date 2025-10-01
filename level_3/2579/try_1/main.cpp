#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    bool selection_array[N] = {false, };
    vector<pair<int, int>> stair_vector;

    for (int i = 0; i < N; i++){  
        int grade;
        cin >> grade;
        stair_vector.push_back(pair<int, int>(grade,i));
    }

    int total_grade = stair_vector.back().first; stair_vector.pop_back();
    selection_array[N-1] = true;

    sort(stair_vector.begin(), stair_vector.end());

    for (int i=0; i<N-1; i++){
        int current_grade = stair_vector.back().first;
        int stair_index = stair_vector.back().second;
        stair_vector.pop_back();

        selection_array[stair_index] = true;

        if (stair_index<=N-3){
            if (selection_array[stair_index]&&selection_array[stair_index+1]&&selection_array[stair_index+2]){
                selection_array[stair_index] = false;
                continue;
            }
        }

        if (stair_index<=N-2 && stair_index>=1){
            if (selection_array[stair_index]&&selection_array[stair_index+1]&&selection_array[stair_index-1]){
                selection_array[stair_index] = false;
                continue;
            }
        }

        if ( stair_index>=2){
            if (selection_array[stair_index]&&selection_array[stair_index-2]&&selection_array[stair_index-1]){
                selection_array[stair_index] = false;
                continue;
            }
        }

        total_grade += current_grade;
    }


    cout << total_grade << '\n';

    return 0;
}