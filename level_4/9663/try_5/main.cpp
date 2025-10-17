#include <bits/stdc++.h>
using namespace std;

int N;
int awnser;
int chess_board[15];

bool test_valid(int max_index)
{
    for (int i = 0; i<max_index; i++){
        
        int horizon_diff =  max_index - i;

        int vertical_diff = abs(chess_board[i] - chess_board[max_index]);

        if (horizon_diff == vertical_diff) return false;
        
    }
    return true;
}


void find_perfection(int test_index){
    if (test_index == N){
        awnser++;
        return;
    }
    /*
    set<int> used_queens;
    for (int used_position=0; used_position < test_index; used_position++){
        used_queens.insert(chess_board[used_position]);
    }
    
    for (int candadate_position=0; candadate_position<N; candadate_position++){
        if (used_queens.find(candadate_position) == used_queens.end()){
            chess_board[test_index] = candadate_position;
            if (test_valid(test_index)){
                find_perfection(test_index + 1);
            }
        }
    }
    */

    bool is_not_usable[15] = {false};
    for (int used_position=0; used_position < test_index; used_position++){
        is_not_usable[chess_board[used_position]] = true;
    }

    for (int candadate_position=0; candadate_position<N; candadate_position++){
        if (!is_not_usable[candadate_position]){
            chess_board[test_index] = candadate_position;
            if (test_valid(test_index)){
                find_perfection(test_index + 1);
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    if (N == 1){
        cout << 1;
        return 0;
    }

    if (N == 2) {
        cout << 0;
        return 0;
    }
    
    awnser = 0;

    find_perfection(0);

    cout << awnser;

    return 0;
}
