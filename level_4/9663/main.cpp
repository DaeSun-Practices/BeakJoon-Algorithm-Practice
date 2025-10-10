#include <bits/stdc++.h>
using namespace std;

int N;
int total = 0;
int col[15]; // col[row] = 퀸이 위치한 열(column)

// 현재 행(row)까지 유효한 배치인지 검사
bool is_valid(int row) {
    for (int i = 0; i < row; i++) {
        // 같은 열이거나, 대각선에 위치한 경우
        if (col[i] == col[row] || abs(col[row] - col[i]) == row - i)
            return false;
    }
    return true;
}

// row번째 행에 퀸을 배치하는 함수
void dfs(int row) {
    if (row == N) {
        total++;
        return;
    }
    for (int c = 0; c < N; c++) {
        col[row] = c;
        if (is_valid(row))
            dfs(row + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dfs(0);
    cout << total << '\n';
    return 0;
}
