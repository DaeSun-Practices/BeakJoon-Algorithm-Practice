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

        // filter N is not enugh
        if (N == 1){
            if (sticker_table[0][0] > sticker_table[1][0]){
                cout << sticker_table[0][0] << '\n';
                continue;
            }
            else {
                cout << sticker_table[1][0] << '\n';
                continue;
            }
        }
        else if (N==2){
            int score_a = sticker_table[0][0] + sticker_table[1][1];
            int score_b = sticker_table[0][1] + sticker_table[1][0];
            if (score_a > score_b){
                cout << score_a << '\n';
                continue;
            }
            else {
                cout << score_b << '\n';
                continue;
            }
        }

        // 0 : 위 사용, 1 : 아래 사용, 2: 안사용
        int score_mask[3][N-2];
        score_mask[0][0] = sticker_table[0][0] + sticker_table[1][1] + sticker_table[0][2];
        score_mask[1][0] = sticker_table[1][0] + sticker_table[0][1] + sticker_table[1][2];

        int score_a = sticker_table[0][0] + sticker_table[1][1];
        int score_b = sticker_table[0][1] + sticker_table[1][0];

        score_mask[2][0] = max(score_a, score_b);

        for (int use_index=1; use_index<N-2; use_index++){
            score_mask[0][use_index] = max(score_mask[1][use_index-1]+sticker_table[0][use_index+2], score_mask[2][use_index-1]+sticker_table[0][use_index+2]);
            score_mask[1][use_index] = max(score_mask[0][use_index-1]+sticker_table[1][use_index+2], score_mask[2][use_index-1]+sticker_table[1][use_index+2]);
            score_mask[2][use_index] = max(score_mask[0][use_index-1], score_mask[1][use_index-1]);
        }

        int max_score = max(score_mask[0][N-3], score_mask[1][N-3]);
        cout << max_score << '\n';
    }



    return 0;
}