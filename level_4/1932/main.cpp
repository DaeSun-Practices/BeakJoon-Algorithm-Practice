#include <bits/stdc++.h>

using namespace std;




int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<long long>> horizon;
    for (int i=0; i<N; i++){
        vector<long long> vertical;

        for (int j=0; j<i+1; j++){
            long long x;
            cin >> x;
            vertical.push_back(x);
        }
        horizon.push_back(vertical);
    }


    vector<vector<long long>> score_horizon;
    vector<long long> score_vertical = { horizon[0][0] };
    score_horizon.push_back(score_vertical);


    for (int i=1; i<N; i++){
        vector<long long> score_vertical;

        for (int j=0; j<i+1; j++){
            if (j==0){
                long long score = score_horizon[i-1][j] + horizon[i][j];
                score_vertical.push_back(score);
            }
            else if (j==i){
                long long score = score_horizon[i-1][j-1] + horizon[i][j];
                score_vertical.push_back(score);
            }
            else {
                long long max_score = max(score_horizon[i-1][j-1], score_horizon[i-1][j]) + horizon[i][j];
                score_vertical.push_back(max_score);
            }
        }
        score_horizon.push_back(score_vertical);
    }

    long long max_score = score_horizon[N-1][0];
    for (int i=1; i < N; i++){
        if (max_score < score_horizon[N-1][i]){
            max_score = score_horizon[N-1][i];
        }
    }

    cout << max_score;


    /*
    for (int i=0; i<N; i++){
        for (int j=0; j<i+1; j++){
           cout << horizon[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<i+1; j++){
           cout << score_horizon[i][j] << ' ';
        }
        cout << '\n';
    }
        */


    return 0;
}