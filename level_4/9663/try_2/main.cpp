#include <bits/stdc++.h>
using namespace std;

bool test_valid(vector<int> chess_board)
{
    for (int i = chess_board.size() - 1; i>0; i--){
        for (int j = i - 1; j>=0; j-- ){
            int horizon_diff =  i - j;

            int vertical_diff = abs(chess_board[i] - chess_board[j]);

            if (horizon_diff == vertical_diff) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 1){
        cout << 1;
        return 0;
    }

    if (N == 2) {
        cout << 0;
        return 0;
    }
    
    vector<int> chess_board;
    for (int i=1; i<=N; i++){
        chess_board.push_back(i);
    }

    int awsner = 0;

    do {
        if (test_valid(chess_board)) awsner++;
       
    } while (next_permutation(chess_board.begin(), chess_board.end(), less()));

    cout << awsner;

    return 0;
}
