#include <bits/stdc++.h>
using namespace std;

struct board_node {
    vector<int> chess_board;
    set<int> left_chess;
};


bool test_valid(vector<int> chess_board)
{
    if (chess_board.size() == 1){
        return true;
    }

    int max_index = chess_board.size() -1;

    for (int i = 0; i<max_index; i++){
        
        int horizon_diff =  max_index - i;

        int vertical_diff = abs(chess_board[i] - chess_board[max_index]);

        if (horizon_diff == vertical_diff) {
            return false;
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
    
    set<int> total_queens;
    for (int i=0; i<N; i++){
        total_queens.insert(i);
    }

    int awnser = 0;

    stack<board_node>s;
    
    board_node init_node;
    vector<int> init_board = {};
    init_node.chess_board = init_board;
    init_node.left_chess = total_queens;

    s.push(init_node);

    while (!s.empty()){
        board_node current_node = s.top(); s.pop();
        vector<int> current_board = current_node.chess_board;
        set<int> current_left_queen = current_node.left_chess;
        
        if (current_left_queen.empty()){
            awnser ++;
            continue;
        }

        for (int test_queen : current_left_queen){
            vector<int> test_board = current_board;
            test_board.push_back(test_queen);

            if (test_valid(test_board)){
                board_node next_node;
                next_node.chess_board = test_board;

                set<int> new_queens = current_left_queen;
                new_queens.erase(test_queen);

                next_node.left_chess = new_queens;

                s.push(next_node);
            }
        }
    }


    cout << awnser;

    return 0;
}
