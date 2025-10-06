#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int test_case_index = 0; test_case_index<T; test_case_index++){
        int N;
        cin >> N;

        int sticker_table [2][N];
        for (int i=0; i < N; i++){
            int x;
            cin >> x;

            sticker_table[0][i] = x;
        }

        for (int i=0; i < N; i++){
            int x;
            cin >> x;

            sticker_table[1][i] = x;
        }

        int score_mask[3][N];

        score_mask[0][0] = sticker_table[0][0];
        score_mask[1][0] = sticker_table[1][0];
        score_mask[2][0] = 0;

        for (int use_index=1; use_index<N; use_index++){
            score_mask[0][use_index] = max(score_mask[1][use_index-1]+sticker_table[0][use_index], score_mask[2][use_index-1]+sticker_table[0][use_index]);
            score_mask[1][use_index] = max(score_mask[0][use_index-1]+sticker_table[1][use_index], score_mask[2][use_index-1]+sticker_table[1][use_index]);
            score_mask[2][use_index] = max(score_mask[0][use_index-1], score_mask[1][use_index-1]);
        }


        int max_score = max(score_mask[0][N-1], score_mask[1][N-1]);
        cout << max_score << '\n';
    }



    return 0;
}